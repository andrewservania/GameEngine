#pragma once

#include "Camera.h"
#include <windows.h>

class KeyBoardControl
{
private:
	int mScreenWidth = 0;
	int mScreenHeight = 0;

	const int mColorDepth = 32;
	const int mRefreshRate = 60;

	bool fullScreenStatus;
public:

	Camera* mCamera;

	KeyBoardControl();
	KeyBoardControl(Camera* camera);
	~KeyBoardControl();
	void ListenToKeys(unsigned char key, int x, int y);
	void ToggleFullScreen(bool isFullScreen);
	RECT GetScreenResolution();
};
