#include "game.hpp"
Room::Room(Mesh *renderer, glm::vec3 pos) :
	_renderer(renderer), _pos(pos)
{

}

void	Room::render(void)
{
	if (_renderer != nullptr)
	{
		_renderer->render(GL_TRIANGLES);
	}
}
