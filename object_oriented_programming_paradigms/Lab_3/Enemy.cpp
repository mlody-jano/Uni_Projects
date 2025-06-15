#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy() : x{ 0.0 }, y{ 0.0 }, strength{ 0.0 } {};
Enemy::Enemy(float tempX, float tempY, float tempStrength) : x{ tempX }, y{ tempY }, strength{ tempStrength } {};

Enemy::~Enemy() {
	cout << "Destruktor klasy bazowej Enemy" << endl;
}

float Enemy::getX() const {
	return x;
}
float Enemy::getY() const {
	return y;
}
float Enemy::getStrength() const {
	return strength;
}
void Enemy::setX(float temp) {
	x = temp;
}
void Enemy::setY(float temp) {
	y = temp;
}
void Enemy::setStrength(float temp) {
	strength = temp;
}

void Enemy::update_position(float tempX, float tempY) {
	x += tempX;
	y += tempY;
}