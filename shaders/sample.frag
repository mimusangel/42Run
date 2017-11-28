#version 330 core

out vec4 color;

uniform sampler2D uTexture;

in vec3 vColor;
in vec2 vTex;

void main(){
	vec4 texColor = texture(uTexture, vTex);
	color = vec4(vColor, 1.0) * texColor;
}
