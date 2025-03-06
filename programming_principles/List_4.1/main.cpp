#include <iostream>
#include <ctime>

using namespace std;

//L4.2

void losowana_tablica() {

    // ustawienie generatora ziarna zaleznego od czasu systemowego
    srand(time(nullptr));

    // wylosowanie rozmiaru tablicy
    unsigned int rozmiar = (rand()%16) + 17;

    cout << "Rozmiar tablicy wynosi: " << rozmiar << endl;

    // utworzenie nowej tablicy dynamicznej
    int * tablica = new int[rozmiar];

    //wypelnienie tablicy
    for(int i = 0; i < rozmiar; i++) {
        tablica[i] = pow(2,i);
    }

    cout << "Zawartosc tablicy: " << endl;

    //wypisanie tablicy wedlug podanego wzoru
    for(int i = 0; i < rozmiar; i++) {
        cout << '[' << i << ']' << " " << "2^" << i << " " << '=' << " " << tablica[i] << endl;
    }

    cout << endl;

    //zwolnienie pamieci
    delete[] tablica;

}

int main() {

    losowana_tablica();

    return 0;
}