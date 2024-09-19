#include <chrono>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Lithuanian");

    // 1 uþduotis

    string Name, LastName, TitleOfSpecialty;
    int Age, Course;

    cout << "Áveskite vardà: " << Name << endl; cin >> Name;
    cout << "Áveskite pavardæ: " << LastName << endl; cin >> LastName;
    cout << "Áveskite studijø programos pavadinimà: " << TitleOfSpecialty << endl; cin >> TitleOfSpecialty;
    cout << "Áveskite amþiø: " << endl; cin >> Age;
    cout << "Áveskite kursà (1-4)" << endl; cin >> Course;

    if(Course < 1 || Course > 4)
    {
        cout << "Kursas negali bûti maþesnis uþ 1-à ir didesnis uþ 4-à" << endl;
        return 0;
    }

    cout << "Studento vardas: " << Name << endl;
    cout << "Studento pavardë " << LastName << endl;
    cout << "Studento studijø programos pavadinimas:" << TitleOfSpecialty << endl;
    cout << "Studento amþius: " << Age << endl;
    cout << "Student kursas: " << Course << endl;

    // 1 uþduoties pabaiga
    //------------------------------------->

    // 2 uþduoties pradþia

    string clubName, OwnerName, OwnerLastName, Arena;
    int ageCreated, seatCount;

    cout << "Áveskite klubo pavadinimà: " << endl; cin >> clubName;
    cout << "Áveskite savininko vardà: " << endl; cin >> OwnerName;
    cout << "Áveskite savininko pavardæ: " << endl; cin >> OwnerLastName;
    cout << "Áveskite arenos pavadinimà: " << endl; cin >> Arena;
    cout << "Áveskite ákûrimo metus: " << endl; cin >> ageCreated;
    cout << "Áveskite vietø skaièiø: " << endl; cin >> seatCount;

    cout << "Klubo pavadinimas: " << clubName << endl;
    cout << "Klubo savininko vardas: " << OwnerName << endl;
    cout << "Klubo savininko pavardë: " << OwnerLastName << endl;
    cout << "Klubo arenos pavadinimas: " << Arena << endl;
    cout << "Klubo ákurimo metai: " << ageCreated << endl;
    cout << "Klubo vietø skaièius: " << seatCount << endl;

    // 2 uþduoties pabaiga
    //------------------------------------->

    // 3 uþduoties pradþia

    string Brand, Model, Color;
    int yearManufactured;
    float Literage;

    cout << "Áveskite automobilio markæ: " << endl; cin >> Brand;
    cout << "Áveskite automobilio modelá: " << endl; cin >> Model;
    cout << "Áveskite automobilio spalvà: " << endl; cin >> Color;
    cout << "Áveskite pagaminimo metus: " << endl; cin >> yearManufactured;
    cout << "Áveskite automobilio litraþà: " << endl; cin >> Literage;

    cout << "Automobilis " << Brand << " " << Model << " yra pagamintas " << yearManufactured << " metais. " \
            "Jo motoras " << Literage << " litrø(-o). Automobilis yra " << Color << " spalvos." << endl;

    // 3 uþduoties pabaiga
    //------------------------------------->

    // 4 uþduoties pradþia

    int a = 13, b = 5;
    float c = 17.5;

    cout << "a + b - c = " << static_cast<float>(a+b) - c << endl;
    cout << "15 / 2 + c = " << (float)15/2 + c << endl;
    cout << "a / static_cast<double>(b) + 2 * c = " << (a / static_cast<double>(b)) + 2*c << endl;
    cout << "14 % 3 + 6.3 + b/a = " << (14%3) + 6.3 + (float)b/(float)a << endl;
    cout << "static_cast<int>(c) % 5 + a - b = " << (static_cast<int>(c) % 5) + (a-b) << endl;
    cout << "13.5 / 2 + 4.0 * 3.5 + 18 = " << (13.5 / 2) + (4.0*3.5) + 18 << endl;

    // 4 uþduoties pabaiga
    //------------------------------------->

    // 5 uþduoties pradþia

    int ax1, ax2, ax3, ax4, ax5;

    cout << "Áveskite skaièiø 1(-à): " << endl; cin >> ax1;
    cout << "Áveskite skaièiø 2(-à): " << endl; cin >> ax2;
    cout << "Áveskite skaièiø 3(-à): " << endl; cin >> ax3;
    cout << "Áveskite sakièiø 4(-à): " << endl; cin >> ax4;
    cout << "Áveskite skaièiø 5(-à):" << endl; cin >> ax5;

    cout << ax1 << " + " << ax2 << " + " << ax3 << " + " << ax4 << " + " << ax5 << " = " << (ax1+ax2+ax3+ax4+ax5)/5 << endl;

    // 5 uþduoties pabaiga
    //------------------------------------->

    // 6 uþduoties pradþia

    int axc1, s1, s2;
    cout << "Áveskite dviþenklá skaièiø: " << endl; cin >> axc1;

    s1 = axc1 / 10;
    s2 = axc1 % 10;

    cout << "Skaièiaus " << axc1 << " pirmas skaitmuo yra " << s1 << " , antras skaitmuo yra " << s2 << endl;

    // 6 uþduoties pabaiga
    //------------------------------------->
    return 0;
}
