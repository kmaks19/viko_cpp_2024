#include <iostream>
#include <ratio>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Lithuanian");
    // 1 u�duotis prad�ia

    int grade0, grade1, grade2;

    cout << "�veskite pirm�j� pa�ym�: " << endl; cin >> grade0;
    cout << "�veskite antr�j� pa�ym�: " << endl; cin >> grade1;
    cout << "�veskite tre�i�j� pa�ym�: " << endl; cin >> grade2;

    int averageGrade = (grade0 + grade1 + grade2)/3;

    (averageGrade > 5) ? cout << "Vidurkis teigiamas" << endl : cout << "Vidurkis neigiamas" << endl;

    // 1 uzduoties pabaiga
    // --------------------------------------------->

    // 2 u�duotis

    int examinationGrade;

    cout << "�veskite egzamino �vartinim�: " << endl; cin >> examinationGrade;

    if(examinationGrade == 10) cout << "Puiku" << endl;
    else if(examinationGrade == 9) cout << "Labai gerai" << endl;
    else if(examinationGrade >= 7) cout << "Gerai" << endl;
    else if(examinationGrade >= 5) cout << "Patenkinamai" << endl;
    else if(examinationGrade < 5) cout << "Egzaminas nei�laikytas" << endl;

    // 2 uzduoties pabaiga
    // --------------------------------------------->

    // 4 u�duoties

    cout << "�veskite egzamino �vartinim�" << endl; cin >> examinationGrade;
    switch(examinationGrade)
    {
        case 10: cout << "Puiku" << endl; break;
        case 9: cout << "Labai gerai" << endl; break;
        case 7: cout << "Gerai" << endl; break;
        case 5: cout << "Patenkinamai" << endl; break;
        default: cout << "Vidurkis" << endl; break;
    }
    // 4  uzduoties pabaiga
    // --------------------------------------------->

    // 5 u�duotis
    int suma;
    for(int i = 1; i <= 20; i++) suma += i;
    cout << "Skai�i� suma: " << suma << endl;


    // 5  uzduoties pabaiga
    // --------------------------------------------->

    // 6 u�duotis

    int moneyCount = 1000, totalYear = 10, monthsPerYear = 12;
    float yearGrowth = 1.05, finalSum = 0; // yearGrowth metinis augimas + 5%

    finalSum = moneyCount * yearGrowth * monthsPerYear * totalYear;

    cout << "Klientas po 10 met� gaus: " << finalSum << endl;

    // 6  uzduoties pabaiga
    // --------------------------------------------->

    for(int i = 1; i <= 20; i++) (i / 4 > 0) ? cout << i : cout << endl;

    return 0;
}
