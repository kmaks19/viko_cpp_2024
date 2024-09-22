#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Lithuanian");

    const float GBP_Bendras = 0.8593, GBP_Pirkti = 0.8493, GBP_Parduoti = 0.9060;

    const float USD_Bendras = 1.0713, USD_Pirkti = 1.0547, USD_Parduoti = 1.1309;

    const float INR_Bendras = 88.8260, INR_Pirkti = 85.2614, INR_Parduoti = 92.8334;

    int menuChoice;
    cout << "J�s� pagrindin� valiuta yra eurai (�)";
    cout << "Pasirinkite: " << endl;

    cout << "1. Valiutos kurso palyginimas su kita valiuta." << endl;
    cout << "2. Pirkti valiut�." << endl;
    cout << "3. Parduoti valiut�." << endl;

    cin >> menuChoice;

    if(menuChoice < 1 || menuChoice > 3)
    {
        cout << "ERROR: Pasirinkite privalote tarp 1-3!" << endl;
        return 0;
    }

    float MoneyValue = 0;

    float finalSum = 0;

    switch(menuChoice)
    {
        case 1:
        {
            cout << "Pasirinkite pirm� valiut�, kuria norite palyginti: " << endl;

            cout << "1. GBP" << endl;
            cout << "2. USD" << endl;
            cout << "3. INR" << endl;

            int currencyChoice;

            cin >> currencyChoice;

            switch(currencyChoice)
            {
                case 1:
                {
                    cout << "�veskite koki� sum� (eurais) norite palyginti su GBP: " << endl;
                    cin >> MoneyValue;

                   if(MoneyValue <= 0)
                   {
                       cout << "Suma turi b�ti ne ma�esn� negu 1!" << endl;
                       return 0;
                   }

                   finalSum = MoneyValue * GBP_Bendras;

                    break;
                }
                case 2:
                {
                   cout << "�veskite koki� sum� (eurais) norite palyginti su USD: " << endl;
                   cin >> MoneyValue;

                   if(MoneyValue <= 0)
                   {
                            cout << "Suma turi b�ti ne ma�esn� negu 1!" << endl;
                            return 0;
                   }

                   finalSum = MoneyValue * USD_Bendras;

                    break;
                }
                case 3:
                {
                   cout << "�veskite koki� sum� (eurais) norite palyginti su INR: " << endl;
                   cin >> MoneyValue;

                   if(MoneyValue <= 0)
                   {
                       cout << "Suma turi b�ti ne ma�esn� negu 1!" << endl;
                       return 0;
                   }

                    finalSum = MoneyValue * INR_Bendras;

                    break;
                }
                default:
                {
                    cout << "ERROR: Pasirinkti privalote tarp 1-3!" << endl;
                    return 0;
                }
            }

            string ValiutosTipas;
            switch(currencyChoice)
            {
                case 1: ValiutosTipas = "GBP";
                case 2: ValiutosTipas = "USD";
                case 3: ValiutosTipas = "INR";
            }

            cout << "EUR valiut� " << MoneyValue << " pavertus � " << ValiutosTipas << " gausime " << finalSum << " " << ValiutosTipas << fixed << setprecision(2) << endl;
            break;
        }
        case 2:
        {
            cout << "Pasirinkite valiut�, kuri� nor�site pirkti: " << endl;

            cout << "1. GBP" << endl;
            cout << "2. USD" << endl;
            cout << "3. INR" << endl;

            int currencyChoice;

            cin >> currencyChoice;

            switch(currencyChoice)
            {
                case 1:
                {

                }
                case 2:
                {

                }
                case 3:
                {

                }
            }

            break;
        }
        case 3:
        {
            break;
        }
    }

    return 0;
}

