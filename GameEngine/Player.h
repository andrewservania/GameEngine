#pragma once
#include "IRenderableObject.h"
#include "Camera.h"
#include "freeglut.h"
#include <memory>

class Player : public IRenderableObject
{
private:
	std::shared_ptr<Camera> camera;
	GLfloat altitude;
	int counter;
	bool jumpingInProgress;
	float lastCamB;
public:


	Player();
	~Player();

	virtual void Update() override;
	virtual void Render() override;

	void MoveForward();
	void MoveBackwards();
	void MoveLeftSideWays();
	void MoveRightSideWays();

	void Jump();
	void Run();
	void Teleport(GLfloat _x, GLfloat _y, GLfloat _z);

	std::shared_ptr<Camera> GetCamera() { return camera; }

};