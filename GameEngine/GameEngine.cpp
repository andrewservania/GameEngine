#include "GameEngine.h"

using namespace std;

vector<IRenderableObject*> GameEngine::renderableObjects;

shared_ptr<KeyBoardControl> GameEngine::mKeyboardControl;
shared_ptr<Player> GameEngine::mainPlayer;

float GameEngine::aaa = -20.0f;
float GameEngine::bbb = 0.0f;
float GameEngine::ccc = 0.0f;
float GameEngine::solarSystemRotation = 0.0f;
float GameEngine::mCameraFrontDistance = 970.0f;
float GameEngine::mCameraRearDistance = 100.0f;

GameEngine::GameEngine()
{
	mainPlayer = make_shared<Player>();
	//mCamera = make_shared<Camera>();
	mKeyboardControl = make_shared<KeyBoardControl>(mainPlayer->GetCamera().get());
	mKeyboardControl->ToggleFullScreen(false);
}

GameEngine::~GameEngine()
{
}

void GameEngine::Update()
{
	for (IRenderableObject* obj : renderableObjects)
		obj->Update();
}

void GameEngine::Render()
{
	Update();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	Update();

	gluLookAt(
		mainPlayer->GetCamera()->camA,		//eye
		mainPlayer->GetCamera()->camB,      //eye
		-mainPlayer->GetCamera()->camC,		//eye
		mainPlayer->GetCamera()->camA,		//center
		mainPlayer->GetCamera()->camB,		//center
		mainPlayer->GetCamera()->camC,		//center
		0, 1, 0);

	//glRotatef(mainPlayer->GetCamera()->cameraViewAngle, 0.0, 10.0, 0.0);

	glPushMatrix();
	glLineWidth(2.0);						// Width of ALL Lines in the 3D environment
	glPopMatrix();

	for (IRenderableObject* obj : renderableObjects)	obj->Render();

	glutSwapBuffers();
	Sleep(1000 / framesPerSecond);
}

void GameEngine::GatherKeyboardInput(unsigned char key, int x, int y)
{
	mKeyboardControl->ListenToKeys(key, x, y, mainPlayer.get());
}

void GameEngine::GatherKeyboardArrowPadInput(int key, int x, int y)
{
	switch (key){
	case GLUT_KEY_UP:
		//do something here
		//mainPlayer->GetCamera()->camB += 10;
		mainPlayer->MoveForward();
		break;
	case GLUT_KEY_DOWN:
		//do something here
		//mainPlayer->GetCamera()->camB -= 10;
		mainPlayer->MoveBackwards();
		break;
	case GLUT_KEY_LEFT:
		//do something here
		//solarSystemRotation += 1.0f;
		//mainPlayer->GetCamera()->cameraViewAngle += 1.0f;
		//glRotatef(mainPlayer->GetCamera()->cameraViewAngle, 0.0, 10.0, 0.0);

		mainPlayer->MoveLeftSideWays();
		break;
	case GLUT_KEY_RIGHT:
		//solarSystemRotation -= 1.0f;
		//mainPlayer->GetCamera()->cameraViewAngle -= 1.0f;
		//glRotatef(mainPlayer->GetCamera()->cameraViewAngle, 0.0, 10.0, 0.0);
		//do something here
		mainPlayer->MoveRightSideWays();

		break;
	}
}

void GameEngine::GatherMouseClickInput(int button, int state, int x, int y)
{
}

void GameEngine::GatherMouseMotionInput(int x, int y)
{

}

void GameEngine::GatherMouseScrollWheelInput(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		// Rotate Up
		mainPlayer->GetCamera()->camC -= 8.0f;					// Forward
	}
	else
	{
		// Rotate Down
		mainPlayer->GetCamera()->camC += 8.0f;					// Back up
	}
}

void GameEngine::Reshape(GLint width, GLint height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, width / (float)height, 1, 2000);
	glMatrixMode(GL_MODELVIEW);
}

void GameEngine::IdleFunction()
{
	//3D Camera Environment Limits///////////
	if (mainPlayer->GetCamera()->camA >= mCameraFrontDistance)
		mainPlayer->GetCamera()->camA = mCameraFrontDistance;

	if (mainPlayer->GetCamera()->camA <= mCameraRearDistance)
		mainPlayer->GetCamera()->camA = mCameraRearDistance;

	//Vertical checking
	//if (mainPlayer->GetCamera()->camB >= mCameraFrontDistance)
	//	mainPlayer->GetCamera()->camB = mCameraFrontDistance;

	//if (mainPlayer->GetCamera()->camB <= mCameraRearDistance)
	//	mainPlayer->GetCamera()->camB = mCameraRearDistance;

	if (mainPlayer->GetCamera()->camC >= mCameraFrontDistance)
		mainPlayer->GetCamera()->camC = mCameraFrontDistance;

	if (mainPlayer->GetCamera()->camC <= mCameraRearDistance)
		mainPlayer->GetCamera()->camC = mCameraRearDistance;
	///////////////////////////////////////////
	if (mainPlayer->GetCamera()->visibility == true)
	{
		mainPlayer->GetCamera()->colorValue = -1.0f;
		glutPostRedisplay();
	}
	if (mainPlayer->GetCamera()->visibility == false)
	{
		mainPlayer->GetCamera()->colorValue = -3.5f;
		glutPostRedisplay();
	}

	if (mainPlayer->GetCamera()->animate == true)
	{
		solarSystemRotation += 1.0f;
		mainPlayer->GetCamera()->cameraViewAngle -= 0.05f;
	}
	//Gradual Camera Reset///////////
	while (mainPlayer->GetCamera()->resetView == true)
	{
		if (mainPlayer->GetCamera()->camA > 20)
		{
			mainPlayer->GetCamera()->camA = mainPlayer->GetCamera()->camA -= 1;

			if (mainPlayer->GetCamera()->camA == 20)
			{
				mainPlayer->GetCamera()->camA = 20;
			}
		}
		if (mainPlayer->GetCamera()->camA < 20)
		{
			mainPlayer->GetCamera()->camA = mainPlayer->GetCamera()->camA += 1;

			if (mainPlayer->GetCamera()->camA == 20)
			{
				mainPlayer->GetCamera()->camA = 20;
			}
		}

		////////////////////////////////////////////
		if (mainPlayer->GetCamera()->camB < -60)
		{
			mainPlayer->GetCamera()->camB = mainPlayer->GetCamera()->camB += 1;

			if (mainPlayer->GetCamera()->camB == -60)
			{
				mainPlayer->GetCamera()->camB = -60;
			}
		}
		if (mainPlayer->GetCamera()->camB > -60)
		{
			mainPlayer->GetCamera()->camB = mainPlayer->GetCamera()->camB -= 1;
			if (mainPlayer->GetCamera()->camB == -60)
			{
				mainPlayer->GetCamera()->camB = -60;
			}
		}
		////////////////////////////////////////////
		if (mainPlayer->GetCamera()->camC < -5)
		{
			mainPlayer->GetCamera()->camC = mainPlayer->GetCamera()->camC += 1;
			if (mainPlayer->GetCamera()->camC == -5)
			{
				mainPlayer->GetCamera()->camC = -5;
			}
		}
		if (mainPlayer->GetCamera()->camC > -5)
		{
			mainPlayer->GetCamera()->camC = mainPlayer->GetCamera()->camC -= 1;
			if (mainPlayer->GetCamera()->camC == -5)
			{
				mainPlayer->GetCamera()->camC = -5;
			}
		}
		////////////////////////////////////////////
		if (aaa < -20)
		{
			aaa = aaa += 1;
			if (aaa == -20)
			{
				aaa = -20;
			}
		}
		if (aaa > -20)
		{
			aaa = aaa -= 1;
			if (aaa == -20)
			{
				aaa = -20;
			}
		}
		//////////////////////////////////////////

		if (mainPlayer->GetCamera()->camA == 20
			&& mainPlayer->GetCamera()->camB == -60
			&& mainPlayer->GetCamera()->camC == -5
			&& aaa == -20)
		{
			mainPlayer->GetCamera()->resetView = false;
		}
	}

	//TODO: Adapt! This method does alot related to lighting!:
	//letThereBeLight();
	//glutPostRedisplay();
}

void GameEngine::AddRenderableObject(IRenderableObject* object)
{
	renderableObjects.push_back(object);
}