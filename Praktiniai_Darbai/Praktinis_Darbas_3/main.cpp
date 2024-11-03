#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

constexpr int Default_Array_Size = 30;

const char LT_ABC_ARRAY[32] = // Abëcëlë saugojama masyve.
{
    'A', 'À', 'B', 'C', 'È', 'D', 'E', 'Æ', 'Ë', 'F', 'G', 'H', 'I', 'Á', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R',
    'S', 'Ð', 'T', 'U', 'Ø', 'Û', 'V', 'Z', 'Þ'
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
        cout << "Ðifravimo/Deðifravimo sistema\n";
        cout << "» Pasirinkite: \n1 - Uþðifruoti tekstà\n2 - Deðifruoti tekstà\n» ÁVEDIMAS: ";

        int choice;
        cin >> choice;

        if(choice > 2 || choice < 1){ // TODO: ADD cin.fail, cin.reset(), UPGRADE
            cout << "[KLAIDA]: Privalote pasirinkti [1-2] !\n";
            continue;
        }

        while(true)
        {
            cout << "» Pasirinkite: \n1 - LT abëcëlë\n2 - ASCII koduotë\n» ÁVEDIMAS: ";

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
            cout << "» Áveskite pradiná tekstà:\n\t• Pradinis tekstas negali bûti ilgesnis nei 25 simboliai\n\t\• Negali bûti trumpesnis nei 1 simbolis\n\t• Gali bûti sudarytas tik ið abëcëlëje esanèiø simboliø\n» ÁVEDIMAS: ";

            cin >> P;



            break;
        }

        break;
    }

    return 0;
}
