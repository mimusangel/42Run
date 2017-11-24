#ifndef GAME_HPP
#define GAME_HPP

# include "mesh.hpp"
# include "shaders.hpp"

class Room {
public:
	int x;
	int y;
	Mesh	*mesh;
	Room	*up;
	Room	*down;
	Room	*left;
	Room	*right;
	Room(int px, int py);
	~Room();
	void	render(Shaders *shaders);
	Room	*setMesh(Mesh *renderer);
	Room	*setUp(Room *child);
	Room	*setDown(Room *child);
	Room	*setLeft(Room *child);
	Room	*setRight(Room *child);
	Room	*getForward(int dir);
	Room	*getLeft(int dir);
	Room	*getRight(int dir);
};

class Game {
private:
	Mesh	*_mesh;
	Mesh	*_player;
	Room	*_room;
	Vec3f	_rot;
	Vec3f	_pos;
	int		dir;
public:
	Vec3f	player;
	Game();
	~Game();
	void	init(void);
	void	generate(void);
	void	update(void *win);
	void	render(Shaders *shaders);
	void	renderPlayer(Shaders *shaders);
	Vec3f	&getPos(void);
	Vec3f	&getRot(void);
	void	forward(void);
	void	rotLeft(void);
	void	rotRight(void);

};

#endif
