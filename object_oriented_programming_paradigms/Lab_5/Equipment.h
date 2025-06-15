#pragma once
#include"Item.h"
#include <vector>
#include <iostream>

using namespace std;

class Equipment
{
private:
	vector<Item> equipment_;

public:
	Equipment();
	~Equipment();

	friend Equipment operator+=(Equipment&,const Item&);
	friend ostream& operator<<(ostream&, const Equipment&);
};

