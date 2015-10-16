#include "KeyBoardControl.h"
#include "glut.h"

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int KeyBoardControl::mScreenWidth;
int KeyBoardControl::mScreenHeight;

KeyBoardControl::KeyBoardControl()
{
}

KeyBoardControl::KeyBoardControl(Camera* camera)
{
	fullScreenStatus = false;
	GetScreenResolution();
	//mCamera = camera;
}

KeyBoardControl::~KeyBoardControl()
{
}

void KeyBoardControl::ListenToKeys(unsigned char key, int x, int y, Player* player)
{
	printf("KeyBoardControlClass: Listening to keys");
	switch (key)
	{
		case 27:  exit(0);				break;  // ESCAPE key terminate Program

		case 'j': 	player->Jump();		break;
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
		glutCreateWindow("Game Engine");
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


void KeyBoardControl::MoveForward(Player* player)
{

}

