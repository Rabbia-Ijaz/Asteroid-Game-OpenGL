/*
 * Bullets.cpp
 *
 *  Created on: 10-May-2018
 *      Author: HP
 */

#include "Bullets.h"

Bullets::Bullets() {
	BuX=1020/2;
	BuY=440;
	// TODO Auto-generated constructor stub

}
void Bullets::BulletsWrapAround()
{
	if (getBuX() > 1020 && getBuY() > (840 - 100)) //wrap around condition for big asteroid 
	{
		setBuX(0);
		setBuY(0);
	}
	else if (getBuX() < 0 && getBuY() < 0)
	{
		setBuX(1020);
		setBuY((840 - 100));
	}
	else if (getBuX() > 1020)
		setBuX(0);
	else if (getBuY() > (840 - 100))
		setBuY(0);
	else if (getBuX() < 0)
		setBuX(1020);
	else if (getBuY() < 0)
		setBuY((840 - 100));
}
float Bullets::getBuX() const {
	return BuX;
}

void Bullets::setBuX(float buX) {
	BuX = buX;
}

float Bullets::getBuY() const {
	return BuY;
}

void Bullets::setBuY(float buY) {
	BuY = buY;
}

Bullets::~Bullets() {
	// TODO Auto-generated destructor stub
}

