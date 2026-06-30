#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Struct voor 1 contact
struct Contact
{
    string naam;
    string telefoon;
    string email;
};

// Lijst met alle contacten
vector<Contact> contacten;

void contactToevoegen()
{
    Contact nieuw;

    cout << "\nNaam: ";
    getline(cin, nieuw.naam);

    cout << "Telefoon: ";
    getline(cin, nieuw.telefoon);

    cout << "Email: ";
    getline(cin, nieuw.email);

    // Voeg contact toe aan de vector
    contacten.push_back(nieuw);

    cout << "\nContact toegevoegd!" << endl;
    cout << "Aantal contacten: " << contacten.size() << endl;
}

void toonContacten()
{
    if (contacten.empty())
    {
        cout << "\nGeen contacten gevonden.\n";
        return;
    }

    cout << "\n===== CONTACTEN =====\n";

    int nummer = 1;

    for (const Contact& contact : contacten)
    {
        cout << "\nContact " << nummer << endl;
        cout << "Naam      : " << contact.naam << endl;
        cout << "Telefoon  : " << contact.telefoon << endl;
        cout << "Email     : " << contact.email << endl;
        cout << "--------------------------" << endl;

        nummer++;
    }
}

void opslaan()
{
    ofstream bestand("contacten.txt");

    if (!bestand)
    {
        cout << "Kon bestand niet openen." << endl;
        return;
    }

    for (const Contact& contact : contacten)
    {
        bestand << contact.naam << ";"
                << contact.telefoon << ";"
                << contact.email << endl;
    }

    bestand.close();

    cout << "\nContacten opgeslagen!\n";
}

void laden()
{
    ifstream bestand("contacten.txt");

    if (!bestand)
    {
        return;
    }

    contacten.clear();

    Contact contact;

    while (getline(bestand, contact.naam, ';'))
    {
        getline(bestand, contact.telefoon, ';');
        getline(bestand, contact.email);

        contacten.push_back(contact);
    }

    bestand.close();
}

int main()
{
    // Laad opgeslagen contacten
    laden();

    int keuze;

    do
    {
        cout << "\n==========================" << endl;
        cout << "     CONTACTENBEHEER" << endl;
        cout << "==========================" << endl;
        cout << "1. Contact toevoegen" << endl;
        cout << "2. Contacten bekijken" << endl;
        cout << "3. Contacten opslaan" << endl;
        cout << "0. Afsluiten" << endl;
        cout << "==========================" << endl;

        cout << "Keuze: ";
        cin >> keuze;
        cin.ignore(1000, '\n'); // Verwijder Enter uit de buffer

        switch (keuze)
        {
        case 1:
            contactToevoegen();
            break;

        case 2:
            toonContacten();
            break;

        case 3:
            opslaan();
            break;

        case 0:
            // Automatisch opslaan bij afsluiten
            opslaan();
            cout << "\nProgramma afgesloten.\n";
            break;

        default:
            cout << "\nOngeldige keuze!\n";
        }

    } while (keuze != 0);

    return 0;
}