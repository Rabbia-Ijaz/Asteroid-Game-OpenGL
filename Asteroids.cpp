/*
 * Asteroids.cpp
 *
 *  Created on: 05-May-2018
 *      Author: HP
 */

#include "Asteroids.h"

Asteroids::Asteroids() {
	AsX= GetRandInRange(10, 1020 - 50);
	
	AsY= GetRandInRange(50, 840 - 100);
	
	SAsX= GetRandInRange(100, 1020 - 100);
	
	SAsY = GetRandInRange(100, 840 - 100);
	AsRadius = 60;
	SAsRadius = 40;
	// TODO Auto-generated constructor stub

}
void Asteroids::BigAsteroid(float cx, float cy,float asradius)
{
		int radius = asradius; // sample radius
		//int rndpoint = GetRandInRange(0, 9);
		int rndpoint = 7;

		int npoints = MAX(4, rndpoint);
		//cout << npoints << endl;
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
			theta = ( stheta + dtheta);
			int x2 = cx + radius * cos(Deg2Rad(theta)), y2 = cy
					+ radius * sin(Deg2Rad(theta));
			DrawLine(x1, y1, x2, y2, 1, colors[WHITE]);
			x1 = x2;
			y1 = y2;
			stheta += dtheta;
		}
		DrawLine(x1, y1, sx, sy, 1, colors[WHITE]);

}
void Asteroids::SmallAsteroid(float cx,float cy,float sasradius)
{
	int radius = sasradius; // sample radius
	int rndpoint = 8;

	int npoints = MIN(5, rndpoint);
	//cout << npoints << endl;
	int dtheta = 360 / npoints;
	// using the formula rcostheta and rsin theta;
//	float theta = GetRandInRange(0, dtheta);
	float theta = dtheta / 3+2;

	int sx = cx + radius * cos(Deg2Rad(theta+5)), sy = cy
			+ radius * sin(Deg2Rad(theta));
	int x1 = sx;
	int y1 = sy;
	int stheta = dtheta/4;
	for (int i = 0; i < npoints - 1; ++i) {
		theta =( stheta + dtheta);
		int x2 = cx + radius * cos(Deg2Rad(theta)), y2 = cy
				+ radius * sin(Deg2Rad(theta));
		DrawLine(x1, y1, x2, y2, 1, colors[WHITE]);
		x1 = x2;
		y1 = y2;
		stheta += dtheta;
	}
	DrawLine(x1, y1, sx, sy, 1, colors[WHITE]);
}

void Asteroids::DrawA()
{
	BigAsteroid(AsX, AsY,AsRadius);
	SmallAsteroid(SAsX, SAsY,SAsRadius);
}
void Asteroids::RemoveAsteroid()
{
	cout<<"**********************Asteroid Removed**********************"<<endl;
}



void Asteroids::WrapAround()
{
	if (getAsX() > 1020 && getAsY() > (840 - 100)) //wrap around condition for big asteroid 
	{
		setAsX(0);
		setAsY(0);
	}
	else if (getAsX() < 0 && getAsY() < 0)
	{
		setAsX(1020);
		setAsY((840 - 100));
	}
	else if (getAsX() > 1020)
		setAsX(0);
	else if (getAsY() > (840 - 100))
		setAsY(0);
	else if (getAsX() < 0)
		setAsX(1020);
	else if (getAsY() < 0)
		setAsY((840 - 100));

	if (getSAsX() > 1020 && getSAsY() > (840 - 100)) //wrap around condition for small asteroid
	{
		setSAsX(0);
		setSAsY(0);
	}
	else if (getSAsX() < 0 && getSAsY() < 0)
	{
		setSAsX(1020);
		setSAsY((840 - 100));
	}
	else if (getSAsX() > 1020)
		setSAsX(0);
	else if (getSAsY() > (840 - 100))
		setSAsY(0);
	else if (getSAsX() < 0)
		setSAsX(1020);
	else if (getSAsY() < 0)
		setSAsY((840 - 100));
}


//getters and setters

float Asteroids::getAsX() const {
	return AsX;
}

void Asteroids::setAsX(float asX) {
	AsX = asX;
}

float Asteroids::getAsY() const {
	return AsY;
}

void Asteroids::setAsY(float asY) {
	AsY = asY;
}
float Asteroids::getSAsX() const {
	return SAsX;
}

void Asteroids::setSAsX(float sasX) {
	SAsX = sasX;
}

float Asteroids::getSAsY() const {
	return SAsY;
}

void Asteroids::setSAsY(float sasY) {
	SAsY = sasY;
}

float Asteroids:: getAsRadius() const
{
	return AsRadius;

}
void Asteroids::setAsRadius(float asradius)
{
	AsRadius = asradius;
}
float Asteroids::getSAsRadius() const
{
	return SAsRadius;
}
void Asteroids::setSAsRadius(float sasradius)
{
	SAsRadius = sasradius;
}

Asteroids::~Asteroids() {
	// TODO Auto-generated destructor stub
}

