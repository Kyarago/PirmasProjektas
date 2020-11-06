// ND1 Su Vektoriais.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Objektinio programavimo Pirmo namu darbo versija 0.5

#include "Mbib.h"

int main()
{
    vector<duomenys> grupe;
    list<duomenys> lgrupe;
    kurt(grupe);
    string o = "";
    int n;
    cout << "Ar norite atlikti programos veikimo laiko analize? (t / n)? : ";
    cin >> o;
    while (o != "t" && o != "n" && o != "N" && o != "T") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> o;
    }
    if (o == "t" || o == "T") {
        cout << "Kiek namu darbu pazymiu failuose? : ";
        cin >> n;
        do {
            try {
                if (cin.fail()) {
                    throw std::runtime_error("Vesti reikia skaiciu!!!\n");
                }
            }
            catch (const std::runtime_error& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Iveskite skaiciu: ";
                cin >> n;
            }
        } while (cin.fail() == true);
        laikas(grupe, 1000, n);
        llaikas(lgrupe, 1000, n);
        laikas(grupe, 10000, n);
        //laikas(grupe, 100000, n);
        //laikas(grupe, 1000000, n);
        //laikas(grupe, 10000000, n);
        llaikas(lgrupe, 10000, n);
    }
    else {
        generavimas(grupe);
        ivedimas(grupe);
        skaidymas(grupe);
        std::sort(grupe.begin(), grupe.end(), Tvarkymas);
        spausd(grupe);
        isvedimas(grupe);
        cout << endl;
        grupe.clear();
    }
}