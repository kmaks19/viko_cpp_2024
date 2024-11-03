#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

constexpr int Default_Array_Size = 30;

const char LT_ABC_ARRAY[32] = // Ab�c�l� saugojama masyve.
{
    'A', '�', 'B', 'C', '�', 'D', 'E', '�', '�', 'F', 'G', 'H', 'I', '�', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', '�', 'T', 'U', '�', '�', 'V', 'Z', '�'
};

const char ASCII_ALPHABET_ARRAY[96] =
{
    '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', \
    '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
    ':', ';', '<', '=', '>', '?', '@', \
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', \
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', \
    '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', \
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'
};

int main(){
    system("chcp 1257");

    while (true)
    {
        cout << "�ifravimo/De�ifravimo sistema\nPasirinkite: \n1. �ifruoti tekst�\n2. De�ifruoti tekst�\n";

        int menu_option;
        cin >> menu_option;

        if (cin.fail() || menu_option < 1 || menu_option > 2)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[KLAIDA]: Pasirinkti privalote tarp [1-2] !\n";
            continue;
        }

        int alphabet_option, strlen_alphabet;

        while(true)
        {
            cout << "Pasirinkite ab�c�l�: \n1 - Lietuvi� ab�c�l�\n2 - ASCII koduot�\n";

            cin >> alphabet_option;

            if(cin.fail() | alphabet_option < 1 || alphabet_option > 2)
            {
                cout << "[KLAIDA]: Pasirinkti privalote tarp [1-2]!" << endl;
                continue;
            }

            switch (alphabet_option)
            {
                case 1: {
                    strlen_alphabet = sizeof(LT_ABC_ARRAY) / sizeof(LT_ABC_ARRAY[0]);
                    break;
                }
                case 2: {
                    strlen_alphabet = sizeof(ASCII_ALPHABET_ARRAY) / sizeof(ASCII_ALPHABET_ARRAY[0]);
                    break;
                }
                default: {
                    cout << "[KLAIDA]: SWITCH: DEFAULT FAULT \n";
                    return 0;
                }
            }
            break;
        }
        break;
    }
    return 0;
}
