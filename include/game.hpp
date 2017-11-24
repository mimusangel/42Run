#ifndef GAME_HPP
#define GAME_HPP

# include "mesh.hpp"
# include "shaders.hpp"

class Room {
public:
	int x;
	int y;
	Mesh	*mesh;
	Room	*front;
	Room	*left;
	Room	*right;
	Room(int px, int py);
	void	render(Shaders *shaders);
	Room	*setMesh(Mesh *renderer);
	Room	*setFront(Room *child);
	Room	*setLeft(Room *child);
	Room	*setRight(Room *child);
};

class Game {
private:
	Mesh	*_mesh;
	Room	*_room;
	Vec3f	_rot;
public:
	Game();
	~Game();
	void	init(void);
	void	update(void *win);
	void	render(Shaders *shaders);

};

#endif
