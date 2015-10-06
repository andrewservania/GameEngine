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