// ND1 Su Vektoriais.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Objektinio programavimo Pirmo namu darbo versija 0.2

#include "Mbib.h"

int main()
{
    vector<duomenys> grupe;
    generavimas(grupe);
    ivedimas(grupe);
    skaidymas(grupe);
    std::sort(grupe.begin(), grupe.end(), Tvarkymas);
    spausd(grupe);
    isvedimas(grupe);
    cout << endl;
    grupe.clear();
}