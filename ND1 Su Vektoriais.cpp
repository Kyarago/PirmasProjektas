// ND1 Su Vektoriais.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>
#include <numeric>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

struct duomenys {
    string Vardas = "";
    string Pavarde = "";
    vector<int> Namu;
    int Egzaminas;
    string p = "";
    string ivestis = "";
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
    while (cin.fail()) {
        cout << "klaida, iveskite skaiciu:  ";
        cin.clear();
        cin.ignore(200, '\n');
        cin >> n;
    }
    grupe.reserve(n);
    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << "-aji varda: ";
        cin >> stud.Vardas;
        cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
        cin >> stud.Pavarde;
        cout << "Jei norite generuoti pazymius - iveskite g, jei vesite - v: ";
        cin >> stud.p;
        while (stud.p != "g" && stud.p != "v") {
            cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
            cin >> stud.p;
        }
        if (stud.p == "g") {
            int kiek;
            stud.Egzaminas = 1 + rand() % 10;
            cout << "Sukurtas egzamino pazimys: " << stud.Egzaminas << endl;
            cout << "Kiek pazymiu generuoti " << i + 1 << " studentui? : ";
            cin >> kiek; for (int k = 0; k < kiek; k++) {
                int nd = 1 + rand() % 10;
                cout << nd << "   ";
                stud.Namu.push_back(nd);
            }
        }
        else if (stud.p == "v") {
            int ex;
            cout << i + 1 << " -ojo studento egzamino pazimys: ";
            cin >> ex;
            while (cin.fail() || ex < 1 || ex > 10) {
                cout << "Klaida, ivestas blogas pazimys, veskite is naujo: ";
                cin.clear();
                cin.ignore(200, '\n');
                cin >> ex;
            }
            stud.Egzaminas = ex;
            cout << "Iveskite " << i + 1 << " -ojo studento nd pazymius, kai noresite sustoti - iveskite 0: \n";
            int nd = 1;
            cin >> nd;
            while (cin.fail() || nd < 0 || nd > 10) {
                cout << "Klaida, ivestas negalimas pazimys, veskite is naujo: ";
                cin.clear();
                cin.ignore(200, '\n');
                cin >> nd;
            }
            while (nd != 0) {
                stud.Namu.push_back(nd);
                cin >> nd;
                while (cin.fail() || nd < 0 || nd > 10) {
                    cout << "Klaida, ivestas negalimas pazimys, veskite is naujo: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> nd;
                }
            }
        }
        std::sort(stud.Namu.begin(), stud.Namu.end());
        int c;
        c = stud.Namu.size();
        cout << "Namu darbu pazymiu skaicius: " << c << endl;
        if (c != 0) {
            if (c % 2 == 1)
                stud.mediana = stud.Namu[c / 2];
            else
                stud.mediana = (stud.Namu[c / 2 - 1] + stud.Namu[c / 2]) / 2;
        }
        if (c == 0) {
            stud.Galutinis = stud.Egzaminas * 0.6;
        }
        else {
            float bendras = 0;
            bendras = accumulate(stud.Namu.begin(), stud.Namu.end(), 0);
            //cout << "Bendras: " << bendras << endl;
            stud.Galutinis = bendras / c;
            stud.Galutinis = stud.Galutinis * 0.4 + 0.6 * stud.Egzaminas;
        }
        grupe.push_back(stud);
        stud.Namu.clear();
    }
    cout << "Jei norite matyti viduriki - iveskite v, jei mediana - iveskite m:   ";
    cin >> stud.ivestis;
    while (stud.ivestis != "v" && stud.ivestis != "m") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> stud.ivestis;
    }
    if (stud.ivestis == "v") {
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
    else if (stud.ivestis == "m") {
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