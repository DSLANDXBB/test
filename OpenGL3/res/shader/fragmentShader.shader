#version 330 core

in vec3 ourColor;
in vec2 ourTexCoord;

uniform sampler2D ourTexture0;
uniform sampler2D ourTexture1;

out vec4 fragColor;

void main()
{
	fragColor = texture(ourTexture0, ourTexCoord) * vec4(ourColor, 1.0f);
}