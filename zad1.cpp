#include <iostream>

using namespace std;

int main()
{
    float liczba1;
    float liczba2;
    float wynik;

    cout << "Podaj pierwsza liczbe:" << endl;
    cin >> liczba1;
    if(cin.fail())
        {
            cout << "Blad! Niepoprawna dana wejsciowa!" << endl;
            goto komunikat_bledu;
        }

    cout << "Podaj druga liczbe:" << endl;
    cin >> liczba2;
    if(cin.fail())
        {
            cout << "Blad! Niepoprawna dana wejsciowa!" << endl;
            goto komunikat_bledu;
        }

    char znak;

    cout << "Podaj znak dzialania:" << endl;
    cin >> znak;

    switch(znak)
    {
        case '+':
        {
            wynik = liczba1 + liczba2;
            cout << "Wynik:" << wynik << endl;
            break;
        }
        case '-':
        {
            wynik = liczba1 - liczba2;
            cout << "Wynik:" << wynik << endl;
            break;
        }
        case '*':
        {
            wynik = liczba1 * liczba2;
            cout << "Wynik:" << wynik << endl;
            break;
        }
        case '/':
        {
            if(liczba2 == 0 && znak== '/' )
            {
                cout << "Nie mozna dzielic przez 0!" << endl;
                break;
            }
            else if(liczba2 != 0 && znak == '/')
            {
                wynik = liczba1 / liczba2;
                cout << "Wynik:" << wynik << endl;
                break;
            }
            default:
            {
                cout << "Nieznany symbol!" << endl;
                break;
            }
        }
    }

    komunikat_bledu:

    return 0;
}
