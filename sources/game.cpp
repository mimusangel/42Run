#include "game.hpp"
#include "window.hpp"




Room::Room(int px, int py) :
	x(px), y(py), mesh(nullptr), front(nullptr), left(nullptr), right(nullptr)
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
	if (front != nullptr)
		front->render(shaders);
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

Room	*Room::setFront(Room *child)
{
	front = child;
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






/* ******************** */
/* *                  * */
/* ******************** */

Game::Game() :
	_rot(-90, 0, 0)
{}

Game::~Game()
{

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

void	Game::init(void)
{
	_mesh = loadRoad();
	_room = (new Room(0, 0))->setMesh(_mesh)->setFront(
		(new Room(0, 1))->setMesh(_mesh)->setLeft(
			(new Room(1, 1))->setMesh(_mesh)
		)->setRight(
			(new Room(-1, 1))->setMesh(_mesh)
		)
	);
}

void	Game::update(void *win)
{
	Window	*window = (Window *)win;
	if (glfwGetKey(window->getGLFW(), GLFW_KEY_W) == GLFW_PRESS)
	{

	}
	if (glfwGetKey(window->getGLFW(), GLFW_KEY_W) == GLFW_PRESS)
	{

	}
	if (glfwGetKey(window->getGLFW(), GLFW_KEY_A) == GLFW_PRESS)
	{

	}
	if (glfwGetKey(window->getGLFW(), GLFW_KEY_D) == GLFW_PRESS)
	{

	}
}

void	Game::render(Shaders *shaders)
{
	Quat rotQuat = Quat::Angle(_rot);
	Mat4 view = Mat4::Translate(0, -3, 0) * rotQuat.toMat4();
	shaders->uniformMat4((GLchar *)"view", (GLfloat *)&view);

	_room->render(shaders);
	// Mat4 model = Mat4::Identity();
	// shaders->uniformMat4((GLchar *)"model", (GLfloat *)&model);
	// _mesh->render(GL_TRIANGLES);
}
