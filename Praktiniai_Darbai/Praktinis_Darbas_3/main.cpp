#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

const char LT_ABC_ARRAY[32] =
{
    'A', 'À', 'B', 'C', 'È', 'D', 'E', 'Æ', 'Ë', 'F', 'G', 'H', 'I', 'Á', 'Y', 'J', \
    'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'Ð', 'T', 'U', 'Ø', 'Û', 'V', 'Z', 'Þ'
};

const char ASCII_ARRAY[94] =
{
    '!', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', \
    '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
    ':', ';', '<', '=', '>', '?', '@', \
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', \
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', \
    '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', \
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'
};

const int MAX_Array_Length = 26;

int main()
{
    system("chcp 1257");

    while(true)
    {
        cout << "Ðifravimo & Deðifravimo sistema" << endl;
        cout << "Pasirinkite: " << endl;
        cout << "1 - Uþðifruoti tekstà" << endl;
        cout << "2 - Deðifruoti tekstà" << endl;

        int choice; // Meniu pasirinkimas

        cin >> choice;

        if(choice > 2 || choice < 1)
        {
            cout << "[KLAIDA]: Tokio meniu pasirinkimo nëra" << endl;
            continue;
        }

        cout << "Pasirinkite:\n1 - LT abëcëlë\n2 - ASCII koduotë\n";
        int alphabet_choice; // Koduotës pasirinkimas.
        cin >> alphabet_choice;

        int n = (alphabet_choice == 1) ? sizeof(LT_ABC_ARRAY) / sizeof(LT_ABC_ARRAY[0]) : sizeof(ASCII_ARRAY) / sizeof(ASCII_ARRAY[0]);

        if (alphabet_choice < 1 || alphabet_choice > 2)
        {
            cout << "[KLAIDA]: Toks pasirinkimas negalimas (neegzistuoja)!" << endl;
            continue;
        }

        char M[28] = {0};

        while(true)
        {
            cout << "Áveskite pradiná tekstà [MAX 25 SIMB]: " << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cin >> M;

            const int length = strlen(M); // Masyvo raidziu kiekio ilgssis.

            if(length > MAX_Array_Length || length < 1)
            {
                cout <<"\n[KLAIDA]: Pradinis tekstas negali bûti ilgesnis negu 25 simboliai arba buti 0 simboliu!\n";
                continue;
            }
            break;
        }



        break;
    }
    return 0;
}
