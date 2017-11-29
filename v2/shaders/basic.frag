#version 330 core

out vec4 color;

uniform sampler2D uTexture[3];

in vec3 vColor;
in vec2 vTex;
flat in int vTexID;

void main(){
	vec4 texColor = texture(uTexture[vTexID], vTex);
	color = vec4(vColor, 1.0) * texColor;
}
