//OpenGL 3D Computer Graphics
//Name: Andrew's Funky Finite 3D Solar System
//Author: Andrew Servania

//#include "glut.h"
#include "freeglut.h"
#include "imageloader.h"
#include "Camera.h"
#include "KeyBoardControl.h"
#include "UniverseBackground.h"
#include "Axes.h"
#include "GameEngine.h"
#include "GameWorld.h"

#include <iostream>
#include <memory>
#include <windows.h>

using namespace std;

shared_ptr<GameWorld> gameWorld;
shared_ptr<GameEngine> gameEngine;

//string fontFilename = "...\\OpenGL\\Resources\\Fonts\\";
//string fontName = "FreeSerif.ttf";

void drawText(string text, float x, float y, float z){
	//glMatrixMode(GL_PROJECTION);
	//glPushMatrix();
	//glLoadIdentity();
	//gluOrtho2D(0.0, mScreenWidth, 0.0, mScreenHeight);

	//glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();
	//glLoadIdentity();

	//glColor3f(0.0, 1.0, 0.0); // Green
	//
	////glRasterPos3f(x, y, z);
	//glRasterPos3f(-mCamera->camA, mCamera->camB, mCamera->camC);
	//
	////glRasterPos2f(x, y);
	//void * font = GLUT_BITMAP_9_BY_15;
	//for (string::iterator i = text.begin(); i != text.end(); ++i)
	//{
	//	char c = *i;
	//	glutBitmapCharacter(font, c);
	//}

	//glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();

	//glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
}

int main(int argc, char* argv[])
{
	cout << "Loading...\n";
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	gameEngine = make_shared<GameEngine>();
	gameWorld = make_shared<GameWorld>();

	//mAxes = make_unique<Axes>();

	glutDisplayFunc(GameEngine::Render);
	glutReshapeFunc(GameEngine::Reshape);
	glutKeyboardFunc(GameEngine::GatherKeyboardInput);
	glutMouseFunc(GameEngine::GatherMouseClickInput);
	glutMotionFunc(GameEngine::GatherMouseMotionInput);
	glutMouseWheelFunc(GameEngine::GatherMouseScrollWheelInput);
	glutIdleFunc(GameEngine::IdleFunction);
	glutSpecialFunc(GameEngine::GatherKeyboardArrowPadInput);

	cout << "Done.\n";
	// Turn the flow of control over to GLUT
	glutMainLoop();

	return 0;
}