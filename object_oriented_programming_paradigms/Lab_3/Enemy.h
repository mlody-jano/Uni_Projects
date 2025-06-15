#pragma once
#include <iostream>
class Enemy
{
protected:

	float x;
	float y;
	float strength;
	Enemy();
	Enemy(float, float, float);

public:

	virtual ~Enemy();
	float getX() const;
	float getY() const;
	float getStrength() const;

	void setX(float);
	void setY(float);
	void setStrength(float);

	virtual void show() = 0;
	virtual void make_attack(float) = 0;
	virtual void make_sound() = 0;

	void update_position(float, float);
};

