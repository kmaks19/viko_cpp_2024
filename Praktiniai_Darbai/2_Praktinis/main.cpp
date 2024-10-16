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
        cout << "Pradþia" << endl;
        cout << "-----------------------------" << endl;
        cout << "Pasirinkite norimà funkcijà: " << endl;
        cout << "1. Tikrinimas ar ávesta raidë yra balsë" << endl;
        cout << "2. Rasti didþiausià daliklá tarp dviejø ávestø skaitmenø" << endl;
        cout << "3. Mini þaidimas, kuris sugeneruoja atsitiktiná skaièiø nuo 1 iki 100" << endl;
        cout << "4. FizzBuzz" << endl;
        cout << "5. Iðeiti ið programos" << endl;
        cout << "-----------------------------" << endl;



        int choice;

        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                char letter;

                cout << "Praðome ávesti raidæ: " << endl;

                cin >> letter;

                if(IsCharVowel(letter)) cout << "Ávesta raidë yra balsis" << endl;
                else cout << "Ávesta raidë nëra balsis" << endl;

                continue;
            }
            case 2:
            {
                int skaitmenys[2];

                int array_length = sizeof(skaitmenys) / sizeof(skaitmenys[0]);

                for(int i = 0; i < array_length; i++)
                {
                    cout << "Áveskite " << i+1 << "-àjá" << " skaitmená: " << endl;
                    cin >> skaitmenys[i];
                }

                cout << "Didþiausias bendras daliklis tarp skaièiaus " << skaitmenys[0] << " ir skaièiaus " << skaitmenys[1] << " yra: " << \
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
                cout << "Pasirinkote iðeiti ið programos. Viso gero" << endl;
                return 0;
            }
            default:
            {
                cout << "Ávestas neteisingas pasirinkimas" << endl;
                cout << "Praðome ávesti per naujo: " << endl;

                cout << "-----------------------------" << endl;
                cout << "1. Tikrinimas ar ávesta raidë yra balsë" << endl;
                cout << "2. Rasti didþiausià daliklá tarp dviejø ávestø skaitmenø" << endl;
                cout << "3. Mini þaidimas, kuris sugeneruoja atsitiktiná skaièiø nuo 1 iki 100" << endl;
                cout << "4. FizzBuzz" << endl;
                cout << "5. Iðeiti ið programos" << endl;
                cout << "-----------------------------" << endl;

                cin >> choice;
            }
        }
        break;
    }
    return 0;
}
