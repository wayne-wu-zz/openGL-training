#ifndef VertexFormat_H_
#define VertexFormat_H_

#include "glm\glm.hpp"

struct VertexFormat {
	glm::vec3 position; 
	glm::vec4 colour; //can use float optionally

	VertexFormat(const glm::vec3 &pos, const glm::vec4 &colr)
	{
		position = pos;
		colour = colr;
	}

};

#endif