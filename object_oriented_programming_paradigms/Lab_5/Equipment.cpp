#include "Equipment.h"
#include "Item.h"
#include <iostream>

using namespace std;

Equipment::Equipment() {}
Equipment::~Equipment() {}
Equipment operator+=(Equipment &eq, const Item &temp) {
	eq.equipment_.push_back(temp);
	return eq;
}
ostream& operator<<(ostream& os, const Equipment& eq) {
	vector<Item>::const_iterator it;

	for (it = eq.equipment_.begin(); it != eq.equipment_.end(); it++) {
		os << *it << endl;
	}
	return os;
}