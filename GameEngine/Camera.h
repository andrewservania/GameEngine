#pragma once
class Camera
{
public:
	float camA;
	float camB;
	float camC;

	float cameraViewAngle;
	bool universeLoaded;

	bool animate;
	bool visibility;
	float colorValue;
	bool light;
	bool resetView;

	int lightPosX;
	int lightPosY;
	int lightPosZ;

	Camera();
	~Camera();
};
