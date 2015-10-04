#pragma once
#include "IRenderableObject.h"
#include "freeglut.h"
#include "imageloader.h"
#include "Camera.h"
#include "KeyBoardControl.h"

#include <vector>
#include <memory>
#include <string>

class GameEngine
{
private:
	// A vector to include all objects to be rendered
	static std::vector<IRenderableObject*> renderableObjects;
	static const int framesPerSecond = 60;

	static std::shared_ptr<Camera> mCamera;
	static std::shared_ptr<KeyBoardControl> mKeyboardControl;
	static float aaa, bbb, ccc, solarSystemRotation, mCameraFrontDistance, mCameraRearDistance;
	void UpdateObjects();
	void RenderObjects();

public:
	GameEngine();
	~GameEngine();
	// Required GLUT callback functions
	static void Update();
	static void Render();
	static void GatherKeyboardInput(unsigned char key, int x, int y);
	static void GatherKeyboardArrowPadInput(int key, int x, int y);
	static void GatherMouseClickInput(int button, int state, int x, int y);
	static void GatherMouseMotionInput(int x, int y);
	static void GatherMouseScrollWheelInput(int button, int dir, int x, int y);
	static void Reshape(GLint width, GLint height);
	static void IdleFunction();

	static void AddRenderableObject(IRenderableObject* object);

	// Make the game engine a singleton as there will be only one
};
