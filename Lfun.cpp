#include "Mbib.h"

void lnuskaitymui(list<duomenys>& lgrupe, int eil, int nd) {
	duomenys lstud;
    string pav = "";
    auto start = std::chrono::high_resolution_clock::now();
    pav = "Studentai" + std::to_string(eil) + ".txt";
    std::ifstream file(pav);
    if (file.good()) {
        int ndpaz;
        string line;
        std::getline(file, line);
        for (int j = 0; j < eil; j++) {
            file >> lstud.Vardas >> lstud.Pavarde;
            for (int i = 0; i < nd; i++) {
                file >> ndpaz;
                lstud.Namu.push_back(ndpaz);
            }
            file >> lstud.Egzaminas;
            std::sort(lstud.Namu.begin(), lstud.Namu.end());
            int c;
            c = lstud.Namu.size();
            if (c != 0) {
                if (c % 2 == 1)
                    lstud.mediana = lstud.Namu[c / 2];
                else
                    lstud.mediana = (lstud.Namu[c / 2 - 1] + lstud.Namu[c / 2]) / 2;
            }
            if (c == 0) {
                lstud.Galutinis = lstud.Egzaminas * 0.6;
            }
            else {
                float bendras = 0;
                bendras = accumulate(lstud.Namu.begin(), lstud.Namu.end(), 0);
                lstud.Galutinis = bendras / c;
                lstud.Galutinis = lstud.Galutinis * 0.4 + 0.6 * lstud.Egzaminas;
            }
            lgrupe.push_back(lstud);
            lstud.Namu.clear();
        }
    }
    else cout << "Failas " << pav << " nebuvo rastas" << endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << eil << " eiluciu failo nuskaitymas uztruko: " << diff.count() << " s\n";
    file.close();
}

void lskaidymas(list<duomenys>& lgrupe, int eil) {
    auto start = std::chrono::high_resolution_clock::now();
    duomenys lstud;
    list<duomenys> Vargseliai;
    list<duomenys> Galvociai;
    int q = lgrupe.size();
    for (auto& t: lgrupe) {
        if (t.Galutinis < 5.0)
            Vargseliai.push_back(t);
        else Galvociai.push_back(t);
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas laikas: " << diff.count() << " s" << endl;

    //start = std::chrono::high_resolution_clock::now();
    std::ofstream vargsai("ListVargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    std::ofstream kieti("ListGalvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Galvociai) {
        kieti << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    //diff = std::chrono::high_resolution_clock::now() - start;
    //cout << eil << " eiluciu failo kietu ir vargsu failu sukurimo laikas: " << diff.count() << " s" << endl;
    vargsai.close();
    kieti.close();
    Vargseliai.clear(); Galvociai.clear();
}

void lskaidymas2(list<duomenys>& lgrupe, int eil) {
    RusList(lgrupe);
    auto start = std::chrono::high_resolution_clock::now();
    duomenys lstud;
    list<duomenys> Vargseliai;
    list<duomenys>::iterator it;
    it = lgrupe.begin();
    for (auto& t : lgrupe) {
        if (t.Galutinis < 5.0)
            it++;
    }
    Vargseliai.splice(Vargseliai.begin(), lgrupe, lgrupe.begin(), it);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << eil << " eiluciu failo suskaidymo i 2 kategorijas laikas: " << diff.count() << " s" << endl;
    std::ofstream vargsai("ListVargseliai" + std::to_string(eil) + ".txt");
    vargsai << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : Vargseliai) {
        vargsai << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    std::ofstream kieti("ListGalvociai" + std::to_string(eil) + ".txt");
    kieti << "Vardas         " << "Pavarde         " << "Egzaminas   " << "Galutinis" << endl;
    for (auto& t : lgrupe) {
        kieti << std::left << std::setw(15) << t.Vardas << std::setw(16) << t.Pavarde << std::setw(12) << t.Egzaminas << std::setw(9) << t.Galutinis << endl;
    }
    vargsai.close();
    kieti.close();
    Vargseliai.clear();
}

void llaikas(list<duomenys>& lgrupe, int eil, int nd) {
    cout << "Programa dirba su listais --------- :\n";
    lnuskaitymui(lgrupe, eil, nd);
    lskaidymas2(lgrupe, eil);
    lgrupe.clear();
}
