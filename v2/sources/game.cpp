#include "game.hpp"

Game::Game()
{
	_mesh = nullptr;
	_shaders = nullptr;
	projection = glm::perspective(glm::radians(45.0f), 1280.f / 720.f, 0.0001f, 1000.0f);
}

Game::~Game()
{
	if (_mesh != nullptr)
		delete _mesh;
	if (_shaders != nullptr)
		delete _shaders;
	for (int i = 1; i >= 0; i--)
	{
		delete _textures[i];
	}
}

void	Game::init(void)
{
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSwapInterval(0);

	_shaders = new Shaders();
	if (!_shaders->loadFragmentShader("shaders/basic.frag"))
		throw std::logic_error("Erreur chargement basic.frag");
	if (!_shaders->loadVertexShader("shaders/basic.vert"))
		throw std::logic_error("Erreur chargement basic.vert");
	if (!_shaders->build())
		throw std::logic_error("Erreur compilation shader(basic)");
	_textures[0] = Texture::LoadBMP("textures/uvtemplate.bmp");
	_textures[1] = Texture::LoadBMP("textures/ground.bmp");
	_textures[2] = Texture::LoadBMP("textures/poto.bmp");
	_mesh = new Mesh(4);
	_mesh->begin();
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, 0.0f, -0.5f,	0.0f, 0.0f, -0.5f,	-1.0f, 0.0f, 0.5f,
		0.0f, 0.0f, 0.5f, 	-1.0f, 0.0f, 0.5f,	0.0f, 0.0f, -0.5f,
		0.0f, 0.0f, -0.5f,	1.0f, 0.0f, -0.5f,	1.0f, 0.0f, 0.5f,
		1.0f, 0.0f, 0.5f, 	0.0f, 0.0f, 0.5f,	0.0f, 0.0f, -0.5f,

		-1.0f, 0.0f, 0.5f,	-1.0f, 1.0f, 0.5f,	-1.0f, 0.0f, -0.5f,
		-1.0f, 0.0f, -0.5f,	-1.0f, 1.0f, 0.5f,	-1.0f, 1.0f, -0.5f,
		-1.0f, 1.0f, 0.5f,	-1.0f, 1.8f, 0.5f,	-1.0f, 1.0f, -0.5f,
		-1.0f, 1.0f, -0.5f,	-1.0f, 1.8f, 0.5f,	-1.0f, 1.8f, -0.5f,

		1.0f, 0.0f, 0.5f,	1.0f, 0.0f, -0.5f,	1.0f, 1.0f, 0.5f,
		1.0f, 0.0f, -0.5f,	1.0f, 1.0f, -0.5f,	1.0f, 1.0f, 0.5f,
		1.0f, 1.0f, 0.5f,	1.0f, 1.0f, -0.5f,	1.0f, 1.8f, 0.5f,
		1.0f, 1.0f, -0.5f,	1.0f, 1.8f, -0.5f,	1.0f, 1.8f, 0.5f,

		-1.0f, 1.8f, -0.5f,	-1.0f, 1.8f, 0.5f,	0.0f, 1.8f, -0.5f,
		0.0f, 1.8f, 0.5f, 	0.0f, 1.8f, -0.5f,	-1.0f, 1.8f, 0.5f,
		0.0f, 1.8f, -0.5f,	1.0f, 1.8f, 0.5f,	1.0f, 1.8f, -0.5f,
		1.0f, 1.8f, 0.5f, 	0.0f, 1.8f, -0.5f,	0.0f, 1.8f, 0.5f,
	};
	static const GLfloat g_color_buffer_data[] = {
		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,
		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,
		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,
		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,

		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,
		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,
		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,
		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,

		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,
		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,
		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,
		0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,	0.8f, 0.8f, 0.8f,

		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,
		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,
		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,
		0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,	0.9f, 0.9f, 0.9f,
	};
	static const GLfloat g_tex_buffer_data[] = {
		1.0, 0.0,	0.0, 0.0,	1.0, 1.0,
		0.0, 1.0,	1.0, 1.0,	0.0, 0.0,
		1.0, 0.0,	0.0, 0.0,	0.0, 1.0,
		0.0, 1.0,	1.0, 1.0,	1.0, 0.0,

		0.0, 0.0,	0.0, 1.0,	1.0, 0.0,
		1.0, 0.0,	0.0, 1.0,	1.0, 1.0,
		0.0, 0.2,	0.0, 1.0,	1.0, 0.2,
		1.0, 0.2,	0.0, 1.0,	1.0, 1.0,

		1.0, 0.0,	0.0, 0.0,	1.0, 1.0,
		0.0, 0.0,	0.0, 1.0,	1.0, 1.0,
		1.0, 0.2,	0.0, 0.2,	1.0, 1.0,
		0.0, 0.2,	0.0, 1.0,	1.0, 1.0,

		1.0, 0.0,	1.0, 1.0,	0.0, 0.0,
		0.0, 1.0,	0.0, 0.0,	1.0, 1.0,
		0.0, 0.0,	1.0, 0.0,	1.0, 1.0,
		1.0, 1.0,	0.0, 1.0,	0.0, 0.0,
	};
	static const GLint g_texid_buffer_data[] = {
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,

		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,

		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,

		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
	};
	_mesh->add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 48);
	_mesh->add(1, GL_FLOAT, 3, (void *)g_color_buffer_data, 48);
	_mesh->add(2, GL_FLOAT, 2, (void *)g_tex_buffer_data, 48);
	_mesh->add(3, GL_INT, 1, (void *)g_texid_buffer_data, 48);
	_mesh->end();

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
			std::cout << "UPS: " << tick << ", FPS: " << frame << std::endl;
			tick = 0;
			frame = 0;
		}
	}
}

void	Game::update(void)
{

}

void	Game::initRender3D(Shaders *shader)
{
	glUseProgram(0);
	glEnable(GL_DEPTH_TEST);
	shader->bind();
}

void	Game::initRender2D(Shaders *shader)
{
	glUseProgram(0);
	glDisable(GL_DEPTH_TEST);
	shader->bind();
}

void	Game::bindAllTexture(Shaders *shader)
{
    glEnable(GL_TEXTURE_2D);
	for (int i = 2; i >= 0; i--)
	// for (int i = 0; i < 3; i++)
	{
		std::stringstream ss;
		ss << "uTexture[" << i << "]";
		std::string s = ss.str();
		// std::cout << s << std::endl;
		shader->uniform1i((GLchar *)s.c_str(), i);
		// std::cout << GL_TEXTURE0 << std::endl;
		glActiveTexture(GL_TEXTURE0 + i);
		// glEnable(GL_TEXTURE_2D);
		_textures[i]->bind();
	}
	// for (int i = 0; i < 3; i++)
	// {
		// std::stringstream ss;
		// ss << "uTexture[" << i << "]";
		// std::string s = ss.str();
		// std::cout << s << std::endl;
		// shader->uniform1i((GLchar *)s.c_str(), i);
		// glActiveTexture(GL_TEXTURE0 + i);
		// _textures[i]->bind();
	// }
	// const GLint samplers[3] = {0, 1, 2};
	// shader->uniform1ia((GLchar *)"uTexture", 3, samplers);
}

void	Game::render(void)
{
	initRender3D(_shaders);
	bindAllTexture(_shaders);
	glm::mat4 view = glm::lookAt(glm::vec3(0, 0.75, -1.5), glm::vec3(0.0, 0.25, 0.5), glm::vec3(0, 1, 0));
	for (size_t i = 0; i < 30; i++)
	{
		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, i));
		glm::mat4 mvp = projection * view * model;
		_shaders->uniformMat4((GLchar *)"MVP", (GLfloat *)&mvp[0][0]);
		_mesh->render(GL_TRIANGLES);
	}

}

void	Game::render2D(void)
{

}
