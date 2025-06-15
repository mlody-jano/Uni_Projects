#pragma once
#include "Person.h"
class Sorceress : public Person {
	
private:
	string magic_academy;
	int age_;

public:
	Sorceress(string, int);
	~Sorceress();
	string get_magic_academy() const;
	int get_age() const;
};

