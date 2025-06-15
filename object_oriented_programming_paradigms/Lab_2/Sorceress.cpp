#include "Sorceress.h"

using namespace std;

Sorceress::Sorceress(string tempMA, int tempAge) : magic_academy{tempMA}, age_{tempAge} {
	cout << "Konstruktor wieloargumentowy - klasa pochodna Sorceress";
}
Sorceress::~Sorceress() {
	cout << "Destruktor - klasa pochodna Sorceress";
}
string Sorceress::get_magic_academy() const {
	return magic_academy;
}
int Sorceress::get_age() const {
	return age_;
}