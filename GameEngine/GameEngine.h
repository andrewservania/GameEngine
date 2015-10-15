#pragma once
#include "IRenderableObject.h"
#include "freeglut.h"
#include "imageloader.h"
#include "Camera.h"
#include "KeyBoardControl.h"
#include "HeadsUpDisplay.h"

#include <vector>
#include <memory>
#include <string>

class GameEngine
{
private:
 	static float aaa, bbb, ccc, solarSystemRotation, mCameraFrontDistance, mCameraRearDistance;
	static const int framesPerSecond = 60;

	// A vector to include all objects to be rendered
	static std::shared_ptr<HeadsUpDisplay> headsUpDisplay;

	void UpdateObjects();
	void RenderObjects();

protected:
	static std::vector<IRenderableObject*> renderableObjects;
	static std::shared_ptr<KeyBoardControl> mKeyboardControl;
	static std::shared_ptr<Player> mainPlayer;




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
