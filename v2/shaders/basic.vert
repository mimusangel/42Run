#version 330 core
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec2 vertexTex;
layout(location = 3) in int vertexTexID;

uniform mat4 MVP;

out vec3 vColor;
out vec2 vTex;
flat out int vTexID;

void main()
{
	gl_Position = MVP * vec4(vertexPosition, 1);
	vColor = vertexColor;
	vTex = vertexTex;
	vTexID = vertexTexID;
}
