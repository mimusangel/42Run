#include "game.hpp"

Game::Game()
{
	for (size_t i = 0; i < MAX_ROAD; i++)
		_road[i] = nullptr;
	_shaders = nullptr;
	_texFont = nullptr;
	for (int i = 0; i < 3; i++)
		_textures[i] = nullptr;
	_fontMesh = nullptr;
	_texFont = nullptr;
	_font = nullptr;
	projection = glm::perspective(glm::radians(45.0f), 1280.f / 720.f, 0.0001f, 1000.0f);
	_state = 0;
	debugMode = false;
}

Game::~Game()
{
	for (size_t i = 0; i < MAX_ROAD; i++)
	{
		if (_road[i] != nullptr)
			delete _road[i];
	}
	if (_shaders != nullptr)
		delete _shaders;
	for (int i = 0; i < 3; i++)
		delete _textures[i];
	if (_texFont != nullptr)
		delete _texFont;
	if (_font != nullptr)
		delete _font;
	if (_fontMesh != nullptr)
		delete _fontMesh;
}

void	Game::init(void)
{
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glEnable(GL_BLEND);
	glfwSwapInterval(0);

	_shaders = new Shaders();
	if (!_shaders->loadFragmentShader("shaders/basic.frag"))
		throw std::logic_error("Erreur chargement basic.frag");
	if (!_shaders->loadVertexShader("shaders/basic.vert"))
		throw std::logic_error("Erreur chargement basic.vert");
	if (!_shaders->build())
		throw std::logic_error("Erreur compilation shader(basic)");
	_font = new Shaders();
	if (!_font->loadFragmentShader("shaders/font.frag"))
		throw std::logic_error("Erreur chargement font.frag");
	if (!_font->loadVertexShader("shaders/font.vert"))
		throw std::logic_error("Erreur chargement font.vert");
	if (!_font->build())
		throw std::logic_error("Erreur compilation shader(font)");
	_textures[0] = Texture::LoadBMP("textures/uvtemplate.bmp");
	_textures[1] = Texture::LoadBMP("textures/ground.bmp");
	_textures[2] = Texture::LoadBMP("textures/poto.bmp");
	_texFont = Texture::LoadBMP("textures/charmap.bmp");


	_fontMesh = new Mesh(2);
	_fontMesh->begin();
	GLfloat vPos[] = {
		0.f, 0.f,	50.f, 0.f,	50.f, 50.f,
		50.f, 50.f,	0.f, 50.f,	0.f, 0.f,
	};
	GLfloat vTex[] = {
		0.f, 0.f,						0.0555555556f, 0.f,	0.0555555556f, 0.1428571429f,
		0.0555555556f, 0.1428571429f,	0.f, 0.1428571429f,	0.f, 0.f,
	};
	_fontMesh->add(0, GL_FLOAT, 2, (void *)vPos, 6);
	_fontMesh->add(1, GL_FLOAT, 2, (void *)vTex, 6);
	_fontMesh->end();
	load();
	resetGame();
}

void	Game::loop(void)
{
	init();
	double timeLast = glfwGetTime();
	double timeSecLast = glfwGetTime();
	double timeAccumulator = 0.0;
	const double tickPerSec = 1.0 / 60.0;
	int tick = 0;
	int frame = 0;
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
		&& !glfwWindowShouldClose(window))
	{
		/* ******************** */
		/* * UPDATE           * */
		/* ******************** */
		double now = glfwGetTime();
		timeAccumulator += (now - timeLast);
		timeLast = now;
		while (timeAccumulator >= tickPerSec)
		{
			timeAccumulator -= tickPerSec;
			update();
			tick++;
		}
		/* ******************** */
		/* * RENDU            * */
		/* ******************** */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		render();
		render2D();
	    glfwSwapBuffers(window);
	    glfwPollEvents();
		frame++;
		if (now - timeSecLast >= 1.0)
		{
			timeSecLast = now;
			// std::cout << "UPS: " << tick << ", FPS: " << frame << std::endl;
			_fps = frame;
			_ups = tick;
			tick = 0;
			frame = 0;
		}
	}
}

void	Game::move(void)
{
	static float fakeRotStep = 5.615f;// 11.25f;
	if (_fakeRot < 0.f)
	{
		_fakeRot -= fakeRotStep;
		if (_fakeRot < -90.f)
			_fakeRot = -90.f;
	}
	if (_fakeRot > 0.f)
	{
		_fakeRot += fakeRotStep;
		if (_fakeRot > 90.f)
			_fakeRot = 90.f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		_playerOffset[0] += .05f;
		if (_playerOffset[0] > 0.5f)
			_playerOffset[0] = 0.5f;
		if (((*(_rooms.begin()))->getRenderer() == _road[1] || (*(_rooms.begin()))->getRenderer() == _road[3]) && _fakeRot == 0.0)
			_fakeRot = fakeRotStep;
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		_playerOffset[0] -= .05f;
		if (_playerOffset[0] < -0.5f)
			_playerOffset[0] = -0.5f;
		if (((*(_rooms.begin()))->getRenderer() == _road[2] || (*(_rooms.begin()))->getRenderer() == _road[3]) && _fakeRot == 0.0)
			_fakeRot = -fakeRotStep;
	}
	else
	{
		if (_playerOffset[0] > 0.f)
		{
			_playerOffset[0] -= .05f;
			if (_playerOffset[0] < 0.f)
				_playerOffset[0] = 0.f;
		}
		else if (_playerOffset[0] < 0.f)
		{
			_playerOffset[0] += .05f;
			if (_playerOffset[0] > 0.f)
				_playerOffset[0] = 0.f;
		}
	}
}

void	Game::jump(void)
{
	if (_playerOffset[1] == 0.f)
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			_jump = 0.15f;
		}
	}
	if (_jump != 0.f)
	{
		_playerOffset[1] += _jump;
		_jump -= 0.01f;
	}
	if (_playerOffset[1] < 0.01f)
	{
		_playerOffset[1] = 0.f;
		_jump = 0.f;
	}
}

void	Game::update(void)
{
	if (_state == 1)
	{
		float speed = (0.1f + (_playerPos[2] / 5000.f));
		_playerPos[2] += speed;
		move();
		jump();
	}
	else if (_state == 2 && debugMode)
	{
		float speed = (0.1f + (_playerPos[2] / 5000.f));
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
			_playerPos[2] += 0.05f;
		move();
		jump();
	}
	std::vector<Room *>::iterator it = _rooms.begin();
	while (it != _rooms.end())
	{
		if ((*it)->getPos()[2] + 1.0 < _playerPos[2])
		{
			if (_fakeRot == 0.0 && (*it)->getRenderer() != _road[0])
			{
				_state = 3;
				break ;
			}
			delete *it;
			_rooms.erase(it);
			it = _rooms.begin();
			_fakeRot = 0;
		}
		else
			break;
	}
	while (_rooms.size() < 30)
		addRoom();
}

void	Game::initRender3D(Shaders *shader)
{
	glUseProgram(0);
	glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	shader->bind();
}

void	Game::initRender2D(Shaders *shader)
{
	glUseProgram(0);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glCullFace(GL_FRONT_AND_BACK);
	shader->bind();
}

void	Game::bindAllTexture(Shaders *shader)
{
    glEnable(GL_TEXTURE_2D);
	for (int i = 2; i >= 0; i--)
	{
		std::stringstream ss;
		ss << "uTexture[" << i << "]";
		std::string s = ss.str();
		shader->uniform1i((GLchar *)s.c_str(), i);
		glActiveTexture(GL_TEXTURE0 + i);
		_textures[i]->bind();
	}
}

void	Game::render(void)
{
	initRender3D(_shaders);
	bindAllTexture(_shaders);
	_debugRoomRender = 0;
	glm::mat4 view = glm::translate(-_playerPos - glm::vec3(0.00, 0.75, -1.5));//glm::lookAt(_playerPos - glm::vec3(0.0, 0.0, 1.5), _playerPos + glm::vec3(0.0, -0.5, 0.5), glm::vec3(0, 1, 0));
	// glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(11.25f), glm::vec3(1.0f, 0.0f, 0.0f));
	// rot = glm::rotate(rot, glm::radians(180.0f + _fakeRot), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rot = glm::eulerAngleXY(glm::radians(11.25f), glm::radians(180.0f - _fakeRot));
	view = rot * view;
	std::vector<Room *>::iterator it = _rooms.begin();
	while (it != _rooms.end())
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), (*it)->getPos());
		// std::cout << glm::to_string((*it)->getPos()) << std::endl;
		glm::mat4 mvp = projection * view * model;
		_shaders->uniformMat4((GLchar *)"MVP", (GLfloat *)&mvp[0][0]);
		(*it)->render();
		_debugRoomRender++;
		if ((*it)->getRenderer() != _road[0])
			break ;
		++it;
	}
	std::vector<Room *>::iterator itNext = it + 1;
	float	i = 1.0;
	while (itNext != _rooms.end() && it != _rooms.end())
	{
		glm::mat4 model; //= glm::translate(glm::mat4(1.0f), (*it)->getPos());
		if ((*it)->getRenderer() == _road[1] || (*it)->getRenderer() == _road[3])
		{
			model = glm::translate(glm::mat4(1.0f), (*it)->getPos() + glm::vec3(i * 1.0f + 0.5f, 0.0, 0.5f));
			model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			glm::mat4 mvp = projection * view * model;
			_shaders->uniformMat4((GLchar *)"MVP", (GLfloat *)&mvp[0][0]);
			(*itNext)->render();
			_debugRoomRender++;
		}
		if ((*it)->getRenderer() == _road[2] || (*it)->getRenderer() == _road[3])
		{
			model = glm::translate(glm::mat4(1.0f), (*it)->getPos() + glm::vec3(i * -1.0f - 0.5f, 0.0, 0.5f));
			model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
			glm::mat4 mvp = projection * view * model;
			_shaders->uniformMat4((GLchar *)"MVP", (GLfloat *)&mvp[0][0]);
			(*itNext)->render();
			_debugRoomRender++;
		}
		if ((*itNext)->getRenderer() != _road[0])
			break ;
		++itNext;
		i += 1.0f;
	}
}

void	Game::render2D(void)
{
	initRender2D(_font);
	if (_state == 0)
	{
		renderText2D("42 Run", 490, 50);
		renderText2D("Press Space to Play!", 140, 600);
	}
	else if (_state == 1 || _state == 2)
	{
		renderText2D(std::to_string((int)_playerPos[2]).c_str(), 10, 10);
	}
	else if (_state == 3)
	{
		renderText2D(std::to_string((int)_playerPos[2]).c_str(), 10, 10);
		renderText2D("PAF", 565, 335);
		renderText2D("Press Space to Retry!", 115, 600);
	}
	if (debugMode)
	{
		renderDebug2D();
	}
}

void	Game::renderDebug2D(void)
{
	std::string fps = "FPS:" + std::to_string(_fps) + " UPS:" + std::to_string(_ups);
	renderText2D(fps.c_str(), 10, 60, 0.4f, 0.4f);
	std::string posX = "X:" + std::to_string(_playerPos[0]);
	renderText2D(posX.c_str(), 10, 80, 0.4f, 0.4f);
	std::string posY = "Y:" + std::to_string(_playerPos[1]);
	renderText2D(posY.c_str(), 10, 100, 0.4f, 0.4f);
	std::string posZ = "Z:" + std::to_string(_playerPos[2]);
	renderText2D(posZ.c_str(), 10, 120, 0.4f, 0.4f);

	std::string offPosX = "OffX:" + std::to_string(_playerOffset[0]);
	renderText2D(offPosX.c_str(), 330, 80, 0.4f, 0.4f);
	std::string offPosY = "OffY:" + std::to_string(_playerOffset[1]);
	renderText2D(offPosY.c_str(), 330, 100, 0.4f, 0.4f);
	std::string offPosZ = "OffZ:" + std::to_string(_playerOffset[2]);
	renderText2D(offPosZ.c_str(), 330, 120, 0.4f, 0.4f);

	float speed = (0.1f + (_playerPos[2] / 5000.f));
	std::string speedDebug = "Speed:" + std::to_string(speed);
	renderText2D(speedDebug.c_str(), 10, 140, 0.4f, 0.4f);
	std::string rotDebug = "Rot:" + std::to_string(_fakeRot);
	renderText2D(rotDebug.c_str(), 330, 140, 0.4f, 0.4f);
	std::string meshSize = "Rooms:" + std::to_string(_rooms.size()) + " (" + std::to_string(_debugRoomRender) + ")";
	renderText2D(meshSize.c_str(), 10, 160, 0.4f, 0.4f);
}

void	Game::renderText2D(const char *str, float x, float y, float scaleX, float scaleY)
{
	static glm::mat4 identity = glm::mat4(1.0f);
	int i = -1;

	_font->uniform1i((GLchar *)"uTexture", 0);
	_font->uniform2fv((GLchar *)"offset", 0, 0);
	_font->uniform2fv((GLchar *)"posScreen", x, y);
	glActiveTexture(GL_TEXTURE0);
	_texFont->bind();
	// _textures[0]->bind();
	while (str[++i])
	{
		int k = (int)str[i] - 32;
		float offx = (float)(k % 18) * 0.0555555556f;
		float offy = (float)(k / 18) * 0.1428571429f;
		// std::cout << str[i] << " / " << k << ": " << offx << ", " << offy << std::endl;
		_font->uniform2fv((GLchar *)"offset", offx, offy);
		_font->uniform2fv((GLchar *)"posScreen", x + (float)i * (50.0f * scaleX), y);
		_font->uniform2fv((GLchar *)"scale", scaleX, scaleY);
		_fontMesh->render(GL_TRIANGLES);
	}
}

void	Game::nextState(void)
{
	if (_state == 0)
		_state = 1;
	else if (_state == 1)
		_state = 2;
	else if (_state == 2)
		_state = 1;
	else if (_state == 3)
	{
		_state = 0;
		resetGame();
	}
}

void	Game::resetGame(void)
{
	_playerPos = glm::vec3(0.0, 0.0, 0.0);
	_playerOffset = glm::vec3(0.0, 0.0, 0.0);
	_jump = 0;
	_fakeRot = 0;
	while (!_rooms.empty())
	{
		delete _rooms.back();
		_rooms.pop_back();
	}
}

void	Game::addRoom(void)
{
	static int	cdRoomType = 0;
	if (_rooms.empty())
	{
		_rooms.push_back(new Room(_road[0]));
	}
	else
	{
		int type = 0;
		if (_rooms.size() >= 10 && cdRoomType == 0)
		{
			if (std::rand() % 10 == 5)
				type = std::rand() % MAX_ROAD;
		}
		_rooms.push_back(new Room(_road[type], _rooms.back()->getPos() + glm::vec3(0, 0, 1)));
		if (cdRoomType > 0)
			cdRoomType--;
		if (type > 0)
			cdRoomType = 5;
	}

}
