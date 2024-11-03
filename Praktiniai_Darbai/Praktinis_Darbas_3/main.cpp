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

const char ASCII_ALPHABET_ARRAY[93] =
{
    '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
    'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z', '{', '|', '}',
    '~'
};

bool IsUsingAllowedSymbols(const char Masyvas[], const char ABCMasyvas[], const int P_MasyvoIlgis_STRLEN, const int ABCIlgis){
    int x = 0;
    for(int i = 0; i < P_MasyvoIlgis_STRLEN; i++){
        for(int j = 0; j < ABCIlgis; j++){
            if(Masyvas[i] == ABCMasyvas[j])
                x++;
        }
    }
    if(x == P_MasyvoIlgis_STRLEN) return true;
    else return false;
}

void Encrypt(const char P[], const char R[], char G[], const int n, const int P_MasyvoIlgis_STRLEN, const int koduote){ // MasyvoIlgis 30.
    for(int i = 0; i < P_MasyvoIlgis_STRLEN; i++){
        int X = 0, Y = 0; // Kintamieji kurie nurodys pradinio þodþio ir ðifravimo rakto X-osios raidës vietà ABËCËLËS MASYVE.

        for(int j = 0; j < n; j++){
            switch(koduote){
                case 1: {
                    if(LT_ABC_ARRAY[j] == P[i]) X = j;
                    if(LT_ABC_ARRAY[j] == R[i]) Y = j;
                    break;
                }
                case 2:{
                    if(ASCII_ALPHABET_ARRAY[j] == P[i]) X = j;
                    if(ASCII_ALPHABET_ARRAY[j] == R[i]) Y = j;
                    break;
                }
            }
        }

        int final_number = 0;

        cout << "X = " << X << endl;
        cout << "Y = " << Y << endl;

        final_number = (X + Y) % n; // C(itasis) = M(itasis) + K(itasis ) ( mod n)

        cout << X <<" + " << Y << " % " << n << " = " << final_number << endl;

        switch(koduote){
            case 1:{
                G[i] = LT_ABC_ARRAY[final_number];
                break;
            }
            case 2:{
                G[i] = ASCII_ALPHABET_ARRAY[final_number];
                break;
            }
        }
    }
    cout << "Uþðifruotas þodis: ";
    for(int al = 0; al < P_MasyvoIlgis_STRLEN; al++)
        cout << G[al];
}

void Decrypt(char P[], const char R[], const int n, const int P_MasyvoIlgis_STRLEN, const int koduote){ // n yra abc ilgis.
    int X = 0, Y = 0; // Nurodys þodþio ir rakto raidës vietà abëcëlëje.

    for(int i = 0; i < P_MasyvoIlgis_STRLEN; i++){
        for(int j = 0; j < n; j++){
            switch(koduote){
                case 1: {
                    if(LT_ABC_ARRAY[j] == P[i]) X = j;
                    if(LT_ABC_ARRAY[j] == R[i]) Y = j;
                }
                case 2:{
                    if(ASCII_ALPHABET_ARRAY[j] == P[i]) X = j;
                    if(ASCII_ALPHABET_ARRAY[j] == R[i]) Y = j;
                }
            }
        }
        int final_number = X-Y + (n%n);

        if(final_number < 0) final_number = n+(final_number);

        switch(koduote){
            case 1:{
                P[i] = LT_ABC_ARRAY[final_number];
                break;
            }
            case 2:{
                P[i] = ASCII_ALPHABET_ARRAY[final_number];
                break;
            }
        }
    }
    cout << "Deðifruotas þodis: ";
    for(int zx = 0; zx < P_MasyvoIlgis_STRLEN; zx++)
        cout << P[zx];
}


int main(){
    system("chcp 1257");

    while(true)
    {
        cout << "Ðifravimo/Deðifravimo sistema\n";
        cout << "» Pasirinkite: \n1 - Uþðifruoti tekstà\n2 - Deðifruoti tekstà\n» ÁVEDIMAS: ";

        int choice;
        cin >> choice;

        if(cin.fail() || choice > 2 || choice < 1){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[KLAIDA]: Privalote pasirinkti [1-2] !\n";
            continue;
        }

        int koduote, n;

        while(true){
            cout << "» Pasirinkite: \n1 - LT abëcëlë\n2 - ASCII koduotë\n» ÁVEDIMAS: ";

            cin >> koduote;

            if(cin.fail() || koduote > 2 || koduote < 1){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

        char P[Default_Array_Size] = {0};

        while(true){
            cout << "» Áveskite pradiná tekstà:\n\t• Pradinis tekstas negali bûti ilgesnis nei 25 simboliai\n\t\• Negali bûti trumpesnis nei 1 simbolis\n\t• Gali bûti sudarytas tik ið abëcëlëje esanèiø simboliø\n» ÁVEDIMAS: ";

            cin >> P;

            if(koduote != 2){
                for(int i = 0; i < strlen(P); i++)
                    P[i] = toupper(P[i]);
            }

            switch(koduote)
            {
                case 1: {
                   if(cin.fail() || !IsUsingAllowedSymbols(P, LT_ABC_ARRAY, strlen(P), n) || strlen(P) > 25 || strlen(P) < 1){
                       cin.clear();
                       cin.ignore(numeric_limits<streamsize>::max(), '\n');

                       for(int x = 0; x < 30; x++)
                           P[x] = 0;

                       cout << "[KLAIDA]: Pradinis tekstas neatitinka vieno ið reikalavimø!\n";
                       continue;
                   }
                    for(int xd = 0; xd < strlen(P); xd++)
                         P[xd] = toupper(P[xd]); // Paverèiame raides didþiosiomis

                    break;
                }
                case 2: {
                    if(cin.fail() || !IsUsingAllowedSymbols(P, ASCII_ALPHABET_ARRAY, strlen(P), n) || strlen(P) > 25 || strlen(P) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(int x = 0; x < 30; x++)
                            P[x] = 0;

                        cout << "[KLAIDA]: Pradinis tekstas neatitinka vieno ið reikalavimø!\n";
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        char R[Default_Array_Size] = {0}; // Ilgis toks pats kaip pradinio þodþio.

        while(true){
            cout << "» Áveskite raktà:\n\t• Raktas negali bûti ilgesnis nei pradinis tekstas\n\t\• Negali bûti trumpesnis nei 1 simbolis\n\t• Gali bûti sudarytas tik ið abëcëlëje esanèiø simboliø\n» ÁVEDIMAS: ";

            cin >> R;

            switch(koduote)
            {
                case 1: {
                    if(cin.fail() || !IsUsingAllowedSymbols(P, LT_ABC_ARRAY, strlen(P), n) || strlen(R) > strlen(P) || strlen(P) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(int x = 0; x < 30; x++)
                            R[x] = 0;

                        cout << "[KLAIDA]: Raktas neatitinka vieno ið reikalavimø!\n";
                        continue;
                    }

                    for(int zx = 0; zx < strlen(P); zx++)
                        R[zx] = toupper(R[zx]);

                    break;
                }
                case 2: {
                    if(cin.fail() || !IsUsingAllowedSymbols(P, ASCII_ALPHABET_ARRAY, strlen(P), n) || strlen(R) > strlen(P) || strlen(R) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(int x = 0; x < 30; x++)
                            R[x] = 0;

                        cout << "[KLAIDA]: Raktas neatitinka vieno ið reikalavimø!\n";
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        if(strlen(R) < strlen(P)){ // Jeigu ðifravimo raktas trumpesnis uþ pradiná tekstà
            int x = 0;
            for(int i = strlen(R); i < strlen(P); i++){
                if(R[x] == R[i-1]){
                    x++;
                    R[i] = R[x];
                }
                else{
                    R[i] = R[x];
                    x++;
                }
            }
        } // Pvþ Þodis LABAS, RAKTAS KEY, TRÛKSTA DVIEJØ RAIDÞIØ TAI DARAÐOMA, BUS KEYKE GALUTINIS.

        char G[Default_Array_Size]; // Galutinis Masyvas tokio paèio ilgio koks pradinis þodis.

        switch(choice){
            case 1: {
                Encrypt(P, R, G, n, strlen(P), koduote);
                break;
            }
            case 2:{
                Decrypt(P, R, n, strlen(P), koduote);
                break;
            }
        }
        break;
    }

    return 0;
}
