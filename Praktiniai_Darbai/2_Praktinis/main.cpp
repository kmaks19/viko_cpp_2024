#include <iostream>
#include <string>
#include <ctime>
#include <array>
#include <cctype>

using namespace std;

bool IsCharVowel(const char letter) // Ar skaicius yra balsis
{
    char vowelsList[5] = { 'A', 'E', 'I', 'O', 'U'};

    for(char i : vowelsList)
    {
        return (letter == i || toupper(letter) == i) ? true : false; // Toupper - pavertimas didşiosiomis, kad nebûtø skirtumo ar ávesta maşoji ar didşioji raidë
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
    cout << "[DEBUG]: Sistemos sugeneruotas skaièius yra: " << randomNumber << endl;

    while(inputGuessNumber != randomNumber)
    {
        cout << "Bandykite atspëti skaièiø nuo 1 iki 100: " << endl;
        cin >> inputGuessNumber;

        if(inputGuessNumber < randomNumber) cout << "Ávestas skaièius " << inputGuessNumber << " buvo maşesnis uş skaièiø kurá reikia atspëti" << endl;
        else if(inputGuessNumber > randomNumber) cout << "Ávestas skaièius " << inputGuessNumber << " buvo didesnis uş skaièiø kurá reikia atspëti" << endl;
    }
    if(inputGuessNumber == randomNumber) cout << "Sveikiname! Atspëjote! Skaièius buvo " << randomNumber << endl;
}

void FizzBuzz(const int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(i % 3 == 0) cout << i << " - Fizz" << endl;
        if(i % 5 == 0) cout << i << " - Buzz" << endl;
        if(i % 3 == 0 && i % 5 == 0) cout << i << " - FizzBuzz" << endl;
    }
}

int main()
{
    system("chcp 1257");

    srand(time(nullptr));

    while(true)
    {
        // Meniu
        cout << "Pradşia" << endl;
        cout << "-----------------------------" << endl;
        cout << "Pasirinkite norimà funkcijà: " << endl;
        cout << "1. Tikrinimas ar ávesta raidë yra balsë" << endl;
        cout << "2. Rasti didşiausià daliklá tarp dviejø ávestø skaitmenø" << endl;
        cout << "3. Mini şaidimas, kuris sugeneruoja atsitiktiná skaièiø nuo 1 iki 100" << endl;
        cout << "4. FizzBuzz" << endl;
        cout << "5. Iğeiti iğ programos" << endl;
        cout << "-----------------------------" << endl;



        int choice;

        cin >> choice;

        if(cin.fail() )
        {
            cout << "[ERROR] Ávedimo klaida. Prağome ávesti skaièiø" << endl;
            cin.clear();
            cin.ignore();
        }

        switch(choice)
        {
            case 1:
            {
                char letter;

                cout << "Prağome ávesti raidæ: " << endl;

                cin >> letter;

                if(!isalpha(letter))
                {
                    cout << "[ERROR]: Ávesti privalote raidæ!" << endl;

                }

                (IsCharVowel(letter)) ? cout << "Ávesta raidë yra balsis" << endl : cout << "Ávesta raidë nëra balsis" << endl;

                continue;
            }
            case 2:
            {
                int skaitmenys[2];

                const int array_length = size(skaitmenys); // Masyvo ilgis

                for(int i = 0; i < array_length; i++)
                {
                    cout << "Áveskite " << i+1 << "-àjá" << " skaitmená: " << endl;
                    cin >> skaitmenys[i];
                }

                cout << "Didşiausias bendras daliklis tarp skaièiaus " << skaitmenys[0] << " ir skaièiaus " << skaitmenys[1] << " yra: " << \
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
                cout << "Áveskite teigiamà sveikàjá skaièiø: " << endl;

                cin >> n;

                FizzBuzz(n);

                continue;
            }
            case 5:
            {
                cout << "Pasirinkote iğeiti iğ programos. Viso gero" << endl;
                return 0;
            }
            default:
            {
                cout << "Ávestas neteisingas pasirinkimas" << endl;
                cout << "Prağome ávesti per naujo: " << endl;
                continue;
            }
        }
    }
}
