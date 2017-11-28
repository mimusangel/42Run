#version 330 core
layout(location = 0) in vec2 vertexPosition;
layout(location = 1) in vec2 vertexUV;

uniform mat4 projection;
uniform mat4 model;

out vec2 vTex;

void main()
{
	mat4 mvp = projection * model;
	gl_Position = mvp * vec4(vertexPosition, 0, 1);
	vTex = vertexUV;
}
