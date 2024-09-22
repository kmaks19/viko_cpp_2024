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
    cout << "Jûsø pagrindinë valiuta yra eurai" << endl;
    cout << "Pasirinkite: " << endl;

    cout << "1. Valiutos kurso palyginimas su kita valiuta." << endl;
    cout << "2. Pirkti valiutà." << endl;
    cout << "3. Parduoti valiutà." << endl;

    cin >> menuChoice;

    if(menuChoice < 1 || menuChoice > 3)
    {
        cout << "ERROR: Pasirinkite privalote tarp 1-3!" << endl;
        return 0;
    }

    double MoneyValue = 0, finalSum;

    string currencyType;

    switch(menuChoice)
    {
        case 1:
        {
            cout << "Pasirinkite pirmà valiutà, kuria norite palyginti: " << endl;

            cout << "1. GBP" << endl;
            cout << "2. USD" << endl;
            cout << "3. INR" << endl;

            int currencyChoice;

            cin >> currencyChoice;

            switch(currencyChoice)
            {
                case 1:
                {
                    cout << "Áveskite kokià sumà (eurais) norite palyginti su GBP: " << endl;
                    cin >> MoneyValue;

                   if(MoneyValue <= 0)
                   {
                       cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                       return 0;
                   }

                   finalSum = MoneyValue * GBP_Bendras;

                    break;
                }
                case 2:
                {
                   cout << "Áveskite kokià sumà (eurais) norite palyginti su USD: " << endl;
                   cin >> MoneyValue;

                   if(MoneyValue <= 0)
                   {
                        cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                        return 0;
                   }

                   finalSum = MoneyValue * USD_Bendras;

                    break;
                }
                case 3:
                {
                   cout << "Áveskite kokià sumà (eurais) norite palyginti su INR: " << endl;
                   cin >> MoneyValue;

                   if(MoneyValue <= 0)
                   {
                       cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
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
            switch(currencyChoice)
            {
                case 1:
                {
                    currencyType = "GBP";
                    break;
                }
                case 2:
                {
                    currencyType = "USD";
                    break;
                }
                case 3:
                {
                    currencyType = "INR";
                    break;
                }
                default: break;
            }

            cout << "EUR valiutà " << MoneyValue << " pavertus á " << currencyType << " gausime " << fixed << setprecision(2) << finalSum << " " << currencyType << endl;
            break;
        }
        case 2:
        {
            cout << "Pasirinkite valiutà, kurià norësite pirkti: " << endl;

            cout << "1. GBP" << endl;
            cout << "2. USD" << endl;
            cout << "3. INR" << endl;

            int currencyChoice;

            cin >> currencyChoice;

            switch(currencyChoice)
            {
                case 1:
                {
                    cout << "Áveskite kiek norësite pirkti GBP:" << endl;
                    cin >> MoneyValue;

                    if(MoneyValue <= 0)
                    {
                        cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                        return 0;
                    }

                    finalSum = MoneyValue * GBP_Pirkti;

                    break;
                }
                case 2:
                {
                    cout << "Áveskite kiek norësite pirkti USD:" << endl;
                    cin >> MoneyValue;

                    if(MoneyValue <= 0)
                    {
                        cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                        return 0;
                    }

                    finalSum = MoneyValue * USD_Pirkti;

                    break;
                }
                case 3:
                {
                    cout << "Áveskite kiek norësite pirkti INR:" << endl;
                    cin >> MoneyValue;

                    if(MoneyValue <= 0)
                    {
                        cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                        return 0;
                    }

                    finalSum = MoneyValue * INR_Pirkti;

                    break;
                }
                default:
                {
                    cout << "ERROR: Pasirinkti privalote tarp 1-3!" << endl;
                    return 0;
                }
            }

            switch(currencyChoice)
            {
                case 1:
                {
                    currencyType = "GBP";
                    break;
                }
                case 2:
                {
                    currencyType = "USD";
                    break;
                }
                case 3:
                {
                    currencyType = "INR";
                    break;
                }
                default: break;
            }

            cout << "Uþ " << MoneyValue << " EUR" << " galite nusipirkti " << fixed << setprecision(2) << finalSum << " " << currencyType << endl;

            break;
        }
        case 3:
        {
            cout << "Pasirinkite valiutà, kurià norësite parduoti: " << endl;

            cout << "1. GBP" << endl;
            cout << "2. USD" << endl;
            cout << "3. INR" << endl;

            int currencyChoice;

            cin >> currencyChoice;

            switch(currencyChoice)
            {
                case 1:
                {
                    cout << "Áveskite kiek norësite parduoti GBP:" << endl;
                    cin >> MoneyValue;

                    if(MoneyValue <= 0)
                    {
                        cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                        return 0;
                    }

                    finalSum = MoneyValue / GBP_Parduoti;

                    break;
                }
                case 2:
                {
                    cout << "Áveskite kiek norësite parduoti USD:" << endl;
                    cin >> MoneyValue;

                    if(MoneyValue <= 0)
                    {
                        cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                        return 0;
                    }

                    finalSum = MoneyValue / USD_Parduoti;

                    break;
                }
                case 3:
                {
                    cout << "Áveskite kiek norësite parduoti INR:" << endl;
                    cin >> MoneyValue;

                    if(MoneyValue <= 0)
                    {
                        cout << "Suma turi bûti ne maþesnë negu 1!" << endl;
                        return 0;
                    }
                    finalSum = MoneyValue / INR_Parduoti;

                    break;
                }
                default:
                {
                    cout << "ERROR: Pasirinkti privalote tarp 1-3!" << endl;
                    return 0;
                }
            }

            switch(currencyChoice)
            {
                case 1:
                {
                    currencyType = "GBP";
                    break;
                }
                case 2:
                {
                    currencyType = "USD";
                    break;
                }
                case 3:
                {
                    currencyType = "INR";
                    break;
                }
                default: break;
            }

            cout << MoneyValue << " " << currencyType << " pardavæ gausite: " << fixed << setprecision(2) << finalSum << " EUR" << endl;

            break;
        }
        default: break;
    }

    return 0;
}

