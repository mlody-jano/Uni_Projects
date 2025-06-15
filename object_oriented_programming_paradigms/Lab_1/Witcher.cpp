#include <iostream>
#include "Witcher.h"

using namespace std;

void Witcher::wczytaj_method() {
	cout << "Podaj dane o postaci: \n";
	    cout << "Nazwa: ";
		getline(cin, name_);
	    cout << "Szkola wiedzminska: ";
	    cin >> witcher_school_;
	    cout << "Wiek: ";
	    cin >> age_;
	    cout << "Wzrost: ";
	    cin >> height_;
		cout << "Waga: ";
		cin >> weight_;
		cout << endl;
}

void Witcher::wypisz_method() const {
	cout << "Dane o postaci: \n";
	   cout << name_ << endl;
	   cout << witcher_school_ << endl;
	   cout << age_ << endl;
	   cout << height_ << endl;
	   cout << weight_ << endl;
	   cout << endl;
}
Witcher::Witcher() {
	name_ = "brak";
	witcher_school_ = "brak";
	age_ = 0;
	height_ = 0;
	weight_ = 0;
	cout << "Nadanie wartosci - konstruktor domyslny." << endl;
}
Witcher::Witcher(string tempName, string tempSchool, int tempAge, int tempHeight, int tempWeight) :
	name_(tempName),
	witcher_school_(tempSchool),
	age_(tempAge),
	height_(tempHeight),
	weight_(tempWeight) {
	cout << "Nadanie wartosci - konstruktor wieloargumentowy." << endl;
}

Witcher::~Witcher() {
	cout << "Likwiduje!";
}