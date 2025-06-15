#include <iostream>
#include "Witcher.h"

using namespace std;

//void wypisz(Witcher temp) const {
//    cout << "Dane o postaci: \n";
//    cout << temp.name_ << endl;
//    cout << temp.witcher_school_ << endl;
//    cout << temp.age_ << endl;
//    cout << temp.height_ << endl;
//    cout << temp.weight_ << endl;
//}
//
//void wczytaj(Witcher& temp) {
//    cout << "Podaj dane o postaci: \n";
//    cout << "Nazwa: ";
//    cin >> temp.name_;
//    cout << "Szkola wiedzminska: ";
//    cin >> temp.witcher_school_;
//    cout << "Wiek: ";
//    cin >> temp.age_;
//    cout << "Wzrost: ";
//    cin >> temp.height_;
//    cout << "Waga: ";
//    cin >> temp.weight_;
//}

int main()
{
    Witcher w1;
    Witcher w2{ "Geralt", "Niedzwiedzia", 59, 184, 82 };

    w1.wypisz_method();
    w1.wczytaj_method();
    w1.wypisz_method();
    w2.wypisz_method();

    return 0;
}

//          PYTANIA
//      Ocena 3.0
//
// (f) Funkcje niebędące metodami klasy nie bedą miały dostępu do prywatnych pól klasy, a więc nie bedą działały.
// (i) Tak, wyświetlone zostały wartości domyślne ustawione w konstruktorze domyślnym zdefiniowanym jawnie.
// (j) Tak, działanie destruktora dało się zauważyć pod koniec działania programu. Nie musiał on zostać wywołany jawnie.
// 
//      Ocena 4.0
//
// (c) Destruktory przy tworzeniu obiektów za pomocą konstruktorów domyślnego oraz wieloargumentowego wywoływane są w odwrotnej kolejności jak konstruktory, tj. "od końca".
//
//      Ocena 5.0
//
// (b) Przy funkcjach dostępowych, tj. nie zmieniających stanów pól klasy dodajemy na końcu słowo "const".
// (c) Konieczne jest zdefiniowanie konstruktora domyślnego, ponieważ nie wywoła się on niejawnie.
