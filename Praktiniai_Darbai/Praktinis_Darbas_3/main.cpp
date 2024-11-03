#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

constexpr int Default_Array_Size = 30;

const char LT_ABC_ARRAY[32] = // Ab�c�l� saugojama masyve.
{
    'A', '�', 'B', 'C', '�', 'D', 'E', '�', '�', 'F', 'G', 'H', 'I', '�', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R',
    'S', '�', 'T', 'U', '�', '�', 'V', 'Z', '�'
};

const char ASCII_ALPHABET_ARRAY[96] =
{
    '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
    '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    ':', ';', '<', '=', '>', '?', '@',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^',
    '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'
};

int main(){
    system("chcp 1257");

    while(true)
    {
        cout << "�ifravimo/De�ifravimo sistema\n";
        cout << "� Pasirinkite: \n1 - U��ifruoti tekst�\n2 - De�ifruoti tekst�\n� �VEDIMAS: ";

        int choice;
        cin >> choice;

        if(choice > 2 || choice < 1){ // TODO: ADD cin.fail, cin.reset(), UPGRADE
            cout << "[KLAIDA]: Privalote pasirinkti [1-2] !\n";
            continue;
        }

        while(true)
        {
            cout << "� Pasirinkite: \n1 - LT ab�c�l�\n2 - ASCII koduot�\n� �VEDIMAS: ";

            int koduote, n;

            cin >> koduote;

            if(koduote > 2 || koduote < 1){ // TODO: ADD cin.fail, cin.reset() UPGRADE
                cout << "[KLAIDA]: Privalote pasirinkti tarp [1-2] !\n";
                continue;
            }

            switch(koduote){
                case 1:{
                    n = sizeof(LT_ABC_ARRAY) / sizeof(LT_ABC_ARRAY[0]);
                    break;
                }
                case 2:{
                    n = sizeof(ASCII_ALPHABET_ARRAY) / sizeof(ASCII_ALPHABET_ARRAY[0]);
                    break;
                }
                default:{
                    cout << "[KLAIDA]: SWITCH DEFAULT FAULT\n";
                    break;
                }
            }
            break;
        }

        char P[50];

        while(true){
            cout << "� �veskite pradin� tekst�:\n\t� Pradinis tekstas negali b�ti ilgesnis nei 25 simboliai\n\t\� Negali b�ti trumpesnis nei 1 simbolis\n\t� Gali b�ti sudarytas tik i� ab�c�l�je esan�i� simboli�\n� �VEDIMAS: ";

            cin >> P;



            break;
        }

        break;
    }

    return 0;
}
