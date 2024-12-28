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

// Patikrinti ar Lietuviškas numeris +370 ir ar iš 8 skaitmenų - pagal REGEX.
bool IsPhoneNumberValid(const string & phoneNumber)
{
    regex LithuanianNumber(R"(\+370\d{8})");
    return regex_match(phoneNumber, LithuanianNumber);
}

// Patikrinti ar įvestas tekstas yra raidės.
bool IsStringEntered(const string & text)
{
    for (char c : text)
    {
        if (!isalpha(c))
            return false;
    }
    return true;
}

// Pridėti naują kontaktą.
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
        cout << "• ĮVESKITE KONTAKTO VARDĄ: " << endl;

        cin >> contact[Contacts_Count].firstName;

        if (contact[Contacts_Count].firstName.empty() || !IsStringEntered(contact[Contacts_Count].firstName))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[❌]: Vardas negali būti tuščias! Ir jį turi sudaryti raidės\n";
            continue;
        }

        while (true)
        {
            cout << "• ĮVESKITE KONTAKTO PAVARDĘ: " << endl;
            cin >> contact[Contacts_Count].lastName;

            if (contact[Contacts_Count].lastName.empty() || !IsStringEntered(contact[Contacts_Count].lastName))
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "[❌]: Pavardė negali būti tuščia! Ir ją turi sudaryti raidės\n";
                continue;
            }

            while (true)
            {
                cout << "• ĮVESKITE KONTAKTO TELEFONO NUMERĮ: ";
                cin >> contact[Contacts_Count].phoneNumber;

                if (!IsPhoneNumberValid(contact[Contacts_Count].phoneNumber))
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "[❌]: Telefono numeris negali būti tuščias! Taip pat jis turi būti 8 skaitmenų ir lietuviško formato +370\n";
                    continue;
                }
                break;
            }
            break;
        }
        contact[Contacts_Count].id = Contacts_Count;
        cout << "[✅] Sukurtas naujas kontaktas, jo duomenys yra:\n";
        cout << "ID: " << contact[Contacts_Count].id+1 << " | " << "Vardas: " << contact[Contacts_Count].firstName
             << " | " << "Pavardė: " << contact[Contacts_Count].lastName << " | " << "Telefonas: "
             << contact[Contacts_Count].phoneNumber << endl;
        Contacts_Count++;

        break;
    }
}

// Išvesti kontaktus į ekraną.
void PrintOutContacts(const Contacts* contacts, const unsigned int Contacts_Count)
{
    if (Contacts_Count == 0)
    {
        cout << "[❌]: Atspausdinti kontaktų negalima, kadangi neturite nei vieno!\n";
        return;
    }
    cout << "ⓘ JŪSŲ ESAMI KONTAKTAI:\n";
    unsigned int count = 1;
    for (unsigned int i = 0; i < Contacts_Count; i++)
    {
        cout << count << ". " << "Vardas: " << contacts[i].firstName << " | "
             << "Pavardė: " << contacts[i].lastName << " | "
             << "Telefonas: " << contacts[i].phoneNumber << endl;
        count++;
    }
}

// Išlyginti kontaktus tarkime yra [0][1][2][3] ištriname 2, tad turetu buti sulyginami tokia tvarka: [0][1][2]
void SortOutContacts(Contacts*  contacts, const unsigned int Contacts_Count, const unsigned int Selected_Contact)
{
    contacts[Selected_Contact - 1] = contacts[Contacts_Count - 1];
    contacts[Selected_Contact - 1].id = Selected_Contact - 1;
    contacts[Contacts_Count - 1] = Contacts{};
}

// Ištrinti kontaktą.
void RemoveContact(Contacts* contacts, unsigned int & Contacts_Count, unsigned int & Selected_Contact)
{
    if (Contacts_Count == 0)
    {
        cout << "[❌]: Kontaktų pašalinimo veiksmas negalimas, kadangi neturite kontaktų!\n";
        return;
    }
    while (true)
    {
        cout << "• Pasirinkite kontaktą pagal ID: \n";
        cin >> Selected_Contact;

        if (cin.fail() || Selected_Contact <= 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[❌]: Privalote įvesti skaičių (didesnį negu 0)\n";
            Selected_Contact = 0;
            continue;
        }
        if (Selected_Contact > Contacts_Count)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[❌]: Tokio kontakto nėra\n";
            Selected_Contact = 0;
            continue;
        }
        while (true)
        {
            unsigned short int isUserSure = 0;
            cout << "[?] Ar tikrai norite pašalinti kontaktą? (ID: " << Selected_Contact << ")\n";
            cout << "[?] 1 - Taip\n";
            cout << "[?] 2 - Ne\n";

            cin >> isUserSure;

            if (isUserSure == 1)
            {
                contacts[Selected_Contact - 1].id = -1;
                contacts[Selected_Contact - 1].firstName = "";
                contacts[Selected_Contact - 1].lastName = "";
                contacts[Selected_Contact - 1].phoneNumber = "";
                cout << "[✅] KONTAKTAS (ID: " << Selected_Contact << ") " << "SĖKMINGAI PAŠALINTAS" << "\n";

                SortOutContacts(contacts, Contacts_Count, Selected_Contact);
                Contacts_Count--;
                Selected_Contact = 0;
            }
            else if (isUserSure == 2)
            {
                cout << "[ⓘ] PASIRINKOTE NE\n";
                Selected_Contact = 0;
                break;
            }
            else
            {
                cout << "[❌]: Privalote pasirinkti tarp 1 ir 2 [TAIP, NE]\n";
                continue;
            }
            break;
        }
        break;
    }
}

// Kontakto redagavimas.
void EditContact(Contacts* contacts, const unsigned int Contacts_Count, unsigned int & Selected_Contact)
{
    if (Contacts_Count == 0)
    {
        cout << "[❌]: Kontaktų pašalinimo veiksmas negalimas, kadangi neturite kontaktų!\n";
        return;
    }
    while (true)
    {
        cout << "• Pasirinkite kontaktą pagal ID: \n";
        cin >> Selected_Contact;

        if (cin.fail() || Selected_Contact <= 0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[❌]: Privalote įvesti skaičių (didesnį negu 0)\n";
            Selected_Contact = 0;
            continue;
        }
        if (Selected_Contact > Contacts_Count)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "[❌]: Tokio kontakto nėra\n";
            Selected_Contact = 0;
            continue;
        }
        cout << "[✅] KONTAKTAS (ID: " << Selected_Contact << ") " << "SĖKMINGAI PASIRINKTAS" << "\n";
        while (true)
        {
            unsigned int userSelection{};
            cout << "• PASIRINKITE: \n"
                    "1 - REDAGUOTI VARDĄ \n"
                    "2 - REDAGUOTI PAVARDĘ \n"
                    "3 - REDAGUOTI TELEFONO NUMERĮ \n"
                    "4 - PASIRINKTI KONTAKTĄ IŠ NAUJO \n"
                    "5 - GRĮŽTI Į MENU\n";

            cin >> userSelection;

            switch (userSelection)
            {
                case 1:
                {
                    while (true)
                    {
                        cout << "ⓘ Dabartinis kontakto (ID: " << Selected_Contact << ") vardas yra: " << contacts[Selected_Contact-1].firstName << "\n";
                        cout << "• ĮVESKITE NAUJĄ VARDĄ: \n";

                        cin >> contacts[Selected_Contact-1].firstName;
                        if (contacts[Selected_Contact-1].firstName.empty() || !IsStringEntered(contacts[Selected_Contact-1].firstName))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "[❌]: Vardas negali būti tuščias! Ir jį turi sudaryti raidės\n";
                            continue;
                        }
                        cout << "[✅] KONTAKTO (ID: " << Selected_Contact << ") " << "NAUJAS VARDAS: " << contacts[Selected_Contact-1].firstName << "\n";
                        Selected_Contact = 0;
                        break;
                    }
                    break;
                }
                case 2:
                {
                    while (true)
                    {
                        cout << "ⓘ Dabartinė kontakto (ID: " << Selected_Contact << ") pavardė yra: " << contacts[Selected_Contact-1].lastName << "\n";
                        cout << "• ĮVESKITE NAUJĄ PAVARDĘ: \n";
                        cin >> contacts[Selected_Contact-1].lastName;
                        if (contacts[Selected_Contact-1].lastName.empty() || !IsStringEntered(contacts[Selected_Contact-1].lastName))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "[❌]: Pavardė negali būti tuščia! Ir ją turi sudaryti raidės\n";
                            continue;
                        }
                        cout << "[✅] KONTAKTO (ID: " << Selected_Contact << ") " << "NAUJA PAVARDĖ: " << contacts[Selected_Contact-1].lastName << "\n";
                        Selected_Contact = 0;
                        break;
                    }
                    break;
                }
                case 3:
                {
                    while (true)
                    {
                        cout << "ⓘ Dabartinis kontakto (ID: " << Selected_Contact << ") telefono numeris yra: " << contacts[Selected_Contact-1].phoneNumber << "\n";
                        cout << "• ĮVESKITE NAUJĄ KONTAKTO TELEFONO NUMERĮ: ";
                        cin >> contacts[Selected_Contact-1].phoneNumber;

                        if (!IsPhoneNumberValid(contacts[Selected_Contact-1].phoneNumber))
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "[❌]: Telefono numeris negali būti tuščias! Taip pat jis turi būti 8 skaitmenų ir lietuviško formato +370\n";
                            continue;
                        }
                        cout << "[✅] KONTAKTO (ID: " << Selected_Contact << ") " << "NAUJAS TELEFONO NUMERIS YRA: " << contacts[Selected_Contact-1].phoneNumber << "\n";
                        Selected_Contact = 0;
                        break;
                    }
                    break;
                }
                case 4:
                {
                    while (true)
                    {
                        cout << "• Pasirinkite kontaktą pagal ID: \n";
                        cin >> Selected_Contact;

                        if (cin.fail() || Selected_Contact <= 0)
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "[❌]: Privalote įvesti skaičių (didesnį negu 0)\n";
                            Selected_Contact = 0;
                            continue;
                        }
                        if (Selected_Contact > Contacts_Count)
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "[❌]: Tokio kontakto nėra\n";
                            Selected_Contact = 0;
                            continue;
                        }
                        cout << "[✅] KONTAKTAS (ID: " << Selected_Contact << ") " << "SĖKMINGAI PASIRINKTAS" << "\n";
                        break;
                    }
                    continue;
                }
                case 5:
                {
                    cout << "ⓘ PASIRINKOTE GRĮŽTI Į MENU\n";
                    Selected_Contact = 0;
                    break;
                }
                default:
                {
                    cout << "[❌]: Tokio pasirinkimo nėra\n";
                    Selected_Contact = 0;
                    continue;
                }
            }
            break;
        }
        break;
    }
}

int main()
{
    unsigned int Contacts_Limit = 10;
    unsigned int Contacts_Count = 0;
    unsigned int Selected_Contact = 0;
    system("chcp 65001 > nul");

    cout << "Praktinis darbas 5. Užduotis 2. Programa tęsis kol pasirinksite išeiti iš programos\n";

    auto* contact = new Contacts[Contacts_Limit];

    while (true)
    {
        cout << "• PASIRINKITE:\n";
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
            cout << "[❌]: Privalote pasirinkti tarp [1-5] !\n";
            continue;
        }

        if (menuChoice == 5)
        {
            cout << "ⓘ PASIRINKOTE IŠEITI IŠ PROGRAMOS!\n";
            delete[] contact;
            contact = nullptr;
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
                EditContact(contact, Contacts_Count, Selected_Contact);
                break;
            }
            case 3:
            {
                RemoveContact(contact, Contacts_Count, Selected_Contact);
                break;
            }
            case 4:
            {
                PrintOutContacts(contact, Contacts_Count);
                break;
            }
            default: break;
        }
    }
}