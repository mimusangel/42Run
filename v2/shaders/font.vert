#version 330 core
layout(location = 0) in vec2 vertexPosition;
layout(location = 1) in vec2 vertexUV;

// uniform mat4 MVP;
uniform vec2 posScreen;
uniform vec2 scale;

out vec2 vTex;

void main()
{
	vec2 inScreen = (vertexPosition * scale + posScreen - vec2(640, 360)) / vec2(640, -360);
	gl_Position = vec4(inScreen, 0, 1);
	vTex = vertexUV;
}
