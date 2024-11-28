#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>

using namespace std;

constexpr int menuSize = 8; // Masyvo element� limitas
constexpr int maximumOrders = 20;

struct menuItemType
{
    string menuItem;
    float menuPrice{};
};

struct TotalOrderList
{
    unsigned int quantity{};
};

void getData(menuItemType menuList[menuSize]){
    menuList[0] = {"Kiau�inien�", 1.45},
    menuList[1] = {"Kiaulienos �onin� su keptu kiau�iniu", 2.45},
    menuList[2] = {"Keksiukas su vy�nia", 0.99},
    menuList[3] = {"Pranc�zi�kas skrebutis", 1.99},
    menuList[4] = {"Vaisi� salotos", 2.49},
    menuList[5] = {"Pusry�i� dribsniai", 0.69},
    menuList[6] = {"Kava", 0.50},
    menuList[7] = {"Arbata", 0.75};
}

void showMenu(const menuItemType menuList[]){
    for(int i = 0; i < menuSize; i++)
        cout << i+1 << ". " << menuList[i].menuItem << ". Kaina: " << menuList[i].menuPrice << "�\n";
}

void printCheck(const TotalOrderList totalOrderList[menuSize], const menuItemType itemMenu[]) {
    ofstream saskaita;
    saskaita.open("saskaita.txt");

    float totalPrice_perm{};

    constexpr int name_setw = 50;
    constexpr float price_setw = 16.5;


    saskaita << "UAB �Phoenix�\n\n";

    for (int x = 0; x < menuSize; x++) {
        if (totalOrderList[x].quantity > 0) {
            const float totalPrice_temp = itemMenu[x].menuPrice * totalOrderList[x].quantity;
            totalPrice_perm += totalPrice_temp;

            saskaita << totalOrderList[x].quantity << " "
                     << setw(name_setw-2) << left << itemMenu[x].menuItem
                     << setw(price_setw-4) << right << fixed << setprecision(2) << totalPrice_temp
                     << "�\n\n";
        }
    }

    const float taxes = totalPrice_perm * 0.21;
    totalPrice_perm += taxes;

    saskaita << setw(name_setw-1) << left << "Moke��iai:"
             << setw(price_setw-2) << right << fixed << setprecision(2) << taxes << "�" << "\n\n";
    saskaita << setw(name_setw-1) << left << "Galutin� suma:"
             << setw(price_setw-2) << right << fixed << setprecision(2) << totalPrice_perm << "�" << "\n\n";

    saskaita.close();
}

void Order(menuItemType itemMenu[menuSize], TotalOrderList totalOrder[menuSize], const unsigned int order_choice, const unsigned int order_amount, unsigned int orders_count){

    for(int j = 0; j < menuSize; j++)
        if (order_choice == j){
            totalOrder[order_choice].quantity += order_amount;
            orders_count++;
        }

    if(orders_count > maximumOrders)
    {
        cout << "� Daugiausiai galima atlikti 20 u�sakym�. U�sisakyti daugiau negalite. Pateikiu jums s�skait�:\n";
        printCheck(totalOrder, itemMenu);
        system("pause");
    }

    cout << "Orders count: " << orders_count << endl;
    cout << "� S�kmingai prid�jote " << order_amount << " vienetus patiekalo " << itemMenu[order_choice].menuItem << "\n";

    while(true)
    {
        cout << "Pasirinkite toliau: \n1 - Baigti u�sakym� ir apskai�iuoti saskait�\n2 - U�sisakyti daugiau\n";
        unsigned int choice1;
        cin >> choice1;

        if(cin.fail() || choice1 > 2 || choice1 < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[KLAIDA]: Privalote pasirinkti tarp [1-2] !\n";
            continue;
        }

        switch(choice1)
        {
            case 1: {
                printCheck(totalOrder, itemMenu);
                break;
            }
            case 2: {
                cout << "� �veskite patiekalo numer�, kur� nor�site u�sisakyti:\n";
                int dish_number{};
                cin >> dish_number;

                while(cin.fail() || dish_number < 1 || dish_number > 8)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "[KLAIDA]: Privalote pasirinkti nuo 1 iki 8 numerio (patiekalai yra 8) !\n";
                    cin >> dish_number;
                    break;
                }

                cout << "� �veskite kiek vienet� �io patiekalo nor�site u�sisakyti: \n";
                int dish_amount{};
                cin >> dish_amount;

                Order(itemMenu, totalOrder, dish_number-1, dish_amount, orders_count);
                break;
            }
            default: {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[KLAIDA]: Privalote pasirinkti tarp [1-2]:\n";
                break;
            }
        }
        break;
    }
}

int main(){

    system("chcp 1257");

    menuItemType menuList[menuSize];
    TotalOrderList totalOrder[menuSize];
    getData(menuList);

    cout << "Sveiki atvyk� � restoran� UAB �Phoenix�\n";
    while(true)
    {
        cout << "Pasirinkite:\n1 - �i�r�ti meniu\n2 - U�sisakyti\n3 - I�eiti\n";

        unsigned int menu_choice{};
        cin >> menu_choice;

        if(cin.fail() || menu_choice > 3 || menu_choice < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[KLAIDA]: Privalote pasirinkti tarp [1-3] !\n";
            continue;
        }

        switch(menu_choice)
        {
            case 1: {
                showMenu(menuList);
                continue;
            }
            case 2: {
                unsigned int order_choice{};
                cout << "�veskite patiekalo numer�, kur� norite pasirinkti: \n";
                cin >> order_choice;

                if(cin.fail() || order_choice > 8 || order_choice < 1)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "[KLAIDA]: Privalote pasirinkti tarp [1-8] (patiekalai yra 8) !\n";
                    cout << "�veskite patiekalo numer�, kur� norite pasirinkti: \n";
                    cin >> order_choice;
                }

                unsigned int order_amount{};
                cout << "Kiek vienet� nor�site u�sisakyti?\n";
                cin >> order_amount;

                Order(menuList, totalOrder, order_choice-1, order_amount, 0);

                break;
            }
            case 3: {
                cout << "Pasirinkote i�eiti i� programos. Viso gero.\n";
                break;
            }
            default: {
                cout << "[KLAIDA]: Privalote pasirinkti tarp [1-3] !\n";
                continue;
            }
        }
        break;
    }


    return 0;
}
