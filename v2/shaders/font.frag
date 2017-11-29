#version 330 core

out vec4 color;

uniform sampler2D uTexture;
uniform vec2 offset;

in vec2 vTex;
void main(){
	vec4 texColor = texture(uTexture, vTex + offset);
	color = vec4(1.0) * texColor;
}
