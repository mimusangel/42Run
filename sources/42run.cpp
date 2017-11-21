#include <iostream>
using namespace std;

#include "window.hpp"
#include "shaders.hpp"
#include "mesh.hpp"

int main()
{
	if (!glfwInit())
		cout << "Erreur init glfw!" << endl;
	else
	{
		Window win(1280, 720, "HumanGL");
		if (win.getError().length() > 0)
			std::cout << win.getError() << endl;
		else
		{
			Shaders sample;
			if (!sample.loadFragmentShader("sample.frag"))
				return (0);
			if (!sample.loadVertexShader("sample.vert"))
				return (0);
			if (!sample.build())
				return (0);
			Mesh mesh(2);
			if (mesh.isCreated())
			{
				mesh.begin();
				static const GLfloat g_vertex_buffer_data[] = {
				  -1.f, 0.f, 1.f, 0.f, 1.f, 1.f, 1.f, 0.f, 1.f,
				  -1.f, 0.f, 1.f, 1.f, 0.f, 1.f, 0.f, 0.f, 0.f,
				  -1.f, 0.0, 1.f, 0.f, 0.f, 0.f, -1.f, 0.f, -1.f,
				  1.f, 0.f, 1.f, 1.f, 0.f, -1.f, 0.f, 0.f, 0.f,
				  0.f, 0.f, 0.f, 1.f, 0.f, -1.f, -1.f, 0.f, -1.f,
				};
				static const GLfloat g_color_buffer_data[] = {
				  1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f,
				  .5f, 0.f, 0.f, .5f, 0.f, 0.f, .5f, 0.f, 0.f,
				  0.f, .5f, 0.f, 0.f, .5f, 0.f, 0.f, .5f, 0.f,
				  0.f, 0.f, .5f, 0.f, 0.f, .5f, 0.f, 0.f, .5f,
				  0.f, .5f, .5f, 0.f, .5f, .5f, 0.f, .5f, .5f,
				};
				mesh.add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 15);
				mesh.add(1, GL_FLOAT, 3, (void *)g_color_buffer_data, 15);
				mesh.end();
			}
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			Mat4 projection = Mat4::Perspective(70.f, 1280.f / 720.f, 0.1f, 1000.f);
			Mat4 model = Mat4::Translate(0, 0, 2);
			Transform cam(Vec3f(0, -1, 0));
			Vec3f rot;
			Vec3f up(0, 1, 0);
			Vec3f right(1, 0, 0);
			Mat4 view = cam.toMat4();
			while (win.isOpen())
			{
				/* ******************** */
				/* * UPDATE           * */
				/* ******************** */
				if (win.isGrabbed())
				{
					if (glfwGetKey(win.getGLFW(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
						win.setGrab(false);
					else
					{
						if (win.dirMouse[1] != 0.f || win.dirMouse[0] != 0.f)
						{
							rot[0] += -win.dirMouse[1] * 0.5f;
							rot[1] += -win.dirMouse[0] * 0.5f;
							if (rot[0] > 90.f)
								rot[0] = 90.f;
							if (rot[0] < -90.f)
								rot[0] = -90.f;
							win.dirMouse[1] = 0.f;
							win.dirMouse[0] = 0.f;
							cam.setRotate(rot);
						}
						Vec3f dir(0.f);
						if (glfwGetKey(win.getGLFW(), GLFW_KEY_W) == GLFW_PRESS)
						{
							dir[0] += sinf(TORADIANS(rot[1]));
							dir[2] += -cosf(TORADIANS(rot[1]));
						}
						if (glfwGetKey(win.getGLFW(), GLFW_KEY_S) == GLFW_PRESS)
						{
							dir[0] += -sinf(TORADIANS(rot[1]));
							dir[2] += cosf(TORADIANS(rot[1]));
						}
						if (glfwGetKey(win.getGLFW(), GLFW_KEY_D) == GLFW_PRESS)
						{
							dir[0] += -cosf(TORADIANS(rot[1]));
							dir[2] += -sinf(TORADIANS(rot[1]));
						}
						if (glfwGetKey(win.getGLFW(), GLFW_KEY_A) == GLFW_PRESS)
						{
							dir[0] += cosf(TORADIANS(rot[1]));
							dir[2] += sinf(TORADIANS(rot[1]));
						}
						dir.normalize();
						cam.translate(dir, 0.1f);
						view = cam.toMat4();
					}

				}
				else
				{
					if (glfwGetMouseButton(win.getGLFW(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
						win.setGrab(true);
				}
				/* ******************** */
				/* * RENDU            * */
				/* ******************** */
				win.makeContextCurrent();
				glClearColor(0.5, 0.5, 0.5, 1);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				sample.bind();
				sample.uniformMat4((GLchar *)"projection", (GLfloat *)&projection);
				sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				sample.uniformMat4((GLchar *)"view", (GLfloat *)&view);
				mesh.render(GL_TRIANGLES);
				win.update();
			}
		}
	}
	return (0);
}
