#pragma once
#include "IRenderableObject.h"

class Block :
	public IRenderableObject
{
private:
	GLfloat size;

	GLfloat xValue;
	GLfloat yValue;
	GLfloat zValue;

public:
	Block();
	~Block();
	void Update() override;
	void Render() override;
	void SetSize(GLfloat val){ size = val; }
};

