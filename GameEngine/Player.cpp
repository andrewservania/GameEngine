#include "Player.h"
#include "GameEngine.h"

#include <cmath>

using namespace std;

Player::Player()
{
	camera = make_shared<Camera>();
	altitude = 0;
	counter = 0;
	jumpingInProgress = false;
	lastCamB = camera->camB;
}

Player::~Player()
{

}

void Player::Update()
{

}

void Player::Render()
{
	if (jumpingInProgress == true)
	{
		Jump();
	}
}


void Player::MoveForward()
{
	camera->camC -= 8.0f;					

}


void Player::MoveBackwards()
{
	camera->camC += 8.0f;
}

void Player::MoveLeftSideWays()
{
	camera->camA += 8.0f;
}

void Player::MoveRightSideWays()
{


	camera->camA -= 8.0f;
}

// Using parabola-like values to simulate a jump
void Player::Jump()
{
		if (altitude <= 7)
		{
			float sum = pow(altitude - 4, 2) + 10;

			if (altitude <= 3) camera->camB += sum;
			else camera->camB -= sum;
			altitude+= 0.1f;
			jumpingInProgress = true;
		}
		if (altitude > 7)
		{
			altitude = 0;
			jumpingInProgress = false;
			camera->camB = lastCamB;
		}

}

void Player::Run()
{

}

// Put the player at a specific location
void Player::Teleport(GLfloat _x, GLfloat _y, GLfloat _z)
{
	X(_x);
	Y(_y);
	Z(_z);
}