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
void tgeneravimas(vector<duomenys>& grupe, int nd, int eil);
void skaidymas(vector<duomenys>& grupe);
void tskaidymas(vector<duomenys>& grupe, int eil);
void spausd(vector<duomenys>& grupe);
void tspausd(vector<duomenys>& grupe, int eil);
void tiknuskaitymui(vector<duomenys>& grupe, int eil, int nd);
void laikas(vector<duomenys>& grupe, int eil, int nd);