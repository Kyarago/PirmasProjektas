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
        
        int m = 0;
        cout << "Iveskite nd skaiciu: ";
        cin >> m;
        if (m>0) cout << "Iveskite " << i + 1 << "-ojo studento nd pazymius: ";
        for (int k = 0; k < m; k++) {
            cin >> stud.Namu[k];
            stud.Galutinis = stud.Galutinis + stud.Namu[k];
        }

        std::sort(stud.Namu, stud.Namu + m);
        if (m % 2==1)
            stud.mediana = stud.Namu[m / 2];
        else
            stud.mediana = (stud.Namu[m / 2 - 1] + stud.Namu[m / 2]) / 2;

        stud.Galutinis = stud.Galutinis / m;
        stud.Galutinis * 0.4 + 0.6 * stud.Egzaminas;
        grupe.push_back(stud);
    }
    
    cout << std::left
        << std::setw(20) << "Vardas "
        << std::setw(20) << "Pavarde"
        << std::setw(20) << "Galutinis"
        << "Mediana \n";
    cout << "-------------------------------------------------\n";
    for (auto& d : grupe) {
        cout << std::left
            << std::setw(20) << d.Vardas
            << std::setw(20) << d.Pavarde
            << std::setw(20) << std::setprecision(2) << std::fixed << d.Galutinis
            << std::setw(20) << std::setprecision(2) << std::fixed << d.mediana << "\n";
    }
    cout << endl;
    grupe.clear();
}