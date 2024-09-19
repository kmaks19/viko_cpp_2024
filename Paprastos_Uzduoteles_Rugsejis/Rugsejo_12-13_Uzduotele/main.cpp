#include <chrono>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Lithuanian");

    // 1 u�duotis

    string Name, LastName, TitleOfSpecialty;
    int Age, Course;

    cout << "�veskite vard�: " << Name << endl; cin >> Name;
    cout << "�veskite pavard�: " << LastName << endl; cin >> LastName;
    cout << "�veskite studij� programos pavadinim�: " << TitleOfSpecialty << endl; cin >> TitleOfSpecialty;
    cout << "�veskite am�i�: " << endl; cin >> Age;
    cout << "�veskite kurs� (1-4)" << endl; cin >> Course;

    if(Course < 1 || Course > 4)
    {
        cout << "Kursas negali b�ti ma�esnis u� 1-� ir didesnis u� 4-�" << endl;
        return 0;
    }

    cout << "Studento vardas: " << Name << endl;
    cout << "Studento pavard� " << LastName << endl;
    cout << "Studento studij� programos pavadinimas:" << TitleOfSpecialty << endl;
    cout << "Studento am�ius: " << Age << endl;
    cout << "Student kursas: " << Course << endl;

    // 1 u�duoties pabaiga
    //------------------------------------->

    // 2 u�duoties prad�ia

    string clubName, OwnerName, OwnerLastName, Arena;
    int ageCreated, seatCount;

    cout << "�veskite klubo pavadinim�: " << endl; cin >> clubName;
    cout << "�veskite savininko vard�: " << endl; cin >> OwnerName;
    cout << "�veskite savininko pavard�: " << endl; cin >> OwnerLastName;
    cout << "�veskite arenos pavadinim�: " << endl; cin >> Arena;
    cout << "�veskite �k�rimo metus: " << endl; cin >> ageCreated;
    cout << "�veskite viet� skai�i�: " << endl; cin >> seatCount;

    cout << "Klubo pavadinimas: " << clubName << endl;
    cout << "Klubo savininko vardas: " << OwnerName << endl;
    cout << "Klubo savininko pavard�: " << OwnerLastName << endl;
    cout << "Klubo arenos pavadinimas: " << Arena << endl;
    cout << "Klubo �kurimo metai: " << ageCreated << endl;
    cout << "Klubo viet� skai�ius: " << seatCount << endl;

    // 2 u�duoties pabaiga
    //------------------------------------->

    // 3 u�duoties prad�ia

    string Brand, Model, Color;
    int yearManufactured;
    float Literage;

    cout << "�veskite automobilio mark�: " << endl; cin >> Brand;
    cout << "�veskite automobilio model�: " << endl; cin >> Model;
    cout << "�veskite automobilio spalv�: " << endl; cin >> Color;
    cout << "�veskite pagaminimo metus: " << endl; cin >> yearManufactured;
    cout << "�veskite automobilio litra��: " << endl; cin >> Literage;

    cout << "Automobilis " << Brand << " " << Model << " yra pagamintas " << yearManufactured << " metais. " \
            "Jo motoras " << Literage << " litr�(-o). Automobilis yra " << Color << " spalvos." << endl;

    // 3 u�duoties pabaiga
    //------------------------------------->

    // 4 u�duoties prad�ia

    int a = 13, b = 5;
    float c = 17.5;

    cout << "a + b - c = " << static_cast<float>(a+b) - c << endl;
    cout << "15 / 2 + c = " << (float)15/2 + c << endl;
    cout << "a / static_cast<double>(b) + 2 * c = " << (a / static_cast<double>(b)) + 2*c << endl;
    cout << "14 % 3 + 6.3 + b/a = " << (14%3) + 6.3 + (float)b/(float)a << endl;
    cout << "static_cast<int>(c) % 5 + a - b = " << (static_cast<int>(c) % 5) + (a-b) << endl;
    cout << "13.5 / 2 + 4.0 * 3.5 + 18 = " << (13.5 / 2) + (4.0*3.5) + 18 << endl;

    // 4 u�duoties pabaiga
    //------------------------------------->

    // 5 u�duoties prad�ia

    int ax1, ax2, ax3, ax4, ax5;

    cout << "�veskite skai�i� 1(-�): " << endl; cin >> ax1;
    cout << "�veskite skai�i� 2(-�): " << endl; cin >> ax2;
    cout << "�veskite skai�i� 3(-�): " << endl; cin >> ax3;
    cout << "�veskite saki�i� 4(-�): " << endl; cin >> ax4;
    cout << "�veskite skai�i� 5(-�):" << endl; cin >> ax5;

    cout << ax1 << " + " << ax2 << " + " << ax3 << " + " << ax4 << " + " << ax5 << " = " << (ax1+ax2+ax3+ax4+ax5)/5 << endl;

    // 5 u�duoties pabaiga
    //------------------------------------->

    // 6 u�duoties prad�ia

    int axc1, s1, s2;
    cout << "�veskite dvi�enkl� skai�i�: " << endl; cin >> axc1;

    s1 = axc1 / 10;
    s2 = axc1 % 10;

    cout << "Skai�iaus " << axc1 << " pirmas skaitmuo yra " << s1 << " , antras skaitmuo yra " << s2 << endl;

    // 6 u�duoties pabaiga
    //------------------------------------->
    return 0;
}
