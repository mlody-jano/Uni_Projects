#include <iostream>
#include "Werewolf.h"
#include "Harpy.h"

using namespace std;

int main() {

	Enemy** Enemies = new Enemy * [4];

	Harpy* h1 = new Harpy(5, 6, 7, 8);
	Harpy* h2 = new Harpy(9, 8, 7, 6);

	Werewolf* w1 = new Werewolf(1, 2, 3, 4);
	Werewolf* w2 = new Werewolf(5, 6, 7, 8);

	Enemies[0] = h1;
	Enemies[1] = h2;
	Enemies[2] = w1;
	Enemies[3] = w2;

	for (int i = 0; i < 4; i++) {
		Enemies[i]->show();
		Enemies[i]->make_attack(0.5);
		Enemies[i]->show();
		Enemies[i]->make_sound();
	}

	delete h1;
	delete h2;
	delete w1;
	delete w2;
	delete Enemies;

	return 0;
}

// Pytania
//
// Dlaczego pola klasy Enemy są polami protected, a nie private?
// 
// Ponieważ gdyby były private, nie byłyby one dostępne dla klas pochodnych
// 
// Pytanie 1
//
//Czym się różnią metody czysto wirtualne od wirtualnych?
//
// Metody czysto wirtualne są definiowane z zerem na końcu definicji, tj. "metoda ... = 0"
//
// Pytanie 2
//
// Klasą abstrakcyjną jest jedynie klasa bazowa Enemy, ponieważ jedynie ona posiada metodę czysto wirtualną