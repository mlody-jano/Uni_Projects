#pragma once
#include "Enemy.h"
class Harpy : public Enemy {
private:
	float height;

public:
	Harpy();
	Harpy(float, float, float, float);
	~Harpy();
	
	float getHeight() const;
	void setHeight(float);

	void show();
	void make_attack(float);
	void make_sound();
};

