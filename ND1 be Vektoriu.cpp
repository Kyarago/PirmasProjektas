// ND1 be Vektoriu.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    string Vardas;
    string Pavarde;
    int Namu[10];
    int Egzaminas;
    float Galutinis = 0;
};

    int main()
    {
        float mediana;
        int n = 0;
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
        duomenys* grupe = new duomenys[n];
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-aji vada: ";
            cin >> grupe[i].Vardas;
//        }
//        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
            cin >> grupe[i].Pavarde;
//        }
//        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento egzamina: ";
            cin >> grupe[i].Egzaminas;
        }
        int m = 0;
        cout << "Iveskite kiek nd pazymiu buvo: ";
        cin >> m;
        int c;
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento nd pazymius: ";
            for (int k = 0; k < m; k++) {
                cin >> grupe[i].Namu[k];
                grupe[i].Galutinis = grupe[i].Galutinis + grupe[i].Namu;
            }
            c = sizeof(grupe[i].Namu) / sizeof(grupe[i].Namu[0]); //ivestu elementu skaicius
            std::sort(grupe[i].Namu, grupe[i].Namu + c); // kadangi nuėjote sudėtingu būdu tai keikia naudoti tokią sintaksę t.y. pirmo elemento adresas ir paskutinio elemento adresas gaunamas iš pirmo plius elementų skaičius - rezultatas tokios sudėties ir yra paskutinio elemento adresas.
//            grupe[i].Galutinis = grupe[i].Galutinis + grupe[i].Namu; //Kodėl k?
        }
//            int c;
//            c = sizeof(grupe[i].Namu) / sizeof(grupe[i].Namu[0]); //įvestų elementų skaičius
//            std::sort(grupe[i].Namu, grupe[i].Namu + c);
//            if (c % 2 == 1)  
//                mediana = grupe[i].Namu[c / 2];
//            else 
//                mediana = (float)(grupe[i].Namu[c / 2 - 1] + grupe[i].Namu[c / 2]) * 0.5;
//            for (int o = 0; o < c; o++) {
//                cout << grupe[i].Namu[o] << ' ';
//            }                        
//        }
//            grupe[i].Galutinis = grupe[i].Galutinis + (int)grupe[i].Namu;
//        int a[] = { 1,5,4,2,3,6,7,8,2 };
//        size_t size = sizeof(a) / sizeof(a[0]); //įvestų elementų skaičius
//        std::sort(a, a + size); // surūšiuoti masyvą a nuo nulinio elemento iki n
//        for (size_t i = 0; i < size; i++) {
//            cout << a[i] << ' ';
//        }

        cout << std::left
        << std::setw(20) << "Vardas "
        << std::setw(20) << "Pavarde"
        << "Galutinis\n";
        cout << "-------------------------------------------------\n";
        for (int i = 0; i < n; i++) {
            grupe[i].Galutinis = (float)grupe[i].Galutinis / m;
            grupe[i].Galutinis = grupe[i].Galutinis * 0.4 + 0.6 * grupe[i].Egzaminas;
            cout << std::setw(20) << grupe[i].Vardas
                << std::setw(20) << grupe[i].Pavarde
                << std::setw(20) << std::setprecision(2) << std::fixed << grupe[i].Galutinis;
//                << std::setw(20) << std::setprecision(2) << std::fixed << mediana << endl;
        }
        delete[] grupe;
    }
        // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
        // Debug program: F5 or Debug > Start Debugging menu
;