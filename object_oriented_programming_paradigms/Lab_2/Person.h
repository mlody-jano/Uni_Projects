#pragma once
#include <iostream>
#include <string>

using namespace std;

class Person {

private:

	string name_;
	int age_;
	float height_;
	float weight_;

protected:

	string origin_;

public:

	Person();
	~Person();
	void introduce_yourself() const;
	string get_name() const;
	int get_age() const;
	int get_weight() const;
	int get_height() const;
};

