#ifndef TEXTURE_HPP
#define TEXTURE_HPP

# include "global.hpp"

class Texture {
private:
	unsigned int	_width;
	unsigned int	_height;
	unsigned char	*_data;
	GLuint			_textureID;
public:
	Texture(unsigned int width, unsigned int height, unsigned char *data);
	~Texture();
	void	bind(void);

	static Texture	LoadBMP(char *path);
};

#endif
