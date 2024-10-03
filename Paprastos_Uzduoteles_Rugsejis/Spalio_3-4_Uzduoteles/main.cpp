#include <iostream>

using namespace std;

int suskaiciuotiPerimetra(int krastine);
void suskaiciuotiPlota(int krastine, int & plotas);
double celsiusToFahrenheit(double tempCelcius);
void fahrenheitToCelsius(double tempFahrenheit, double & tempCelcius);

int main()
{
    setlocale(LC_ALL, "Lithuanian");

    cout << "Pirma uþduotis" << endl;
    cout << "--------------------------------->" << endl;

    int plotas;
    int krastine;

    cout << "Áveskite kvadrato kraðtinës ilgá: " << endl; cin >> krastine;
    cout << "Kvadratas kurio kraðtinës ilgis yra: " << krastine << ", yra " << suskaiciuotiPerimetra(krastine) << endl;

    cout << "--------------------------------->" << endl;

    suskaiciuotiPlota(krastine, plotas);

    cout << "Kvadrato plotas: " << plotas << endl;

    cout << "--------------------------------->" << endl;

    cout << "Antra uþduotis" << endl;

    cout << "--------------------------------->" << endl;

    double tempCelsius, tempFahrenheit;

    cout << "Áveskite temperatûra Celsijais: " << endl; cin >> tempCelsius;
    cout << "Pavertus " << tempCelsius << " celsijus á Fahrenheitus, gausime: " << celsiusToFahrenheit(tempCelsius) << " F" << endl;

    cout << "Áveskite temperatûrà Fahrenheitais: " << endl; cin >> tempFahrenheit;
    fahrenheitToCelsius(tempFahrenheit, tempCelsius);
    cout << "Pavertus " << tempFahrenheit << " fahrenheitus á celsijø, gausime: " << tempCelsius<< " C" << endl;


    return 0;
}

int suskaiciuotiPerimetra(const int krastine)
{
    return krastine*4;
}

void suskaiciuotiPlota(const int krastine, int & plotas)
{
    plotas = krastine*krastine;
}

double celsiusToFahrenheit(const double tempCelcius)
{
    return ( (double) 9/5 * (tempCelcius) ) + 32;
}

void fahrenheitToCelsius(double tempFahrenheit, double & tempCelcius)
{
    tempCelcius = (double)5/9 * (tempFahrenheit - 32);
}