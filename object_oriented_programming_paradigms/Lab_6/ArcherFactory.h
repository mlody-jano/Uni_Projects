#pragma once
#include "CharacterFactory.h"
class ArcherFactory :
    public CharacterFactory
{
public:
    ArcherFactory();
    ~ArcherFactory();

    Character* createCharacter();
};
ArcherFactory::ArcherFactory() {}
ArcherFactory::~ArcherFactory() {}

Character* ArcherFactory::createCharacter() {
    return new Archer();
}

