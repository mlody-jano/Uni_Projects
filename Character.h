#pragma once
#include <iostream>

using namespace std;

class Character {
private:
	double hp_;
	double strength_;

public:
	Character();
	Character(double, double);
	~Character();

	virtual void showInfo() const = 0;

	double getHp_() const;
	double getStrenght_() const;
	void setHp_(double);
	void setStrength_(double);
};

Character::Character() : hp_{ 0.0 }, strength_{ 0.0 } {}
Character::Character(double tempH, double tempS) : hp_{tempH},strength_{tempS} {}
Character::~Character() {}

double Character::getHp_() const {
	return hp_;
}
double Character::getStrenght_() const {
	return strength_;
}
void Character::setHp_(double temp) {
	hp_ = temp;
}
void Character::setStrength_(double temp) {
	strength_ = temp;
}

