// ND1 be Vektoriu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <functional>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

struct duomenys {
    string Vardas;
    string Pavarde;
    int Namu[10];
    int Egzaminas;
    float Galutinis = 0;
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
        }
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
            cin >> grupe[i].Pavarde;
        }
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento egzamina: ";
            cin >> grupe[i].Egzaminas;
        }
        int m = 0;
        cout << "Iveskite kiek nd pazymiu buvo: ";
        cin >> m;
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-ojo studento nd pazymius: ";
            for (int k = 0; k < m; k++) {
                cin >> grupe[i].Namu[k];
                grupe[i].Galutinis = grupe[i].Galutinis + grupe[i].Namu[k];
            }
        }
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
                << std::setw(20) << std::setprecision(2) << std::fixed << grupe[i].Galutinis << endl;
        }

        int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
        int c = sizeof(arr) / sizeof(arr[0]);

        std::list::sort(arr, arr + c);

        cout << "Array after sorting : \n";
        for (int i = 0; i < c; ++i)
            cout << arr[i] << " ";

        return 0;
        delete[] grupe;
    }
        // Run program: Ctrl + F5 or Debug > Start Without Debugging menu
        // Debug program: F5 or Debug > Start Debugging menu
;