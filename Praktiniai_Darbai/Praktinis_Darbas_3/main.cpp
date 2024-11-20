#include <iostream>
#include <cstring>
#include <limits>

using namespace std;

constexpr int DEFAULT_ARRAY_SIZE = 30;

constexpr char LT_ABC_ARRAY[33] = // Ab�c�l� saugojama masyve.
{
    'A', '�', 'B', 'C', '�', 'D', 'E', '�', '�', 'F', 'G', 'H', 'I', '�', 'Y', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R',
    'S', '�', 'T', 'U', '�', '�', 'V', 'Z', '�', '\0' // \0 �ymi masyvo pabaig�, be jo neveikia tinkamai kodas.
};

bool IsUsingAllowedSymbols(const int encoding, const char Array[]){
    const int Array_Length = strlen(Array);
    if(encoding == 1) { // JEI LT_ABC_ARRAY
        int x = 0;
        const int Encoding_Length = strlen(LT_ABC_ARRAY);
        for(int i = 0; i < Array_Length; i++)
            for(int j = 0; j < Encoding_Length; j++)
                if(Array[i] == LT_ABC_ARRAY[j])
                    x++;
        return (x == Array_Length) ? true : false;
        // Tikrinama ar tam tikrame masyve raid�s atitinka LT ab�c�l�s masyv�, tarkime jei yra bent vienas neleistinas �enklas gra�ins false.
    }
    else if(encoding == 2) { // Jeigu ASCII koduot�
        int total = 0;
        for(int xd = 0; xd < Array_Length; xd++){
            if(static_cast<int>(Array[xd]) >= 33 && static_cast<int>(Array[xd]) <= 126)
                total++;
        }
        return (total == Array_Length) ? true : false;

        // Tikrina ar raid�s Integer reik�m� yra ribose [33-126] pagal ASCII lentel�s simbolius, kurie yra reikalingi
        // Jeigu visos raid�s yra tose ribose, gra�ina true reik�m�, jei ne false.
    }
    else {
        cout << "[KLAIDA]: Function IsUsingAllowedSymbols Fault, encoding is neither 1 nor 2\nPrograma stabdoma";
        system("pause");
        return false;
    }
}

void Encrypt(const int encoding, const char P_Array[], const char R_Array[], char Final_Array_LT[], int Final_Array_ASCII[], const int abc_letter_count){
    const int Array_Length = strlen(P_Array);
    switch(encoding){
        case 1: { // LT encoding
            int M = 0, K = 0; // M(-itasis), K(-itasis)
            for(int i = 0; i < Array_Length; i++){
                for(int j = 0; j < abc_letter_count; j++){
                    if(LT_ABC_ARRAY[j] == P_Array[i]) M = j;
                    if(LT_ABC_ARRAY[j] == R_Array[i]) K = j;
                }

                int final_number = 0;
                final_number = (M+K) % abc_letter_count; // �ifravimas ci? mi+ki(mod n),

                Final_Array_LT[i] = LT_ABC_ARRAY[final_number]; // Dedame � galutin� masyv�.
            }
            break;
        }
        case 2: { // ASCII encoding
            for(int i = 0; i < Array_Length; i++){
                const int ASCII_Value_P = static_cast<int>(P_Array[i]); // Gauname i� simbolio ASCII reik�m� pradinio �od�io (Pv� ! = 33)
                const int ASCII_Value_R = static_cast<int>(R_Array[i]); // Gauname i� simbolio ASCII reik�m� rakto (pv� ! = 33)
                if( ASCII_Value_P >= 33 && ASCII_Value_P <= 126 && ASCII_Value_R >= 33 && ASCII_Value_R <= 126 ){ // Jeigu reik�m� [33-126] Ribose tikriname
                    // Pv� Pradinis �odis ! ir raktas ! = (33+33) % dalinta i� liekanos viso ASCII ab�c�l�je esan�i� raid�i�: 66 % 93 gauname 66, tai ASCII koduot�je yra raid� B
                    Final_Array_ASCII[i] = (ASCII_Value_P + ASCII_Value_R) % abc_letter_count; // ci = mi+ki(mod n)
                }
                if(Final_Array_ASCII[i] < 33){ // ASCII reik�m� negali b�ti �emiau 33, nes nuo 33 prasideda ABC, b�davo kad �vedus @ gaudavosi reik�m� 6, tai darome kad to i�vengti
                    Final_Array_ASCII[i] += abc_letter_count;
                }
            }
            break;
        }
    }
    cout << "U��ifruotas �odis: \n";
    for(int al = 0; al < Array_Length; al++){
        if(encoding == 1)
            cout << Final_Array_LT[al];
        else if(encoding == 2)
            cout << static_cast<char>(Final_Array_ASCII[al]);
        // Paver�iame int reik�m� � char, i� i�vedame � ekran�.
        else{
            cout << "[KLAIDA]: Encrypt encoding unequal 1 nor 2.\n";
            system("pause");
        }
    }
    cout << "\n";
}

void Decrypt(const int encoding, const char P_Array[], const char R_Array[], char Final_Array_LT[], int Final_Array_ASCII[], const int abc_letter_count){
    const int Array_Length = strlen(P_Array);
    int C = 0, K = 0;
    switch(encoding){
        case 1: {
            for(int i = 0; i < Array_Length; i++){
                for(int j = 0; j < abc_letter_count; j++){
                    if(LT_ABC_ARRAY[j] == P_Array[i]) C = j;
                    if(LT_ABC_ARRAY[j] == R_Array[i]) K = j;
                }
                int final_number = C-K + (abc_letter_count % abc_letter_count);

                if(final_number < 0) final_number = abc_letter_count+(final_number);

                Final_Array_LT[i] = LT_ABC_ARRAY[final_number];
            }
            break;
        }
        case 2: {
            for(int i = 0; i < Array_Length; i++){
                const int ASCII_Value_P = static_cast<int>(P_Array[i]);
                const int ASCII_Value_R = static_cast<int>(R_Array[i]);
                if( ASCII_Value_P >= 33 && ASCII_Value_P <= 126 && ASCII_Value_R >= 33 && ASCII_Value_R <= 126 )// Jeigu reik�m� [33-126] Ribose tikriname
                    Final_Array_ASCII[i] = (ASCII_Value_P - ASCII_Value_R + abc_letter_count ) % abc_letter_count; // ci = mi+ki(mod n)
            }
            break;
        }
    }
    cout << "De�ifruotas �odis: ";
    for(int zx = 0; zx < Array_Length; zx++){
        if(encoding == 1)
            cout << Final_Array_LT[zx];
        else if(encoding == 2)
            cout << static_cast<char>(Final_Array_ASCII[zx]);
        // Paver�iame int reik�m� � char, i� i�vedame � ekran�.
        else{
            cout << "[KLAIDA]: Decrypt encoding unequal 1 nor 2.\n";
            system("pause");
        }
    }
    cout << "\n";
}

int main(){
    system("chcp 1257"); // Lietuvi�kos raid�s.

    while(true){
        cout << "�ifravimo / De�ifravimo sistema\n";
        cout << "Pasirinkite: \n1 - U��ifruoti tekst�\n2 - De�ifruoti tekst�\n3 - I�eiti\n �vedimas: ";

        int menu_choice; // Pasirinkimas menu
        cin >> menu_choice;

        if(cin.fail() || menu_choice > 3 || menu_choice < 1){
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "[KLAIDA]: Privalote pasirinkti tarp [1-2] !\n";
            continue;
            // Jeigu �vestas ne skai�ius, arba neatitinka MENU rib� [1-3]
        }

        if(menu_choice == 3){
            cout << "� PASIRINKOTE I�EITI I� PROGRAMOS\n";
            break;
        }

        int encoding; // Koduot� - 1: LT; 2 - ASCII
        int abc_letter_count; // Ab�c�l�s raid�i� strlen(), kiekis pv� JONAS - 5

        while(true){
            cout << "� Pasirinkite:\n1 - LT ab�c�l�\n2 - ASCII koduot�\n� �VEDIMAS: ";
            cin >> encoding;

            if(cin.fail() || encoding > 2 || encoding < 1){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "[KLAIDA]: Privalote pasirinkti tarp [1-2]\n";
                continue;
            }

            switch(encoding){
                // abc_letter_count, ab�c�l�s ilgis LT arba ASCII.
            case 1: {
                    // LT encoding
                    abc_letter_count = sizeof(LT_ABC_ARRAY) / sizeof(LT_ABC_ARRAY[0]);
                    break;
                }
                case 2: {
                    // ASCII encoding
                    abc_letter_count = 93; // I� viso i� ASCII table 93 simboliai reikalingi
                    break;
                }
                default: {
                    cout << "[KLAIDA]: switch(encoding) � default case FAULT\n";
                    break;
                }
            }
            break;
        }

        char P[DEFAULT_ARRAY_SIZE] = {0}; // Pradinis �odis

        while(true){
            cout << "� �veskite pradin� tekst�:\n\t� Pradinis tekstas negali b�ti ilgesnis nei 25 simboliai\n\t\� Negali b�ti trumpesnis nei 1 simbolis\n\t� Gali b�ti sudarytas tik i� ab�c�l�je esan�i� simboli�\n� �VEDIMAS: ";
            cin >> P;

            if(encoding != 2){ // Jei LT koduot�, ver�iame automati�kai � did�i�sias raides.
                for(int i = 0; i < strlen(P); i++)
                    P[i] = toupper(P[i]);
            }

            switch(encoding){
                case 1: {
                    if(cin.fail() || !IsUsingAllowedSymbols(encoding, P) || strlen(P) > 25 || strlen(P) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(int x = 0; x < 30; x++)
                            P[x] = 0; // Tu�tiname pradinio �od�io masyv�

                        cout << "[KLAIDA]: Pradinis tekstas neatitinka vieno i� reikalavim�!\n";
                        continue;
                    }

                    break;
                }
                case 2: {
                    if(cin.fail() || !IsUsingAllowedSymbols(encoding, P) || strlen(P) > 25 || strlen(P) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(int x = 0; x < 30; x++)
                            P[x] = 0; // Tu�tiname pradinio �od�io masyv�

                        cout << "[KLAIDA]: Pradinis tekstas neatitinka vieno i� reikalavim�!\n";
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        char R[DEFAULT_ARRAY_SIZE] = {0}; // Raktas

        while(true){

            cout << "� �veskite rakt�:\n\t� Raktas negali b�ti ilgesnis nei pradinis tekstas\n\t\� Negali b�ti trumpesnis nei 1 simbolis\n\t� Gali b�ti sudarytas tik i� ab�c�l�je esan�i� simboli�\n� �VEDIMAS: ";
            cin >> R;

            if(encoding == 1)
                for(int zx = 0; zx < strlen(R); zx++)
                    R[zx] = toupper(R[zx]);

            switch(encoding){
                case 1: {
                    if(cin.fail() || !IsUsingAllowedSymbols(encoding, R) || strlen(R) > strlen(P) || strlen(R) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(char & tustinti : R)
                            tustinti = 0; // Tu�tiname rakto masyv�

                        cout << "[KLAIDA]: Raktas neatitinka vieno i� reikalavim�!\n";
                        continue;
                    }

                    break;
                }
                case 2: {
                    if(cin.fail() || !IsUsingAllowedSymbols(encoding, R) || strlen(R) > strlen(P) || strlen(R) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(char & tustinti : R)
                            tustinti = 0;

                        cout << "[KLAIDA]: Raktas neatitinka vieno i� reikalavim�!\n";
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        if (strlen(R) < strlen(P)) { // Sulyginame pradin� �od� su raktu.
            int x = 0;
            for (int i = strlen(R); i < strlen(P); i++) {
                R[i] = R[x];
                x = (x + 1) % strlen(R);
            }
        }

        const int FINAL_ARRAY_SIZE_P = strlen(P);

        char G[FINAL_ARRAY_SIZE_P] = {0}; // Galutinio �ifruoto arba de�ifruoto �od�io masyvas LT encoding
        int G_ASCII[FINAL_ARRAY_SIZE_P] = {0}; // Galutinio �ifruoto arba de�ifruoto �od�io masyvas ASCII encoding

        switch(menu_choice){
            case 1: {
                Encrypt(encoding, P, R, G, G_ASCII, abc_letter_count);
                break;
            }
            case 2: {
                Decrypt(encoding, P, R, G, G_ASCII, abc_letter_count);
                break;
            }
        }
    }
    return 0;
}