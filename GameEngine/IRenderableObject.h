#pragma once
//#include "glut.h"
#include "freeglut.h"

class IRenderableObject
{
protected: // These will be the basic properties of a given render-able object within the game engine

	GLfloat x;
	GLfloat y;
	GLfloat z;

public:

	IRenderableObject();
	~IRenderableObject();
	virtual void Render() = 0;
	virtual void Update() = 0;

	GLfloat X() const { return x; }
	void X(GLfloat val) { x = val; }

	GLfloat Y() const { return y; }
	void Y(GLfloat val) { y = val; }

	GLfloat Z() const { return z; }
	void Z(GLfloat val) { z = val; }
};
