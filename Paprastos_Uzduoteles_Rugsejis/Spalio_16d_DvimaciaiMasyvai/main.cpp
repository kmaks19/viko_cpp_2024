#include <iostream>

using namespace std;

int ArraySum(const int Array[], const int array_length)
{
    int sum = 0;
    for(int i = 0; i < array_length; i++) sum += Array[i];
    return sum;
}

int Array_Max(const int Array[], const int array_length)
{
    int max = Array[0];
    for(int i = 0; i < array_length; i++) if(Array[i] > max) max = Array[i];
    return max;
}

int Array_Min(const int Array[], const int array_length)
{
    int lowest_value = Array[0];
    for(int i = 0; i < array_length; i++) if(Array[i] < lowest_value) lowest_value = Array[i];
    return lowest_value;
}

void IvertinimuPasikartojimas(const int Array[], const int array_length)
{
    int pasikartojimas[11] = {0};

    for(int i = 0; i < array_length; i++)
    {
        if(Array[i] >= 1 && Array[i] <= 10)
        {
            pasikartojimas[Array[i]]++;
        }
    }

    for(int i = 1; i <= 10; i++)
    {
        cout << i << " balø buvo gauta: " << pasikartojimas[i] << " kartus" << endl;
     }
}

int main()
{
    system("chcp 1257");

    // 1 uþduoties pradþia

    int array[6];

    for(int i = 1; i <= 6; i++)
    {
        int skaicius;

        cout << "Áveskite " << i << "-à" << " sveikàjá skaièiø: " << endl;

        cin >> skaicius;

        array[i-1] = skaicius;
    }

    int length_of_array = sizeof( array ) / sizeof( array[0] );

    cout << "Masyvo elementø suma yra: " << ArraySum(array, length_of_array) << endl;

    cout << "Didþiausias elementas yra: " << Array_Max(array, length_of_array) << endl;

    cout << "Maþiausias elementas yra: " << Array_Min(array, length_of_array) << endl;

    // 1 uþduoties pabaiga

    // 2 uþduoties pradþia

    int numberOfStudentsAttended = 40;
    int rating[numberOfStudentsAttended];
    int array_length_l = sizeof(rating) / sizeof( rating[0] );

    for(int j = 1; j <= 40; j++)
    {
        cout << "Ávertinkite nuo 1 iki 10 balø: " << endl;

        cin >> rating[j-1];
    }

    IvertinimuPasikartojimas(rating, array_length_l);

    return 0;
}