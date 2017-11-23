#ifndef GAME_HPP
#define GAME_HPP

# include "mesh.hpp"
# include "shaders.hpp"
# include "room.hpp"

class Game {
private:
	Mesh	*_mesh;
	Vec3f	_pos;
	Room	*_room;
public:
	Game();
	~Game();
	void	init(void);
	void	update(void *win);
	void	render(Shaders *shaders);

};

#endif
