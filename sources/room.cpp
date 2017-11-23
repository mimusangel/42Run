#include "room.hpp"

Room::Room(Mesh *render, Room *frontRoom, Room *leftRoom, Room *rightRoom)
{
	_render = render;
	_frontRoom = frontRoom;
	_leftRoom = leftRoom;
	_rightRoom = rightRoom;
	_next = 1;
}

Room::~Room()
{
	if (_frontRoom != nullptr && _next != 0)
		delete _frontRoom;
	if (_leftRoom != nullptr && _next != 1)
		delete _leftRoom;
	if (_rightRoom != nullptr && _next != 2)
		delete _rightRoom;
}

void	Room::render(Shaders *shaders, const Vec3f &pos, const Vec3f &rot)
{
	Mat4 posMat = Mat4::Translate(pos);
	Mat4 rotMat = Quat::Angle(rot).toMat4();
	Mat4 model = rotMat *  posMat;
	shaders->uniformMat4((GLchar *)"model", (GLfloat *)&model);
	_render->render(GL_TRIANGLES);
	if (_frontRoom != nullptr)
		_frontRoom->render(shaders, Vec3f(pos[0], pos[1], pos[2] + 2), rot);
	if (_leftRoom != nullptr)
		_leftRoom->render(shaders, Vec3f(pos[0] - 1.5, pos[1], pos[2]), Vec3f(rot[0], rot[1] - 90, rot[2]));
	if (_rightRoom != nullptr)
		_rightRoom->render(shaders, Vec3f(pos[0] + 1.5, pos[1], pos[2]), Vec3f(rot[0], rot[1] + 90, rot[2]));
}

Room	&Room::setNext(int i)
{
	_next = i;
	return (*this);
}

Room	*Room::getNext()
{
	if (_next == 1)
		return (_leftRoom);
	else if (_next == 2)
		return (_rightRoom);
	else
		return (_frontRoom);
}

Room	&Room::setFrontRoom(Room *room)
{
	_frontRoom = room;
	return (*this);
}

Room	&Room::setLeftRoom(Room *room)
{
	_leftRoom = room;
	return (*this);
}

Room	&Room::setRightRoom(Room *room)
{
	_rightRoom = room;
	return (*this);
}
