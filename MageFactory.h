#pragma once
#include "CharacterFactory.h"
class MageFactory :
    public CharacterFactory
{
public:
    MageFactory();
    ~MageFactory();

    Character* createCharacter();
};

MageFactory::MageFactory() {}
MageFactory::~MageFactory() {}

Character* MageFactory::createCharacter() {
    return new Mage();
}

