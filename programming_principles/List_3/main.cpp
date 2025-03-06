#include <iostream>
#include <cstdlib>
#include <ctime>

//L3.1
//L3.2
//L3.3

using namespace std;

const int n = 10; // deklaracja wielkosci tablicy

void wpisywanie_do_tablicy(int table[], int wielkosc) {

    cout << "Podaj " << wielkosc << " elementow do tablicy: " << endl;

    for (int i = 0; i < wielkosc; i++) {           // wypelnianie tablicy z klawiatury przez uzytkownika
        cin >> table[i];

    }
}

void suma_tablicy(int table[], int wielkosc) {
    int suma = 0;

    for (int i = 0; i < wielkosc; i++) {
        suma += table[i];
    }

    cout << "Suma elementow tablicy: " << suma << endl;
}

void wart_maks(int table[], int wielkosc) {

    int maksimum = 0;

    for (int i = 0; i < wielkosc-1; i++) {
        if (table[i+1] > table[i] && table[i+1] > maksimum) {    //  ustawianie maksimum znajdujacego sie w tablicy
            maksimum = table[i+1];
        }
    }
    cout << "Wartosc maksymalna w tablicy: " << maksimum << endl;
}

void wypisanie_liczb(int table[], int wielkosc) {

    for (int i = 0; i < wielkosc; i++) {
        cout << "Tab[" << i << "] = " << table[i] << " " << "\n";;     // wypisywanie liczb wedlug podanego formatu
    }
}

void liczby_losowe(int table[], int wielkosc) {

    int granica_dol{0}, granica_gor{0};                     // deklaracja granic losowania

    cout << "Podaj dolna granice losowania liczb:" << endl;
    cin >> granica_dol;                                             // zapisanie granic podanych z klawiatury przez uzytkownika

    cout << "Podaj gorna granice losowania liczb: " << endl;
    cin >> granica_gor;                                             // zapisanie granic podanych z klawiatury przez uzytkownika

    srand(time(nullptr));

    for (int i = 0; i < wielkosc; i++) {
        table[i] = rand() %(granica_gor-1) + granica_dol;           // losowanie liczb z podanego zakresu
    }
    for (int i = 0; i < wielkosc; i++) {
        cout << "Tab[" << i << "] = " << table[i] << " " << "\n";         // wypisanie liczb po losowaniu
    }
}

void dec_to_bin(int table[], int wielkosc) {

    int dziesietna = 0;                                                 // deklaracja liczby dziesietnej

    cout << "Wprowadz liczbe z zakresu 0-30: " << endl;
    cin >> dziesietna;

    if(dziesietna > 30 || dziesietna < 0) {                             // warunek wpisania liczby do zamiany na inny system liczbowy
        cout << "Licza poza zakresem!" << endl;
    }
    else {
        for(int i = 4; i>=0; i--) {
            if(dziesietna %2 == 0) {                                // sprawdzenie czy liczba jest podzielna przez 2, przypisanie 0 do pozycji w tabeli
                table[i] = 0;
                dziesietna /= 2;
            }
            else {                                                  // instrukcje dla liczb niepodzielnych przez 2, odpowiadają przypisaniu jedynki na odpowiednie miejsca
                table[i] = 1;
                dziesietna = floor(dziesietna/2);
            }

        }
        for (int i = 0; i < wielkosc; i++) {
            cout << "Tab[" << i << "] = " << table[i] << " " << "\n";         // wypisanie liczb po losowaniu
        }

    }
    cout << "\n";
}

void sortowanie_tablicy(int table[], int wielkosc) {

    clock_t start;
    for(int i = 0; i <= wielkosc; i++) {
        for(int j = 0; j < wielkosc-1; j++) {
            if(table[j+1] < table[j]) {
                swap(table[j+1], table[j]);
            }
        }
    }
    clock_t end;
    for (int i = 0; i < wielkosc; i++) {
        cout << "Tab[" << i << "] = " << table[i] << " " << "\n";
    }
    cout << "Czas sortowania: " << (end-start) << " ms" << endl;
}

int main() {

    int tablica[n];     // deklaracja tablicy

    wpisywanie_do_tablicy(tablica, n);

    suma_tablicy(tablica, n);

    wart_maks(tablica, n);

    wypisanie_liczb(tablica, n);

    liczby_losowe(tablica, n);

    dec_to_bin(tablica, n);

    sortowanie_tablicy(tablica, n);

    return 0;
}
