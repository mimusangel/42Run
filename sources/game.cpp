#include "game.hpp"

Game::Game()
{}

Game::~Game()
{
	delete _rooms;
}

void	Game::init(void)
{
	_rooms = new Mesh(3);
	if (_rooms->isCreated())
	{
		_rooms->begin();
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
		_rooms->add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 24);
		_rooms->add(1, GL_FLOAT, 3, (void *)g_color_buffer_data, 24);
		_rooms->add(2, GL_FLOAT, 2, (void *)g_uv_buffer_data, 24);
		_rooms->end();
	}
}

void	Game::update(void)
{

}

void	Game::render(Shaders *shaders)
{
	static float pz = 0.f;
	for (int i = 0; i < 10; i++)
	{
		Mat4 model = Mat4::Translate(0, 0, pz + (float)i * 2.f);
		shaders->uniformMat4((GLchar *)"model", (GLfloat *)&model);
		_rooms->render(GL_TRIANGLES);
	}

	pz -= (1.f / 60.f) * 0.25f;
	if (pz <= -2.f)
		pz += 2.f;
}
