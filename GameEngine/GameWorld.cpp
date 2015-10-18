#include "GameWorld.h"
#include "GameEngine.h"
#include "Axes.h"

using namespace std;

GLfloat _3DenvironmentSize = 30000.0f;

GameWorld::GameWorld()
{
	// Create the background for the universe
//	mUniverseBackground = make_shared<UniverseBackground>(1000);
	mAxes = make_shared<Axes>();

	for (int i = 0; i < 2000; ++i)
	{
		Block* aBlock = new Block();
		aBlock->SetSize(rand() % 10 + 0.f);
		aBlock->SetPosition(
			-_3DenvironmentSize / 2 + rand() % static_cast<int>(_3DenvironmentSize),
			-_3DenvironmentSize / 2 + rand() % static_cast<int>(_3DenvironmentSize),
			-_3DenvironmentSize / 2 + rand() % static_cast<int>(_3DenvironmentSize));
	}
}

GameWorld::~GameWorld()
{
}