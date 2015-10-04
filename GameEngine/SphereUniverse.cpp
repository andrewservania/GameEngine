//OpenGL 3D Computer Graphics
// Andrew Servania

#include <iostream>
//#include <glut.h>
#include <GL/freeglut.h>
#include <gl/GL.h>

//For printing out messages (like java system.out.println)
using namespace std;

 // rotation value variables
float a = 0.0f;
float b = 0.0f;
float c = 0.0f;

//axes lines float variables
float ORG[3] = {0,0,0};

 //Andy Note: By playing with these numbers you can change the length of the line.
float XP[3] = {3,0,0};
float XN[3] = {-3,0,0};

float YP[3] = {0,3,0};
float YN[3] = {0,-3,0};

float ZP[3] = {0,0,3};
float ZN[3] = {0,0,-3};


// translate temporary variables 
float xMove = 0.0;
float yMove = 0.0;

// this variable will be used to monitor the mouse value
// and display this on the screen

//float MouseXcoordinate;

 //gluLookAt default values
// these will later be manipulated by the keyboard switch-case statement
float zz = 0; 
float xx = 0;
float cc = 0;

// Orthogonal variables, they don't work
int w1 = 200;
int h1 = 200;

void orthogonalStart (void) {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, w1, 0, h1);
    glScalef(1, -1, 1);
    glTranslatef(0, -h1, 0);
    glMatrixMode(GL_MODELVIEW);
}

void orthogonalEnd (void) {
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void Display(void)
{
	
	// The following line empties the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();



	// This important function enables camera functionality and movement with the 3D environment
		gluLookAt(	0+zz,-1+xx,-1+cc, //eye
					0+zz,2+xx,0+cc,  //center
					0,1,0);          // up vector THIS ONE STAYS LIKE ThIS! UNLESS YOU WANT TO WORK WITH HEIGHTS!
	
	glRotatef(b, 1.0, 0.0, 0.0); // rotate around x axis
    glRotatef(c, 0.0, 0.0, 1.0); // rotate around z axis

	glPushMatrix();


glLineWidth (2.0);

	glEnd();


glBegin (GL_LINES);
glColor3f (1,0,0); // X axis is red. 
glVertex3fv (ORG);
glVertex3fv (XP ); 
glColor3f (0,1,0); // Y axis is green.
glVertex3fv (ORG);
glVertex3fv (YP );
glColor3f (0,0,1); // z axis is blue.
glVertex3fv (ORG);
glVertex3fv (ZP ); 


glEnd();

glPopMatrix();


glTranslatef(xMove,0,0);


glutWireCube(2.0f); // Render the primitive, in this case, cuve


glTranslatef(yMove,0,0);
glutWireCube(2.0f); // Render the primitive
//glColor3f(0.5,0.0f,0.0f);

// Sphere 2 experimentation

	//glutWireSphere() Function Technical Details:
	//radius: The radius of the sphere. 
	//slices: The number of subdivisions around the Z axis (similar to lines of longitude). 
	//stacks: The number of subdivisions along the Z axis (similar to lines of latitude). 
	//Description: Renders a sphere centered at the modeling coordinates origin of the specified radius. 
	//			   The sphere is subdivided around the Z axis into slices and along the Z axis into stacks.

glutWireSphere(xx,200,64);

	glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0,0,0);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(0,1,0);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(1,1,0);


	glutSwapBuffers();
}






void Reshape(GLint width, GLint height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, width/(float)height,1,2000);

    w1 = width;
    h1 = height;
	glMatrixMode(GL_MODELVIEW);
}

void InitGraphics(void)
{
	glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);
}

void MouseButton(int button, int state, int x, int y)
{





}


void mouseWheel(int button, int dir, int x, int y)
{
	 if (dir > 0)
    {
        // Zoom in
		xx +=0.1f;
		cout << "Mouse Motion X value:" << xx << endl;
		cout << "Scrolled Up!" << endl;
    }
    else
    {
        // Zoom out
		xx -=0.1f;
		cout << "Mouse Motion X value:" << xx << endl;
		cout << "Scrolled Down!" << endl;
    }

   // return;
}
void MouseMotion(int x, int y)
{
	//cc = x*0.1f;
	//MouseXcoordinate = x*0.1f;

	//cout << "Mouse Motion X value:" << MouseXcoordinate << endl;


}


void IdleFunc(void)
{
	// Hier update ik alles qua graphics,
	// dan hoef ik niet elke keer op nieuw gluPostRedisplay te gebruiken.
	glutPostRedisplay();	
}

void Keyboard(unsigned char key, int x, int y)
{
		cout << key <<" Key is Pressed :)" << endl;

	switch (key)
	{
	case 27:             // ESCAPE key
		cout << "Esc Key is Pressed :)" << endl;
		exit (0);
		break;

	case 'r':			/* 114 number button number R Key */

		// maximize rotating value on pressing the R key
		a +=1;
		glutPostRedisplay();
		cout << "r Key is Pressed :)" << endl;
		
		break;

	case 116:		/* 116 number button number t Key */

		a -=1;
	
		cout << "t Key is Pressed :)" << endl;

		break;


		//camera view case statements
	case 122:  // z 
		

		zz +=1;
		
		cout << " Increase ZZ value to : " << zz << endl;
		
		break;

	case 120: // x
		zz -=1;
		
		cout << "Decrease ZZ value to : " << zz << endl;
		break;

	case 99: // c
		
		xx +=1;
		
		cout << "Increase XX value to : " << xx << endl;
		
		break;

	case 118:		//v
		xx -=1;
		
		cout << "Decrease XX value to : " << xx << endl;

		break;

	case 98:		//b
		cc +=1;
		
		cout << "Increase CC value to : " << cc << endl;

		break;

	case 110:		//n
		cc -=1;
		
		cout << "Decrease CC value to : " << cc << endl;

		break;
	case 109:		//m


		// Moves the 3D Cube Object
		cout << " M button is pressed" << endl;
		xMove +=0.1f;
		yMove -=0.1f;
		//glutPostRedisplay();

		break;
	case 'k':		//k
		cout << " M button is pressed" << endl;
		xMove -=0.1f;
		break;
	case 108:		//l

		break;
	
	//Nummeric Camera Movement Implementation

	case 56: // Number 8 UP
		cc +=0.1f;
		
		break;

	case 50: // Number 2 DOWN

		cc -=0.1f;
		
		break;

	case 52:  // Number 4 LINKS

		zz -=0.1f;
		

		break;

	case 54:   // Number 6 RIGHT
		zz +=0.1f;

		break;

		// rotate around the x axis
	case 'o':
		b +=1;
		break;

		// rotate around the y axis
	case 'p':

		c+=1;
		break;

	}


}



int main(int argc, char* argv[])
{


	glutInit (&argc, argv);
	glutInitWindowSize (1280,720);
	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow ("GLUT Andrew example");
	glutPositionWindow(500, 200);

	// Initialize OpenGL graphics state
	InitGraphics();
	// Register callbacks:
	glutDisplayFunc (Display);
	glutReshapeFunc (Reshape);
	glutKeyboardFunc (Keyboard);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutMouseWheelFunc(mouseWheel);

	glutIdleFunc (IdleFunc);
	// Turn the flow of control over to GLUT
	glutMainLoop ();
	return 0;
}


