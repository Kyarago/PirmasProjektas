#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>
#include <numeric>
#include <fstream>
#include <sstream>
#include <chrono>

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
    string kategorija;
};

bool Tvarkymas(const duomenys& pirmas, const duomenys& antras);
void ivedimas(vector<duomenys> &grupe);
void isvedimas(vector<duomenys>& grupe);
void generavimas(vector<duomenys>& grupe); 
void gene1k(vector<duomenys>& grupe);
void skaidymas(vector<duomenys>& grupe); 
void skaidymas1k(vector<duomenys>& grupe);
void spausd(vector<duomenys>& grupe);
void spausd1k(vector<duomenys>& grupe);
void tiknuskaitymui1k(vector<duomenys>& grupe);
void laikas1k(vector<duomenys>& grupe);
void gene10k(vector<duomenys>& grupe);
void skaidymas10k(vector<duomenys>& grupe);
void spausd10k(vector<duomenys>& grupe);
void tiknuskaitymui10k(vector<duomenys>& grupe);
void laikas10k(vector<duomenys>& grupe);
void gene100k(vector<duomenys>& grupe);
void skaidymas100k(vector<duomenys>& grupe);
void spausd100k(vector<duomenys>& grupe);
void tiknuskaitymui100k(vector<duomenys>& grupe);
void laikas100k(vector<duomenys>& grupe);
void gene1m(vector<duomenys>& grupe);
void skaidymas1m(vector<duomenys>& grupe);
void spausd1m(vector<duomenys>& grupe);
void tiknuskaitymui1m(vector<duomenys>& grupe);
void laikas1m(vector<duomenys>& grupe);
void gene10m(vector<duomenys>& grupe);
void skaidymas10m(vector<duomenys>& grupe);
void spausd10m(vector<duomenys>& grupe);
void tiknuskaitymui10m(vector<duomenys>& grupe);
void laikas10m(vector<duomenys>& grupe);