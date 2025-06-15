#include "Werewolf.h"
#include <iostream>

using namespace std;

Werewolf::Werewolf() : radius{ 0.0 } {};
Werewolf::Werewolf(float tempX, float tempY, float tempStrength, float tempRadius) : Enemy{ tempX,tempY,tempStrength }, radius{ tempRadius } {};

Werewolf::~Werewolf() {
	cout << "Werewolf destroyed - destruktor klasy Werewolf" << endl;
}
float Werewolf::getRadius() const {
	return radius;
}
void Werewolf::setRadius(float temp) {
	radius = temp;
}
void Werewolf::show() {
	cout << "The werewolf is at point: (" << x << "," << y << "), has a strength of: " <<strength << " and its radius is: " << radius << endl;
}
void Werewolf::make_sound() {
	cout << "Werewolf's growl" << endl;
}
void Werewolf::make_attack(float attack_factor) {
	setStrength(getStrength() - getStrength() * attack_factor);
	setRadius(getRadius()*1.5);
	make_sound();
}