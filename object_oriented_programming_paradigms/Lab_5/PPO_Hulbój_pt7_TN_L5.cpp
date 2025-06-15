#include <iostream>
#include "Item.h"
#include "Equipment.h"

using namespace std;

int main() {
	Item i1(10.0, 20.0, 5.0);
	Item i2(15.0, 25.0, 10.0);

	Item i3 = i1 + i2;

	cout << i3 << endl;

	Item i4;

	cin >> i4;

	cout << i4 << endl;

	Equipment eq;

	eq += i1;

	cout << eq << endl;


	return 0;
}