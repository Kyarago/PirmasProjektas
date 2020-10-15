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
void skaidymas(vector<duomenys>& grupe);
void spausd(vector<duomenys>& grupe);