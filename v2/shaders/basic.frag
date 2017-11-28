#version 330 core

out vec4 color;

uniform sampler2D uTexture[3];

in vec3 vColor;
in vec2 vTex;
flat in int vTexID;

void main(){
	vec4 texColor = texture(uTexture[vTexID], vTex);
	// vec4 texColor = texture(uTexture[vTexID], vTex);
	// if (vTexID == 0)
	// {
	// 	texColor = texture(uTexture[0], vTex);
	// }
	// else
	// {
	// 	texColor = texture(uTexture[1], vTex);
	// }

	// color = vec4(vColor, 1.0) * vec4(1.0, 0.0, vTexID, 1.0);
	color = vec4(vColor, 1.0) * texColor;
	// color = vec4(1.0, 0.0, vTexID, 1.0);
}
