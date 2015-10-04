#include "GameEngine.h"

using namespace std;

vector<IRenderableObject*> GameEngine::renderableObjects;
std::shared_ptr<Camera> GameEngine::mCamera;
std::shared_ptr<KeyBoardControl> GameEngine::mKeyboardControl;
float GameEngine::aaa = -20.0f;
float GameEngine::bbb = 0.0f;
float GameEngine::ccc = 0.0f;
float GameEngine::solarSystemRotation = 0.0f;
float GameEngine::mCameraFrontDistance = 970.0f;
float GameEngine::mCameraRearDistance = 100.0f;

GameEngine::GameEngine()
{
	mCamera = make_shared<Camera>();
	mKeyboardControl = make_shared<KeyBoardControl>(mCamera.get());
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

	gluLookAt(mCamera->camA, mCamera->camB, -mCamera->camC,		//eye
		mCamera->camA, mCamera->camB, mCamera->camC,		//center
		0, 1, 0);
	glRotatef(mCamera->cameraViewAngle, 0.0, 10.0, 0.0);

	glPushMatrix();
	glLineWidth(2.0);						// Width of ALL Lines in the 3D environment
	glPopMatrix();

	for (IRenderableObject* obj : renderableObjects)	obj->Render();

	glutSwapBuffers();
	Sleep(1000 / framesPerSecond);
}

void GameEngine::GatherKeyboardInput(unsigned char key, int x, int y)
{
	mKeyboardControl->ListenToKeys(key, x, y);
}

void GameEngine::GatherKeyboardArrowPadInput(int key, int x, int y)
{
	switch (key){
	case GLUT_KEY_UP:
		//do something here
		mCamera->camB += 10;
		break;
	case GLUT_KEY_DOWN:
		//do something here
		mCamera->camB -= 10;
		break;
	case GLUT_KEY_LEFT:
		//do something here
		//solarSystemRotation += 1.0f;
		mCamera->cameraViewAngle += 1.0f;
		glRotatef(mCamera->cameraViewAngle, 0.0, 10.0, 0.0);
		break;
	case GLUT_KEY_RIGHT:
		//solarSystemRotation -= 1.0f;
		mCamera->cameraViewAngle -= 1.0f;
		glRotatef(mCamera->cameraViewAngle, 0.0, 10.0, 0.0);
		//do something here
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
		mCamera->camC -= 8.0f;					// Forward
	}
	else
	{
		// Rotate Down
		mCamera->camC += 8.0f;					// Back up
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
	if (mCamera->camA >= mCameraFrontDistance)
		mCamera->camA = mCameraFrontDistance;

	if (mCamera->camA <= mCameraRearDistance)
		mCamera->camA = mCameraRearDistance;

	//Vertical checking
	//if (mCamera->camB >= mCameraFrontDistance)
	//	mCamera->camB = mCameraFrontDistance;

	//if (mCamera->camB <= mCameraRearDistance)
	//	mCamera->camB = mCameraRearDistance;

	if (mCamera->camC >= mCameraFrontDistance)
		mCamera->camC = mCameraFrontDistance;

	if (mCamera->camC <= mCameraRearDistance)
		mCamera->camC = mCameraRearDistance;
	///////////////////////////////////////////
	if (mCamera->visibility == true)
	{
		mCamera->colorValue = -1.0f;
		glutPostRedisplay();
	}
	if (mCamera->visibility == false)
	{
		mCamera->colorValue = -3.5f;
		glutPostRedisplay();
	}

	if (mCamera->animate == true)
	{
		solarSystemRotation += 1.0f;
		mCamera->cameraViewAngle -= 0.05f;
	}
	//Gradual Camera Reset///////////
	while (mCamera->resetView == true)
	{
		if (mCamera->camA > 20)
		{
			mCamera->camA = mCamera->camA -= 1;

			if (mCamera->camA == 20)
			{
				mCamera->camA = 20;
			}
		}
		if (mCamera->camA < 20)
		{
			mCamera->camA = mCamera->camA += 1;

			if (mCamera->camA == 20)
			{
				mCamera->camA = 20;
			}
		}

		////////////////////////////////////////////
		if (mCamera->camB < -60)
		{
			mCamera->camB = mCamera->camB += 1;

			if (mCamera->camB == -60)
			{
				mCamera->camB = -60;
			}
		}
		if (mCamera->camB > -60)
		{
			mCamera->camB = mCamera->camB -= 1;
			if (mCamera->camB == -60)
			{
				mCamera->camB = -60;
			}
		}
		////////////////////////////////////////////
		if (mCamera->camC < -5)
		{
			mCamera->camC = mCamera->camC += 1;
			if (mCamera->camC == -5)
			{
				mCamera->camC = -5;
			}
		}
		if (mCamera->camC > -5)
		{
			mCamera->camC = mCamera->camC -= 1;
			if (mCamera->camC == -5)
			{
				mCamera->camC = -5;
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

		if (mCamera->camA == 20
			&& mCamera->camB == -60
			&& mCamera->camC == -5
			&& aaa == -20)
		{
			mCamera->resetView = false;
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