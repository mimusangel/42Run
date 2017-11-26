#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "global.hpp"

class Window {

private:
	GLFWwindow			*_win;
	std::string			_error;
	bool				_grab;
	void				*_gamePointer;

public:
	Vec2f				mouse;
	Vec2f				dirMouse;
	Mat4				projection;
	Window(int width, int height, std::string title);
	~Window();
	std::string			&getError(void);
	void				makeContextCurrent(void);
	void				update(void);
	void				setTitle(std::string title);
	bool				isGrabbed(void);
	void				setGrab(bool grab);
	bool				isOpen(void);
	GLFWwindow			*getGLFW(void);
	void				*getGamePointer(void);
	void				setGamePointer(void *pointer);

};

#endif
