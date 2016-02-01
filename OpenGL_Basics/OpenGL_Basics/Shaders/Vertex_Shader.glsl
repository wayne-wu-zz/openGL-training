//vertex shader
#version 430 core 
layout(location = 0) in vec4 in_position; //set the first input on location 0; 
layout(location = 1) in vec4 in_colour;

out vec4 colour; //out to fragment shader (or the next one)

void main(void)
{
	gl_Position = in_position;
	colour = in_colour;
	//glVertexID represents the id of the vertex that's currently being processed
}