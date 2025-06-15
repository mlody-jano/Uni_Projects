#pragma once
#include <iostream>
#include <string>

using namespace std;

class Witcher {

	string name_;
	string witcher_school_;
	int age_;
	int height_;
	int weight_;

public:

	void wczytaj_method();
	void wypisz_method() const;

	Witcher();
	Witcher(string, string, int, int, int);
	~Witcher();
};