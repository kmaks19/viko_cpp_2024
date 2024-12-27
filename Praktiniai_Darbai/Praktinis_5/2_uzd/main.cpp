#include <iostream>
#include <limits>
#include <regex>

using namespace std;

struct Contacts
{
    unsigned int id{};
    string firstName;
    string lastName;
    string phoneNumber;
};

bool IsPhoneNumberValid(const string & telefonas)
{
    regex LithuanianNumber(R"(\+370\d{8})"); // Lietuviskas ir ar 8 skaiciai.
    return regex_match(telefonas, LithuanianNumber);
}

void AddContact(Contacts* & contact, unsigned int & Contacts_Limit, unsigned int & Contacts_Count)
{
    if (Contacts_Limit == Contacts_Count) // Jei masyuvas pasiekia limitą
    {
        Contacts_Limit += 10;

        auto* temp = new Contacts[Contacts_Limit];

        for (int i = 0; i < Contacts_Count; i++)
            temp[i] = contact[i];

        delete[] contact;
        contact = temp;
    }

    while (true)
    {
        cout << "ĮVESKITE KONTAKTO VARDĄ: " << endl;

        cin >> contact[Contacts_Count].firstName;

        if (contact[Contacts_Count].firstName.empty())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[KLAIDA]: Vardas negali būti tuščias!\n";
            continue;
        }

        while (true)
        {
            cout << "ĮVESKITE KONTAKTO PAVARDĘ: " << endl;
            cin >> contact[Contacts_Count].lastName;

            if (contact[Contacts_Count].lastName.empty())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "[KLAIDA]: Pavardė negali būti tuščia!\n";
                continue;
            }

            while (true)
            {
                cout << "ĮVESKITE KONTAKTO TELEFONO NUMERĮ: ";
                cin >> contact[Contacts_Count].phoneNumber;

                if (!IsPhoneNumberValid(contact[Contacts_Count].phoneNumber))
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "[KLAIDA]: Telefono numeris negali būti tuščias! Taip pat jis turi būti 8 skaitmenų ir lietuviško formato +370\n";
                    continue;
                }
                break;
            }
            break;
        }
        contact[Contacts_Count].id = Contacts_Count;
        cout << "Sukurtas naujas kontaktas, jo duomenys yra:\n";
        cout << "ID: " << contact[Contacts_Count].id << " | " << "Vardas: " << contact[Contacts_Count].firstName
             << " | " << "Pavardė: " << contact[Contacts_Count].lastName << " | " << "Telefonas: "
             << contact[Contacts_Count].phoneNumber << endl;
        Contacts_Count += 1;

        break;
    }
}



int main()
{
    unsigned int Contacts_Limit = 10;
    unsigned int Contacts_Count = 0;
    system("chcp 65001 > nul");

    cout << "Praktinis darbas 5. Užduotis 2. Programa tęsis kol pasirinksite išeiti iš programos\n";

    auto* contact = new Contacts[Contacts_Limit];

    while (true)
    {
        cout << "PASIRINKITE:\n";
        cout << "1 - Pridėti kontaktą\n"
                "2 - Redaguoti kontaktą\n"
                "3 - Pašalinti kontaktą\n"
                "4 - Atspausdinti kontaktus\n"
                "5 - IŠEITI IŠ PROGRAMOS\n";

        unsigned int menuChoice;
        cin >> menuChoice;

        if (cin.fail() || menuChoice <= 0 || menuChoice > 5)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[KLAIDA]: Privalote pasirinkti tarp [1-5] !\n";
            continue;
        }

        if (menuChoice == 5)
        {
            cout << "PASIRINKOTE IŠEITI IŠ PROGRAMOS!\n";
            delete[] contact;
            return 0;
        }

        switch (menuChoice)
        {
            case 1:
            {
                AddContact(contact, Contacts_Limit, Contacts_Count);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            default: break;
        }
    }
}