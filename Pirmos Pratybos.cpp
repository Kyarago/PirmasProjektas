// Pirmos Pratybos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using std::cout;
using std::cin;
using std::string;
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
    duomenys Eil; duomenys Eil_masyvas[5];
    vector<duomenys> Eil_vector;
//    cout << "Sveiki, iveskite Eil duomenis (Vardas, Pavarde, Egzamino rezultatas, 5 semestro pazymiai:\n";
//    cin >> Eil.Vardas >> Eil.Pavarde >> Eil.Egzaminas;
    for (int k = 0; k < 2; k++) {
        cout << "Sveiki, iveskite savo varda: \n";
        cin >> Eil.Vardas;
        cout << "Sveiki, iveskite savo pavarde: \n";
        cin >> Eil.Pavarde;
        cout << "Sveiki, iveskite savo egzamina: \n";
        cin >> Eil.Egzaminas;
        cout << "Sveiki, iveskite savo 3 nd pazymius: \n";
        for (int i = 0; i < 3; i++) {
            cin >> Eil.Namu[i];
            Eil.Galutinis = Eil.Galutinis + Eil.Namu[i];
        }
    }

//    cout << "Sveiki, iveskite savo 3 nd pazymius: \n";
//    for (int i = 0; i < 3; i++) {
//        cin >> Eil.Namu[i];
//        Eil.Galutinis = Eil.Galutinis + Eil.Namu[i];
//    }
    Eil.Galutinis = (float)Eil.Galutinis / 3.0;
    Eil.Galutinis = Eil.Galutinis * 0.4 + 0.6 * Eil.Egzaminas;
//    cout << std::left 
//        << std::setw(20) << "Vardas "
//        << std::setw(20) << "Pavarde" 
//        << "Galutinis\n";
//    cout << "-------------------------------------------------\n";
//    cout << std:: left
//        << std:: setw(20) 
//        << Eil.Vardas 
//        << std:: setw(20) << Eil.Pavarde ;
//    for (int i = 0; i < 3; i++); //cout << " " << Eil.Namu[i];
//    cout << std:: setw(20) << std::setprecision(2) << std::fixed << Eil.Galutinis << std::endl;

//    int pause;
//    cin >> pause;

    Eil_vector.push_back(Eil); // su indexu 0
    Eil_vector.push_back(Eil); // -||- 1
    cout << std::left
            << std::setw(20) << "Vardas "
            << std::setw(20) << "Pavarde"
            << "Galutinis\n";
    cout << "-------------------------------------------------\n";
    for (int j = 0; j < 2; j++) {
        cout << std::left
            << std::setw(20)
            << Eil_vector[j].Vardas
            << std::setw(20) << Eil_vector[j].Pavarde;
        for (int i = 0; i < 3; i++); //cout << " " << Eil.Namu[i];
        cout << std::setw(20) << std::setprecision(2) << std::fixed << Eil_vector[j].Galutinis << std::endl;
    }
    Eil_vector.clear();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
