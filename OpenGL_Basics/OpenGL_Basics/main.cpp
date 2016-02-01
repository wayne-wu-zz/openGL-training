#include "GL\glew.h"
#include "GL\freeglut.h"
#include "Core\Shader_Loader.h"
#include "Core\GameModels.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace Core;
using namespace Models;

GameModels* gameModels;
GLuint program; //from core
const std::string TRI_NAME = "triangle1";

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	//bind to the vao
	glBindVertexArray(gameModels->GetModel(TRI_NAME));
	
	//use the created program
	glUseProgram(program);
	//the program is a container for the shaders used in this case to draw the scene
	//you can switch programs between objects being drawn

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glutSwapBuffers(); // to work with double buffering
}

void closeCallback() 
{
	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init() {

	glEnable(GL_DEPTH_TEST);

	gameModels = new Models::GameModels(); 
	gameModels->CreateTriangleModel(TRI_NAME);

	//load and compile shaders (written in core)
	Shader_Loader shaderLoader; 
	program = shaderLoader.CreateProgram("Shaders\\Vertex_Shader.glsl", "Shaders\\Fragment_Shader.glsl");

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("OpenGL First Window");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glewInit(); 

	Init(); //initialize

	//register callbacks
	glutDisplayFunc(renderScene);
	glutCloseFunc(closeCallback); //callled when the program is closed
		
	glutMainLoop();

	delete gameModels;
	glDeleteProgram(program);

	return 0;
}

