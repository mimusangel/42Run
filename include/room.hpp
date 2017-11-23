#ifndef ROOM_HPP
# define ROOM_HPP

# include "global.hpp"
# include "mesh.hpp"
# include "shaders.hpp"

class Room {
private:
	Mesh	*_render;
	Room	*_frontRoom;
	Room	*_leftRoom;
	Room	*_rightRoom;
	int		_next;
public:
	Room(Mesh *render, Room *frontRoom = nullptr, Room *leftRoom = nullptr, Room *rightRoom = nullptr);
	~Room();
	void	render(Shaders *shaders, const Vec3f &pos, const Vec3f &rot = Vec3f());
	Room	&setNext(int i);
	Room	*getNext();
	Room	&setFrontRoom(Room *room);
	Room	&setLeftRoom(Room *room);
	Room	&setRightRoom(Room *room);
};

#endif
