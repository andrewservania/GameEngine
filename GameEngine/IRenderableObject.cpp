#include "IRenderableObject.h"
#include "GameEngine.h"
IRenderableObject::IRenderableObject()
{
	GameEngine::AddRenderableObject(this);
}

IRenderableObject::~IRenderableObject()
{
}