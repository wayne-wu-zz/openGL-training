#pragma once

#include "GL/glew.h"
#include "GL/freeglut.h"
#include <iostream>

namespace Core
{
	class Shader_Loader {
	private:

		//reads and returns the contents of a file
		std::string ReadShader(char *filename);
		//create and compilee shader
		GLuint CreateShader(GLenum shaderType,
			std::string source,
			char* shaderName);

	public:
		
		Shader_Loader(void);
		~Shader_Loader(void);
		GLuint CreateProgram(char* VertexShaderFilename,
						char* FragmentShaderFilename);

	};
}