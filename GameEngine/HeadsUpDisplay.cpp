#include "HeadsUpDisplay.h"

#include "KeyBoardControl.h"



using namespace std;


HeadsUpDisplay::HeadsUpDisplay()
{
	textVisible = true;
	hudBackgroundVisible = true;
	worldCoordinatesVisible = true;
	cameraCoordinatesVisible = true;

	borderGap = 25;
	northSquareLinePosition = KeyBoardControl::mScreenHeight - 300.0f;
	southSquareLinePosition = KeyBoardControl::mScreenHeight - borderGap;
	westSquareLinePosition = borderGap;
	eastSquareLinePosition = KeyBoardControl::mScreenWidth - borderGap;


	text = "Initial Heads up Display. Use your mouse scroll wheel to zoom in and zoom out. Use the arrow pad to move around and press J to jump.";
	worldCoordinates = "World Coordinates: null";
	cameraCoordinates = "Camera Coordinates: null";

	basicTextFont = GLUT_BITMAP_HELVETICA_18;
	cameraCoordinatesFont = GLUT_BITMAP_HELVETICA_12;
	worldCoordinatesFont = GLUT_BITMAP_HELVETICA_12;

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
	glLoadIdentity();
	glDisable(GL_CULL_FACE);
	glClear(GL_DEPTH_BUFFER_BIT);

	// Add HUD stuff here..

	if (hudBackgroundVisible) RenderHUDbackground();
	if (textVisible)	RenderText();
	if (worldCoordinatesVisible) RenderWorldCoordinates();
	if (cameraCoordinatesVisible) RenderCameraCoordinates();

	// End of HUD stuff

	// Making sure we can render 3D again
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

}

void HeadsUpDisplay::RenderText()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glRasterPos2f(100.0f, static_cast<GLfloat>(KeyBoardControl::mScreenHeight - 250));
	//glRasterPos2f(x, y);

	for (string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(basicTextFont, c);
	}


}
void HeadsUpDisplay::DrawTextOnScreen(string _text)
{
	text = _text;
}

void HeadsUpDisplay::RenderHUDbackground()
{
	glBegin(GL_QUADS);
	glColor4f(0.2f, 0.2f, 0.2f,0.8f); // Red
	glVertex2f(westSquareLinePosition, northSquareLinePosition);  /* point 1 left-upper-corner vertex  */  
	glVertex2f(eastSquareLinePosition, northSquareLinePosition);  /* point 2 right-upper-corner vertex */
	glVertex2f(eastSquareLinePosition, southSquareLinePosition);  /* point 4 right-lower-corner vertex */  
	glVertex2f(westSquareLinePosition, southSquareLinePosition);  /* point 3 left-lower-corner vertex  */
	glEnd();

}

void HeadsUpDisplay::RenderWorldCoordinates(){
	glColor3f(0.0f, 1.0f, 0.0f);
	glRasterPos2f(100.0f, static_cast<GLfloat>(KeyBoardControl::mScreenHeight - 230));
	//glRasterPos2f(x, y);

	for (string::iterator i = worldCoordinates.begin(); i != worldCoordinates.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(worldCoordinatesFont, c);
	}
}
void HeadsUpDisplay::RenderCameraCoordinates()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glRasterPos2f(100.0f, static_cast<GLfloat>(KeyBoardControl::mScreenHeight - 210));
	//glRasterPos2f(x, y);
	
	for (string::iterator i = cameraCoordinates.begin(); i != cameraCoordinates.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(cameraCoordinatesFont, c);
	}
}