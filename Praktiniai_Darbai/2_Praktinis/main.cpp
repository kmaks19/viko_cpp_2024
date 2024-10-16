#include <iostream>
#include <string>

using namespace std;

bool IsCharVowel(char letter)
{
    char vowelsList[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };

    for(char i : vowelsList)
    {
        if(letter == i) return true;
    }
    return false;
}

int MaxDivider(int skaicius1, int skaicius2)
{
    while(abs(skaicius1) && abs(skaicius2))
        if(abs(skaicius1) > abs(skaicius2)) skaicius1 %= skaicius2;
            else skaicius2 %= skaicius1;
    return skaicius1 + skaicius2;
}

int main()
{
    system("chcp 1257");
    while(true)
    {
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

        switch(choice)
        {
            case 1:
            {
                char letter;

                cout << "Pra�ome �vesti raid�: " << endl;

                cin >> letter;

                if(IsCharVowel(letter)) cout << "�vesta raid� yra balsis" << endl;
                else cout << "�vesta raid� n�ra balsis" << endl;

                continue;
            }
            case 2:
            {
                int skaitmenys[2];

                int array_length = sizeof(skaitmenys) / sizeof(skaitmenys[0]);

                for(int i = 0; i < array_length; i++)
                {
                    cout << "�veskite " << i+1 << "-�j�" << " skaitmen�: " << endl;
                    cin >> skaitmenys[i];
                }

                cout << "Did�iausias bendras daliklis tarp skai�iaus " << skaitmenys[0] << " ir skai�iaus " << skaitmenys[1] << " yra: " << \
                    MaxDivider(skaitmenys[0], skaitmenys[1]) << endl;
                continue;
            }
            case 3:
            {

            }
            case 4:
            {

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

                cout << "-----------------------------" << endl;
                cout << "1. Tikrinimas ar �vesta raid� yra bals�" << endl;
                cout << "2. Rasti did�iausi� dalikl� tarp dviej� �vest� skaitmen�" << endl;
                cout << "3. Mini �aidimas, kuris sugeneruoja atsitiktin� skai�i� nuo 1 iki 100" << endl;
                cout << "4. FizzBuzz" << endl;
                cout << "5. I�eiti i� programos" << endl;
                cout << "-----------------------------" << endl;

                cin >> choice;
            }
        }
        break;
    }
    return 0;
}
