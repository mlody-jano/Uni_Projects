#pragma once
#include "CharacterFactory.h"
class WarriorFactory :
    public CharacterFactory
{
public:
    WarriorFactory();
    ~WarriorFactory();

    Character* createCharacter();
};
WarriorFactory::WarriorFactory() {}
WarriorFactory::~WarriorFactory() {}

Character* WarriorFactory::createCharacter() {
    return new Warrior();
}
