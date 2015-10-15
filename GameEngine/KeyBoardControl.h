#pragma once

#include "Camera.h"
#include "Player.h"


class KeyBoardControl
{
public:
	
	static int mScreenWidth;
	static int mScreenHeight;
private:

	const int mColorDepth = 32;
	const int mRefreshRate = 60;

	bool fullScreenStatus;
public:


	KeyBoardControl();
	KeyBoardControl(Camera* camera);
	~KeyBoardControl();
	void ListenToKeys(unsigned char key, int x, int y, Player* player);
	void ToggleFullScreen(bool isFullScreen);
	RECT GetScreenResolution();
	void MoveForward(Player* player);
};
