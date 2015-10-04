#include "UniverseBackground.h"
#include "GameEngine.h"

UniverseBackground::UniverseBackground(int _radius)
{
	radius = _radius;
	fileLocationOfUniverses = "..\\GameEngine\\Resources\\Universe Background Pictures\\";
	mQuad = gluNewQuadric();
	//Image* image = loadBMP((fileLocationOfUniverses + "universe4.bmp").c_str()); //Defualt
	Image* image = loadBMP((fileLocationOfUniverses + "hubble1.bmp").c_str());

	mTextureId = LoadTexture(image);
	delete image;

	glEnable(GL_TEXTURE_2D);
	GameEngine::AddRenderableObject(this);
}

UniverseBackground::~UniverseBackground()
{
}

void UniverseBackground::Render()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, mTextureId);
	gluQuadricTexture(mQuad, 1);
	gluSphere(mQuad, radius, 100, 100);

	//mIsUniverseRendering = true;
	//return mIsUniverseRendering;
}

void UniverseBackground::Update()
{
}
void UniverseBackground::RenderWireFrame()
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glutWireSphere(280, 200, 256);
}

void UniverseBackground::RenderUniverseBackground(){
}

GLuint UniverseBackground::LoadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);				//Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);	//Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                 //Always GL_TEXTURE_2D
		0,										//0 for now
		GL_RGB,									//Format OpenGL uses for image
		image->width, image->height,			//Width and height
		0,										//The border of the image
		GL_RGB,									//GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE,						//GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);							//The actual pixel data
	return textureId;							//Returns the id of the texture
}