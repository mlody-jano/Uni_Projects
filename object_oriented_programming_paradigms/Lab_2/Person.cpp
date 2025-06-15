#include "Person.h"

using namespace std;

Person::Person() : name_{ "none" }, age_{ 0 }, height_{ 0 }, weight_{0} {
	cout << "Konstruktor domyœlny - klasa podstawowa Person";
}

Person::~Person() {
	cout << "Destruktor - klasa podstawowa Person";
}
void Person::introduce_yourself() const {
	cout << "I'm " << name_ << endl;
}
string Person::get_name() const {
	return name_;
}
int Person::get_age() const {
	return age_;
}
int Person::get_height() const {
	return height_;
}
int Person::get_weight() const {
	return weight_;
}