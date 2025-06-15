#pragma once
#include <iostream>
#include <string>
#include "Character.h"
#include "Warrior.h"
#include "Mage.h"
#include "Archer.h"

using namespace std;

class CharacterFactory
{
public:
	CharacterFactory();
	~CharacterFactory();

	virtual Character* createCharacter() = 0;
};

//Character* CharacterFactory::createCharacter (string type) {
//	if (type == "Warrior")
//		return new Warrior();
//	else if (type == "Mage")
//		return new Mage();
//	else if (type == "Archer")
//		return new Archer();
//	else
//		return nullptr;
//}
CharacterFactory::CharacterFactory() {}
CharacterFactory::~CharacterFactory() {}
