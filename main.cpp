#include <iostream>
#include "ClassesAll.h"

using namespace std;


int main()
{
	CharacterFactory *charFac = nullptr;

	//OCENA 3.0

	/*Character* w1 = charFac.createCharacter("Warrior");
	w1->showInfo();

	Character* m1 = charFac.createCharacter("Mage");
	m1->showInfo();

	Character* a1 = charFac.createCharacter("Archer");
	a1->showInfo();*/

	//OCENA 4.0

	string tempClass;

	cout << "Enter character class: ";
	cin >> tempClass;

	if (tempClass == "Warrior") {
		charFac = new WarriorFactory();
	}
	else if (tempClass == "Mage") {
		charFac = new MageFactory();
	}
	else if (tempClass == "Archer") {
		charFac = new ArcherFactory();
	}
	else {
		throw invalid_argument("Invalid type");
	}

	Character* c1 = charFac->createCharacter();
	c1->showInfo();

	//OCENA 5.0

	c1->setHp_(100);
	c1->setStrength_(30);

	c1->showInfo();

	return 0;
}
