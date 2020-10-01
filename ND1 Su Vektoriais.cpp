// ND1 Su Vektoriais.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Objektinio programavimo Pirmo namu darbo versija 0.2

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>
#include <numeric>
#include <fstream>
#include <sstream>

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
    float Galutinis = 0;
    float mediana;
};

bool Tvarkymas(const duomenys& pirmas, const duomenys& antras) { 
    return pirmas.Vardas < antras.Vardas; 
};

int main()
{
    vector<duomenys> grupe;
    duomenys stud;
    string s = "";
    string p = "";
    cout << "Ar duomenis norite nuskaityti is failo (t / n)? : ";
    cin >> s;
    while (s != "t" && s != "n" && s != "N" && s != "T") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> s;
    }
    if (s == "n" || s == "N") {
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
            cout << "Pazymius norite generuoti ar vesti (v / g)? : ";
            cin >> p;
            while (p != "g" && p != "v" && p != "G" && p!= "V") {
                cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
                cin >> p;
            }
            if (p == "g" || p == "G") {
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
            else if (p == "v" || p == "V") {
                int ex;
                cout << "Iveskite " << i + 1 << "-ojo studento egzamino pazimys: ";
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
    }
    else if (s == "T" || s == "t") {
        string pav = "";
        cout << "Failo kuri norit nnuskaityti pavadinimas (pvz.: studentai.txt): ";
        cin >> pav;
        std::ifstream file(pav);
        if (file.good()) {
            cout << "Failas surastas!" << endl;
            int nd;
            int kiekis = 0;
            cout << "Kiek namu darbu pazymiu yra faile? : ";
            cin >> kiekis;
            while (cin.fail()) {
                cout << "klaida, iveskite skaiciu:  ";
                cin.clear();
                cin.ignore(200, '\n');
                cin >> kiekis;
            }
            int h;
            h = 100;
            file.unsetf(std::ios_base::skipws);
            int b = std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n');
            std::cout << "Studentu skaicius faile: " << b << endl;
            std::ifstream filee(pav);
            filee.ignore(10000, '\n');
            for (int j = 0; j < b; j++) {
                filee >> stud.Vardas >> stud.Pavarde;
                for (int i = 0; i < kiekis; i++) {
                    filee >> nd;
                    stud.Namu.push_back(nd);
                }
                filee >> stud.Egzaminas;
                std::sort(stud.Namu.begin(), stud.Namu.end());
                int c;
                c = stud.Namu.size();
                //            cout << "Namu darbu pazymiu skaicius: " << c << endl;
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
        }
        else cout << "Ivestas failas nebuvo rastas" << endl;
    }
    std::sort(grupe.begin(), grupe.end(), Tvarkymas);
    string ivestis = "";
    cout << "Norite matyti viduriki ar mediana (v / m)? : ";
    cin >> ivestis;
    while (ivestis != "v" && ivestis != "m") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> ivestis;
    }
    if (ivestis == "v") {
        cout << std::left
            << std::setw(20) << "Vardas "
            << std::setw(20) << "Pavarde"
            << "Galutinis (vid) \n";
        cout << "-------------------------------------------------------\n";
        for (auto& d : grupe) {
            cout << std::left
                << std::setw(20) << d.Vardas
                << std::setw(20) << d.Pavarde
                << std::setw(20) << std::setprecision(2) << std::fixed << d.Galutinis << "\n";
        }
    }
    else if (ivestis == "m") {
        cout << std::left
            << std::setw(20) << "Vardas "
            << std::setw(20) << "Pavarde"
            << "Galutinis (med) \n";
        cout << "-------------------------------------------------------\n";
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