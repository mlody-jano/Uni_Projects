#include "Witcher.h"

using namespace std;

Witcher::Witcher() : Person() {
	cout << "Konstruktor domyœlny - klasa pochodna Witcher";
}
Witcher::~Witcher() {
	cout << "Destruktor - klasa pochodna Witcher" << endl;
}
void Witcher::cast_a_sign() const {
	cout << "The sign: Aard!" << endl;
}
void Witcher::set_origin(string temp) {
	origin_ = temp;
}
void Witcher::reveal_the_origin() const {
	cout << "I come from " << origin_ << endl;
}