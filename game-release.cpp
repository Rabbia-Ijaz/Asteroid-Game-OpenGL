//============================================================================
// Name        : bubble-shooter.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Bubble Shooting...
//============================================================================
#ifndef BUBBLE_SHOOTER_CPP
#define BUBBLE_SHOOTER_CPP

//#include <GL/gl.h>
//#include <GL/glut.h>
#include <iostream>
#include<string>
#include<cmath>
#include "util.h"
using namespace std;
#define MAX(A,B) ((A) > (B) ? (A):(B)) // defining single line functions....
#define MIN(A,B) ((A) < (B) ? (A):(B))
#define ABS(A) ((A) < (0) ? -(A):(A))
#define FPS 30

#define KEY_ESC 27 // A

// 20,30,30
const int bradius = 25; // ball radius in pixels...

int width = 800, height = 600; // i have set my window size to be 800 x 600
int dball = 0; // difference between balls center of 5 pixels
int byoffset = 3 * bradius + dball; // board yoffset

float score = 0;

/*
 * Main Canvas drawing function.
 * */

int setcolor, psetcolor;
enum GameState { // Use to check different states of game...
	Ready, Shot, Over, RemoveCluster
};
GameState gamestate = Ready;

int neighbors[][6][2] = { { { 0, 1 }, { 0, -1 }, { -1, -1 }, { -1, 0 },
		{ 1, -1 }, { 1, 0 } }, // Even row tiles
		{ { 0, 1 }, { 0, -1 }, { -1, 0 }, { -1, 1 }, { 1, 0 }, { 1, 1 } } }; // Odd row tiles

// Function returns a random number from following set [0,10,20,30,40,50,60,70]
// Replace 8 with smaller number if you want small set...
int GetColor() {
	return GetRandInRange(1, 8) * 10;
}
// Cacluate L2 distance between two points...
float Distance(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void Pixels2Cell(int px, int py, int & cx, int &cy)
// converts the Pixel coordinates to cell coordinates...
		{

}
void Cell2Pixels(int cx, int cy, int & px, int &py)
// converts the cell coordinates to pixel coordinates...
		{
}

void Display()/**/{
// set the background color using function glClearColor.
// to change the background play with the red, green and blue values below.
// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1.0/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors

// #----------------- Write your code here ----------------------------#
//write your drawing commands here or call your drawing functions...

	DrawRectangle((width - 30) / 2, 500, 10, 30, colors[GREEN_YELLOW]);
	DrawCircle(width / 2, height / 2, 50, colors[ORANGE_RED]);

	DrawString(5, 5, "Score " + Num2Str(score), colors[BLUE_VIOLET]);

// #----------------- Write your code till here ----------------------------#
	// do not modify below this
	glutSwapBuffers(); // do not modify this line..
}
/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
// what to do when left key is pressed...

	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	} else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */

void MouseMoved(int x, int y) {

	cout << "Current Mouse Coordinates X=" << x << " Y= " << height - y<< endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{

		if (state == GLUT_DOWN && gamestate == Ready) {
			cout << "Left Mouse Button Pressed at Coordinates X=" << x << " Y= "
					<< height - y<<endl;
		}

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == KEY_ESC/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
float dt = 0, lastframe = 0;
void Timer(int m) {
	dt = (m - lastframe) / 1000.0;
	lastframe = m;

	// dt is time elapsed between two frames..

	// Do not modify this line...
	glutTimerFunc(1000.0 / FPS, Timer, m + 1);
}

/*
 * our gateway main function
 * */

int main(int argc, char*argv[]) {
	InitRandomizer(); // seed the random number generator...
	setcolor = GetColor();
	glutInit(&argc, argv); // initialize the graphics library...

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("ITCs Ballon Bursting"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
	glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse

// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0 / FPS, Timer, 0);

// now handle the control to library and it will call our registered functions when
// it deems necessary...
	glutMainLoop();

	return 1;
}
#endif /* */
