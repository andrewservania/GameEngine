#pragma once


#include "UniverseBackground.h"
#include "Axes.h"

#include <memory>

class GameWorld
{
private:

	std::shared_ptr<UniverseBackground> mUniverseBackground;
	std::shared_ptr<Axes> mAxes;


public:
	GameWorld();
	~GameWorld();
};
