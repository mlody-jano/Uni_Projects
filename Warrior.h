#pragma once
#include "Character.h"
class Warrior :
    public Character
{
public:
    Warrior();
    Warrior(double, double);
    ~Warrior();

    void showInfo() const;
};

void Warrior::showInfo() const {
    cout << "Warrior - filled with anger\n";
    cout << "Stats:\n\n";
    cout << "Health points: " << getHp_() << endl;
    cout << "Strength: " << getStrenght_() << "\n\n";
}
Warrior::Warrior() {}
Warrior::Warrior(double tempH,double tempS) : Character(tempH,tempS) {}
Warrior::~Warrior() {}

