#version 330 core

out vec4 color;

uniform sampler2D uTexture;
uniform vec2 id;

in vec2 vTex;
void main(){
	vec4 texColor = texture(uTexture, vTex + id);
	color = texColor * vec4(1.0);
}
