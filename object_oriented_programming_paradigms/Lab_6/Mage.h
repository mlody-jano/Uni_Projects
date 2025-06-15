#pragma once
#include "Character.h"
class Mage :
    public Character
{
public:
    Mage();
    Mage(double, double);
    ~Mage();

    void showInfo() const;
};

void Mage::showInfo() const {
    cout << "Mage - wisdom, spells and magic\n";
    cout << "Stats:\n\n";
    cout << "Health points: " << getHp_() << endl;
    cout << "Strength: " << getStrenght_() << "\n\n";
}
Mage::Mage() {}
Mage::Mage(double tempH,double tempS) : Character(tempH,tempS) {}
Mage::~Mage() {}

