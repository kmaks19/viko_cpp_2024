#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void NameAndStudiesReason(const string & vardas, const string & priezastis);
void KolegijosPavadinimas();
void FakultetoPavadinimas();
int RandomNumber();
int Sum(int a, int b);
int Multiply(int a, int b);
int Divide(int a, int b);
int Max(int a, int b);

int main(){

    setlocale(LC_ALL, "Lithuanian");

    // 1 punktas Uzduoties

    NameAndStudiesReason("Karolis", "Technologijos nuo maþens patiko");
    NameAndStudiesReason("Karolis", "Vienintelë sritis kur manau bûèiau tinkamas");

    // 1 punkto pabaiga

    // 2 punktas

    KolegijosPavadinimas();
    FakultetoPavadinimas();

    // 2 punkto pabaiga

    // 3 punkto pradzia

    for(int i = 0; i < 10; i++) cout << "Atsitiktinis skaièius(" << i+1 << ")" << ": " << RandomNumber() << endl;

    // 3 punkto pabaiga

    // 4 punkto pradzia

    cout << "10+20 = " << Sum(10, 20) << " ; 20*2 = " << Multiply(20, 2) << " ; 40/4 = " << Divide(40, 4) << endl;

    // 4 punkto pabaiga

    // 5 punkto pradzia

    cout << "Didþiausias skaièius tarp 3 ir 5 yra: " << Max(5, 3) << endl;
    cout << "Didþiausias skaièius tarp 4 ir 32 yra: " << Max(32, 4) << endl;

    // 5 punkto pabaiga

    return 0;
}

void NameAndStudiesReason(const string & vardas, const string & priezastis)
{
    cout << "Vardas: " << vardas << " - Prieþastis: " << priezastis << endl;
}

void KolegijosPavadinimas()
{
    cout << "Vilniaus Kolegija" << endl;
}

void FakultetoPavadinimas()
{
    cout << "Elektronikos ir informatikos fakultetas" << endl;
}

int RandomNumber(){
    return rand() % 100;
}

int Sum(int a, int b){
    return a + b;
}

int Multiply(int a, int b){
    return a * b;
}

int Divide(int a, int b){
    return a / b;
}

int Max(int a, int b){
    return a > b ? a : b;
}
