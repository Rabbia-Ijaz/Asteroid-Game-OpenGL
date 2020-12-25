/*
 * Board.h
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */
#ifndef _BOARD_H_
#define _BOARD_H_

#include <GL/glut.h>
#include <iostream>
#include "util.h"
#include "Ship.h"
#include"Asteroids.h"
#include"Bullets.h"
//#define WITH_TEXTURES
using namespace std;

class Board {
private:
	Asteroids* A; //Asteroid array
	int SizeOfAsteroidsArray; //size of asteroid array
	Ship S; //ship object
	Bullets* B;
    int Score; //Game Score
	int HighScore;
	int Lives; //No of Lives
	

	int xcellsize, ycellsize;
	int width, height;
	ColorNames pcolor, bcolor, gcolor;

public:
	
	static const int BOARD_X = 17;
	static const int BOARD_Y = 14;

	int board_array[BOARD_Y][BOARD_X];
	Board(int xsize = 8, int ysize = 8);
	
	
	void InitalizeBoard(int, int);
	//draw the board
	void Draw();
	char Circle(float x1, float y1, float x2, float y2, float r1, float r2); // tells if circles are colliding or not
	void CollisionWithAsteroids();
	bool BulletsFired();
	int GetSizeOfAsteroidsArray();
	void GetInitTextPosition(int &x, int &y);

	bool GameOver();
    static int GetBoardX();
	static int GetBoardY();
	int GetMidX();
	int GetMidY();
	int GetCellSize();
	void GetInitRandomPosition(int &x, int &y);
	int GetWidth();
	int GetHeight();
	Asteroids* GetA();
	Ship& GetS();
	Bullets* GetB();
	int getScore(); //getter and setter of Score
	void setScore(int score);
	int getHighScore(); //getter and setter of HighScore
	void setHighScore(int highscore);

   int getLives(); //getter setter of  no of Lives
	void setLives(int lives);
	
     ~Board();
	
};

#endif
