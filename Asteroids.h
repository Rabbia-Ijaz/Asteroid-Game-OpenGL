/*
 * Asteroids.h
 *
 *  Created on: 05-May-2018
 *      Author: HP
 */

#ifndef ASTEROIDS_H_
#define ASTEROIDS_H_
#include <iostream>
#include "util.h"
using namespace std;
class Asteroids {
	float AsX; //Big Asteroids
	float AsY;
	float AsRadius;
	float SAsX; //Small asteroids
	float SAsY;
	float SAsRadius;
public:
	Asteroids();
	void SmallAsteroid(float cx, float cy, float asradius); 
	void BigAsteroid(float cx, float cy,float sasradius);
	void DrawA(); // Draw function to draw big and small Asteroids
	void RemoveAsteroid();
	void WrapAround(); //Wrap around for Asteroids

   float getAsX() const;
	void setAsX(float asX);
	float getAsY() const;
	void setAsY(float asY);
	float getSAsX() const;
	void setSAsX(float asX);
	float getSAsY() const;
	void setSAsY(float asY);
	float getAsRadius() const;
	void setAsRadius(float asradius);
	float getSAsRadius() const;
	void setSAsRadius(float sasradius);
	virtual ~Asteroids();
};

#endif /* ASTEROIDS_H_ */
