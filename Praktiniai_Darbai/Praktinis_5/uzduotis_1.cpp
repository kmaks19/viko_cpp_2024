#include <iostream>
#include <limits>

using namespace std;

void PrintTable(int **array, unsigned const int d, unsigned const int zx) {
    cout << "LENTELĖ ATRODO TAIP:\n";
    for(int i = 0; i < d; i++) {
        cout << i+1 << " lentelės elementai:\n";
        for(int z = 0; z < zx; z++)
            cout << z+1 << "." << " " << array[i][z] << "\n";
    }
}

void CountEilutes(int **array, unsigned const int d, unsigned const int zx) {
    int total_value[d] = {0};
    for(int i = 0; i < d; i++)
        for(int x = 0; x < zx; x++)
            total_value[i] += array[i][x];

    cout << "EILUČIŲ SUMA ATRODO TAIP:\n";

    for(int i = 0; i < d; i++)
        cout << i+1 << " eilutės suma: " << total_value[i] << "\n";
}

void CountStulpeliai(int **array, unsigned const int d, unsigned const int zx) {
    int total_value[zx] = {0};
    for(int i = 0; i < zx; i++)
        for(int x = 0; x < d; x++)
            total_value[i] += array[x][i];

    cout << "STULPELIŲ SUMA ATRODO TAIP:\n";

    for(int i = 0; i < zx; i++)
        cout << i+1 << " stulpelio suma: " << total_value[i] << "\n";
}

void FindMaxInTable(int **array, unsigned const int d, unsigned const int zx) {
    int max_value = array[0][0];

    for(int i = 0; i < d; i++) {
        for(int x = 0; x < zx; x++) {
            if(max_value < array[i][x])
                max_value = array[i][x];
        }
    }
    cout << "Didžiausia lentelės reikšmė yra: " << max_value << "\n";
}


int main(){

    system("chcp 65001 > nul");

    while (true)
    {
        cout << "Praktinis darbas Nr 5. Užduotis Nr 1. \n";
        cout << "PRADŽIA\n";

        cout << "» Įveskite lentelės dydį: \n";

        unsigned int tableSize{};

        cin >> tableSize;

        if (cin.fail() || tableSize <= 0)
        {
            cout << "[KLAIDA]: Lentelės dydis negali būti mažesnis negu 1 ir turi būti skaičius\n";
            continue;
        }

        unsigned int tableElementsSize{};

        cout << "» Įveskite kiek elementų galės būti vienos lentelės eilutėje: \n";

        cin >> tableElementsSize;

        if (cin.fail() || tableElementsSize <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[KLAIDA]: Lentelės elementų kiekis negali būti mažesnis negu 1 ir turi būti skaičius\n";
            continue;
        }

        int **array = new int *[tableElementsSize];

        for(int i = 0; i < tableElementsSize; i++)
            array[i] = new int[tableElementsSize];

        for (int o = 0; o < tableSize; o++)
        {
            for (int p = 0; p < tableElementsSize; p++)
            {
                while (true)
                {
                    cout << "Įveskite " << o+1 << " eilutės " << p+1 << " elementą: \n";
                    cin >> array[o][p];

                    if (cin.fail() || array[o][p] <= 0)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "[KLAIDA]: Įvesti privalote skaičių! Taip pat jis negali būti mažesnis nei 1\n";
                    }
                    else break;
                }
            }
        }

        while (true)
        {
            cout << "» PASIRINKITE: \n";
            cout << "1 - Atspausdinti lentelę\n"
                    "2 - Apskaičiuoti kiekvienos eilutės sumą\n"
                    "3 - Apskaičiuoti kiekvieno stulpelio sumą\n"
                    "4 - Rasti didžiausią reikšmę lentelėje\n"
                    "5 - IŠEITI IŠ PROGRAMOS\n";

            unsigned int menuChoice{};

            cin >> menuChoice;

            if (cin.fail() || menuChoice < 1)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[KLAIDA]: Privalote įvesti skaičių, taip pat jis negali būti mažesnis nei 1\n";
                continue;
            }
            if (menuChoice == 5)
            {
                cout << "[INFO]: PASIRINKOTE IŠEITI IŠ PROGRAMOS\n";

                for (int i = 0; i < tableSize; i++)
                {
                    delete[] array[i];
                    array[i] = nullptr;
                }

                delete[] array;

                return 0;
            }

            switch (menuChoice)
            {
                case 1:
                {
                    PrintTable(array, tableSize, tableElementsSize);
                    break;
                }
                case 2:
                {
                    CountEilutes(array, tableSize, tableElementsSize);
                    break;
                }
                case 3:
                {
                    CountStulpeliai(array, tableSize, tableElementsSize);
                    break;
                }
                case 4:
                {
                    FindMaxInTable(array, tableSize, tableElementsSize);
                    break;
                }
                default: break;
            }
            break;
        }
        for (int i = 0; i < tableSize; i++)
        {
            delete[] array[i];
            array[i] = nullptr;
        }
        delete[] array;
    }
}