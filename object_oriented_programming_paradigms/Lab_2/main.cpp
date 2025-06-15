#include <iostream>
#include "Person.h"
#include "Witcher.h"
#include "Sorceress.h"

using namespace std;

int main() {

	Witcher w1;
	cout << endl;
	w1.introduce_yourself();
	cout << w1.get_name() << endl;
	cout << w1.get_age() << endl;
	cout << w1.get_height() << endl;
	cout << w1.get_weight() << endl;
	w1.cast_a_sign();
	w1.set_origin("Polska");
	w1.reveal_the_origin();

	Sorceress s1("Polska", 24);
	cout << endl;
	cout << s1.get_name() << endl;
	cout << s1.get_age() << endl;
	cout << s1.get_height() << endl;
	cout << s1.get_weight() << endl;
	cout << s1.get_magic_academy() << endl;

	cout << endl;

	cout << s1.Person::get_age() << endl;


	return 0;
}

// Pytania
// OCENA 3.0
// 
// (a) Zauważyć można było działanie konstruktorów zarówno klasy podstawowej oraz pochodnej, ponieważ najpierw tworzony jest obiekt klasy podstawowej, a później klasy pochodnej
// (b) Udało się wywołać metody klasy podstawowej dla obiektu klasy pochodnej, ponieważ klasa pochodna dziedziczyła z klasy pierwotnej po public, a więc metody klasy pierwotnej były dla niej dostępne
// (c) Podobnie jak w punkcie pierwszym można było zauważyć działanie obu destruktorów, tj. klasy pierwotnej oraz pochodnej
//
// OCENA 4.0
//
// Istnieje możliwość nadania wartości polu w klasie podstawowej poprzez metodę klasy pochodnej, ponieważ przy dziedziczeniu przez public pola protected klasy bazowej też są polami protected w klasie pochodnej, co oznacza że metoda z klasy pochodnej będzie miała do nich dostep
//
// OCENA 5.0
//
// (a) Wyświetlone zostały wartości przypisane obiektowi s1 podczas jego tworzenia, tj.  magic_academy "Polska" oraz age 24
// (b) Zmiana specyfikatora dostępu spowodowała zmianę wyświetlonej wartości na 0
// (c) W sytuacji gdy klasa pochodna i pierwotna posiadają zmienną o tej samej nazwie następuje przysłonięcie i trzeba stosować specyfikatory dostępu 
