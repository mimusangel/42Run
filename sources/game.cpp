#include "game.hpp"
#include "window.hpp"

Game::Game()
{}

Game::~Game()
{
	delete _mesh;
}

void	Game::init(void)
{
	_mesh = new Mesh(3);
	if (_mesh->isCreated())
	{
		_mesh->begin();
		static const GLfloat g_vertex_buffer_data[] = {
			-1.5f, 0.f, 0.f, -1.5f, 0.f, 2.f, 1.5f, 0.f, 2.f,
			1.5f, 0.f, 2.f, 1.5f, 0.f, 0.f, -1.5f, 0.f, 0.f,
			-1.5f, 0.f, 0.f, -1.5f, 3.f, 0.f, -1.5f, 3.f, 2.f,
			-1.5f, 3.f, 2.f, -1.5f, 0.f, 2.f, -1.5f, 0.f, 0.f,
			1.5f, 0.f, 2.f, 1.5f, 3.f, 2.f, 1.5f, 3.f, 0.f,
			1.5f, 3.f, 0.f, 1.5f, 0.f, 0.f, 1.5f, 0.f, 2.f,
			-1.5f, 2.1f, 0.f, 1.5f, 2.1f, 2.f, -1.5f, 2.1f, 2.f,
			1.5f, 2.1f, 2.f, -1.5f, 2.1f, 0.f, 1.5f, 2.1f, 0.f,
		};
		static const GLfloat g_color_buffer_data[] = {
			1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
			1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
			.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
			.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
			.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
			.9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f, .9f,
			1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
			1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f,
		};
		static const GLfloat g_uv_buffer_data[] = {
			0.f, 0.f, 0.f, 1.f, 1.f, 1.f,
			1.f, 1.f, 1.f, 0.f, 0.f, 0.f,
			0.f, 0.f, 0.f, 1.f, 1.f, 1.f,
			1.f, 1.f, 1.f, 0.f, 0.f, 0.f,
			1.f, 0.f, 1.f, 1.f, 0.f, 1.f,
			0.f, 1.f, 0.f, 0.f, 1.f, 0.f,
			0.f, 0.f, 1.f, 1.f, 0.f, 1.f,
			1.f, 1.f, 0.f, 0.f, 1.f, 0.f,
		};
		_mesh->add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 24);
		_mesh->add(1, GL_FLOAT, 3, (void *)g_color_buffer_data, 24);
		_mesh->add(2, GL_FLOAT, 2, (void *)g_uv_buffer_data, 24);
		_mesh->end();
		_room = new Room(_mesh);
		_room->setLeftRoom(new Room(_mesh));
	}
}

void	Game::update(void *win)
{
	Window	*window = (Window *)win;
	if (glfwGetKey(window->getGLFW(), GLFW_KEY_W) == GLFW_PRESS)
	{
		_pos += Vec3f(0.f, 0.f, -(1.f / 60.f) * .1f);
	}
}

void	Game::render(Shaders *shaders)
{
	if (_room != nullptr)
		_room->render(shaders, _pos);
	// static float pz = 0.f;
	// for (int i = 0; i < 10; i++)
	// {
	// 	Mat4 model = Mat4::Translate(0, 0, pz + (float)i * 2.f);
	// 	shaders->uniformMat4((GLchar *)"model", (GLfloat *)&model);
	// 	_rooms->render(GL_TRIANGLES);
	// }



}
