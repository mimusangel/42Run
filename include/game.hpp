#ifndef GAME_HPP
# define GAME_HPP

# include <vector>
# include <iostream>
# include <stdexcept>
# include "window.hpp"
# include "shaders.hpp"
# include "mesh.hpp"
# include "texture.hpp"

class Room {
private:
	Vec3f	_pos;
	Mesh	*_render;
	int		_item;
	Vec3f	_itemPos;
	int		_type;
public:
	Room(Mesh *render, int type = 0, const Vec3f pos = Vec3f());
	Mesh 	*getRender(void);
	Vec3f	&getPos(void);
	int		getItem(void);
	void	setItem(int item);
	Vec3f	&getItemPos(void);
	void	setItemPos(const Vec3f &pos);
	bool	itemCollid(Vec3f &pos, Vec3f &size);
	int		getType(void);
};

class Game {
private:
	Window				*_win;
	Shaders				_sample;
	Mesh				*_road[4];
	Mesh				*_cluster[2];
	Mesh				*_items[2];
	Texture				*_textures[2];
	std::vector<Room *>	_rooms;
	Mesh				*_player;
	Shaders				_playerShader;
	Vec3f				_playerPos;
	Vec3f				_playerOffset;
	Texture				*_font;
	Shaders				_fontShader;
	Mesh				*_meshFont;
	float				_velocity;
	int					_state;
	float				_fakeRot;
	void				init3D(Shaders &shaders, Mat4 &view, bool texEnable = true);
	void				init2D(Shaders &shaders);
	void				renderStart(void);
	void				renderGame(void);
	void				renderLost(void);
	void				updateStart(void);
	void				updateGame(void);
	void				updateLost(void);
	void				renderText2D(const char *str, const Vec2f &vec);
	void				reset(void);
public:
	Game(Window *win);
	~Game();
	void	render(void);
	void	update(void);
	void	addRoom(void);
	void	nextState(void);
};

#endif
