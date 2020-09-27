// ND1 Su Vektoriais.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

struct duomenys {
    string Vardas = "";
    string Pavarde = "";
    int Namu[10];
    int Egzaminas;
    int ivestis;
    float Galutinis = 0;
    float mediana;
};

int main()
{
    vector<duomenys> grupe;
    duomenys stud;
    int n = 0;
    cout << "Iveskite studentu skaiciu: ";
    cin >> n;
    grupe.reserve(n);
    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << "-aji varda: ";
        cin >> stud.Vardas;
        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
        cin >> stud.Pavarde;
        cout << "Iveskite " << i + 1 << "-ojo studento egzamina: ";
        cin >> stud.Egzaminas;
        while (stud.Egzaminas < 1 || stud.Egzaminas > 10) {
            cout << "Ivestas negalimas pazimys, veskite is naujo: ";
            cin >> stud.Egzaminas;
        }
        
        int c;
        int m = 0;
        cout << "Iveskite nd skaiciu: ";
        cin >> m;
        if (m > 0 & m < 11) cout << "Iveskite " << i + 1 << "-ojo studento nd pazymius: ";
        for (int k = 0; k < m; k++) {
            cin >> stud.Namu[k];
            while (stud.Namu[k] < 1 || stud.Namu[k] > 10) {
                cout << "Ivestas negalimas pazimys, veskite is naujo: ";
                cin >> stud.Namu[k];
            }
            stud.Galutinis = stud.Galutinis + stud.Namu[k];
            c = sizeof(stud.Namu) / sizeof(stud.Namu[0]);
        }
        cout << "C = " << c;
        std::sort(stud.Namu, stud.Namu + m);
        if (m % 2==1)
            stud.mediana = stud.Namu[m / 2];
        else
            stud.mediana = (stud.Namu[m / 2 - 1] + stud.Namu[m / 2]) / 2;

        stud.Galutinis = stud.Galutinis / m;
        stud.Galutinis = stud.Galutinis * 0.4 + 0.6 * stud.Egzaminas;
        grupe.push_back(stud);
    }
    cout << "Jei norite matyti viduriki - iveskite 1, jei mediana - iveskite 0   ";
    cin >> stud.ivestis;
    while (stud.ivestis > 1 || stud.ivestis < 0) {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> stud.ivestis;
    }
    if (stud.ivestis == 1) {
        cout << std::left
            << std::setw(20) << "Vardas "
            << std::setw(20) << "Pavarde"
            << "Galutinis \n";
        cout << "-------------------------------------------------\n";
        for (auto& d : grupe) {
            cout << std::left
                << std::setw(20) << d.Vardas
                << std::setw(20) << d.Pavarde
                << std::setw(20) << std::setprecision(2) << std::fixed << d.Galutinis << "\n";
        }
    }
    else if (stud.ivestis == 0) {
        cout << std::left
            << std::setw(20) << "Vardas "
            << std::setw(20) << "Pavarde"
            << "Mediana \n";
        cout << "-------------------------------------------------\n";
        for (auto& d : grupe) {
            cout << std::left
                << std::setw(20) << d.Vardas
                << std::setw(20) << d.Pavarde
                << std::setw(20) << std::setprecision(2) << std::fixed << d.mediana << "\n";
        }
    }

    cout << endl;
    grupe.clear();
}