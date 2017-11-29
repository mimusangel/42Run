#pragma once

# include "global.hpp"
# include "mesh.hpp"
# include "shaders.hpp"
# include "texture.hpp"

class Game {
private:
	Mesh	*_mesh;
	Shaders	*_shaders;
	Texture	*_textures[3];

	Mesh	*_fontMesh;
	Shaders	*_font;
	Texture	*_texFont;

	void	init(void);

public:
	GLFWwindow	*window;
	glm::mat4	projection;
	glm::mat4	orthographic;

	Game();
	~Game();
	void	loop(void);
	void	update(void);
	void	initRender3D(Shaders *shader);
	void	initRender2D(Shaders *shader);
	void	bindAllTexture(Shaders *shader);
	void	render(void);
	void	render2D(void);
	void	renderText2D(const char *str, float x, float y);
};
