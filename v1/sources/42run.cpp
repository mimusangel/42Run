#include <iostream>
using namespace std;

#include "window.hpp"
#include "game.hpp"

int main()
{
	if (!glfwInit())
		cout << "Erreur init glfw!" << endl;
	else
	{
		Window win(1280, 720, "42Run");
		if (win.getError().length() > 0)
			std::cout << win.getError() << endl;
		else
		{
			// Mesh mesh(2);
			// if (mesh.isCreated())
			// {
			// 	mesh.begin();
			// 	static const GLfloat g_vertex_buffer_data[] = {
			// 	  -1.f, 0.f, 1.f, 0.f, 1.f, 1.f, 1.f, 0.f, 1.f,
			// 	  -1.f, 0.f, 1.f, 1.f, 0.f, 1.f, 0.f, 0.f, 0.f,
			// 	  -1.f, 0.0, 1.f, 0.f, 0.f, 0.f, -1.f, 0.f, -1.f,
			// 	  1.f, 0.f, 1.f, 1.f, 0.f, -1.f, 0.f, 0.f, 0.f,
			// 	  0.f, 0.f, 0.f, 1.f, 0.f, -1.f, -1.f, 0.f, -1.f,
			// 	};
			// 	static const GLfloat g_color_buffer_data[] = {
			// 	  1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f,
			// 	  .5f, 0.f, 0.f, .5f, 0.f, 0.f, .5f, 0.f, 0.f,
			// 	  0.f, .5f, 0.f, 0.f, .5f, 0.f, 0.f, .5f, 0.f,
			// 	  0.f, 0.f, .5f, 0.f, 0.f, .5f, 0.f, 0.f, .5f,
			// 	  0.f, .5f, .5f, 0.f, .5f, .5f, 0.f, .5f, .5f,
			// 	};
			// 	mesh.add(0, GL_FLOAT, 3, (void *)g_vertex_buffer_data, 15);
			// 	mesh.add(1, GL_FLOAT, 3, (void *)g_color_buffer_data, 15);
			// 	mesh.end();
			// }
			Game game(&win);
			win.setGamePointer((void *)&game);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			win.projection = Mat4::Perspective(70.f, 1280.f / 720.f, 0.001f, 1000.f);
			win.ortho = Mat4::Orthographic(0.f, 1280.f, 720.f, 0.f, 0.f, 1.f);
			// Mat4 model = Mat4::Translate(0, 0, 2);
			double timeLast = glfwGetTime();
			double timeSecLast = glfwGetTime();
			double timeAccumulator = 0.0;
			const double tickPerSec = 1.0 / 60.0;
			int tick = 0;
			int frame = 0;
			while (win.isOpen())
			{
				/* ******************** */
				/* * UPDATE           * */
				/* ******************** */
				double now = glfwGetTime();
				timeAccumulator += (now - timeLast);
				timeLast = now;
				while (timeAccumulator >= tickPerSec)
				{
					timeAccumulator -= tickPerSec;
					game.update();
					tick++;
				}
				/* ******************** */
				/* * RENDU            * */
				/* ******************** */
				win.makeContextCurrent();
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				game.render();
				// sample.bind();
				// sample.uniformMat4((GLchar *)"projection", (GLfloat *)&(win.projection));
				// sample.uniformMat4((GLchar *)"model", (GLfloat *)&model);
				// Quat rotQuat = Quat::AxisAngle(Vec3f(1, 0, 0), TORADIANS(-90.f));
				// Mat4 view = Mat4::Translate(0, -3, 0) * rotQuat.toMat4();
				// sample.uniformMat4((GLchar *)"view", (GLfloat *)&view);
				// mesh.render(GL_TRIANGLES);
				// glActiveTexture(GL_TEXTURE0);
				// sample.uniform1i((GLchar *)"uTexture", 0);
				// texture.bind();
				// player.bind();
				// player.uniformMat4((GLchar *)"projection", (GLfloat *)&(win.projection));

				win.update();
				frame++;
				if (now - timeSecLast >= 1.0)
				{
					timeSecLast = now;
					cout << "UPS: " << tick << ", FPS: " << frame << endl;
					tick = 0;
					frame = 0;
				}
			}
		}
	}
	return (0);
}
