#pragma once
#include "freeglut.h"
#include "IRenderableObject.h"

#include <string>


class Axes : public IRenderableObject
{
private:
	bool mIsXBeingRendered, mIsYBeingRendered, mIsZBeingRendered;
	bool mIsXGridBeingRendered, mIsYGridBeingRendered, mIsZGridBeingRendered;
	GLfloat mLengthOfAxes;
	GLfloat depth;
	int squareSizeInGrid;

public:
	Axes();
	~Axes();

	bool RenderXAxis();
	bool RenderYAxis();
	bool RenderZAxis();

	bool RenderXAxisGrid();
	bool RenderYAxisGrid();
	bool RenderZAxisGrid();
	void drawText(std::string text, float x, float y, float z);

	virtual void Update() override;
	virtual void Render() override;
};
