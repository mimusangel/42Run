#version 330 core

out vec4 color;

uniform sampler2D uTexture;
uniform vec2 offset;

in vec2 vTex;
void main(){
	vec2 uv = vTex + offset;
	uv.y = 1.0 - uv.y;
	vec4 texColor = texture(uTexture, uv);
	vec3 black = vec3(0.0);
	if (texColor.xyz == black)
	{
		color = vec4(0.0);
	}
	else
	{
		color = vec4(1.0) * texColor;
	}
}
