//OpenGL 3D Computer Graphics
//Name: Andrew's Funky Finite 3D Solar System
//Author: Andrew Servania

//DEPRECATED CLASS!
#include <iostream>
#include "glut.h"
#include "freeglut.h"
#include <gl/GL.h>
#include <windows.h>
#include "imageloader.h"
#include "Planets.h"

using namespace std;

Planets::Planets()
{
	showOrbitalLanes = true;
	colorValue2 = 0.0f;
	visibility2 = true;
	imageLoaded = false;
	fileLocationOfPlanets = "..\\OpenGL\\Resources\\Planets\\";
}
Planets::~Planets()
{
}

GLuint loadTexturePlanet(Image* image) {
	GLuint textureId;

	glGenTextures(1, &textureId); //Make room for our texture

	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit

	//Map the image to the texture

	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D

		0,                            //0 for now

		GL_RGB,                       //Format OpenGL uses for image

		image->width, image->height,  //Width and height

		0,                            //The border of the image

		GL_RGB, //GL_RGB, because pixels are stored in RGB format

		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored

		//as unsigned numbers

		image->pixels);               //The actual pixel data

	return textureId; //Returns the id of the texture
}

void Planets::drawOrbit(GLfloat Radius, int numPoints, bool visible, float customV)
{
	double PI = 3.1415926535897f;
	glBegin(GL_LINE_STRIP);

	//Standard gray-white color
	glColor4f(1.0f + colorValue2 + customV, 1.0f +
		colorValue2 + customV, 1.0f +
		colorValue2 + customV, 0.0f +
		colorValue2 + customV);
	//	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	//glColor3f(r, r, r);
	for (int i = 0; i < numPoints; i++)
	{
		// putting 2.2 instead of 2.0 fixed the LINE issue!! Nice :)
		double Angle = i * (2.2*PI / numPoints);	// use 360 instead of 2.0*PI if
		GLfloat X = (GLfloat)cos(Angle)*Radius;			// you use d_cos and d_sin
		GLfloat Y = (GLfloat)sin(Angle)*Radius;
		glVertex2f(X, Y);
	}
	glEnd();
}

//Done
void Planets::CreateMercury(float solarSystemRotation)
{
	glPushMatrix();
	glRotatef(solarSystemRotation / 2, 0, 0, 1); // rotate on the ... axis
	glTranslatef(25, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	glColor3f(0.0f, 1.0f, 0.0f); //green
	createTexturedPlanet("texture_mercury.bmp", 1, 20, 10);
	//glutSolidSphere(1, 20, 10); //First variable - Size of the planet
	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(25, 60, visibility2, 1.0f);
	}
}

//Done
void Planets::CreateVenus(float solarSystemRotation)
{
	//////////////////////Venus//////////////////////////////////////////
	glPushMatrix();
	glRotatef(solarSystemRotation / 3, 0, 0, 1); // rotate on the ... axis
	glTranslatef(40, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	glColor3f(0.7f, 0.6f, 0.0f); //brown

	createTexturedPlanet("texture_venus.bmp", 2, 20, 10);
	//glutSolidSphere(2, 20, 10); //First variable - Size of the planet
	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(40, 60, visibility2, 0.9f);
	}
	/////////////////////////////////////////////////////////////////////
}

//Done
void Planets::CreatePlanetEarth(float solarSystemRotation)
{
	//////////////////////Planet Earth///////////////////////////////////
	glPushMatrix();
	glRotatef(solarSystemRotation / 4, 0, 0, 1); // rotate on the ... axis
	glTranslatef(50, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	//glColor3f(0.0f, 0.0f, 1.0f); //blue

	createTexturedPlanet("Earth.bmp", 8, 50, 50);

	//glutSolidSphere(4, 20, 10);

	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(50, 60, visibility2, 0.8f);
	}
	/////////////////////////////////////////////////////////////////////
}

//Done
void Planets::CreateMars(float solarSystemRotation)
{
	//////////////////////Mars///////////////////////////////////////////
	glPushMatrix();
	glRotatef(solarSystemRotation / 5, 0, 0, 1); // rotate on the ... axis
	glTranslatef(60, 0, 0); // The distance from the origin!! Or better said.. From the sun :)

	glColor3f(0.6f, 0.3f, 0.1f); //dark brown
	createTexturedPlanet("texture_mars.bmp", 2, 20, 10);
	//glutSolidSphere(2, 20, 10);
	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(60, 60, visibility2, 0.7f);
	}
	//////////////////////////////////////////////////////////////////////
}

//Done
void Planets::CreateJupiter(float solarSystemRotation)
{
	//////////////////////Jupiter/////////////////////////////////////////
	glPushMatrix();
	glRotatef(solarSystemRotation / 6, 0, 0, 1); // rotate on the ... axis
	glTranslatef(75, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	glColor3f(0.4f, 0.3f, 0.2f); //lime green
	createTexturedPlanet("texture_jupiter.bmp", 6, 20, 10);
	//glutSolidSphere(6, 20, 10);
	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(75, 60, visibility2, 0.6f);
	}
	//////////////////////////////////////////////////////////////////////
}

//Done
void Planets::CreateSaturn(float solarSystemRotation)
{
	//////////////////////Saturn/////////////////////////////////////////
	glPushMatrix();
	glRotatef(solarSystemRotation / 7, 0, 0, 1); // rotate on the ... axis
	glTranslatef(90, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	glColor3f(0.9f, 0.5f, 0.1f); // darker yellow
	//glutSolidSphere(5, 20, 10);
	createTexturedPlanet("texture_saturn.bmp", 5, 20, 10);
	//Saturn's Rings!
	glRotatef(30, 1, 0, 0);

	drawOrbit(6.2f, 20, 1, 1);
	drawOrbit(6.5f, 20, 1, 1);
	drawOrbit(7.1f, 20, 1, 1);
	drawOrbit(7.6f, 20, 1, 1);
	drawOrbit(8.0f, 20, 1, 1);
	drawOrbit(8.2f, 20, 1, 1);
	drawOrbit(8.4f, 20, 1, 1);
	drawOrbit(8.6f, 20, 1, 1);
	drawOrbit(8.8f, 20, 1, 1);
	drawOrbit(9.0f, 20, 1, 1);
	drawOrbit(9.2f, 20, 1, 1);

	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(90, 60, visibility2, 0.5f);
	}
	//
	// Circles coming soon!! :D :D
	//////////////////////////////////////////////////////////////////////
}

//Done
void Planets::CreateUranus(float solarSystemRotation)
{
	//////////////////////Uranus//////////////////////////////////////////
	glPushMatrix();
	glRotatef(solarSystemRotation / 8, 0, 0, 1); // rotate on the ... axis
	glTranslatef(110, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	glColor3f(0.4f, 0.4f, 1.0f); // light blue
	//glutSolidSphere(4, 20, 10);
	createTexturedPlanet("texture_uranus.bmp", 4, 20, 10);
	//Uranus' rings!
	glRotatef(90, 1, 0, 0);
	drawOrbit(6.4f, 20, 1, 1);
	drawOrbit(6.2f, 20, 1, 1);

	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(110, 60, visibility2, 0.4f);
	}
	//////////////////////////////////////////////////////////////////////
}

//Done
void Planets::CreateNeptunus(float solarSystemRotation)
{
	//////////////////////Neptunus////////////////////////////////////////
	glPushMatrix();
	glRotatef(solarSystemRotation / 9, 0, 0, 1); // rotate on the ... axis
	glTranslatef(140, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	glColor3f(0.6f, 0.5f, 0.7f);
	//glutSolidSphere(4, 20, 10);
	createTexturedPlanet("texture_neptune.bmp", 4, 20, 10);
	glPopMatrix();
	if (showOrbitalLanes == true)
	{
		drawOrbit(140, 60, visibility2, 0.3f);
	}
	//////////////////////////////////////////////////////////////////////
}

void Planets::CreatePluto(float solarSystemRotation)
{
	//////////////////////Pluto///////////////////////////////////////////
	//glRotatef(17, 1, 0, 0); Woa! This method causes alot of trouble here!
	glPushMatrix();
	glRotatef(17, 1, 0, 0); // The precise scientifical angle of Pluto's orbit. 17 degrees
	if (showOrbitalLanes == true)
	{
		drawOrbit(160, 60, visibility2, 0.2f);
	}
	glRotatef(solarSystemRotation / 10, 0, 0, 1); // rotate on the ... axis
	glTranslatef(160, 0, 0); // The distance from the origin!! Or better said.. From the sun :)
	glColor3f(0.6f, 0.3f, 0.1f); //dark brown
	//glutSolidSphere(1, 20, 10);
	createTexturedPlanet("texture_pluto_fictional.bmp", 1, 20, 10);
	glPopMatrix();

	//////////////////////////////////////////////////////////////////////
}

void Planets::LoadPlanetImages(const char* fileName)
{
	if (imageLoaded == false)
	{
		glEnable(GL_DEPTH_TEST);

		//	glEnable(GL_LIGHTING);

		glEnable(GL_LIGHT0);

		glEnable(GL_NORMALIZE);

		glEnable(GL_COLOR_MATERIAL);

		printf("Init Graphics method called");

		quadPlanet = gluNewQuadric();
		Image* image = loadBMP(fileName);
		_textureIdPlanet = loadTexturePlanet(image);

		delete image;
		imageLoaded = true;
	}
}

void Planets::createTexturedPlanet(string planetImageLocation, int radius, int slices, int stacks)
{
	LoadPlanetImages((fileLocationOfPlanets += planetImageLocation).c_str());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureIdPlanet);
	gluQuadricTexture(quadPlanet, 1);
	gluSphere(quadPlanet, radius, slices, stacks);
}
