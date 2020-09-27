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
    float Mediana;
};

    int main()
    {
        int n = 0;
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
        duomenys* grupe = new duomenys[n];
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-aji vada: ";
            cin >> grupe[i].Vardas;
            cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
            cin >> grupe[i].Pavarde;
            cout << "Iveskite " << i + 1 << "-ojo studento egzamina: ";
            cin >> grupe[i].Egzaminas; 
        }
        int c;
        int m = 0;
        cout << "Iveskite kiek nd pazymiu buvo: ";
        cin >> m;
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento nd pazymius: ";
            for (int k = 0; k < m; k++) {
                cin >> grupe[i].Namu[k];
                grupe[i].Galutinis = grupe[i].Galutinis + grupe[i].Namu[k];
//                size_t c = sizeof(grupe[i].Namu[k]) / sizeof(grupe[i].Namu[0]); //ivestu elementu skaicius
                std::sort(grupe[i].Namu, grupe[i].Namu + m);
                cout << m << endl;
                cout << grupe[i].Namu[k];
            }
            if (m % 2 == 1)
                grupe[i].Mediana = grupe[i].Namu[m / 2];
            else
                grupe[i].Mediana = (grupe[i].Namu[m / 2 - 1] + grupe[i].Namu[m / 2]) / 2;
        }
//                size_t c = sizeof(grupe[i].Namu[k]) / sizeof(grupe[i].Namu[0]); //ivestu elementu skaicius
//                std::sort(grupe[i].Namu, grupe[i].Namu + c);
//                cout << c << endl;
//                if (c % 2 == 1)
//                    mediana = grupe[i].Namu[c / 2];
//               else
//                    mediana = (grupe[i].Namu[c / 2 - 1] + grupe[i].Namu[c / 2]) * 0.5;
//            } 
//            if (c % 2 == 1)
//                mediana = grupe[i].Namu[c / 2];
//            else
//                mediana = (float)(grupe[i].Namu[c / 2 - 1] + grupe[i].Namu[c / 2]) * 0.5;
//        }
        
//        int a[] = { 9, 7, 5, 10 };
//        size_t size = sizeof(a) / sizeof(a[0]); //įvestų elementų skaičius
//        std::sort(a, a + size); // surūšiuoti masyvą a nuo nulinio elemento iki n
//        for (size_t i = 0; i < size; i++) {
//            cout << a[i] << ' ';
//        }
//        int c;
//        c = sizeof(a) / sizeof(a[0]); //ivestu elementu skaicius
//        std::sort(a, a + c);
//        cout << c << endl;
//        if (c % 2 == 1)
//            mediana = a[c / 2];
//       else
//            mediana = (a[c / 2 - 1] + a[c / 2]) * 0.5;
//        int ivestis;
//        cout << "Jei norite vidurkio, iveskite v, jei medianos m: ";
//        cin >> ivestis; 
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
                //                if (ivestis == 'v')
                //                   cout << std::setw(20) << std::setprecision(2) << std::fixed << grupe[i].Galutinis<< endl; 
                //                else
                //                    cout << std::setw(20) << std::setprecision(2) << std::fixed << mediana << endl;
                << std::setw(20) << std::setprecision(2) << std::fixed << grupe[i].Galutinis
                << std::setw(20) << std::setprecision(2) << std::fixed << grupe[i].Mediana << endl;
        }
        delete[] grupe;
        //char pause;
        //cin >> pause;
    }
        // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
        // Debug program: F5 or Debug > Start Debugging menu
;