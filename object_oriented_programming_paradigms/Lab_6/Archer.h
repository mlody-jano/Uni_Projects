#pragma once
#include "Character.h"
class Archer :
    public Character
{
public:
    Archer();
    Archer(double, double);
    ~Archer();

    void showInfo() const;
};

void Archer::showInfo() const {
    cout << "Archer - faster than the blink of an eye\n";
    cout << "Stats:\n\n";
    cout << "Health points: " << getHp_() << endl;
    cout << "Strength: " << getStrenght_() << "\n\n";
}
Archer::Archer() {}
Archer::Archer(double tempH,double tempS) : Character(tempH,tempS) {}
Archer::~Archer() {}

