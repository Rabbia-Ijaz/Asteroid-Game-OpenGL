/*
 * Ship.h
 *
 *  Created on: 08-May-2018
 *      Author: HP
 */

#ifndef SHIP_H_
#define SHIP_H_
#include"util.h"
#include<iostream>
using namespace std;

class Ship {
	float ShipX; //ship coordinates
	float ShipY;

	float EnX;
	float EnY;
	float EnRadius;

	float X ; // ship's tip line
	float Y ;
	float X1 ;
	float Y1 ;

	float ChX; //Change in coordinates of ship's tip line
	float ChY;
	float ShipAngle;

public:
	Ship();
	void ShipWrapAround(); //wrap around for ship
	virtual ~Ship();
	float GetShipAngle() ;
	void SetShipAngle(float shipAngle);
	float GetShipX() ;
	void SetShipX(float shipX);
	float GetShipY();
	void SetShipY(float shipY);

	float GetEnX();
	void SetEnX(float enx);
	float GetEnY();
	void SetEnY(float eny);
	float GetEnRadius();
	void SetEnRadius(float enradius);

	float GetX();
	void SetX(float x);
	float GetY();
	void SetY(float y);
	float GetX1();
	void SetX1(float x1);
	float GetY1();
	void SetY1(float y1);

	float GetChX();
	void SetChX(float chx);
	float GetChY();
	void SetChY(float chy);
};

#endif /* SHIP_H_ */
