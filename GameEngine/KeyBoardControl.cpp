#include "KeyBoardControl.h"
#include "glut.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
KeyBoardControl::KeyBoardControl()
{
}
//KeyBoardControl::KeyBoardControl(Planets* planets, Camera* camera)
//{
//	mPlanets = planets;ko
//	mCamera = camera;
//}

KeyBoardControl::KeyBoardControl(Camera* camera)
{
	fullScreenStatus = false;
	GetScreenResolution();
	mCamera = camera;
}

KeyBoardControl::~KeyBoardControl()
{
}

void KeyBoardControl::ListenToKeys(unsigned char key, int x, int y)
{
	printf("KeyBoardControlClass: Listening to keys");
	switch (key)
	{
	case 27:  exit(0);					break;  // ESCAPE key terminate Program

		///////////Numeric Keypad Camera Movement Implementation: /////////////////
	case '8': mCamera->camB += 2.0f;															break; // Forward
	case '5': mCamera->camB -= 2.0f;															break; // Back up
	case '4': mCamera->cameraViewAngle++;							printf("4 called");			break; // Move to the Right
	case '6': mCamera->cameraViewAngle--;							printf("6 called");			break; // Move to the Left

	case '9': mCamera->camA -= 2.0f;	mCamera->camB += 2.0f;									break; // Number 9 Rechts Boven
	case '1': mCamera->camA += 2.0f;	mCamera->camB -= 2.0f;									break; // Number 1 Links Beneden
	case '7': mCamera->camB += 2.0f;	mCamera->camA += 2.0f;									break; // Number 7 Links Boven
	case '3': mCamera->camB -= 2.0f;	mCamera->camA -= 2.0f;									break; // Number 3 Rechts Beneden

	case '2': mCamera->camC -= 2.0f;															break; // Elevate
	case '0': mCamera->camC += 2.0f;															break; // Descent

		////////Planetary Orbit Lanes Visibility:///////////////////////
	case 'o':	mCamera->visibility = !mCamera->visibility;										break;
		///////////////////////////////////////////////////////////////

		////////Solar System Animation/////////////////////////////////
	case 'a': mCamera->animate = !mCamera->animate;											break;
		///////////////////////////////////////////////////////////////

		//////Lighting/////////////////////////////////////////////////
	case 'l': mCamera->light = !mCamera->light;													break;
		///////////////////////////////////////////////////////////////

	case 'r': mCamera->resetView = true;														break; // reset camera view to default position

		//case 'm': mPlanets->showOrbitalLanes = !mPlanets->showOrbitalLanes;							break; // Draw Orbital Lanes

	case 't': mCamera->lightPosX++;																break;
	case 'y': mCamera->lightPosY++;																break;
	case 'u': mCamera->lightPosZ++;																break;

	case 'g': mCamera->lightPosX--;																break;
	case 'h': mCamera->lightPosY--;																break;
	case 'j': mCamera->lightPosZ--;																break;
	}
}

void KeyBoardControl::ToggleFullScreen(bool isFullScreen)
{
	fullScreenStatus = isFullScreen;
	if (isFullScreen == true)
	{
		string  screenSettings =
			to_string(mScreenWidth) +
			"x" +
			to_string(mScreenHeight) +
			":" +
			to_string(mColorDepth) +
			"@" +
			to_string(mRefreshRate);
		const char* screenResolutionSetting = screenSettings.c_str();

		glutGameModeString(screenResolutionSetting); //the settings for full screen mode

		glutEnterGameMode(); //set glut to full screen using the settings in the line above
	}

	else
	{
		// These three functions HAVE to follow this order!
		// Otherwise you will BREAK the window!
		int windowWidth = mScreenWidth - 100;
		int windowHeight = mScreenHeight - 150;
		glutInitWindowSize(windowWidth, windowHeight);
		glutCreateWindow("A Finite Solar System");
		glutPositionWindow(mScreenWidth / 2 - windowWidth / 2,
			mScreenHeight / 2 - windowHeight / 2);
	}
}

RECT KeyBoardControl::GetScreenResolution()
{
	RECT desktop;
	//Get handle for the desktop window
	const HWND hDesktop = GetDesktopWindow();

	//Get the size of screen to the variable desktop
	GetWindowRect(hDesktop, &desktop);
	//The top left corner will have coordinates (0,0)
	//and the bottom right corner will have coordinates
	//(horizontal, vertical)
	mScreenWidth = desktop.right;
	mScreenHeight = desktop.bottom;
	return desktop;
}