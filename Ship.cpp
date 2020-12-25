/*
 * Ship.cpp
 *
 *  Created on: 08-May-2018
 *      Author: HP
 */

#include "Ship.h"

Ship::Ship() {
	ShipX=1020/2;
	ShipY=840/2;
	X = 510;
	Y = 420;
	X1 = 510;
	Y1 = 440;
	ShipAngle=90;
	EnX = (1020 / 3);
	EnY = (840 / 2) + 200;
	EnRadius = 30;
	//cout << "Constructor" << endl;

}
void Ship::ShipWrapAround()
{
	if (GetShipX() > 1020 && GetShipY() > (840 - 100)) //wrap around condition for Ship
	{
		SetShipX(0);
		SetShipY(0);
		SetX(GetShipX());
		SetY(GetShipY());
		float Tx = GetX() + 20;
		float Ty = GetY();
		SetX1(Tx);
		SetY1(Ty);

		SetX1(GetX1() - GetShipX());
		SetY1(GetY1() - GetShipY());
		float A = GetX1()*(cos(Deg2Rad(GetShipAngle()))) - GetY1()*(sin(Deg2Rad(GetShipAngle())));
		float B = GetY1()*(cos(Deg2Rad(GetShipAngle()))) + GetX1()*(sin(Deg2Rad(GetShipAngle())));
		SetX1(GetShipX() + A);
		SetY1(GetShipY() + B);
	}
	else if (GetShipX() < 0 && GetShipY() < 0)
	{
		SetShipX(1020);
		SetShipY((840 - 100));
		SetX(GetShipX());
		SetY(GetShipY());
		float Tx = GetX() + 20;
		float Ty = GetY();
		SetX1(Tx);
		SetY1(Ty);

		SetX1(GetX1() - GetShipX());
		SetY1(GetY1() - GetShipY());
		float A = GetX1()*(cos(Deg2Rad(GetShipAngle()))) - GetY1()*(sin(Deg2Rad(GetShipAngle())));
		float B = GetY1()*(cos(Deg2Rad(GetShipAngle()))) + GetX1()*(sin(Deg2Rad(GetShipAngle())));
		SetX1(GetShipX() + A);
		SetY1(GetShipY() + B);
	}
	else if (GetShipX() > 1020)
	{
		SetShipX(0);
		SetX(GetShipX());
		SetY(GetShipY());
		float Tx = GetX() + 20;
		float Ty = GetY();
		SetX1(Tx);
		SetY1(Ty);

		SetX1(GetX1() - GetShipX());
		SetY1(GetY1() - GetShipY());
		float A = GetX1()*(cos(Deg2Rad(GetShipAngle()))) - GetY1()*(sin(Deg2Rad(GetShipAngle())));
		float B = GetY1()*(cos(Deg2Rad(GetShipAngle()))) + GetX1()*(sin(Deg2Rad(GetShipAngle())));
		SetX1(GetShipX() + A);
		SetY1(GetShipY() + B);
	}
	else if (GetShipY() > (840 - 100))
	{
		SetShipY(0);
		SetX(GetShipX());
		SetY(GetShipY());
		float Tx = GetX() + 20;
		float Ty = GetY();
		SetX1(Tx);
		SetY1(Ty);

		SetX1(GetX1() - GetShipX());
		SetY1(GetY1() - GetShipY());
		float A = GetX1()*(cos(Deg2Rad(GetShipAngle()))) - GetY1()*(sin(Deg2Rad(GetShipAngle())));
		float B = GetY1()*(cos(Deg2Rad(GetShipAngle()))) + GetX1()*(sin(Deg2Rad(GetShipAngle())));
		SetX1(GetShipX() + A);
		SetY1(GetShipY() + B);
	}
	else if (GetShipX() < 0)
	{
		SetShipX(1020);
		SetX(GetShipX());
		SetY(GetShipY());
		float Tx = GetX() + 20;
		float Ty = GetY();
		SetX1(Tx);
		SetY1(Ty);

		SetX1(GetX1() - GetShipX());
		SetY1(GetY1() - GetShipY());
		float A = GetX1()*(cos(Deg2Rad(GetShipAngle()))) - GetY1()*(sin(Deg2Rad(GetShipAngle())));
		float B = GetY1()*(cos(Deg2Rad(GetShipAngle()))) + GetX1()*(sin(Deg2Rad(GetShipAngle())));
		SetX1(GetShipX() + A);
		SetY1(GetShipY() + B);
	}
	else if (GetShipY() < 0)
	{
		SetShipY((840 - 100));
		SetX(GetShipX());
		SetY(GetShipY());
		float Tx = GetX() + 20;
		float Ty = GetY();
		SetX1(Tx);
		SetY1(Ty);

		SetX1(GetX1() - GetShipX());
		SetY1(GetY1() - GetShipY());
		float A = GetX1()*(cos(Deg2Rad(GetShipAngle()))) - GetY1()*(sin(Deg2Rad(GetShipAngle())));
		float B = GetY1()*(cos(Deg2Rad(GetShipAngle()))) + GetX1()*(sin(Deg2Rad(GetShipAngle())));
		SetX1(GetShipX() + A);
		SetY1(GetShipY() + B);
	}

	if (EnX > 1020)
	  SetEnX(0);
	
}

float Ship::GetShipAngle(){
	return ShipAngle;

}

void Ship::SetShipAngle(float shipAngle) {
	ShipAngle = shipAngle;

}

float Ship::GetShipX() {
	return ShipX;

}

void Ship::SetShipX(float shipX) {
	ShipX = shipX;
	
}

float Ship::GetShipY() {
	return ShipY;
}

void Ship::SetShipY(float shipY) {
	ShipY = shipY;
}

float Ship::GetEnX()
{
	return EnX;
}
void Ship::SetEnX(float enx)
{
	EnX = enx;
}
float Ship::GetEnY()
{
	return EnY;
}
void Ship::SetEnY(float eny)
{
	EnY = eny;
}
float Ship::GetEnRadius() {
	return EnRadius;

}

void Ship::SetEnRadius(float enradius) {
	EnRadius = enradius;

}

float Ship::GetX()
{
	return X;
}
void Ship::SetX(float x)
{
	X = x;
}
float Ship::GetY()
{
	return Y;
}
void Ship::SetY(float y)
{
	Y = y;
}
float Ship::GetX1()
{
	return X1;
}
void Ship::SetX1(float x1)
{
	X1 = x1;
}
float Ship::GetY1()
{
	return Y1;
}
void Ship::SetY1(float y1)
{
	Y1 = y1;
}

float Ship::GetChX()
{
	return ChX;
}

void Ship::SetChX(float chx)
{
	ChX = chx;
}

float Ship::GetChY()
{
	return ChY;
}

void Ship::SetChY(float chy)
{
	ChY = chy;
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

