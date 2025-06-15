#include "Item.h"

Item::Item() : defense_(0), strength_(0), critChance_(0) {}
Item::Item(double tempDefense, double tempStrength, double tempCritChance) : defense_(tempDefense), strength_(tempStrength), critChance_(tempCritChance) {}
Item::~Item() {}

double Item::getDefense() const {
	return defense_;
}
double Item::getStrength() const {
	return strength_;
}
double Item::getCritChance() const {
	return critChance_;
}
void Item::setDefense(double tempDefense) {
	defense_ = tempDefense;
}
void Item::setStrength(double tempStrength) {
	strength_ = tempStrength;
}
void Item::setCritChance(double tempCritChance) {
	critChance_ = tempCritChance;
}
ostream& operator<<(ostream& os, const Item& temp) {
	os << "Defense: " << temp.getDefense() << endl;
	os << "Strength: " << temp.getStrength() << endl;
	os << "Crit Chance: " << temp.getCritChance() << endl;
	return os;
}
istream& operator>>(istream& is, Item& temp) {
	cout << "Input Defense: ";
	is >> temp.defense_;
	cout << "Input Strength: ";
	is >> temp.strength_;
	cout << "Input Crit Chance: ";
	is >> temp.critChance_;
	return is;
}
Item operator+(Item& item1, Item& item2) {
	Item temp;
	temp.setDefense(item1.getDefense() + item2.getDefense());
	temp.setStrength(item1.getStrength() + item2.getStrength());
	temp.setCritChance(item1.getCritChance() + item2.getCritChance());
	return temp;
}