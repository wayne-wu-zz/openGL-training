//fragment shader
#version 430 core
layout(location = 0) out vec4 out_color; //output to render
in vec4 colour; //recieve from vertex shader

void main(void)
{
	//color = vec4(0.0, 1.0, 0.0, 1.0); <- Hardcoded value
	out_color = colour;
}