#include "window.hpp"
#include "game.hpp"

/*
** Static function Callback
*/
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_F)
		{
			GLint polygonMode;
			glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
			if (polygonMode == GL_LINE)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glEnable(GL_CULL_FACE);
				glCullFace(GL_FRONT);
			}
			else if (polygonMode == GL_FILL)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				glDisable(GL_CULL_FACE);
			}
		}
		if (key == GLFW_KEY_SPACE)
		{
			Game *g = (Game *)win->getGamePointer();
			if (g != nullptr)
				g->nextState();
		}
		// win->getGame().getRot().debug();
	}
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
	win->dirMouse[0] = xpos - win->mouse[0];
	win->dirMouse[1] = ypos - win->mouse[1];
	win->mouse[0] = xpos;
	win->mouse[1] = ypos;
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	if (!win)
		return ;
}

static void win_resize_callback(GLFWwindow *window, int width, int height)
{
	Window	*win;

	win = (Window *)glfwGetWindowUserPointer(window);
	glViewport(0, 0, width, height);
	win->projection = Mat4::Perspective(70.0f, (float)width / (float)height, 0.001f, 1000.0f);
}

/*
** Class Window
*/

Window::Window(int width, int height, std::string title) : _grab(false)//, mouse(0), dirMouse(0)
{
	_gamePointer = nullptr;
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if ((_win = glfwCreateWindow(width, height, title.c_str(), NULL, NULL)))
	{
		glfwMakeContextCurrent(_win);
		glfwSetWindowUserPointer(_win, this);
		glfwSetKeyCallback(_win, key_callback);
		glfwSetCursorPosCallback(_win, cursor_position_callback);
		glfwSetMouseButtonCallback(_win, mouse_button_callback);
		glfwSetFramebufferSizeCallback(_win, win_resize_callback);
		glfwSwapInterval(0);
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			_error = "Erreur init glew!";
	}
	else
		_error = "La fenetre n'a pas pu etre creer.";

}

Window::~Window()
{
	if (_win)
		glfwDestroyWindow(_win);
	glfwTerminate();
}

std::string			&Window::getError(void)
{
	return (_error);
}

void				Window::makeContextCurrent(void)
{
	glfwMakeContextCurrent(_win);
}

void				Window::update(void)
{
	glfwSwapBuffers(_win);
	glfwPollEvents();
}

void				Window::setTitle(std::string title)
{
	glfwSetWindowTitle(_win, title.c_str());
}

bool				Window::isGrabbed(void)
{
	return (_grab);
}

void				Window::setGrab(bool grab)
{
	_grab = grab;
	if (_grab)
	{
		glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		dirMouse[0] = 0.f;
		dirMouse[1] = 0.f;
	}
	else
		glfwSetInputMode(_win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

bool				Window::isOpen(void)
{
	return (!glfwWindowShouldClose(_win));
}

GLFWwindow			*Window::getGLFW(void)
{
	return (_win);
}

void				*Window::getGamePointer(void)
{
	return (_gamePointer);
}

void				Window::setGamePointer(void *pointer)
{
	_gamePointer = pointer;
}
