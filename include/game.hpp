#ifndef GAME_HPP
#define GAME_HPP

# include "mesh.hpp"
# include "shaders.hpp"

class Game {
private:
	Mesh	*_rooms;
public:
	Game();
	~Game();
	void	init(void);
	void	update(void);
	void	render(Shaders *shaders);

};

#endif
