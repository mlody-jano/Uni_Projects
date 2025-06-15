#pragma once
#include "Enemy.h"
class Werewolf : public Enemy {
private:
	float radius;

public:
	Werewolf();
	Werewolf(float, float, float, float);
	~Werewolf();

	float getRadius() const;
	void setRadius(float);

	void show();
	void make_attack(float);
	void make_sound();
};

