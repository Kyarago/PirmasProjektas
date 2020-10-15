#include "Mbib.h"

bool Tvarkymas(const duomenys& pirmas, const duomenys& antras) {
    return pirmas.Vardas < antras.Vardas;
};

void ivedimas(vector<duomenys> &grupe) {
    duomenys stud;
    string p = "";
    string s = "";
    cout << "Ar duomenis norite nuskaityti is failo (t / n)? : ";
    cin >> s;
    while (s != "t" && s != "n" && s != "N" && s != "T") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> s;
    }
    if (s == "n" || s == "N") {
        int n = 0;
        cout << "Iveskite studentu skaiciu: ";
        cin >> n;
        do {
            try {
                if (cin.fail()) {
                    throw std::runtime_error("Vesti reikia skaiciu!!!\n");
                }
            }
            catch (const std::runtime_error& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Iveskite skaiciu: ";
                cin >> n;
            }
        } while (cin.fail() == true);

        grupe.reserve(n);
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-aji varda: ";
            cin >> stud.Vardas;
            cout << "Iveskite " << i + 1 << "-ojo studento pavarde: ";
            cin >> stud.Pavarde;
            cout << "Pazymius norite generuoti ar vesti (v / g)? : ";
            cin >> p;
            while (p != "g" && p != "v" && p != "G" && p != "V") {
                cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
                cin >> p;
            }
            if (p == "g" || p == "G") {
                int kiek;
                stud.Egzaminas = 1 + rand() % 10;
                cout << "Sukurtas egzamino pazimys: " << stud.Egzaminas << endl;
                cout << "Kiek pazymiu generuoti " << i + 1 << " studentui? : ";
                cin >> kiek; for (int k = 0; k < kiek; k++) {
                    int nd = 1 + rand() % 10;
                    cout << nd << "   ";
                    stud.Namu.push_back(nd);
                }
            }
            else if (p == "v" || p == "V") {
                int ex;
                cout << "Iveskite " << i + 1 << "-ojo studento egzamino pazimys: ";
                cin >> ex;
                do {
                    try {
                        if (cin.fail() || ex < 1 || ex > 10) {
                            throw std::runtime_error("Ivestas neteisingas pazimys!!!\n");
                        }
                    }
                    catch (const std::runtime_error& e) {
                        cout << e.what();
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Iveskite " << i + 1 << "-ojo studento egzamino pazimi: ";
                        cin >> ex;
                    }
                } while (cin.fail() == true);

                stud.Egzaminas = ex;
                cout << "Iveskite " << i + 1 << " -ojo studento nd pazymius, kai noresite sustoti - iveskite 0: \n";
                int nd = 1;
                cin >> nd;
                do {
                    try {
                        if (cin.fail()) {
                            throw std::runtime_error("Klaida, ivestas negalimas pazimys!!!\n");
                        }
                    }
                    catch (const std::runtime_error& e) {
                        cout << e.what();
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout << "Iveskite skaiciu: ";
                        cin >> nd;
                    }
                } while (cin.fail() == true);

                while (nd != 0) {
                    stud.Namu.push_back(nd);
                    cin >> nd;
                    do {
                        try {
                            if (cin.fail() || nd < 0 || nd > 10) {
                                throw std::runtime_error("Klaida, ivestas negalimas pazimys!!!\n");
                            }
                        }
                        catch (const std::runtime_error& e) {
                            cout << e.what();
                            cin.clear();
                            cin.ignore(200, '\n');
                            cout << "Iveskite skaiciu: ";
                            cin >> nd;
                        }
                    } while (cin.fail() == true);
                }
            }
            std::sort(stud.Namu.begin(), stud.Namu.end());
            int c;
            c = stud.Namu.size();
            cout << "Namu darbu pazymiu skaicius: " << c << endl;
            if (c != 0) {
                if (c % 2 == 1)
                    stud.mediana = stud.Namu[c / 2];
                else
                    stud.mediana = (stud.Namu[c / 2 - 1] + stud.Namu[c / 2]) / 2;
            }
            if (c == 0) {
                stud.Galutinis = stud.Egzaminas * 0.6;
            }
            else {
                float bendras = 0;
                bendras = accumulate(stud.Namu.begin(), stud.Namu.end(), 0);
                //cout << "Bendras: " << bendras << endl;
                stud.Galutinis = bendras / c;
                stud.Galutinis = stud.Galutinis * 0.4 + 0.6 * stud.Egzaminas;
            }
            grupe.push_back(stud);
            stud.Namu.clear();
        }
    }
    else if (s == "T" || s == "t") {
        string pav = "";
        cout << "Failo kuri norit nnuskaityti pavadinimas (pvz.: kursiokai.txt): ";
        cin >> pav;
        std::ifstream file(pav);
        if (file.good()) {
            cout << "Failas surastas!" << endl;
            int nd;
            int kiekis = 0;
            cout << "Kiek namu darbu pazymiu yra faile? : ";
            cin >> kiekis;
            do {
                try {
                    if (cin.fail()) {
                        throw std::runtime_error("Vesti reikia skaiciu!!!\n");
                    }
                }
                catch (const std::runtime_error& e) {
                    cout << e.what();
                    cin.clear();
                    cin.ignore(200, '\n');
                    cout << "Iveskite kiek namu darbu pazimiu yra faile: ";
                    cin >> kiekis;
                }
            } while (cin.fail() == true);

            int h;
            h = 100;
            string line;
            file.unsetf(std::ios_base::skipws);
            int b = std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n');
            std::cout << "Studentu skaicius faile: " << b << endl;
            std::ifstream filee(pav);
            filee.ignore(10000, '\n');
            for (int j = 0; j < b; j++) {
                filee >> stud.Vardas >> stud.Pavarde;
                for (int i = 0; i < kiekis; i++) {
                    filee >> nd;
                    stud.Namu.push_back(nd);
                }
                filee >> stud.Egzaminas;
                std::sort(stud.Namu.begin(), stud.Namu.end());
                int c;
                c = stud.Namu.size();
                //            cout << "Namu darbu pazymiu skaicius: " << c << endl;
                if (c != 0) {
                    if (c % 2 == 1)
                        stud.mediana = stud.Namu[c / 2];
                    else
                        stud.mediana = (stud.Namu[c / 2 - 1] + stud.Namu[c / 2]) / 2;
                }
                if (c == 0) {
                    stud.Galutinis = stud.Egzaminas * 0.6;
                }
                else {
                    float bendras = 0;
                    bendras = accumulate(stud.Namu.begin(), stud.Namu.end(), 0);
                    //cout << "Bendras: " << bendras << endl;
                    stud.Galutinis = bendras / c;
                    stud.Galutinis = stud.Galutinis * 0.4 + 0.6 * stud.Egzaminas;
                }
                grupe.push_back(stud);
                stud.Namu.clear();
            }
        }
        else cout << "Ivestas failas nebuvo rastas" << endl;
    }
}

void isvedimas(vector<duomenys>& grupe) {
    string ivestis = "";
    cout << "Norite matyti viduriki ar mediana (v / m)? : ";
    cin >> ivestis;
    while (ivestis != "v" && ivestis != "m") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> ivestis;
    }

    if (ivestis == "v") {
        cout << std::left
            << std::setw(20) << "Vardas "
            << std::setw(20) << "Pavarde"
            << "Galutinis (vid) \n";
        cout << "-------------------------------------------------------\n";
        for (auto& d : grupe) {
            cout << std::left
                << std::setw(20) << d.Vardas
                << std::setw(20) << d.Pavarde
                << std::setw(20) << std::setprecision(2) << std::fixed << d.Galutinis << "\n";
        }
    }
    else if (ivestis == "m") {
        cout << std::left
            << std::setw(20) << "Vardas "
            << std::setw(20) << "Pavarde"
            << "Galutinis (med) \n";
        cout << "-------------------------------------------------------\n";
        for (auto& d : grupe) {
            cout << std::left
                << std::setw(20) << d.Vardas
                << std::setw(20) << d.Pavarde
                << std::setw(20) << std::setprecision(2) << std::fixed << d.mediana << "\n";
        }
    }
}

void generavimas(vector<duomenys>& grupe) {
    duomenys stud;
    int eil;
    int egz;
    string klaus = "";
    cout << "Ar norite sugeneruoti studentu faila? (t/n): ";
    cin >> klaus;
    while (klaus != "t" && klaus != "n" && klaus != "N" && klaus != "T") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> klaus;
    }
    if (klaus == "t" || klaus == "T") {
        cout << "Kiek eiluciu norite sugeneruoti?: ";
        cin >> eil;
        do {
            try {
                if (cin.fail()) {
                    throw std::runtime_error("Vesti reikia skaiciu!!!\n");
                }
            }
            catch (const std::runtime_error& e) {
                cout << e.what();
                cin.clear();
                cin.ignore(200, '\n');
                cout << "Iveskite skaiciu: ";
                cin >> eil;
            }
        } while (cin.fail() == true);
        grupe.reserve(eil);
        string pav = "Studentai" + std::to_string(eil) + ".txt";
        cout << "Naujo failo pavadinimas: " << pav << endl;;
        std::ofstream out(pav);
        out << "Vardas        " << "Pavarde        " << "nd1   " << "nd2   " << "nd3   " << "nd4   " << "nd5   " << "Egz   " << endl;
        for (int i = 0; i < eil; i++) {
            stud.Vardas = "Vardas" + std::to_string(i + 1);
            stud.Pavarde = "Pavarde" + std::to_string(i + 1);
            for (int j = 0; j < 5; j++) {
                int nd = 1 + rand() % 10;
                stud.Namu.push_back(nd);
            }
            egz = 1 + rand() % 10;
            grupe.push_back(stud);
            out << std::left << std::setw(14) << stud.Vardas << std::left << std::setw(15) << stud.Pavarde <<
                std::left << std::setw(6) << stud.Namu[0] << std::left << std::setw(6) << stud.Namu[1] << std::left << std::setw(6) << stud.Namu[2] <<
                std::left << std::setw(6) << stud.Namu[3] << std::left << std::setw(6) << stud.Namu[4] << std::left << std::setw(6) << egz << '\n';
            stud.Namu.clear();
        }
    }
}

void skaidymas(vector<duomenys>& grupe) {
    duomenys stud;
    int q = grupe.size();
    for (int i = 0; i < q; i++) {
        if (grupe[i].Galutinis < 5) {
            grupe[i].kategorija = "Vargseliai";
        }
        else grupe[i].kategorija = "Galvociai";
    }
}

void spausd(vector<duomenys>& grupe) {
    duomenys stud;
    string ar = "";
    cout << "Ar norite sukurti vargseliu ir galvociu failus? (t/n): ";
    cin >> ar;
    while (ar != "t" && ar != "n" && ar != "N" && ar != "T") {
        cout << "Ivestas negalimas pasirinkimas, veskite is naujo: ";
        cin >> ar;
    }
    if (ar == "t" || ar == "T") {
        std::ofstream vargsai("Vargseliai.txt");
        std::ofstream kieti("Galvociai.txt");
        vargsai << "Vardas        " << "Pavarde        " << "Egzaminas   " << "Galutinis" << endl;
        kieti << "Vardas        " << "Pavarde        " << "Egzaminas   " << "Galutinis" << endl;
        for (int i = 0; i < grupe.size(); i++) {
            if (grupe[i].kategorija == "Vargseliai") {
                vargsai << std::left << std::setw(14) << grupe[i].Vardas << std::left << std::setw(15) << grupe[i].Pavarde << std::left << std::setw(12) << grupe[i].Egzaminas << std::left << std::setw(9) << grupe[i].Galutinis << endl;
            }
            else if (grupe[i].kategorija == "Galvociai") {
                kieti << std::left << std::setw(14) << grupe[i].Vardas << std::left << std::setw(15) << grupe[i].Pavarde << std::left << std::setw(12) << grupe[i].Egzaminas << std::left << std::setw(9) << grupe[i].Galutinis << endl;
            }
        }
    }
}