#include "HeadsUpDisplay.h"
#include "freeglut.h"
#include "KeyBoardControl.h"
#include <string>

using namespace std;

string text;
HeadsUpDisplay::HeadsUpDisplay()
{
	text = "Initial Heads up Display. Use your mouse scroll wheel to zoom in and zoom out. Use the arrow pad to move around and press J to jump.";
}


HeadsUpDisplay::~HeadsUpDisplay()
{
}

void HeadsUpDisplay::Render()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, KeyBoardControl::mScreenWidth
		, KeyBoardControl::mScreenHeight,
		0.0, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	//glPushMatrix();        ----Not sure if I need this
	glLoadIdentity();
	glDisable(GL_CULL_FACE);

	glClear(GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);


	//glRasterPos3f(x, y, z);
	glRasterPos2f(100.0f, static_cast<GLfloat>(KeyBoardControl::mScreenHeight - 100));


	//glRasterPos2f(x, y);
	void * font = GLUT_BITMAP_HELVETICA_18;
	for (string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}
	glBegin(GL_QUADS);
	// Small line in the upper-left corner of the screen
	glColor3f(1.0f, 0.0f, 0.0); // Red
	glVertex2f(0.0, 0.0);
	glVertex2f(10.0, 0.0);
	glVertex2f(10.0, 10.0);
	glVertex2f(0.0, 10.0);
	glEnd();




	// Making sure we can render 3d again
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	//glPopMatrix();        ----and this?

}