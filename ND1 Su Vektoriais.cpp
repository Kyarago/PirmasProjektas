// ND1 Su Vektoriais.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Objektinio programavimo Pirmo namu darbo versija 0.2

#include "Mbib.h"

int main()
{
    vector<duomenys> grupe;
    ivedimas(grupe);
    std::sort(grupe.begin(), grupe.end(), Tvarkymas);
    isvedimas(grupe);
    cout << endl;
    grupe.clear();
}