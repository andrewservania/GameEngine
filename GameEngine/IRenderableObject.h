#pragma once
#include "freeglut.h"

#include <string>
class IRenderableObject
{
protected: // These will be the basic properties of a given render-able object within the game engine

	GLfloat x;
	GLfloat y;
	GLfloat z;

public:

	IRenderableObject();
	~IRenderableObject();
	void Load3DModel(std::string _filePath);
	void Render3DModel();
	virtual void Render() = 0;
	virtual void Update() = 0;

	GLfloat X() const { return x; }
	void X(GLfloat val) { x = val; }

	GLfloat Y() const { return y; }
	void Y(GLfloat val) { y = val; }

	GLfloat Z() const { return z; }
	void Z(GLfloat val) { z = val; }

	void SetPosition(GLfloat _x, GLfloat _y, GLfloat _z){
		 X( _x); Y( _y); Z( _z);
	}
};
