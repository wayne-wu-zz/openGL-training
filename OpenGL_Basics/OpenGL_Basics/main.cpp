#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 0.0, 0.0, 1.0); //red

	glutSwapBuffers(); // to work with double buffering
}

int main(int argc, char **argv) 
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("OpenGL First Window");

	glewInit(); 
	if (glewIsSupported("GL_VERSION_4_5")) {
		std::cout << "GLEW Version is 4.5\n";
	}
	else {
		std::cout << "GLEW 4.5 not supported\n";
	}

	glEnable(GL_DEPTH_TEST);
	//register callbacks
	glutDisplayFunc(renderScene);

	glutMainLoop();

	return 0;
}

