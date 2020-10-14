#include <iostream>
#include<string>
#include<vector>
#include<iomanip> /*setprecision, setw*/
#include<bits/stdc++.h> /*accumulate, nth_element*/
#include<stdlib.h> /*EXIT_FAILURE*/

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
using std::to_string;
using std::ofstream;
using std::ifstream;

struct duomuo {
    string Vard, Pav, kat;
    float egz, paz;
    vector<int> pazymiai;
    float GP=0;

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

bool yra_skaicius(string s){
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}


int main()
{
    duomuo Eil;
    std::vector <duomuo> Eil_vect;
    int stud;
    string n, t, pvd, Vid="Vidurkis", Med="Mediana", vid="vidurkis", med="mediana", tipas;
    cout << "Ar norite generuoti atsitiktinius studentu sarasus?\n";
    cin >> t;
    if (t == "Taip" || t == "taip"){

        cout << "Irasykite, kiek eiluciu norite generuoti?\n";
        cin >> stud;
        cout << "Irasykite norimo irasyti failo pavadinima (su .txt):\n";
        cin >> pvd;
        srand((unsigned) time(0));
        ofstream failas(pvd);

        for (int i = 0; i<stud; i++){
            int skaicius = rand();
            Eil.Vard = "Vardas";
            Eil.Vard += to_string(skaicius);
            Eil.Pav = "Pavarde";
            Eil.Pav += to_string(skaicius);
            Eil.GP = (rand() % 10) + 1;
            Eil_vect.push_back(Eil);
        }

            failas<< left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)\n";
            failas << "------------------------------------------------------------------\n";

            for (int j=0; j<stud; j++){
            failas << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
            failas << setprecision(2);
            failas << Eil_vect[j].GP << endl;
        }

         failas.close();

        string line;
        ifstream atidarymas(pvd);
        if (atidarymas.is_open())
            {
                while ( getline (atidarymas,line) )
                {
                        cout << line << '\n';
                }

            failas<< left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)" << setw(20) << "Kategorija\n");
            failas << "-------------------------------------------------------------------------\n";
            for (int j=0; j<stud; j++){
            failas << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
            failas << setprecision(2);
            failas << Eil_vect[j].GP<<endl;

        }


        }
    atidarymas.close();
  }

  else cout << "Nera tokio failo!";

  return 0;
    }
    else{
    cout << "Ar norite, kad mokinio balai( egzamino ir namu darbu) butu generuojami atsitiktinai?\n";
    cin >> n;
    if (n == "Ne" || n == "ne"){

        cout << "Iveskite kaip bus skaiciuojamas galutinis balas (Vidurkis/Mediana):\n";
        cin >> tipas;
        cout << "Iveskite, kiek studentu noresite irasyti?\n";
        cin >> stud;

        /*Kai pasirenkamas galutinis balas isvestas is vidurkio*/
        if (tipas.compare(Vid) == 0 || tipas.compare(vid) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde, egzamino rezultatas, semestro pazymiai):\n *Irase visus pazymius, iveskite '000' ir paspauskite 'Enter'\n";
            for (int i = 0; i < stud; i++){
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

            Eil_vect.push_back(Eil);
}
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)\n";
            cout << "------------------------------------------------------------------\n";

            for (int j=0; j<stud; j++){
            cout << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
            cout << setprecision(2);
            cout << Eil_vect[j].GP << endl;
        }}


        /*Pasirenkamas galutinio balo skaiciavimas naudojant mediana*/
        else if (tipas.compare(Med) == 0 || tipas.compare(med) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde, egzamino rezultatas, semestro pazymiai):\n *Irase visus pazymius, iveskite '000' ir paspauskite 'Enter'\n";
            for (int i = 0; i < stud; i++){
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
            Eil_vect.push_back(Eil);
            }
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavardë" << setw(4) << "Galutinis (Med.)\n";
            cout << "------------------------------------------------------------------\n";
            for (int j=0; j<stud; j++){
            cout << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
            cout << setprecision(2);
            cout << Eil_vect[j].GP << endl;
        }
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
        cout << "Iveskite, kiek studentu noresite irasyti?\n";
        cin >> stud;
        cout << "Kiek pazymiu rezultatu norite sugeneruoti?\n";
        cin >> r;
        srand((unsigned) time(0));
        int randomp, randome;
        cout << "Iveskite kaip bus skaiciuojamas galutinis balas (Vidurkis/Mediana):\n";
        cin >> tipas;


        /*Kai pasirenkamas galutinis balas isvestas is vidurkio*/
        if (tipas.compare(Vid) == 0 || tipas.compare(vid) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde):\n *Irase visus duomenis paspauskite 'Enter'\n";
            for (int i = 0; i < stud; i++){
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

            for (int i = 0; i < 1; i++){
                randome = (rand() % 10) + 1;
                Eil.egz = randome;
            }

            for (int i = 0; i < r; i++){
                randomp = (rand() % 10) + 1;
                Eil.pazymiai.push_back(randomp);
            }

            Eil.GP = accumulate(Eil.pazymiai.begin(), Eil.pazymiai.end(), 0);
            Eil.GP = Eil.GP / Eil.pazymiai.size();
            Eil.GP = Eil.GP*0.4 + Eil.egz*0.6;
            Eil_vect.push_back(Eil);
            }

            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)\n";
            cout << "------------------------------------------------------------------\n";

            for (int j=0; j<stud; j++){
            cout << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
            cout << setprecision(2);
            cout << Eil_vect[j].GP << endl;
        }
        }



        /*Pasirenkamas galutinio balo skaiciavimas naudojant mediana*/
        else if (tipas.compare(Med) == 0 || tipas.compare(med) == 0){
            cout << "Iveskite eilutes duomenis (Vardas, pavarde):\n *Irase visus duomenis paspauskite 'Enter'\n";
            for (int i = 0; i < stud; i++){
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

            for (int i = 0; i < 1; i++){
                randome = (rand() % 10) + 1;
                Eil.egz = randome;
            }

            for (int i = 0; i < r; i++) {
                randomp = (rand() % 10) + 1;
                Eil.pazymiai.push_back(randomp);
            }

            Eil.GP=mediana(Eil.pazymiai, Eil.pazymiai.size());
            Eil.GP=Eil.GP*0.4 + Eil.egz*0.6;
            Eil_vect.push_back(Eil);
            }

            cout << "------------------------------------------------------------------\n";
            cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Med.)\n";

            for (int j=0; j<stud; j++){
            cout << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
            cout << setprecision(2);
            cout << Eil_vect[j].GP << endl;
        }
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
}

