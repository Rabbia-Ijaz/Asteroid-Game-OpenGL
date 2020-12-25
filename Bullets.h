/*
 * Bullets.h
 *
 *  Created on: 10-May-2018
 *      Author: HP
 */

#ifndef BULLETS_H_
#define BULLETS_H_

class Bullets {
	float BuX;
	float BuY;
public:
	Bullets();
	void BulletsWrapAround(); //wrap around for bullet
	virtual ~Bullets();
	float getBuX() const;
	void setBuX(float buX);
	float getBuY() const;
	void setBuY(float buY);
};

#endif /* BULLETS_H_ */
