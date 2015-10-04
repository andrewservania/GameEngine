#pragma once
#include "glut.h"
#include <string>

using namespace std;

class Planets
{
public:
	bool showOrbitalLanes;
	float colorValue2;
	bool visibility2;
	bool imageLoaded;

	GLuint _textureIdPlanet; //The id of the texture
	GLUquadric *quadPlanet;

	//TODO:Are these variables used? I don't thinks so. Find out
	GLuint _textureId; //The id of the texture
	GLUquadric *quad;
	string fileLocationOfPlanets;

	Planets();
	~Planets();

	void drawOrbit(float Radius, int numPoints, bool visible, float customV);

	void CreateMercury(float solarSystemRotation);

	void CreateVenus(float solarSystemRotation);

	void CreatePlanetEarth(float solarSystemRotation);

	void CreateMars(float solarSystemRotation);

	void CreateJupiter(float solarSystemRotation);

	void CreateSaturn(float solarSystemRotation);

	void CreateUranus(float solarSystemRotation);

	void CreateNeptunus(float solarSystemRotation);

	void CreatePluto(float solarSystemRotation);

	void LoadPlanetImages(const char* fileName);

	void createTexturedPlanet(string planetImageLocation, int radius, int slices, int stacks);
};
