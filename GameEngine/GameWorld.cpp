#include "GameWorld.h"
#include "GameEngine.h"
#include "Axes.h"

using namespace std;

GameWorld::GameWorld()
{
	// Create the background for the universe
//	mUniverseBackground = make_shared<UniverseBackground>(1000);
	mAxes = make_shared<Axes>();

}

GameWorld::~GameWorld()
{
}