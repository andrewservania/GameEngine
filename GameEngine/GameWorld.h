#pragma once


#include "UniverseBackground.h"
#include "Axes.h"
#include "Block.h"

#include <memory>

class GameWorld
{
private:

	std::shared_ptr<UniverseBackground> mUniverseBackground;
	std::shared_ptr<Axes> mAxes;
	std::shared_ptr<Block> block;


public:
	GameWorld();
	~GameWorld();
};
