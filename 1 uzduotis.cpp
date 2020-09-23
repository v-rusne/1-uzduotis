#include <iostream>
#include<string>
#include<vector>
#include<iomanip> /*setprecision, setw*/
#include<bits/stdc++.h> /*accumulate, nth_element*/
#include<stdlib.h> /*EXIT_FAILURE*/
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::invalid_argument;
using std::setw;
using std::right;
using std::left;
using std::accumulate;
using std::endl;
using std::setprecision;
using std::any_of;
using std::isdigit;

struct duomuo {
    string Vard;
    string Pav;
    int paz;
    int egz;
    float GP=0;
    string tipas;
    string Vid="Vidurkis";
    string Med="Mediana";
    string vid="vidurkis";
    string med="mediana";
    vector<int> pazymiai;
};


double mediana(vector<int> a, int m){
    if (m%2 == 0){
        nth_element(a.begin(),a.begin()+m/2,a.end());
        nth_element(a.begin(),a.begin()+(m-1)/2,a.end());
        return (double)(a[(m-1)/2]+a[m/2])/2.0;
    }

    else{
        nth_element(a.begin(),a.begin()+m/2,a.end());
        return (double)a[m/2];
    }
}

bool yra_skaicius(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}


int main()
{
    duomuo Eil;
    string n;
    cout << "Ar norite, kad mokinio balai( egzamino ir namu darbu) butu generuojami atsitiktinai?\n";
    cin >> n;
    if (n == "Ne" || n == "ne"){
        cout << "Iveskite kaip bus skaiciuojamas galutinis balas (Vidurkis/Mediana):\n";
        cin >> Eil.tipas;


        /*Kai pasirenkamas galutinis balas isvestas is vidurkio*/
        if (Eil.tipas.compare(Eil.Vid) == 0 || Eil.tipas.compare(Eil.vid) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde, egzamino rezultatas, semestro pazymiai):\n";
            cin >> Eil.Vard >> Eil.Pav >> Eil.egz;
            try{
                if (yra_skaicius(Eil.Vard) || yra_skaicius(Eil.Pav)){
                 throw invalid_argument("Netinkama vardo ir/arba pavardes reiksme!");
                }
            }
            catch (invalid_argument vpr){
                cout << vpr.what();
                exit(EXIT_FAILURE);
            }



            try {
                if(Eil.egz < 1 || Eil.egz > 10){
                    throw invalid_argument("Netinkama egzamino rezultato reiksme!");
                }
            }
            catch (invalid_argument er){
                cout << er.what();
                exit(EXIT_FAILURE);
            }

            while(cin >> Eil.paz){
                if(Eil.paz == 000) break;

                try{
                    if(Eil.paz < 1 || Eil.paz > 10){
                    throw invalid_argument("Netinkama pazymio reiksme!");
                    }
                }
                catch (invalid_argument pr){
                    cout << pr.what();
                    exit(EXIT_FAILURE);
                }
                Eil.pazymiai.push_back(Eil.paz);
            }

            Eil.GP = accumulate(Eil.pazymiai.begin(), Eil.pazymiai.end(), 0);
            Eil.GP = Eil.GP / Eil.pazymiai.size();
            Eil.GP = Eil.GP*0.4 + Eil.egz*0.6;
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavardë" << setw(4) << "Galutinis (Vid.)\n";
            cout << "------------------------------------------------------------------\n";
            cout << left << setw(20) << Eil.Vard << setw(20) << Eil.Pav<<setw(4);
            cout << setprecision(2);
            cout << Eil.GP << endl;
        }


        /*Pasirenkamas galutinio balo skaiciavimas naudojant mediana*/
        else if (Eil.tipas.compare(Eil.Med) == 0 || Eil.tipas.compare(Eil.med) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde, egzamino rezultatas, semestro pazymiai):\n";
            cin >> Eil.Vard >> Eil.Pav >> Eil.egz;

            try {
                if(Eil.egz < 1 || Eil.egz > 10){
                    throw invalid_argument("Netinkama egzamino rezultato reiksme!");
                }
            }
            catch (invalid_argument er){
                cout << er.what();
                exit(EXIT_FAILURE);
            }

            while(cin >> Eil.paz) {
                if(Eil.paz == 000) break;

                try{
                    if(Eil.paz < 1 || Eil.paz > 10){
                        throw invalid_argument("Netinkama pazymio reiksme!");
                    }
                }
                catch (invalid_argument pr){
                    cout << pr.what();
                    exit(EXIT_FAILURE);
                }
            Eil.pazymiai.push_back(Eil.paz);

            }

            Eil.GP = mediana(Eil.pazymiai, Eil.pazymiai.size());
            Eil.GP = Eil.GP*0.4 + Eil.egz*0.6;
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavardë" << setw(4) << "Galutinis (Med.)\n";
            cout << "------------------------------------------------------------------\n";
            cout << left << setw(20) << Eil.Vard << setw(20) << Eil.Pav << setw(4);
            cout << setprecision(2);
            cout << Eil.GP << endl;
        }


        else{
            try{
                throw invalid_argument("Irasyta netinkama skaiciavimo tipo reiksme!");
            }
            catch (invalid_argument tr){
                cout << tr.what();
            }
        }
    }


    else{
        int r;
        cout << "Kiek rezultatu norite sugeneruoti?\n";
        cin >> r;
        srand((unsigned) time(0));
        int random;
        cout << "Iveskite kaip bus skaiciuojamas galutinis balas (Vidurkis/Mediana):\n";
        cin >> Eil.tipas;


        /*Kai pasirenkamas galutinis balas isvestas is vidurkio*/
        if (Eil.tipas.compare(Eil.Vid) == 0 || Eil.tipas.compare(Eil.vid) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde):\n";
            cin >> Eil.Vard >> Eil.Pav;

            try{
                if (yra_skaicius(Eil.Vard) || yra_skaicius(Eil.Pav)){
                 throw invalid_argument("Netinkama vardo ir/arba pavardes reiksme!");
                }
            }
            catch (invalid_argument vpr){
                cout << vpr.what();
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < r; i++){
                random = (rand() % 10) + 1;
                Eil.pazymiai.push_back(random);
            }

            Eil.GP = accumulate(Eil.pazymiai.begin(), Eil.pazymiai.end(), 0);
            Eil.GP = Eil.GP / Eil.pazymiai.size();
            Eil.GP = Eil.GP*0.4 + Eil.egz*0.6;
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)\n";
            cout << "------------------------------------------------------------------\n";
            cout << left << setw(20) << Eil.Vard << setw(20) << Eil.Pav << setw(4);
            cout << setprecision(2);
            cout << Eil.GP <<endl;
    }


        /*Pasirenkamas galutinio balo skaiciavimas naudojant mediana*/
        else if (Eil.tipas.compare(Eil.Med) == 0 || Eil.tipas.compare(Eil.med) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde):\n";
            cin >> Eil.Vard >> Eil.Pav;

            try{
                if (yra_skaicius(Eil.Vard) || yra_skaicius(Eil.Pav)){
                 throw invalid_argument("Netinkama vardo ir/arba pavardes reiksme!");
                }
            }
            catch (invalid_argument vpr){
                cout << vpr.what();
                exit(EXIT_FAILURE);
            }

            for (int i = 0; i < r; i++) {
                random = (rand() % 10) + 1;
                Eil.pazymiai.push_back(random);
            }

            Eil.GP=mediana(Eil.pazymiai, Eil.pazymiai.size());
            Eil.GP=Eil.GP*0.4 + Eil.egz*0.6;
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Med.)\n";
            cout << "------------------------------------------------------------------\n";
            cout << left << setw(20) << Eil.Vard << setw(20) << Eil.Pav << setw(4);
            cout << setprecision(2);
            cout << Eil.GP << endl;
        }


        else {
            try{
                throw invalid_argument("Irasyta netinkama skaiciavimo tipo reiksme!");
            }
            catch (invalid_argument sr){
                cout << sr.what();
            }
        }
    }
}
