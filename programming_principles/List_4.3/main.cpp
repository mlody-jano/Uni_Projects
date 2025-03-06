#include <iostream>
#include <string>

// L4.3

using namespace std;

void histogram_wystapien() {

    string input;
    cout << "Podaj zdanie: ";

    // wczytanie wejscia funkcja getline
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {

        // zmiana malych liter na duze
        input[i] = tolower(input[i]);
    }

    // petla ustawiajaca kolejne znaki alfabetu
    for(char znak = 'a'; znak <= 'z'; znak++) {

        cout << znak << " ";

        // petla szukajaca wystapien danego znaku w sygnale wejsciowym
        for (int i = 0; i < input.length(); i++) {

            // wypisanie znaku '#' w sytuacji znalezienia szukanego znaku
            if (input[i] == znak) {
                cout << '#';
            }
        }
        cout << endl;
    }
}

int main() {

    histogram_wystapien();

    return 0;
}