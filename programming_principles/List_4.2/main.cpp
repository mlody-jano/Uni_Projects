#include <iostream>

//L4.1

using namespace std;

void wpisanie_tekstu(char tekst1[]) {

    cout << "Wpisz tekst: ";
    cin.getline(tekst1, 15);
}

void wyswietlenie_tekstu(char tekst1[],int lenght) {

    for(int i = 0; i<lenght; i++) {
        cout << tekst1[i];
    }
    cout << endl;
}

void liczba_znakow(int lenght) {
    cout << "Liczba wprowadzonych znakow: " << lenght << endl;          // wypisanie liczby wprowadzonych znakow
}

void zmiana_znakow(char tekst1[],int lenght) {
    cout << "Tekst przed zamiana: " << tekst1 << endl;

    for (int i = 0; i < lenght; i++) {

        //Sprawdzenie wielkosci litery

        if (tekst1[i] >= 'a' && tekst1[i] <= 'z') {
            tekst1[i] -= 32;
        }
        else if (tekst1[i] >= 'A' && tekst1[i] <= 'Z') {
            tekst1[i] += 32;
        }
    }
    cout << "Tekst po zamianie: " << tekst1 << endl;
}

int main() {

    char tekst[15];

    wpisanie_tekstu(tekst);

    int dlugosc = strlen(tekst);                    // okreslenie dlugosci wpisanego tekstu

    wyswietlenie_tekstu(tekst,dlugosc);

    liczba_znakow(dlugosc);

    zmiana_znakow(tekst,dlugosc);

    return 0;
}
