#pragma once

# include "global.hpp"
# include "mesh.hpp"
# include "shaders.hpp"
# include "texture.hpp"

# define MAX_ROAD 4

class Room {
private:
	glm::vec3	_pos;
	Mesh		*_renderer;

public:
	Room(Mesh *renderer, glm::vec3 pos = glm::vec3(0.0));
	void				render(void);
	inline glm::vec3	&getPos(void) { return (_pos); }
	inline Mesh			*getRenderer(void) { return (_renderer); }
};

class Game {
private:
	Mesh		*_road[MAX_ROAD];
	Shaders		*_shaders;
	Texture		*_textures[3];

	Mesh		*_fontMesh;
	Shaders		*_font;
	Texture		*_texFont;

	int			_state;
	std::vector<Room *>	_rooms;
	glm::vec3	_playerPos;
	glm::vec3	_playerOffset;
	float		_jump;
	Mesh		*_playerRenderer;

	int			_fps;
	int			_ups;
	int			_debugRoomRender;
	float		_fakeRot;


	void	load(void);
	void	init(void);
	void	addRoom(void);
	void	move(void);
	void	jump(void);

public:
	GLFWwindow	*window;
	glm::mat4	projection;
	bool		debugMode;
	bool		jumpKey;
	Game();
	~Game();
	void	loop(void);
	void	update(void);
	void	initRender3D(Shaders *shader);
	void	initRender2D(Shaders *shader);
	void	bindAllTexture(Shaders *shader);
	void	render(void);
	void	render2D(void);
	void	renderText2D(const char *str, float x, float y, float scaleX = 1.0f, float scaleY = 1.0f);
	void	nextState(void);
	void	resetGame(void);
	void	renderDebug2D(void);
};
