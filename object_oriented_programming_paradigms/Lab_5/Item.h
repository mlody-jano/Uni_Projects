#pragma once
#include <iostream>

using namespace std;

class Item
{
private:
	double defense_;
	double strength_;
	double critChance_;

public:

	Item();
	Item(double, double, double);
	~Item();

	double getDefense() const;
	double getStrength() const;
	double getCritChance() const;

	void setDefense(double);
	void setStrength(double);
	void setCritChance(double);


	friend ostream& operator<<(ostream&, const Item& temp);
	friend istream& operator>>(istream&, Item& temp);
	friend Item operator+(Item&, Item&);
};

