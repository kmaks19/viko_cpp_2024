#include <iostream>
#include <fstream>

using namespace std;

int main(){

    // 1 Užduotis

    ifstream read_f1;
    ofstream write_f1;

    read_f1.open("input.txt");

    int number;
    int suma = 0;
    for(int i = 0; i < 4; i++){
        read_f1 >> number;
        suma += number;
    }
    read_f1.close();

    write_f1.open("output.txt");

    write_f1 << suma;

    write_f1.close();

    // 1 pabaiga -----------------------------------------

    // 2 pradžia

    ifstream read_f2;
    ofstream write_f2;

    read_f2.open("input1.txt");

    int number_array[11];

    for(int z = 0; z < 11; z++)
        read_f2 >> number_array[z];


    read_f2.close();

    write_f2.open("output1.txt");

    for(int x = 0; x < 11; x++)
    {
        if(number_array[x] % 2 == 0) write_f2 << number_array[x] << endl;
    }

    write_f2.close();

    // 2 pabaiga -----------------------------------------

    // 3 pradžia

    ifstream read_f3;
    ofstream write_f3;

    read_f3.open("input2.txt");

    read_f3.close();

    return 0;
}
