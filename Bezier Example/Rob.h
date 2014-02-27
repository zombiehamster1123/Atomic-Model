#ifndef ROB_H
#define ROB_H

#include <stdlib.h>
#include <crtdbg.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <cstdio>

#pragma region
//Boolean that determines if you are on the Menu Screen
bool menu = true;
//Boolean that determines if you are on the Game Screen
bool toot;
//Boolean that determines if you are on the Selection Screen
bool selector;

//These are variables designed to draw the atom code I have, but you don't need them
float angle = 0.9;
float rotated = 15;
float x = -.2;
float y = 0.0;
float position1 = 0.0;
float position2 = 1.0;

//The following are the variables used to perform the element selection process
int selected = 1;
char* atomicSymbol;
char* nameOfElement;
char* charSelected;
int typeOfElement;
char* eGroup;

//These are the booleans that light up the arrows on the selection screen
bool rightLight;
bool leftLight;
#pragma endregion Global Variables
//This is a setup function that was present in the example code I based the drawings on
void setup()
{
	glFlush();
	glutSwapBuffers();
}

//This function is designed to write text to the screen, at a position you pass in
void writeText(char* urString, float x, float y, float z, float spacing)
{
	char *a= urString;
	for(int i = 0; a[i] != '\0'; i++)
	{
		glColor3f(0.0,0.0,0.0);
		glRasterPos3f(x + spacing*i , y ,z);
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , a[i]);
	}
}

//This method draws the right arrow, and is identical to the left arrow draw method
void drawRightArrow(float x, float y)
{
	//Drawing the Right arrow
	glBegin(GL_POLYGON);
	//Makes sure the arrow is lit up properly
	if(rightLight == true)
	{
		glColor3f(1.0,0,0);
	}
	else
	{
		glColor3f(0.0,1.0,0);
	}
	//Draws the arrow
	glVertex3f(x, y, -0.1 );
	glVertex3f(x, y - .05, -0.1 );
	glVertex3f(x + .1,  y, -0.1 );
	glVertex3f(x, y + .05, -0.1 );
	glVertex3f(x, y, -0.1 );
	glEnd();
}
void drawLeftArrow(float x, float y)
{
	//Drawing the Right arrow
	glBegin(GL_POLYGON);
	if(leftLight == true)
	{
		glColor3f(1.0,0,0);
	}
	else
	{
		glColor3f(0.0,1.0,0);
	}
	glVertex3f(x, y, -0.1 );
	glVertex3f(x, y - .05, -0.1 );
	glVertex3f(x - .1,  y, -0.1 );
	glVertex3f(x, y + .05, -0.1 );
	glVertex3f(x, y, -0.1 );
	glEnd();
}

//Not important
float drawElectron(int ring, float velocity, float angle)
{
	float xPos = ring * .1;
	x = xPos* cos(angle);
	y = xPos* sin(angle);
	glColor3f(0.0,0.0,1.0);
	glTranslatef(x,y,0.0);
	glutSolidSphere(.03,100,100);
	position1 += velocity;
	position2 += velocity;
	return angle;
}

#pragma region
//This is the element selector method
void selectElement()
{
	switch (selected)
	{
	case 1: 
		atomicSymbol = "H";
		nameOfElement = "Hydrogen";
		typeOfElement = 0;
		break;
	case 2: 
		atomicSymbol = "He";
		nameOfElement = "Helium";
		typeOfElement = 3;
		break;
	case 3: 
		atomicSymbol = "Li";
		nameOfElement = "Lithium";
		typeOfElement = 1;
		break;
	case 4: 
		atomicSymbol = "Be";
		nameOfElement = "Beryllium";
		typeOfElement = 2;
		break;
	case 5: 
		atomicSymbol = "B";
		nameOfElement = "Boron";
		typeOfElement = 6;
		break;
	case 6: 
		atomicSymbol = "C";
		nameOfElement = "Carbon";
		break;
	case 7: 
		atomicSymbol = "N";
		nameOfElement = "Nitrogen";
		break;
	case 8: 
		atomicSymbol = "O";
		nameOfElement = "Oxygen";
		break;
	case 9: 
		atomicSymbol = "F";
		nameOfElement = "Fluorine";
		typeOfElement = 6;
		break;
	case 10: 
		atomicSymbol = "Ne";
		nameOfElement = "Neon";
		typeOfElement = 3;
		break;
	case 11: 
		atomicSymbol = "Na";
		nameOfElement = "Sodium";
		typeOfElement = 1;
		break;
	case 12: 
		atomicSymbol = "Mg";
		nameOfElement = "Magnesium";
		typeOfElement = 2;
		break;
	case 13: 
		atomicSymbol = "Al";
		nameOfElement = "Aluminium";
		typeOfElement = 5;
		break;
	case 14: 
		atomicSymbol = "Si";
		nameOfElement = "Silicon";
		typeOfElement = 6;
		break;
	case 15: 
		atomicSymbol = "P";
		nameOfElement = "Phosphorus";
		break;
	case 16: 
		atomicSymbol = "S";
		nameOfElement = "Sulfur";
		break;
	case 17: 
		atomicSymbol = "Cl";
		nameOfElement = "Chlorine";
		typeOfElement = 6;
		break;
	case 18: 
		atomicSymbol = "Ar";
		nameOfElement = "Argon";
		typeOfElement = 3;
		break;
	case 19: 
		atomicSymbol = "K";
		nameOfElement = "Potassium";
		break;
	case 20: 
		atomicSymbol = "Ca";
		nameOfElement = "Calcium";
		break;
	case 21: 
		atomicSymbol = "Sc";
		nameOfElement = "Scandium";
		typeOfElement = 4;
		break;
	case 22: 
		atomicSymbol = "Ti";
		nameOfElement = "Titanium";
		break;
	case 23: 
		atomicSymbol = "V";
		nameOfElement = "Vanadium";
		break;
	case 24: 
		atomicSymbol = "Cr";
		nameOfElement = "Chromium";
		break;
	case 25: 
		atomicSymbol = "Mn";
		nameOfElement = "Manganese";
		break;
	case 26: 
		atomicSymbol = "Fe";
		nameOfElement = "Iron";
		break;
	case 27: 
		atomicSymbol = "Co";
		nameOfElement = "Cobalt";
		break;
	case 28: 
		atomicSymbol = "Ni";
		nameOfElement = "Nickel";
		break;
	case 29: 
		atomicSymbol = "Cu";
		nameOfElement = "Copper";
		typeOfElement = 4;
		break;
	case 30: 
		atomicSymbol = "Zn";
		nameOfElement = "Zinc";
		typeOfElement = 5;
		break;
	case 31: 
		atomicSymbol = "Ga";
		nameOfElement = "Galium";
		break;
	case 32: 
		atomicSymbol = "Ge";
		nameOfElement = "Germanium";
		typeOfElement = 5;
		break;
	case 33: 
		atomicSymbol = "As";
		nameOfElement = "Arsenic";
		typeOfElement = 6;
		break;
	case 34: 
		atomicSymbol = "Se";
		nameOfElement = "Selenium";
		break;
	case 35: 
		atomicSymbol = "Br";
		nameOfElement = "Bromine";
		typeOfElement = 6;
		break;
	case 36: 
		atomicSymbol = "Kr";
		nameOfElement = "Krypton";
		typeOfElement = 3;
		break;
	case 37: 
		atomicSymbol = "Rb";
		nameOfElement = "Rubidium";
		typeOfElement = 1;
		break;
	case 38: 
		atomicSymbol = "Sr";
		nameOfElement = "Stronium";
		typeOfElement = 2;
		break;
	case 39: 
		atomicSymbol = "Y";
		nameOfElement = "Yttrium";
		typeOfElement = 4;
		break;
	case 40: 
		atomicSymbol = "Zr";
		nameOfElement = "Zirconium";
		break;
	case 41: 
		atomicSymbol = "Nb";
		nameOfElement = "Niobium";
		break;
	case 42: 
		atomicSymbol = "Mo";
		nameOfElement = "Molybdenum";
		break;
	case 43: 
		atomicSymbol = "Tc";
		nameOfElement = "Technetium";
		break;
	case 44: 
		atomicSymbol = "Ru";
		nameOfElement = "Ruthenium";
		break;
	case 45: 
		atomicSymbol = "Rh";
		nameOfElement = "Rhodium";
		break;
	case 46: 
		atomicSymbol = "Pd";
		nameOfElement = "Palladium";
		break;
	case 47: 
		atomicSymbol = "Ag";
		nameOfElement = "Silver";
		typeOfElement = 4;
		break;
	case 48: 
		atomicSymbol = "Cd";
		nameOfElement = "Cadmium";
		typeOfElement = 5;
		break;
	case 49: 
		atomicSymbol = "In";
		nameOfElement = "Indium";
		break;
	case 50: 
		atomicSymbol = "Sn";
		nameOfElement = "Tin";
		break;
	case 51: 
		atomicSymbol = "Sb";
		nameOfElement = "Antimony";
		typeOfElement = 5;
		break;
	case 52: 
		atomicSymbol = "Te";
		nameOfElement = "Tellurium";
		typeOfElement = 6;
		break;
	case 53: 
		atomicSymbol = "I";
		nameOfElement = "Iodine";
		typeOfElement = 6;
		break;
	case 54: 
		atomicSymbol = "Xe";
		nameOfElement = "Xenon";
		typeOfElement = 3;
		break;
	case 55: 
		atomicSymbol = "Cs";
		nameOfElement = "Ceasium";
		typeOfElement = 1;
		break;
	case 56: 
		atomicSymbol = "Ba";
		nameOfElement = "Barium";
		typeOfElement = 2;
		break;
	case 57: 
		atomicSymbol = "La";
		nameOfElement = "Lanthanum";
		typeOfElement = 7;
		break;
	case 58: 
		atomicSymbol = "Ce";
		nameOfElement = "Cerium";
		break;
	case 59: 
		atomicSymbol = "Pr";
		nameOfElement = "Praseodymium";
		break;
	case 60: 
		atomicSymbol = "Nd";
		nameOfElement = "Neodymium";
		break;
	case 61: 
		atomicSymbol = "Pm";
		nameOfElement = "Prometheum";
		break;
	case 62: 
		atomicSymbol = "Sm";
		nameOfElement = "Samarium";
		break;
	case 63: 
		atomicSymbol = "Eu";
		nameOfElement = "Europium";
		break;
	case 64: 
		atomicSymbol = "Gd";
		nameOfElement = "Gadolinium";
		break;
	case 65: 
		atomicSymbol = "Tb";
		nameOfElement = "Terbium";
		break;
	case 66: 
		atomicSymbol = "Dy";
		nameOfElement = "Dysporsium";
		break;
	case 67: 
		atomicSymbol = "Ho";
		nameOfElement = "Holmium";
		break;
	case 68: 
		atomicSymbol = "Er";
		nameOfElement = "Erbium";
		break;
	case 69: 
		atomicSymbol = "Tm";
		nameOfElement = "Thullium";
		break;
	case 70: 
		atomicSymbol = "Yb";
		nameOfElement = "Ytterbium";
		break;
	case 71: 
		atomicSymbol = "Lu";
		nameOfElement = "Lutetium";
		typeOfElement = 7;
		break;
	case 72: 
		atomicSymbol = "Hf";
		nameOfElement = "Hafnium";
		typeOfElement = 4;
		break;
	case 73: 
		atomicSymbol = "Ta";
		nameOfElement = "Tantalum";
		break;
	case 74: 
		atomicSymbol = "W";
		nameOfElement = "Tungsten";
		break;
	case 75: 
		atomicSymbol = "Re";
		nameOfElement = "Rhenium";
		break;
	case 76: 
		atomicSymbol = "Os";
		nameOfElement = "Osmium";
		break;
	case 77: 
		atomicSymbol = "Ir";
		nameOfElement = "Iridium";
		break;
	case 78: 
		atomicSymbol = "Pt";
		nameOfElement = "Platinum";
		break;
	case 79: 
		atomicSymbol = "Au";
		nameOfElement = "Gold";
		typeOfElement = 4;
		break;
	case 80: 
		atomicSymbol = "Hg";
		nameOfElement = "Mercury";
		typeOfElement = 5;
		break;
	case 81: 
		atomicSymbol = "Ti";
		nameOfElement = "Thallium";
		break;
	case 82: 
		atomicSymbol = "Pb";
		nameOfElement = "Lead";
		break;
	case 83: 
		atomicSymbol = "Bi";
		nameOfElement = "Bismuth";
		break;
	case 84: 
		atomicSymbol = "Po";
		nameOfElement = "Polonium";
		typeOfElement = 5;
		break;
	case 85: 
		atomicSymbol = "At";
		nameOfElement = "Astatine";
		typeOfElement = 6;
		break;
	case 86: 
		atomicSymbol = "Rn";
		nameOfElement = "Radon";
		typeOfElement = 3;
		break;
	case 87: 
		atomicSymbol = "Fr";
		nameOfElement = "Francium";
		typeOfElement = 1;
		break;
	case 88: 
		atomicSymbol = "Ra";
		nameOfElement = "Radium";
		typeOfElement = 2;
		break;
	case 89: 
		atomicSymbol = "Ac";
		nameOfElement = "Actinum";
		typeOfElement = 8;
		break;
	case 90: 
		atomicSymbol = "Th";
		nameOfElement = "Thorium";
		break;
	case 91: 
		atomicSymbol = "Pa";
		nameOfElement = "Protactinium";
		break;
	case 92: 
		atomicSymbol = "U";
		nameOfElement = "Uranium";
		break;
	case 93: 
		atomicSymbol = "Np";
		nameOfElement = "Neptunium";
		break;
	case 94: 
		atomicSymbol = "Pu";
		nameOfElement = "Plutonium";
		break;
	case 95: 
		atomicSymbol = "Am";
		nameOfElement = "Americium";
		break;
	case 96: 
		atomicSymbol = "Cm";
		nameOfElement = "Curium";
		break;
	case 97: 
		atomicSymbol = "Bk";
		nameOfElement = "Berkelium";
		break;
	case 98: 
		atomicSymbol = "Cf";
		nameOfElement = "Californium";
		break;
	case 99: 
		atomicSymbol = "Es";
		nameOfElement = "Einsteinium";
		break;
	case 100: 
		atomicSymbol = "Fm";
		nameOfElement = "Fermium";
		break;
	case 101: 
		atomicSymbol = "Md";
		nameOfElement = "Mendelium";
		break;
	case 102: 
		atomicSymbol = "No";
		nameOfElement = "Nobelium";
		break;
	case 103: 
		atomicSymbol = "Lr";
		nameOfElement = "Lawrencium";
		typeOfElement = 8;
		break;
	case 104: 
		atomicSymbol = "Rf";
		nameOfElement = "Rutherforium";
		typeOfElement = 4;
		break;
	case 105: 
		atomicSymbol = "Db";
		nameOfElement = "Dubnium";
		break;
	case 106: 
		atomicSymbol = "Sg";
		nameOfElement = "Seaborgium";
		break;
	case 107: 
		atomicSymbol = "Bh";
		nameOfElement = "Bohrium";
		break;
	case 108: 
		atomicSymbol = "Hs";
		nameOfElement = "Hassium";
		break;
	case 109: 
		atomicSymbol = "Mt";
		nameOfElement = "Meitnerium";
		break;
	case 110: 
		atomicSymbol = "Ds";
		nameOfElement = "Darmstadtium";
		break;
	case 111: 
		atomicSymbol = "Rg";
		nameOfElement = "Roentgenium";
		typeOfElement = 4;
		break;
	case 112: 
		atomicSymbol = "Uub";
		nameOfElement = "Unubium";
		typeOfElement = 5;
		break;
	case 113: 
		atomicSymbol = "Uut";
		nameOfElement = "Ununtrium";
		break;
	case 114: 
		atomicSymbol = "Uuq";
		nameOfElement = "Ununquadium";
		break;
	case 115: 
		atomicSymbol = "Uup";
		nameOfElement = "Ununpentium";
		break;
	case 116: 
		atomicSymbol = "Uus";
		nameOfElement = "Ununseptium";
		break;
	case 117: 
		atomicSymbol = "Uuh";
		nameOfElement = "Ununhexium";
		typeOfElement = 5;
		break;
	case 118: 
		atomicSymbol = "Uu0";
		nameOfElement = "Ununoctium";
		typeOfElement = 3;
		break;
	default:
		break;
	}
}
#pragma endregion Element Selector

//This is the method which draws the element selector screen
void drawElement()
{
	//Color of the atomic picture background
	float r;
	float g;
	float b;
	//Element color and type switch
	switch(typeOfElement)
	{
		//Hydrogen
	case 0: 
		r = .2;
		g = .2;
		b = .2;
		eGroup = "Hydrogen";
		break;
		//Alkali Metals
	case 1:
		r = 1.0;
		g = .647;
		b = 0;
		eGroup = "Alkali Metals";
		break;
		//Alkaline Earth Metals
	case 2:
		r = 1.0;
		g = 1.0;
		b = 0;
		eGroup = "Alkaline Earth Metals";
		break;
		//Noble Gasses
	case 3:
		r = .27;
		g = .5;
		b = .7;
		eGroup = "Noble Gasses";
		break;
		//Transition Metals
	case 4:
		r = 1;
		g = .48;
		b = .3;
		eGroup = "Transition Metals";
		break;
		//Poor Metals
	case 5:
		r = 0.0;
		g = .48;
		b = .4;
		eGroup = "Poor Metals";
		break;
		//Other Nonmetals
	case 6:
		r = .5;
		g = 1.0;
		b = .5;
		eGroup = "Other NonMetals";
		break;
		//Lanthanoids
	case 7:
		r = 1.0;
		g = .5;
		b = .5;
		eGroup = "Lanthanoids";
		break;
		//Actinoids
	case 8:
		r = 1.0;
		g = .5;
		b = 1.0;
		eGroup = "Actinoids";
		break;
	}

	selectElement();
	glPushMatrix();
	//Drawing the background
	glBegin(GL_POLYGON);
	glColor3f(.7,.7,.7);
	glVertex3f(  1, -1, 0.1 );
	glVertex3f(  1,  1, 0.1 );
	glVertex3f( -1,  1, 0.1 );
	glVertex3f( -1, -1, 0.1 );
	glEnd();
	//Drawing the element box
	glBegin(GL_POLYGON);
	glColor3f(r,g,b);
	glVertex3f(  .1, -.1, -0.1 );
	glVertex3f(  .1,  .1, -0.1 );
	glVertex3f( -.1,  .1, -0.1 );
	glVertex3f( -.1, -.1, -0.1 );
	glEnd();
	//Arrows
	drawRightArrow(.3,.1);
	drawLeftArrow(-.3,.1);
	//All of the writing on the selection screen
	glColor3f(0,0,0);
	char selChar[12];
	int num = selected;
	sprintf_s(selChar, "%d", num);
	//charSelected = selChar;
	//sprintf(charSelected, "%d", selected);
	//writeText(charSelected,-.1,.1,-.2,.05);
	writeText(atomicSymbol,0,0,-.2,.03);
	writeText(nameOfElement,-.14,-.14,-.2,.05);
	writeText(eGroup,-.3,-.2,-.2,.05);
	writeText("Periodic Table Selection Screen",-.7,.9,-.2,.05);
	writeText("(Press the Left and Right Keys",-.9,.8,-.2,.05);
	writeText("then hit space to view the atom)",-.9,.7,-.2,.05);

	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
//Not important since it's a placeholder for your code
void drawAtom()
{
	//glRotatef(5.0,0.0,0.0,15.0);

	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	glutSolidSphere(.1,100,100);
	drawElectron(2,0.1,position1);
	drawElectron(4,0.0,position2);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	angle += .1;
}
//This creates a background thing that is the size of the screen, although I'd say your screen is probably a different size
void createBG(float r, float g, float b)
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f( r, g, b);
	glVertex3f(  1, -1, 0.0 );
	glVertex3f(  1,  1, 0.0 );
	glVertex3f( -1,  1, 0.0 );
	glVertex3f( -1, -1, 0.0 );
	glEnd();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
// ----------------------------------------------------------
// display() is where the code to actually draw our application gets called
// ----------------------------------------------------------
void Robdisplay(){
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//This if statement is what determines the type of screen you're supposed to be seeing
	if(menu == true)
	{
		writeText("Atomic Model Project",-.5,.2,0,.05);
		writeText("By Rob Clifford and Ryan Russell",-.8,.1,0,.05);
		writeText("(Press Space to Start)",-.55,0,0,.05);
		createBG(.5,.5,.5);
	}
	else if(toot == true)
	{
		drawAtom();
	}
	else if(selector == true)
	{
		drawElement();
	}
	glutPostRedisplay();
}


//Special keys makes sure that you are able to do things with the arrow keys
void RobspecialKeys( int key, int x, int y ) {

	if(key == GLUT_KEY_F1)
	{
		exit( EXIT_SUCCESS );
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		rightLight = true;
		leftLight = false;
		if(selected + 1 <= 118)
		{
			selected += 1;
		}
	}
	else if(key == GLUT_KEY_LEFT)
	{
		rightLight = false;
		leftLight = true;
		if(selected - 1 >= 1)
		{
			selected -= 1;
		}
	}
	else if(key == GLUT_KEY_UP)
	{
	}
	else if(key == GLUT_KEY_DOWN)
	{
	}
	else
	{
		rightLight = false;
		leftLight = false;
	}
	//  Request display update
	glutPostRedisplay();
}

//This is a function that checks for a key press
void RobkeyPress(unsigned char key, int x, int y)
{
	if(key == ' ')
	{
		if(menu == true)
		{
			toot = false;
			menu = false;
			selector = true;
		}

		else if(toot == true)
		{
			menu = false;
			toot = false;
			selector = true;
		}
		else if(selector == true)
		{
			toot = true;
			selector = false;
			menu = false;
		}
	}
}

//This method checks to see if the Keys that control the toot are up
void RobkeyUp (unsigned char key, int x, int y) 
{  

}  

void RobWindow()
{
	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900,900);
	// Create window
	glutCreateWindow("Atomic Model");
	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);
	// Callback functions
	glutDisplayFunc(Robdisplay);
	glutSpecialFunc(RobspecialKeys);
	glutKeyboardFunc(RobkeyPress);
	glutKeyboardUpFunc(RobkeyUp);
	//  Pass control to GLUT for events
	glutMainLoop();
}

#endif