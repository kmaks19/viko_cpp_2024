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
        int X = 0, Y = 0; // Kintamieji kurie nurodys pradinio �od�io ir �ifravimo rakto X-osios raid�s viet� AB�C�L�S MASYVE.

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
    cout << "U��ifruotas �odis: ";
    for(int al = 0; al < P_MasyvoIlgis_STRLEN; al++)
        cout << G[al];
}

void Decrypt(char P[], const char R[], const int n, const int P_MasyvoIlgis_STRLEN, const int koduote){ // n yra abc ilgis.
    int X = 0, Y = 0; // Nurodys �od�io ir rakto raid�s viet� ab�c�l�je.

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
    cout << "De�ifruotas �odis: ";
    for(int zx = 0; zx < P_MasyvoIlgis_STRLEN; zx++)
        cout << P[zx];
}


int main(){
    system("chcp 1257");

    while(true)
    {
        cout << "�ifravimo/De�ifravimo sistema\n";
        cout << "� Pasirinkite: \n1 - U��ifruoti tekst�\n2 - De�ifruoti tekst�\n� �VEDIMAS: ";

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
            cout << "� Pasirinkite: \n1 - LT ab�c�l�\n2 - ASCII koduot�\n� �VEDIMAS: ";

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
            cout << "� �veskite pradin� tekst�:\n\t� Pradinis tekstas negali b�ti ilgesnis nei 25 simboliai\n\t\� Negali b�ti trumpesnis nei 1 simbolis\n\t� Gali b�ti sudarytas tik i� ab�c�l�je esan�i� simboli�\n� �VEDIMAS: ";

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

                       cout << "[KLAIDA]: Pradinis tekstas neatitinka vieno i� reikalavim�!\n";
                       continue;
                   }
                    for(int xd = 0; xd < strlen(P); xd++)
                         P[xd] = toupper(P[xd]); // Paver�iame raides did�iosiomis

                    break;
                }
                case 2: {
                    if(cin.fail() || !IsUsingAllowedSymbols(P, ASCII_ALPHABET_ARRAY, strlen(P), n) || strlen(P) > 25 || strlen(P) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(int x = 0; x < 30; x++)
                            P[x] = 0;

                        cout << "[KLAIDA]: Pradinis tekstas neatitinka vieno i� reikalavim�!\n";
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        char R[Default_Array_Size] = {0}; // Ilgis toks pats kaip pradinio �od�io.

        while(true){
            cout << "� �veskite rakt�:\n\t� Raktas negali b�ti ilgesnis nei pradinis tekstas\n\t\� Negali b�ti trumpesnis nei 1 simbolis\n\t� Gali b�ti sudarytas tik i� ab�c�l�je esan�i� simboli�\n� �VEDIMAS: ";

            cin >> R;

            switch(koduote)
            {
                case 1: {
                    if(cin.fail() || !IsUsingAllowedSymbols(P, LT_ABC_ARRAY, strlen(P), n) || strlen(R) > strlen(P) || strlen(P) < 1){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        for(int x = 0; x < 30; x++)
                            R[x] = 0;

                        cout << "[KLAIDA]: Raktas neatitinka vieno i� reikalavim�!\n";
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

                        cout << "[KLAIDA]: Raktas neatitinka vieno i� reikalavim�!\n";
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        if(strlen(R) < strlen(P)){ // Jeigu �ifravimo raktas trumpesnis u� pradin� tekst�
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
        } // Pv� �odis LABAS, RAKTAS KEY, TR�KSTA DVIEJ� RAID�I� TAI DARA�OMA, BUS KEYKE GALUTINIS.

        char G[Default_Array_Size]; // Galutinis Masyvas tokio pa�io ilgio koks pradinis �odis.

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
