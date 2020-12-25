//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef AsteroidS_CPP_
#define AsteroidS_CPP_
#include "Board.h"
#include<Windows.h>
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
//int x1=510, Y1=442, x2=499 ,y2=398, x3=521, y3=398;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void DrawAsteroid(const int & cx, const int &cy, const ColorNames & cname=RED) // center of Asteroid
		{

	int radius = 60; // sample radius
	//int rndpoint = GetRandInRange(0, 9);
	int rndpoint = 7;

	int npoints = MAX(5, rndpoint);
	cout << npoints << endl;
	int dtheta = 360 / npoints;
	// using the formula rcostheta and rsin theta;
//	float theta = GetRandInRange(0, dtheta);
	float theta = dtheta / 3;

	int sx = cx + radius * cos(Deg2Rad(theta)), sy = cy
			+ radius * sin(Deg2Rad(theta));
	int x1 = sx;
	int y1 = sy;
	int stheta = dtheta;
	for (int i = 0; i < npoints - 1; ++i) {
		theta = /*GetRandInRange(stheta+ */(stheta + dtheta);
		int x2 = cx + radius * cos(Deg2Rad(theta)), y2 = cy
				+ radius * sin(Deg2Rad(theta));
		DrawLine(x1, y1, x2, y2, 3, colors[cname]);
		x1 = x2;
		y1 = y2;
		stheta += dtheta;
	}
	DrawLine(x1, y1, sx, sy, 3, colors[cname]);

}
void DrawAsteroid(int x/*starting x*/, int y/*starting y*/,
		ColorNames color/*color*/, float radius = 6/*Asteroid radius in Units*/,
		const int corners = 7/*Asteroid corners*/) {
	int ogr = 6, ogh = 7;

	glPushMatrix();
	float sx = (float) radius / ogr;
	//glTranslatef(x, y, 1);
	//glScalef(sx, 1, 1);

	// Draw Asteroid here
	const int nvertices = 722;
	GLfloat vertices[nvertices][2];
	float hdegree = M_PI / (corners / 2);
	float angle = 0;
	for (int i = 0; i < nvertices; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}

	glColor3fv(colors[color]); // set the circle color
	glBegin (GL_TRIANGLE_FAN);
	glVertex4f(x, y, 0, 1);
	for (int i = 0; i < nvertices; ++i)
		glVertex4f(x + vertices[i][0], y + vertices[i][1], 0, 1);
	glEnd();

	glPopMatrix();
}

/*
 * Main Canvas drawing function.
 * */
Board *b;
//int shipX = 1020/2, shipY = 840 / 2;

void GameDisplay()/**/ {
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors

	 
	if (b->getLives() >0 )
	{
		b->CollisionWithAsteroids();
		for (int i = 0; i < b->GetSizeOfAsteroidsArray(); ++i)
		{
			
			b->GetA()[i].DrawA();
			b->GetA()[i].WrapAround();
		}
		for (int i = 0; i < b->GetSizeOfAsteroidsArray(); ++i)
		{
			cout << "Axis of Big Asteroid " << i + 1 << " :   X= " << b->GetA()[i].getAsX() << "  Y= " << b->GetA()[i].getAsX() << endl;
			cout << "Axis of Small Asteroid " << i + 1 << " :   X= " << b->GetA()[i].getSAsX() << "  Y= " << b->GetA()[i].getSAsX() << endl;
		}
		cout << "____" << endl;
		
		b->GetS().ShipWrapAround();
		Torus2d(b->GetS().GetShipX(), b->GetS().GetShipY(), b->GetS().GetShipAngle(), 360, 20, 3, 2, colors[CYAN]); //ship
		DrawLine(b->GetS().GetX(), b->GetS().GetY(), b->GetS().GetX1(), b->GetS().GetY1(),1 ,colors[CYAN]); //tip of ship

		Torus2d(b->GetS().GetEnX(), b->GetS().GetEnY(), 90, 360, b->GetS().GetEnRadius(), 2, 4, colors[RED]); //enemyShip
		for (int i = 0; i < 3; ++i)
		{
			b->GetB()[i].BulletsWrapAround();
			DrawCircle(b->GetB()[i].getBuX(), b->GetB()[i].getBuY(), 2, colors[RED]);
			

		}



		DrawString(1020 / 2, 840 - 50, "Score: " + Num2Str(b->getScore()), colors[LIGHT_GRAY]);
		DrawString(50, 840 - 50, "Lives: " + Num2Str(b->getLives()), colors[CYAN]);



		for (int i = 0; i < b->GetSizeOfAsteroidsArray(); ++i)
		{
			b->GetA()[i].setAsX(b->GetA()[i].getAsX() - 10);
			b->GetA()[i].setAsY(b->GetA()[i].getAsY() + 10);
			b->GetA()[i].setSAsX(b->GetA()[i].getSAsX() + 10);
			b->GetA()[i].setSAsY(b->GetA()[i].getSAsY() + 10);
		}
		b->GetS().SetChX(b->GetS().GetX1() - b->GetS().GetX());
		b->GetS().SetChY(b->GetS().GetY1() - b->GetS().GetY());


		b->GetS().SetX1(b->GetS().GetChX() + b->GetS().GetX1());
		b->GetS().SetY1(b->GetS().GetChY() + b->GetS().GetY1());
		b->GetS().SetX(b->GetS().GetChX() + b->GetS().GetX());
		b->GetS().SetY(b->GetS().GetChY() + b->GetS().GetY());
		b->GetS().SetShipX(b->GetS().GetX());
		b->GetS().SetShipY(b->GetS().GetY());

		b->GetS().SetEnX(b->GetS().GetEnX()+30);
		
		for (int i = 0; i < 3; ++i)
		{
			b->GetB()[i].setBuX(b->GetS().GetX1());
			b->GetB()[i].setBuY(b->GetS().GetY1());
		}



	


	}
	
	if (b->getLives() == 0 )
	{
		DrawString((1020 / 2)-50, (840/2) + 50, "Game Over!", colors[WHITE]);
		DrawString((1020 / 2)-50, 840/2, "Your Score: " + Num2Str(b->getScore()), colors[WHITE]);
		if (b->getHighScore() > b->getScore())
		{
			DrawString((1020 / 2) - 50,( 840 / 2)-50, "Threshold: " + Num2Str(b->getHighScore()), colors[WHITE]);

		}
		else if (b->getScore() > b->getHighScore())
		{
		
			DrawString((1020 / 2) - 50, (840 / 2) - 50, "Threshold: " + Num2Str(b->getHighScore()), colors[WHITE]);
			DrawString((1020 / 2) - 100, (840 / 2) - 100, "Congratulations You crossed The Threshold !", colors[WHITE]);

		}
		else
			DrawString((1020 / 2) - 50, (840 / 2) - 50, "Threshold: " + Num2Str(b->getHighScore()), colors[WHITE]);



		
	}
	else if (b->GameOver())
	{
		DrawString((1020 / 2) - 50, (840 / 2) + 50, "Game Over!", colors[WHITE]);
		DrawString((1020 / 2) - 50, 840 / 2, "Your Score: " + Num2Str(b->getScore()), colors[WHITE]);
		if (b->getHighScore() > b->getScore())
		{
			DrawString((1020 / 2) - 50, (840 / 2) - 50, "High Score: " + Num2Str(b->getHighScore()), colors[WHITE]);

		}
		else if (b->getScore() > b->getHighScore())
		{
			b->setHighScore(b->getScore());
			DrawString((1020 / 2) - 50, (840 / 2) - 50, "High Score: " + Num2Str(b->getHighScore()), colors[WHITE]);
		}
		else
			DrawString((1020 / 2) - 50, (840 / 2) - 50, "High Score: " + Num2Str(b->getHighScore()), colors[WHITE]);
		b->setLives(0);
	}

	
		

	glutSwapBuffers(); // do not modify this line..
	Sleep(300);
	glutPostRedisplay();

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
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		

		int change = 10; //change in angle
		b->GetS().SetShipAngle(b->GetS().GetShipAngle() + change);

		b->GetS().SetX1( b->GetS().GetX1() - b->GetS().GetShipX());
		b->GetS().SetY1( b->GetS().GetY1() - b->GetS().GetShipY());
		float A	= b->GetS().GetX1()*(cos(Deg2Rad(change))) - b->GetS().GetY1()*(sin(Deg2Rad(change)));
		float B= b->GetS().GetY1()*(cos(Deg2Rad(change))) + b->GetS().GetX1()*(sin(Deg2Rad(change)));
		b->GetS().SetX1(b->GetS().GetShipX() + A);
		b->GetS().SetY1(b->GetS().GetShipY() + B);

		for (int i = 0; i < 3; ++i)
		{
			b->GetB()[i].setBuX(b->GetS().GetX1());
			b->GetB()[i].setBuY(b->GetS().GetY1());

		//	b->GetB()[i].setBuX(b->GetB()[i].getBuX());
			//b->GetB()[i].setBuY(b->GetB()[i].getBuX());
		}
	
	
		cout << "X " << b->GetS().GetX1() <<endl;
		cout << "Y " << b->GetS().GetY1() <<endl;
		


		

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {


		int change = -10; //change in angle
		b->GetS().SetShipAngle(b->GetS().GetShipAngle() + change);

		b->GetS().SetX1(b->GetS().GetX1() - b->GetS().GetShipX());
		b->GetS().SetY1(b->GetS().GetY1() - b->GetS().GetShipY());
		float A = b->GetS().GetX1()*(cos(Deg2Rad(change))) - b->GetS().GetY1()*(sin(Deg2Rad(change)));
		float B = b->GetS().GetY1()*(cos(Deg2Rad(change))) + b->GetS().GetX1()*(sin(Deg2Rad(change)));
		b->GetS().SetX1(b->GetS().GetShipX() + A);
		b->GetS().SetY1(b->GetS().GetShipY() + B);
	
		for (int i = 0; i < 3; ++i)
		{
			b->GetB()[i].setBuX(b->GetS().GetX1());
			b->GetB()[i].setBuY(b->GetS().GetY1());

		//	b->GetB()[i].setBuX(b->GetB()[i].getBuX());
			//b->GetB()[i].setBuY(b->GetB()[i].getBuX());
		}

		cout << "X " << b->GetS().GetX1() << endl;
		cout << "Y " << b->GetS().GetY1() << endl;
		
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		
		b->GetS().SetChX ( b->GetS().GetX1() - b->GetS().GetX());
		b->GetS().SetChY (b->GetS().GetY1() - b->GetS().GetY());

		
		b->GetS().SetX1(b->GetS().GetChX() + b->GetS().GetX1());
		b->GetS().SetY1(b->GetS().GetChY() + b->GetS().GetY1());
		b->GetS().SetX(b->GetS().GetChX() + b->GetS().GetX());
		b->GetS().SetY(b->GetS().GetChY() + b->GetS().GetY());
		b->GetS().SetShipX(b->GetS().GetX());
		b->GetS().SetShipY(b->GetS().GetY());
	

		for (int i = 0; i < 3; ++i)
		{
			b->GetB()[i].setBuX(b->GetS().GetX1());
			b->GetB()[i].setBuY(b->GetS().GetY1());

		//	b->GetB()[i].setBuX(b->GetB()[i].getBuX());
			//b->GetB()[i].setBuY(b->GetB()[i].getBuX());
		}

	}


	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		b->GetS().SetChX(b->GetS().GetX() - b->GetS().GetX1());
		b->GetS().SetChY(b->GetS().GetY() - b->GetS().GetY1());


		b->GetS().SetX1(b->GetS().GetChX() + b->GetS().GetX1());
		b->GetS().SetY1(b->GetS().GetChY() + b->GetS().GetY1());
		b->GetS().SetX(b->GetS().GetChX() + b->GetS().GetX());
		b->GetS().SetY(b->GetS().GetChY() + b->GetS().GetY());
		b->GetS().SetShipX(b->GetS().GetX());
		b->GetS().SetShipY(b->GetS().GetY());

		for (int i = 0; i < 3; ++i)
		{
			b->GetB()[i].setBuX(b->GetS().GetX1());
			b->GetB()[i].setBuY(b->GetS().GetY1());

			//b->GetB()[i].setBuX(b->GetB()[i].getBuX());
			//b->GetB()[i].setBuY(b->GetB()[i].getBuX());
		}
	
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
	

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		{
			float CX0 = (b->GetB()[0].getBuX() - b->GetS().GetX() );
			float CY0 = (b->GetB()[0].getBuY() - b->GetS().GetY() );


			b->GetB()[0].setBuX((CX0 + b->GetB()[0].getBuX()));
			b->GetB()[0].setBuY((CY0 + b->GetB()[0].getBuY()));

			b->GetB()[1].setBuX(2*CX0 + b->GetB()[1].getBuX());
			b->GetB()[1].setBuY(2*CY0 + b->GetB()[1].getBuY());

			b->GetB()[2].setBuX(4*CX0 + b->GetB()[2].getBuX());
			b->GetB()[2].setBuY(4*CY0 + b->GetB()[2].getBuY());
			if (b->BulletsFired()) { cout << "YASS" << endl; }
			glutPostRedisplay();

		}
		
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	/*for (int i = 0; i < b->GetSizeOfAsteroidsArray(); ++i)
	{
		b->GetA()[i].setAsX(b->GetA()[i].getAsX() - 10);
		b->GetA()[i].setAsY(b->GetA()[i].getAsY() + 10);
		b->GetA()[i].setSAsX(b->GetA()[i].getSAsX() + 10);
		b->GetA()[i].setSAsY(b->GetA()[i].getSAsY() +10 );
	}
	

    b->GetS().SetChX(b->GetS().GetX1() - b->GetS().GetX());
	b->GetS().SetChY(b->GetS().GetY1() - b->GetS().GetY());


	b->GetS().SetX1(b->GetS().GetChX() + b->GetS().GetX1());
	b->GetS().SetY1(b->GetS().GetChY() + b->GetS().GetY1());
	b->GetS().SetX(b->GetS().GetChX() + b->GetS().GetX());
	b->GetS().SetY(b->GetS().GetChY() + b->GetS().GetY());
	b->GetS().SetShipX(b->GetS().GetX());
	b->GetS().SetShipY(b->GetS().GetY());*/

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 2);
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	//glutPostRedisplay();
	//delete b->GetA();
	//glutPostRedisplay();

}
void MouseMoved(int x, int y) {
	//delete b->GetA();
	//glutPostRedisplay();
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
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	//glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...
	
	//b->GetInitRandomPosition(X, Y);
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Asteroid"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	//glutMouseFunc(MouseClicked);
	//glutPassiveMotionFunc(MouseMoved); // Mouse
	//glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
