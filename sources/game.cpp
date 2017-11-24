#include <cstdlib>
#include <cmath>
#include "game.hpp"
#include "window.hpp"

Room::Room(int px, int py) :
	x(px), y(py), mesh(nullptr), up(nullptr), down(nullptr), left(nullptr), right(nullptr)
{}

Room::~Room()
{

}

void	Room::render(Shaders *shaders)
{
	if (mesh != nullptr)
	{
		Mat4 model = Mat4::Translate((float)x * 2.f, 0.f, (float)y * 2.f);
		shaders->uniformMat4((GLchar *)"model", (GLfloat *)&model);
		mesh->render(GL_TRIANGLES);
	}
	if (up != nullptr)
		up->render(shaders);
	if (down != nullptr)
		down->render(shaders);
	if (left != nullptr)
		left->render(shaders);
	if (right != nullptr)
		right->render(shaders);
}


Room	*Room::setMesh(Mesh *renderer)
{
	mesh = renderer;
	return (this);
}

Room	*Room::setUp(Room *child)
{
	up = child;
	return (this);
}

Room	*Room::setDown(Room *child)
{
	down = child;
	return (this);
}

Room	*Room::setLeft(Room *child)
{
	left = child;
	return (this);
}

Room	*Room::setRight(Room *child)
{
	right = child;
	return (this);
}

Room	*Room::getForward(int dir)
{
	if (dir == 8)
		return (up);
	if (dir == 4)
		return (left);
	if (dir == 2)
		return (down);
	return (right);
}

Room	*Room::getLeft(int dir)
{
	if (dir == 8)
		return (left);
	if (dir == 4)
		return (down);
	if (dir == 2)
		return (right);
	return (up);
}

Room	*Room::getRight(int dir)
{
	if (dir == 8)
		return (right);
	if (dir == 6)
		return (down);
	if (dir == 2)
		return (left);
	return (up);
}



/* ******************** */
/* *                  * */
/* ******************** */

Game::Game() :
	 _pos(0, -10, 0), _rot(-90, 0, 0)
{
	dir = 8;
}

Game::~Game()
{
	delete _mesh;
	delete _player;
}

static Mesh	*loadRoad()
{
	Mesh *mesh = new Mesh(3);
	mesh->begin();
	GLfloat vPos[] = {
		-1.f, 0.f, -1.f,	-1.f, 0.f, 1.f,		1.f, 0.f, 1.f,
		1.f, 0.f, 1.f,		1.f, 0.f, -1.f,		-1.f, 0.f, -1.f
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f
	};
	GLfloat vTex[] = {
		0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		1.f, 0.f, 1.f, 1.f, 0.f, 1.f
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 6);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 6);
	mesh->add(2, GL_FLOAT, 2, (void *)vTex, 6);
	mesh->end();
	return (mesh);
}

static Mesh	*loadPlayer()
{
	Mesh *mesh = new Mesh(2);
	mesh->begin();
	GLfloat vPos[] = {
		-0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f,

		-0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
		0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f,

		-0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f,
		0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f
	};
	GLfloat vColor[] = {
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f,
		.8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f, .8f
	};
	mesh->add(0, GL_FLOAT, 3, (void *)vPos, 36);
	mesh->add(1, GL_FLOAT, 3, (void *)vColor, 36);
	mesh->end();
	return (mesh);
}

void	Game::init(void)
{
	_player = loadPlayer();
	_mesh = loadRoad();
	_room = (new Room(0, 0))->setMesh(_mesh)->setUp(
		(new Room(0, 1))->setMesh(_mesh)
	);
	generate();
}

void	Game::generate(void)
{
	Room *tmp = _room->getForward(dir);
	while (std::rand() % 3 >= 1)
	{
		if (dir == 8)
			tmp->setUp((new Room(tmp->x, tmp->y + 1))->setMesh(_mesh));
		else if (dir == 4)
			tmp->setLeft((new Room(tmp->x - 1, tmp->y))->setMesh(_mesh));
		else if (dir == 6)
			tmp->setRight((new Room(tmp->x + 1, tmp->y))->setMesh(_mesh));
		else
			tmp->setDown((new Room(tmp->x, tmp->y - 1))->setMesh(_mesh));
		tmp = tmp->getForward(dir);
	}
	if (dir == 8 || dir == 2)
	{
		tmp->setLeft((new Room(tmp->x - 1, tmp->y))->setMesh(_mesh));
		tmp->setRight((new Room(tmp->x + 1, tmp->y))->setMesh(_mesh));
	}
	if (dir == 4 || dir == 6)
	{
		tmp->setUp((new Room(tmp->x, tmp->y + 1))->setMesh(_mesh));
		tmp->setDown((new Room(tmp->x, tmp->y - 1))->setMesh(_mesh));
	}

}

void	Game::update(void *win)
{
	forward();
}

void	Game::render(Shaders *shaders)
{
	Quat rotQuat = Quat::Angle(_rot);
	Mat4 view = Mat4::Translate(-_pos[0] * 2.f, _pos[1], -_pos[2] * 2.f) * rotQuat.toMat4();
	shaders->uniformMat4((GLchar *)"view", (GLfloat *)&view);

	_room->render(shaders);
	// Mat4 model = Mat4::Identity();
	// shaders->uniformMat4((GLchar *)"model", (GLfloat *)&model);
	// _mesh->render(GL_TRIANGLES);
}

void	Game::renderPlayer(Shaders *shaders)
{
	Quat rotQuat = Quat::Angle(_rot);
	Mat4 view = Mat4::Translate(-_pos[0] * 2.f, _pos[1], -_pos[2] * 2.f) * rotQuat.toMat4();
	shaders->uniformMat4((GLchar *)"view", (GLfloat *)&view);

	Mat4 model = Mat4::Translate(_pos[0] * 4.f, .5f, _pos[2] * 4.f) * Mat4::Scale(Vec3f(0.5f));
	shaders->uniformMat4((GLchar *)"model", (GLfloat *)&model);
	_player->render(GL_TRIANGLES);
}

Vec3f	&Game::getPos(void)
{
	return (_pos);
}

Vec3f	&Game::getRot(void)
{
	return (_rot);
}

void	Game::forward(void)
{
	Room *forward;
	if (_room != nullptr && (forward = _room->getForward(dir)) != nullptr)
	{
		Vec3f vecDir(-sin(TORADIANS(_rot[1])), 0.f, cos(TORADIANS(_rot[1])));
		_pos += vecDir * 0.05;
		// std::cout << ((float)forward->x - 0.5f) << ", " << ((float)forward->x + 0.5f) << std::endl;
		// std::cout << ((float)forward->y - 0.5f) << ", " << ((float)forward->y + 0.5f) << std::endl;
		// _pos.debug();
		// std::cout << (((float)forward->x - 0.5f) <= _pos[0] && ((float)forward->x + 0.5f) > _pos[0]) << " // " << (((float)forward->y - 0.5f) >= _pos[2] && ((float)forward->y + 0.5f )< _pos[2]) << std::endl;
		if ((float)forward->x - .5f <= _pos[0] && (float)forward->x + .5f > _pos[0]
			&& (float)forward->y - .5f <= _pos[2] && (float)forward->y + .5f > _pos[2])
		{
			delete _room;
			_room = forward;
		}
	}
}

void	Game::rotLeft(void)
{
	Room *left;
	if (_room != nullptr && (left = _room->getLeft(dir)) != nullptr)
	{
		_rot[1] += 90.0;
		if (dir == 8)
			dir = 4;
		else if (dir == 4)
			dir = 2;
		else if (dir == 2)
			dir = 6;
		else
			dir = 8;
		generate();
	}
}

void	Game::rotRight(void)
{
	Room *right;
	if (_room != nullptr && (right = _room->getRight(dir)) != nullptr)
	{
		_rot[1] -= 90.0;
		if (dir == 8)
			dir = 6;
		else if (dir == 6)
			dir = 2;
		else if (dir == 2)
			dir = 4;
		else
			dir = 8;
		generate();
	}
}
