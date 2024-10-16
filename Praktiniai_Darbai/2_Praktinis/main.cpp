#include <iostream>
#include <string>
#include <ctime>
#include <array>

using namespace std;

bool IsCharVowel(const char letter) // Ar skaicius yra balsis
{
    char vowelsList[5] = { 'A', 'E', 'I', 'O', 'U'};

    for(char i : vowelsList)
    {
        if(letter == i || toupper(letter) == i) return true; // Toupper - pavertimas did�iosiomis, kad neb�t� skirtumo ar �vesta ma�oji ar did�ioji raid�
    }
    return false;
}

int MaxDivider(int skaicius1, int skaicius2) // Didziausias daliklis tarp dvieju skaitmenu
{
    while(abs(skaicius1) && abs(skaicius2))
        if(abs(skaicius1) > abs(skaicius2)) skaicius1 %= skaicius2;
        else skaicius2 %= skaicius1;
    return skaicius1 + skaicius2;
}

void zaidimas()
{
    const int randomNumber = rand() % 100 + 1;
    int inputGuessNumber;
    cout << "[DEBUG]: Sistemos sugeneruotas skai�ius yra: " << randomNumber << endl;

    while(inputGuessNumber != randomNumber)
    {
        cout << "Bandykite atsp�ti skai�i� nuo 1 iki 100: " << endl;
        cin >> inputGuessNumber;

        if(inputGuessNumber < 1 || inputGuessNumber > 100)
        {
            cout << "[ERROR]: �vestas skai�ius negali b�ti 0 arba didesnis u� 100!" << endl;
            cout << "Bandykite atsp�ti skai�i� nuo 1 iki 100: (�veskite per naujo)" << endl;
            cin >> inputGuessNumber;
        }

        if(inputGuessNumber < randomNumber) cout << "�vestas skai�ius " << inputGuessNumber << " buvo ma�esnis u� skai�i� kur� reikia atsp�ti. Sp�kite � didesn� pus�!" << endl;
        else if(inputGuessNumber > randomNumber) cout << "�vestas skai�ius " << inputGuessNumber << " buvo didesnis u� skai�i� kur� reikia atsp�ti. Sp�kite � ma�esn� pus�!" << endl;
    }
    if(inputGuessNumber == randomNumber) cout << "Sveikiname! Atsp�jote! Skai�ius buvo " << randomNumber << endl;
}

void FizzBuzz(const int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(i % 3 == 0 && i % 5 == 0) cout << i << " - FizzBuzz" << endl;
        else if(i % 3 == 0) cout << i << " - Fizz" << endl;
        else if(i % 5 == 0) cout << i << " - Buzz" << endl;
    }
}

int main()
{
    system("chcp 1257");

    srand(time(nullptr));

    while(true)
    {
        // Meniu
        cout << "Prad�ia" << endl;
        cout << "-----------------------------" << endl;
        cout << "Pasirinkite norim� funkcij�: " << endl;
        cout << "1. Tikrinimas ar �vesta raid� yra bals�" << endl;
        cout << "2. Rasti did�iausi� dalikl� tarp dviej� �vest� skaitmen�" << endl;
        cout << "3. Mini �aidimas, kuris sugeneruoja atsitiktin� skai�i� nuo 1 iki 100" << endl;
        cout << "4. FizzBuzz" << endl;
        cout << "5. I�eiti i� programos" << endl;
        cout << "-----------------------------" << endl;



        int choice;

        cin >> choice;

        if(cin.fail() )
        {
            cout << "[ERROR] �vedimo klaida. Pra�ome �vesti skai�i�" << endl;
            cin.clear();
            cin.ignore();
        }

        switch(choice)
        {
            case 1:
            {
                char letter;

                cout << "Pra�ome �vesti raid�: " << endl;

                cin >> letter;

                (IsCharVowel(letter)) ? cout << "�vesta raid� yra balsis" << endl : cout << "�vesta raid� n�ra balsis" << endl;

                continue;
            }
            case 2:
            {
                int skaitmenys[2];

                const int array_length = size(skaitmenys); // Masyvo ilgis

                for(int i = 0; i < array_length; i++)
                {
                    cout << "�veskite " << i+1 << "-�j�" << " skaitmen�: " << endl;

                    cin >> skaitmenys[i];

                    if(cin.fail() ) // Jeigu �vestas yra ne skaitmuo
                    {
                        cout << "[ERROR]: Pra�ome �vesti skai�i�. �veskite per naujo. " << endl;
                        cout << "�veskite " << i+1 << "-�j�" << " skaitmen�: " << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> skaitmenys[i];
                    }
                }

                cout << "Did�iausias bendras daliklis tarp skai�iaus " << skaitmenys[0] << " ir skai�iaus " << skaitmenys[1] << " yra: " << \
                    MaxDivider(skaitmenys[0], skaitmenys[1]) << endl;
                continue;
            }
            case 3:
            {
                zaidimas();
                continue;
            }
            case 4:
            {
                int n;
                cout << "�veskite teigiam� sveik�j� skai�i�: " << endl;

                cin >> n;

                if(cin.fail() )
                {
                    cout << "[ERROR]: Pra�ome �vesti skai�i�. �veskite per naujo. " << endl;
                    cout << "�veskite teigiam� sveik�j� skai�i�: " << endl;
                    cin.clear();
                    cin.ignore();
                    cin >> n;
                }

                FizzBuzz(n);

                continue;
            }
            case 5:
            {
                cout << "Pasirinkote i�eiti i� programos. Viso gero" << endl;
                return 0;
            }
            default:
            {
                cout << "�vestas neteisingas pasirinkimas" << endl;
                cout << "Pra�ome �vesti per naujo: " << endl;
                continue;
            }
        }
    }
}
