#include <iostream>
#include <string>
#include <fstream>

// L5.1
// L5.2
// L5.3

const unsigned int max_size = 10;

using namespace std;

// Stworzenie odpowiedniej struktury
struct student {
    long int index{0};
    string firstName;
    string lastName;
    char sex{0};
    string dateOfBirth;
};

// Wyswietlenie menu wyboru funkcji bazy danych
void wyswietl_menu() {
    cout << "Witaj! Wybierz operacje: " << endl;
    cout << "1. Import danych z pliku." << endl;
    cout << "2. Eksport danych do pliku." << endl;
    cout << "3. Dodanie rekordu do bazy." << endl;
    cout << "4. Wyswietlenie wszystkich rekordow obecnych w bazie." << endl;
    cout << "5. Usuniecie rekordu z bazy." << endl;
    cout << "6. Wylaczenie programu." << endl;
    cout << "7. Wylosowanie rekordu." << endl;
    cout << "8. Szukanie po elemencie." << endl;

    cout << "Wybierz operacje: ";
}

// Funkcja importujaca dane z pliku zewnetrznego do tablicy struktur
void importowanie_danych(fstream &plik, student table[]) {

    plik.close();
    plik.open("data.txt", ios::in);

    for (unsigned int i = 0; i < 10; i++) {
        plik >> table[i].index >> table[i].firstName >> table[i].lastName >> table[i].sex >> table[i].dateOfBirth;
    }
    cout << "Dane zostały pobrane! \n";
}

// Funkcja eksportujaca dane z tablicy struktur do pliku zewnetrznego
void zapis_danych(fstream &plik, student table[]) {

    plik.close();
    plik.open("data.txt", ios::out | ios::trunc);

        for (int i = 0; i < 10; i++) {

            plik << table[i].index << " ";
            plik << table[i].firstName << " ";
            plik << table[i].lastName << " ";
            plik << table[i].sex << ' ';
            plik << table[i].dateOfBirth << " \n";
        }
        cout << "Dane zostały zapisane!" << endl;
}

// Funkcja dodajaca rekord do tablicy struktur
void dodanie_rekordu(fstream &plik, student table[]) {

    // Stworzenie tymczasowego rekordu
    student temp;

    cout << "Podaj dane według wzoru: " << endl;
    cout << "Nr indeksu; Imie; Nazwisko; Plec; Data urodzenia." << endl;

    cin >> temp.index;
    cin >> temp.firstName;
    cin >> temp.lastName;
    cin >> temp.sex;
    cin >> temp.dateOfBirth;

    for (int i = 0; i < 10; i++) {
        if (table[i].index == 0) {

            table[i].index = temp.index;
            table[i].firstName = temp.firstName;
            table[i].lastName = temp.lastName;
            table[i].sex = temp.sex;
            table[i].dateOfBirth = temp.dateOfBirth;

            break;
        }
    }

    cout << "Rekord dodany poprawnie!" << endl;
}

// Funkcja wyswietlajaca zawartosc tablicy struktur
void wyswietlenie_danych(fstream &plik, student table[]) {

    cout << "Dane dostępne w bazie: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << table[i].index << " ";
        cout << table[i].firstName << " ";
        cout << table[i].lastName << " ";
        cout << table[i].sex << " ";
        cout << table[i].dateOfBirth << " ";

        cout << endl;
    }
}

// Funkcja pozwalajaca na usuniecie dowolnego rekordu z tablicy struktur, "zsuwajaca" pozniejsze rekordy
void usuwanie_elementu(fstream &plik, student table[]) {

    unsigned int index_num;

    cout << "Podaj indeks rekordu do usuniecia: ";
    cin >> index_num;

    //Wyzerowanie podanego indeksu

    table[index_num].index = NULL;
    table[index_num].firstName = " ";
    table[index_num].lastName = "";
    table[index_num].sex = ' ';
    table[index_num].dateOfBirth = "";

    for(unsigned int i = index_num; i < 9; i++) {
        table[i].index = table[i+1].index;
        table[i].firstName = table[i+1].firstName;
        table[i].lastName = table[i+1].lastName;
        table[i].sex = table[i+1].sex;
        table[i].dateOfBirth = table[i+1].dateOfBirth;
    }

    char choice;

    cout << "Czy zaaktualizowana baze zapisac do pliku? (y/n): ";
    cin >> choice;

    if (choice == 'y') {
        zapis_danych(plik, table);
        cout << "Rekord usuniety oraz plik zapisany!" << endl;
    }
    else
        cout << "Rekord usuniety!" << endl;
}

// Funkcja losujaca element z tablicy struktur
void random_element(fstream &plik, student table[]) {

    //Ustawienie generatora ziarna losowania zaleznego od czasu

    srand(time(nullptr));

    unsigned int data_num = 0;
    unsigned int rand_index = 0;

    for (int i = 0; i < 10; i++) {
        if(table[i].index != NULL) {
            data_num++;
        }
    }

    rand_index = rand() % data_num;

    cout << "Wylosowano indeks o numerze: \n" << rand_index << endl;
    cout << "Wylosowane dane: \n";

    cout << table[rand_index].index << " " << table[rand_index].firstName << " " << table[rand_index].lastName << " " << table[rand_index].sex << " " << table[rand_index].dateOfBirth << endl;
}

// Funkcja pozwalajaca na przeszukiwanie bazy na podstawie pojedynczego elementu
void search_by_element(fstream &plik, student table[]) {

    char wybor;

    cout << "Wybierz po jakim elemencie szukac (1 = indeks; 2 = imie; 3 = nazwisko; 4 = plec; 5 = data urodzenia): " << endl;
    cin >> wybor;

    //Menu wyboru trybu szukania wykonane za pomoca instrukcji switch, case

    switch (wybor) {
        case '1': {
            long int index;

            cout << "Podaj index: ";
            cin >> index;

            bool found = NULL;
            unsigned int i{0};

            //Petla przeszukujaca baze

            while (!found) {
                if(index == table[i].index) {
                    found = true;
                }
                i++;


                // W razie wykroczenia poza baze, komunikat bledu i przerwanie

                if(i > 10) {
                    cout << "Sprawdzono cala baze! Rekord nie znaleziony! \n";
                    break;
                }
            }

            //Zmniejszenie wartosci iteratora, tak aby wyswietlal poprawny indeks
            i -= 1;

            cout << "Znaleziono! Indeks rekordu: " << i << endl;
            cout << "Rekord: " << endl;

            cout << table[i].index <<" "<<  table[i].firstName << " " << table[i].lastName << " " << table[i].sex << " " << table[i].dateOfBirth << endl;
            break;
        }
        case '2': {
            string first_name;

            cout << "Podaj imie: ";
            cin >> first_name;

            bool found = NULL;
            unsigned int i{0};

            while (!found) {
                if(first_name == table[i].firstName) {
                    found = true;
                }
                i++;

                if(i > 10) {
                    cout << "Sprawdzono cala baze! Rekord nie znaleziony! \n";
                    break;
                }
            }

            i -= 1;

            cout << "Znaleziono! Indeks rekordu: " << i << endl;
            cout << "Rekord: " << endl;

            cout << table[i].index << " " << table[i].firstName << " " << table[i].lastName << " " << table[i].sex << " " << table[i].dateOfBirth << endl;
            break;
        }
        case '3': {
            string last_name;

            cout << "Podaj nazwisko: ";
            cin >> last_name;

            bool found = NULL;
            unsigned int i{0};

            while (!found) {
                if(last_name == table[i].lastName) {
                    found = true;
                }
                i++;

                if(i > 10) {
                    cout << "Sprawdzono cala baze! Rekord nie znaleziony! \n";
                    break;
                }
            }

            i -= 1;

            cout << "Znaleziono! Indeks rekordu: " << i << endl;
            cout << "Rekord: " << endl;

            cout << table[i].index << " " << table[i].firstName << " " << table[i].lastName << " " << table[i].sex << " " << table[i].dateOfBirth << endl;
            break;
        }
        case '4': {
            char sex;

            cout << "Podaj plec: " << endl;
            cin >> sex;

            bool found = NULL;
            unsigned int i{0};

            while (!found) {
                if(sex == table[i].sex) {
                    found = true;
                }
                i++;

                if(i > 10) {
                    cout << "Sprawdzono cala baze! Rekord nie znaleziony! \n";
                    break;
                }
            }

            i -= 1;

            cout << "Znaleziono! Indeks rekordu: " << i << endl;
            cout << "Rekord: " << endl;

            cout << table[i].index << " " << table[i].firstName << " " << table[i].lastName << " " << table[i].sex << " " << table[i].dateOfBirth << endl;
            break;
        }
        case '5': {
            string DoB;

            cout << "Podaj date urodzenia (wedlug formatu DD-MM-YYYY): ";
            cin >> DoB;

            bool found = NULL;
            unsigned int i{0};

            while (!found) {
                if(DoB == table[i].dateOfBirth) {
                    found = true;
                }
                i++;

                if(i > 10) {
                    cout << "Sprawdzono cala baze! Rekord nie znaleziony! \n";
                    break;
                }
            }

            i -= 1;

            cout << "Znaleziono! Indeks rekordu: " << i << endl;
            cout << "Rekord: " << endl;

            cout << table[i].index << " " << table[i].firstName << " " << table[i].lastName << " " << table[i].sex << " " << table[i].dateOfBirth << endl;
            break;
        }
        default: {
            cout << "Niepoprawna komenda!" << endl;
            break;
        }
    }
}

int main() {

    fstream plik;

    student student_table[max_size];

    char wybor;

    plik.open("data.txt", fstream::in | fstream::out);

    //Sprawdzenie czy plik zostal otwarty poprawnie

    if (plik.is_open()) {
        cout << "File loaded succesfully!" << endl;
    }
    else {
        cerr << "Error opening file!" << endl;
        return 0;
    }

    // Stale wyswietlane menu
    while (true) {

        wyswietl_menu();

        cin >> wybor;

        switch (wybor) {
            case '1': {
                importowanie_danych(plik, student_table);
                break;
            }
            case '2': {
                zapis_danych(plik, student_table);
                break;
            }
            case '3': {
                dodanie_rekordu(plik, student_table);
                break;
            }
            case'4': {
                wyswietlenie_danych(plik, student_table);
                break;
            }
            case'5': {
                usuwanie_elementu(plik, student_table);
                break;
            }
            case'6': {
                plik.close();

                cout << "File closed succesfully!" << endl;

                cout << "Wylaczam program!" << endl;
                return 0;
            }
            case '7': {
                random_element(plik, student_table);
                break;
            }
            case '8': {
                search_by_element(plik, student_table);
                break;
            }
            default: {
                cerr << "Nieznana operacja!" << endl;
            }
        }
        wybor = 0; //Zerowanie wyboru przed zakonczeniem petli
    }
}