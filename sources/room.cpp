#include "game.hpp"

Room::Room(Mesh *render, int type, const Vec3f pos) : _pos(pos), _render(render), _type(type)
{
	_item = -1;
	// _pos.debug();
}

Mesh 	*Room::getRender(void)
{
	return (_render);
}

Vec3f	&Room::getPos(void)
{
	return (_pos);
}

int		Room::getItem(void)
{
	return (_item);
}

void	Room::setItem(int item)
{
	_item = item;
}

Vec3f	&Room::getItemPos(void)
{
	return (_itemPos);
}

void	Room::setItemPos(const Vec3f &pos)
{
	_itemPos = pos;
}

bool	Room::itemCollid(Vec3f &pos, Vec3f &size)
{
	if (_item == 0)
	{
		Vec3f	pMin = pos - size;
		pMin[1] -= size[1];
		Vec3f	pMax = pos + size;
		Vec3f	iMin = _pos + (_itemPos - Vec3f(.15f, .0f, .15f));
		Vec3f	iMax = _pos + (_itemPos + Vec3f(.85f, .7f, .15f));
		if ((pMin[0] >= iMax[0])
			|| (pMax[0] <= iMin[0])
			|| (pMin[1] >= iMax[1])
			|| (pMax[1] <= iMin[1])
			|| (pMin[2] >= iMax[2])
			|| (pMax[2] <= iMin[2]))
			return (false);
	   	else
			return (true);
	}
	return (false);
}

int		Room::getType(void)
{
	return (_type);
}
