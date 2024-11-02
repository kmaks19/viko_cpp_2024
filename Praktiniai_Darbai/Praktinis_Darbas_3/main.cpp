#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

constexpr int Default_Array_Size = 30;

const char LT_ABC_ARRAY[32] = // Abëcëlë saugojama masyve.
{
    'A', 'À', 'B', 'C', 'È', 'D', 'E', 'Æ', 'Ë', 'F', 'G', 'H', 'I', 'Á', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'Ð', 'T', 'U', 'Ø', 'Û', 'V', 'Z', 'Þ'
};

const char ASCII_ALPHABET_ARRAY[94] =
{
    '!', '\u0021', '#', '$', '%', '&', '\u0027', '(', ')', '*', '+', ',', '-', \
    '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', \
    ':', ';', '<', '=', '>', '?', '@', \
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', \
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\u005C', ']', '^', \
    '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', \
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~'
};

bool IsUsingAllowedSymbols(const char EWArray[], const char ALPHABET_ARRAY[], const int EWArray_STRLEN, const int ALPHABET_ARRAY_STRLEN){
    int x = 0;
    for(int i = 0; i < EWArray_STRLEN; i++){
        for(int j = 0; j < ALPHABET_ARRAY_STRLEN; j++){
            if(EWArray[i] == ALPHABET_ARRAY[j])
                x++;
        }
    }
    return (x == EWArray_STRLEN) ? true : false;
}

void Encrypt(const char EWArray[], const char KEY_ARRAY[], char FINAL_ARRAY[], const int ALPHABET_ARRAY_STRLEN, const int EWArray_STRLEN, const int ALPHABET_OPTION){
    // ALPHABET_OPTION Koduote
    // EW_ARRAY Pradinio zodzio masyvas
    // KEY_ARRAY Ðifravimo rakto masyvas
    // ALPHABET_ARRAY_STRLEN Abëcëlës masyvo ilgis
    // EWArray_STRLEN - Pradinio masyvo zodzio ilgis
    // FINAL_ARRAY - Galutinis masyvas, kuriame saugomas galutinis þodis uþðifruotas

    for(int i = 0; i < EWArray_STRLEN; i++)
    {
        int M = 0, K = 0; // Ðie kintamieji nurodys pradinio ir ðifravimo þodþio pozicijà ALFABETO masyve.

        for(int j = 0; j < ALPHABET_ARRAY_STRLEN; j++)
        {
            switch(ALPHABET_OPTION)
            {
                case 1: {
                    if(LT_ABC_ARRAY[j] == EWArray[i]) M = j;
                    if(LT_ABC_ARRAY[j] == KEY_ARRAY[i]) K = j;
                }
                case 2: {
                    if(ASCII_ALPHABET_ARRAY[j] == EWArray[i]) M = j;
                    if(ASCII_ALPHABET_ARRAY[j] == KEY_ARRAY[i]) K = j;
                }
            }
        }
        int finalnumber = (M+K) % ALPHABET_ARRAY_STRLEN;

        switch(ALPHABET_OPTION)
        {
            case 1: {
                FINAL_ARRAY[i] = LT_ABC_ARRAY[finalnumber];
                break;
            }
            case 2: {
                FINAL_ARRAY[i] = ASCII_ALPHABET_ARRAY[finalnumber];
                break;
            }
        }
    }

    cout << "Uþðifruotas þodis ";
    for(int zx = 0; zx < EWArray_STRLEN; zx++)
        cout << FINAL_ARRAY[zx];
}

int main(){
    system("chcp 1257");

    while (true)
    {
        cout << "Ðifravimo/Deðifravimo sistema\nPasirinkite: \n1. Ðifruoti tekstà\n2. Deðifruoti tekstà\n";

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
            cout << "Pasirinkite abëcëlæ: \n1 - Lietuviø abëcëlë\n2 - ASCII koduotë\n";

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
        /* EW_Array - EntryWord_Array
         * Arba kitaip pradinio þodþio masyvas
         */
        char EW_Array[Default_Array_Size] = {0};

        while (true)
        {
            cout << "Praðome ávesti pradiná tekstà:\n\t• Pradinio teksto ilgis negali bûti ilgesnis nei 25 simboliai\n\t• Negali bûti tuðèias!\n\t• Ávesti galite tik leidþiamus pasirinktos abëcëlës simbolius\n";
            cin >> EW_Array;

            if(alphabet_option != 2) // JEIGU NE ASCII KODUOTE VERÈIAME Á DIDÞIASIAS RAIDES.
                for(char &al : EW_Array)
                    al = toupper(al);

            if (cin.fail() || strlen(EW_Array) > 25 || strlen(EW_Array) < 1 || !IsUsingAllowedSymbols(EW_Array, (alphabet_option == 1) ? LT_ABC_ARRAY : ASCII_ALPHABET_ARRAY, strlen(EW_Array),strlen_alphabet))
            {
                for(char &xd : EW_Array)
                    xd = 0; // Nustatome masyva kaip 0

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[KLAIDA]: Pradinio teksto ilgis negali bûti maþesnis negu 1 simbolis arba didesnis negu 25\nTaip pat já gali sudaryti tik simboliai leistini pasirinktoje abëcëlëje\n";
                continue;
            }
            break;
        }

        char KEY_ARRAY[Default_Array_Size] = {0};

        while(true)
        {
            cout << "Praðome ávesti raktà: \n\t• Raktas negali bûti ilgesnis nei 25 simboliai\n\t• Laukelis negali bûti tuðèias\n\t• Ávesti galite tik leidþiamus pasirinktos abëcëlës simbolius\n";
            cin >> KEY_ARRAY;

            if(alphabet_option != 2) // JEIGU NE ASCII KODUOTE VERÈIAME Á DIDÞIASIAS RAIDES.
                for(char &toup : KEY_ARRAY) // &toup representuoja masyva, ir apacioje peraso ji tiesiog, paprastesnis masyvo naudojimas.. nereikia rasyt x < ; x++ .. iskarto nuo min iki max iesko
                    toup = toupper(toup); // Verèiame raktà didþiosiomis raidëmis

            if(!IsUsingAllowedSymbols(KEY_ARRAY, (alphabet_option) ? LT_ABC_ARRAY : ASCII_ALPHABET_ARRAY, strlen(KEY_ARRAY), strlen_alphabet))
            {
                for(char &xd : KEY_ARRAY)
                    xd = 0;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[KLAIDA]: Rakto ilgis negali bûti maþesnis negu 1 simbolis arba didesnis negu 25\nTaip pat já gali sudaryti tik simboliai leistini pasirinktoje abëcëlëje\n";
                continue;
            }
            break;
        }

        if(strlen(KEY_ARRAY) < strlen(EW_Array)) // Jeigu ðifravimo raktas trumpesnis uþ pradiná tekstà
        {
            int x = 0;
            for(int i = strlen(KEY_ARRAY); i < strlen(EW_Array); i++)
            {
                if(KEY_ARRAY[x] == KEY_ARRAY[i-1])
                {
                    x++;
                    KEY_ARRAY[i] = KEY_ARRAY[x];
                }
                else
                {
                    KEY_ARRAY[i] = KEY_ARRAY[x];
                    x++;
                }
            }
        }

        /* F_ARRAY - Final ARRAY
         * Galutinis þodis.
         */
        char F_ARRAY[Default_Array_Size]; //

        switch(alphabet_option)
        {
            case 1: {
                switch(menu_option)
                {
                    case 1: {
                        Encrypt(EW_Array, KEY_ARRAY, F_ARRAY, strlen_alphabet, strlen(EW_Array), alphabet_option);
                        break;
                    }
                    case 2: {
                        //Decrypt
                        break;
                    }
                    default: {
                        cout << "[KLAIDA]: SWITCH FAULT" << endl;
                        break;
                    }
                }
                break;
            }
            case 2: {
                switch(menu_option)
                {
                    case 1: {
                        //Encrypt
                        break;
                    }
                    case 2: {
                            //Decrypt
                    }
                    default: {
                        cout << "[KLAIDA]: SWITCH FAULT" << endl;
                        break;
                    }
                }
                break;
            }
            default: {
                cout << "[KLAIDA]: SWITCH FAULT" << endl;
                break;
            }
        }
        break;
    }
    return 0;
}
