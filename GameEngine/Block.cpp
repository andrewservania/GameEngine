#include "Block.h"


Block::Block()
{
	
	size = 100.0f;
	
	x = 0;
	y = 0;
	z = 0;

	xValue = 10.f + size;
	yValue = 10.f + size;
	zValue = 10.f + size;
}


Block::~Block()
{
}

void Block::Update()
{

}


void Block::Render()
{

	// Multi-colored side - FRONT
	glBegin(GL_POLYGON);
	glVertex3f(-0.5f - xValue + x, -0.5f - yValue + y, -0.5f - zValue + z);       // P1
	glVertex3f(-0.5f - xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);       // P2
	glVertex3f(0.5f + xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);       // P3
	glVertex3f(0.5f + xValue + x, -0.5f - yValue + y, -0.5f - zValue + z);       // P4
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);     glVertex3f(0.5f + xValue + x,-0.5f - yValue + y, -0.5f - zValue + z);      // P1 is red
	glColor3f(0.0, 1.0, 0.0);     glVertex3f(0.5f + xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);      // P2 is green
	glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5f - xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);      // P3 is blue
	glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.5f - xValue + x,-0.5f - yValue + y, -0.5f - zValue + z);      // P4 is purple
	glEnd();
	
	// White side - BACK
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.5f + xValue + x,-0.5f - yValue + y, 0.5f + zValue + z);
	glVertex3f(0.5f + xValue + x, 0.5f + yValue + y, 0.5f + zValue + z);
	glVertex3f(-0.5f - xValue + x, 0.5f + yValue + y, 0.5f + zValue + z);
	glVertex3f(-0.5f - xValue + x,-0.5f - yValue + y, 0.5f + zValue + z);
	glEnd();

	// Purple side - RIGHT
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5f + xValue + x,-0.5f - yValue + y, -0.5f - zValue + z);
	glVertex3f(0.5f + xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);
	glVertex3f(0.5f + xValue + x, 0.5f + yValue + y, 0.5f + zValue + z);
	glVertex3f(0.5f + xValue + x,-0.5f - yValue + y, 0.5f + zValue + z);
	glEnd();

	// Green side - LEFT
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5f - xValue + x,-0.5f - yValue + y, 0.5f + zValue + z);
	glVertex3f(-0.5f - xValue + x, 0.5f + yValue + y, 0.5f + zValue + z);
	glVertex3f(-0.5f - xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);
	glVertex3f(-0.5f - xValue + x,-0.5f - yValue + y, -0.5f - zValue + z);
	glEnd();

	// Blue side - TOP
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5f + xValue + x, 0.5f + yValue + y, 0.5f + zValue + z);
	glVertex3f(0.5f + xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);
	glVertex3f(-0.5f - xValue + x, 0.5f + yValue + y, -0.5f - zValue + z);
	glVertex3f(-0.5f - xValue + x, 0.5f + yValue + y, 0.5f + zValue + z);
	glEnd();

	// Red side - BOTTOM
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5f + xValue + x,-0.5f - yValue + y, -0.5f - zValue + z);
	glVertex3f(0.5f + xValue + x,-0.5f - yValue + y, 0.5f + zValue + z);
	glVertex3f(-0.5f - xValue + x,-0.5f - yValue + y, 0.5f + zValue + z);
	glVertex3f(-0.5f - xValue + x,-0.5f - yValue + y, -0.5f - zValue + z);
	glEnd();

	glFlush();
	//glutPostRedisplay();

}
