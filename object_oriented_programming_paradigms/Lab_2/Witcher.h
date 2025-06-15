#pragma once
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

class Witcher : public Person {

public:

	Witcher();
	~Witcher();
	void cast_a_sign() const;
	void set_origin(string);
	void reveal_the_origin() const;
};

