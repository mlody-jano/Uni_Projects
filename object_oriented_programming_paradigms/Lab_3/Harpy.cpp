#include "Harpy.h"
#include <iostream>

using namespace std;

Harpy::Harpy() : height{ 0.0 } {};
Harpy::Harpy(float tempX, float tempY, float tempStrength, float tempHeight) : Enemy(tempX, tempY, tempStrength), height{ tempHeight } {};

Harpy::~Harpy() {
	cout << "Harpy destroyed - destruktor klasy Harpy" << endl;
}
float Harpy::getHeight() const {
	return height;
}
void Harpy::setHeight(float temp) {
	height = temp;
}
void Harpy::show() {
	cout << "The harpy is at point: (" << x << "," << y << "), has a strength of: " << strength << ", and its height is: " << height << endl;
}
void Harpy::make_sound() {
	cout << "Harpy's yell" << endl;
}
void Harpy::make_attack(float attack_factor) {
	setStrength(getStrength() - getStrength() * attack_factor);
	setHeight(1.85);
	make_sound();
}