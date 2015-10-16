#include "Camera.h"

Camera::Camera()
{
	// camA = 20;
	// camB = -120;
	// camC = -60;

	camA = 400;
	camB = 100;
	camC = 500;

	cameraViewAngle = -10.0f;
	universeLoaded = false;

	animate = true;
	visibility = true;
	colorValue = 0.0f;
	light = true;
	resetView = false;

	lightPosX = 1;
	lightPosY = 1;
	lightPosZ = 1;
}

Camera::~Camera()
{
}