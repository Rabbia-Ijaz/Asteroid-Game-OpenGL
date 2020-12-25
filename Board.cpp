/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>

// Asteroids board

// Note that all these enum constants from NILL onwards
// have been given numbers in increasing order
// e.g. NILL=0, and so on
// and these numbers are represented in the board array...
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK
};
// defining some utility functions...

/* board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0 } };*/



void Board::InitalizeBoard(int w, int h) {
	cout << "Initialize board" << endl;
	width = w;
	height = h;
	for (int i = 0; i < BOARD_Y - 1; ++i) {
		for (int j = 0; j < BOARD_X; ++j) {
			// can use G_BRICK, R_BRICK, or S_BRICK here
			board_array[i][j] = G_BRICK;
			//board_array[i][j] =R_BRICK;  //it will create wall of bricks on the screen

		}
	}
}
//Constructor
Board::Board(int xsize, int ysize):S() {
	cout << "Constructor board" << endl;
	cout << "Choose difficulty level of the Game: " << endl;
	cout << "3 for Easy " << endl;
	cout << "5 for Medium " << endl;
	cout << "7 for Hard " << endl;
	cout << "12 for Very Hard " << endl;
	cin >> SizeOfAsteroidsArray;
	A = new Asteroids[SizeOfAsteroidsArray];
	B = new Bullets[4];
	Lives = 3;
	Score = 0;
	HighScore = 200;
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;
	for (int i = 0; i < BOARD_Y; ++i)
		for (int j = 0; j < BOARD_X; ++j)
			board_array[i][j] = 0;
//set up board
}

void Board::Draw() {
	glColor3f(0, 0, 1);
	glPushMatrix();

	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize)) {
			//			cout <<      " " << board_array[i][j] << " " << flush;
			switch (board_array[i][j]) {
			case NILL:
				// Empty space
				break;
			case S_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[SLATE_GRAY]);
				//DrawLine(x - 10, y, x - 10 + ycellsize, y, 4, colors[BLACK]);
				break;
			case G_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
						colors[LIGHT_GREEN]);
				break;
			case R_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
				break;
			}
		}
	}
	glPopMatrix();
}
void Board::CollisionWithAsteroids()
{
	for (int i = 0; i < GetSizeOfAsteroidsArray(); ++i)
	{
		if ((Circle(GetA()[i].getAsX(), GetA()[i].getAsY(), GetS().GetShipX(), GetS().GetShipY(), GetA()[i].getAsRadius(), 20) == 'i')
			||
			(Circle(GetA()[i].getSAsX(), GetA()[i].getSAsY(), GetS().GetShipX(), GetS().GetShipY(), GetA()[i].getSAsRadius(), 20) == 'i'))
		{
			setLives(getLives() - 1);
			GetS().SetShipX(1020 / 2);
			GetS().SetShipY(840 / 2);
			GetS().SetShipAngle(90);
			GetS().SetX(510);
			GetS().SetY(420);
			GetS().SetX1(510);
			GetS().SetY1(440);
		}
	
	}
	if ((Circle(GetS().GetEnX(), GetS().GetEnY(), GetS().GetShipX(), GetS().GetShipY(), GetS().GetEnRadius(), 20) == 'i'))
	{
		setLives(getLives() - 1);
		GetS().SetShipX(1020 / 2);
		GetS().SetShipY(840 / 2);
		GetS().SetShipAngle(90);
		GetS().SetX(510);
		GetS().SetY(420);
		GetS().SetX1(510);
		GetS().SetY1(440);
	}


	
}
bool Board::BulletsFired()
{
	for (int i = 0; i < GetSizeOfAsteroidsArray(); ++i)
	{
		if (Circle(GetA()[i].getAsX(), GetA()[i].getAsY(), GetB()[0].getBuX(), GetB()[0].getBuY(), GetA()[i].getAsRadius(), 2) == 'i')

		{
			setScore(getScore() + 10);
			GetB()[0].setBuX( GetS().GetX1());
			GetB()[0].setBuY(GetS().GetY1());
			GetA()[i].setAsRadius(GetA()[i].getAsRadius() - 20);
			return true;

		}
		if (Circle(GetA()[i].getAsX(), GetA()[i].getAsY(), GetB()[1].getBuX(), GetB()[1].getBuY(), GetA()[i].getAsRadius(), 2) == 'i')

		{
			setScore(getScore() + 10);
			GetB()[1].setBuX(GetS().GetX1());
			GetB()[1].setBuY(GetS().GetY1());
			GetA()[i].setAsRadius(GetA()[i].getAsRadius() - 20);
			return true;

		}
		if (Circle(GetA()[i].getAsX(), GetA()[i].getAsY(), GetB()[2].getBuX(), GetB()[2].getBuY(), GetA()[i].getAsRadius(), 2) == 'i')

		{
			setScore(getScore() + 10);
			GetB()[2].setBuX(GetS().GetX1());
			GetB()[2].setBuY(GetS().GetY1());
			GetA()[i].setAsRadius(GetA()[i].getAsRadius() - 20);
			return true;

		}
		if
			(Circle(GetA()[i].getSAsX(), GetA()[i].getSAsY(), GetB()[0].getBuX(), GetB()[0].getBuY(), GetA()[i].getSAsRadius(), 2) == 'i')
		{
			setScore(getScore() + 10);
			GetB()[0].setBuX(GetS().GetX1());
			GetB()[0].setBuY(GetS().GetY1());
			GetA()[i].setSAsRadius(GetA()[i].getSAsRadius() - 20);
			return true;

		}
		if
			(Circle(GetA()[i].getSAsX(), GetA()[i].getSAsY(), GetB()[1].getBuX(), GetB()[1].getBuY(), GetA()[i].getSAsRadius(), 2) == 'i')
		{
			setScore(getScore() + 10);
			GetB()[1].setBuX(GetS().GetX1());
			GetB()[1].setBuY(GetS().GetY1());
			GetA()[i].setSAsRadius(GetA()[i].getSAsRadius() - 20);
			return true;

		}
		if
			(Circle(GetA()[i].getSAsX(), GetA()[i].getSAsY(), GetB()[2].getBuX(), GetB()[2].getBuY(), GetA()[i].getSAsRadius(), 2) == 'i')
		{
			setScore(getScore() + 10);
			GetB()[2].setBuX(GetS().GetX1());
			GetB()[2].setBuY(GetS().GetY1());
			GetA()[i].setSAsRadius(GetA()[i].getSAsRadius() - 20);
			return true;

		}
		if
			(Circle(GetS().GetEnX(), GetS().GetEnY(), GetB()[0].getBuX(), GetB()[0].getBuY(), 2, 30) == 'i')
		{
			setScore(getScore() + 20);
			GetB()[2].setBuX(GetS().GetX1());
			GetB()[2].setBuY(GetS().GetY1());
			GetS().SetEnRadius(0);
			return true;
		}
		if
			(Circle(GetS().GetEnX(), GetS().GetEnY(), GetB()[1].getBuX(), GetB()[1].getBuY(), 2, 30) == 'i')
		{
			setScore(getScore() + 20);
			GetB()[2].setBuX(GetS().GetX1());
			GetB()[2].setBuY(GetS().GetY1());
			GetS().SetEnRadius(0);
			return true;
		}
		if
			(Circle(GetS().GetEnX(), GetS().GetEnY(), GetB()[2].getBuX(), GetB()[2].getBuY(), 2, 30) == 'i')
		{
			setScore(getScore() + 20);
			GetB()[2].setBuX(GetS().GetX1());
			GetB()[2].setBuY(GetS().GetY1());
			GetS().SetEnRadius(0);
			return true;
		}
		
	}
	return false;
}
char Board::Circle(float x1, float y1, float x2, float y2, float r1, float r2)
{
	float d = sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
	if (d < r1 + r2)
		return 'i';
	else if (d > r1 + r2)
		return 'o';
}
void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}

bool Board::GameOver()
{
	for (int i = 0; i < GetSizeOfAsteroidsArray(); ++i)
	{
		if (GetA()[i].getAsRadius() > 0 || GetA()[i].getSAsRadius() > 0)
			return false;
	}
	setLives(0);
	return true;
}

void Board::GetInitRandomPosition(int &x, int &y) {
	// leave 10 units from all sides
	x = GetRandInRange(50, width - 50);
	y = GetRandInRange(50, height - 50);
}
int Board:: GetBoardX() {
	return BOARD_X;
}
int Board:: GetBoardY() {
	return BOARD_Y;
}
int Board::GetMidX() {
	return BOARD_X * xcellsize / 2.0;
}
int Board::GetMidY() {
	return BOARD_Y * ycellsize / 2.0;
}
int Board::GetCellSize() {
	return xcellsize;
}


int Board::GetWidth() {
	return width;
}
int Board::GetHeight() {
	return height;
}
int Board::GetSizeOfAsteroidsArray()
{
	return SizeOfAsteroidsArray;
}
Asteroids* Board::GetA()
{
	return A;
}
Ship& Board::GetS()
{
	return S;
}
Bullets * Board::GetB()
{
	return B;
}
int Board::getLives()
{
	return Lives;
}
void Board::setLives(int lives)
{
	Lives = lives;
}
int Board::getScore()
{
	return Score;
}
void Board::setScore(int score)
{
	Score = score;
}
int Board::getHighScore()
{
	return HighScore;
}
void Board::setHighScore(int highscore)
{
	HighScore = highscore;
}


// Destructor
Board::~Board()
{
	delete [] A ;
}
