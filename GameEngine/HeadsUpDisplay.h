#pragma once
#include "freeglut.h"

#include <string>

class HeadsUpDisplay
{
private:

	// HUD background square parameters
	bool hudBackgroundVisible;
	GLfloat northSquareLinePosition;
	GLfloat southSquareLinePosition;
	GLfloat westSquareLinePosition;
	GLfloat eastSquareLinePosition;
	GLfloat borderGap;
	
	// Basic Text Parameters
	std::string text;
	bool textVisible;
	void * basicTextFont;
	// Wow, void pointers? Seriously?! 
	// I know.. remnants of C crawled and stayed in C++. 
	// As late Robin Williams Jumanji would quote: "What year is this?!"

	//Camera Coordinates Parameters
	std::string cameraCoordinates;
	bool cameraCoordinatesVisible;
	void * cameraCoordinatesFont;

	//World Coordinates Parameters
	std::string worldCoordinates;
	bool worldCoordinatesVisible;
	void * worldCoordinatesFont;

	void RenderText();
	void RenderHUDbackground();
	void RenderWorldCoordinates();
	void RenderCameraCoordinates();
public:
	HeadsUpDisplay();
	~HeadsUpDisplay();
	void Render();
	void DrawTextOnScreen(std::string _text);
	void ToggleTextOnOff() { textVisible = !textVisible; }
	void SetCameraCoordinates(std::string _cameraCoordinates) { cameraCoordinates = _cameraCoordinates; }
	void SetWorldCoordinates(std::string _worldCoordinates) { worldCoordinates = _worldCoordinates; }
};

