#include "struct.h"
#include "funkc.h"


int main()
{
    duomuo Eil;
    vector <duomuo> Eil_vect;
    int stud;
    string generuojami, atsitiktiniai, pavad, tipas;

    cout << "Ar norite generuoti atsitiktinius studentu sarasus?\n";
    cin >> atsitiktiniai;
    if (atsitiktiniai == "Taip" || atsitiktiniai == "taip"){
        cout << "Irasykite, kiek eiluciu norite generuoti?\n";
        cin >> stud;
        cout << "Irasykite norimo irasyti failo pavadinima (su .txt):\n";
        cin >> pavad;
        srand((unsigned) time(0));
        ofstream failas(pavad);

        for (int i = 0; i<stud; i++){
            int skaicius = rand();
            Eil.Vard = "Vardas";
            Eil.Vard += to_string(skaicius);
            Eil.Pav = "Pavarde";
            Eil.Pav += to_string(skaicius);
            Eil.GP = (rand() % 10) + 1;
            Eil_vect.push_back(Eil);
        }

            failas<< left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis\n";
            failas << "------------------------------------------------------------------\n";
            for (int j=0; j<stud; j++){
                failas << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
                failas << setprecision(2);
                failas << Eil_vect[j].GP << endl;
            }

            ofstream vargs("vargsiukai.txt");
            vargs<< left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)\n";
            vargs << "------------------------------------------------------------------\n";
            ofstream saun("saunuoliai.txt");
            saun << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)\n";
            saun << "------------------------------------------------------------------\n";

            for (int j=0; j<stud; j++){
                if (Eil_vect[j].GP < 5){
                    vargs << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
                    vargs << setprecision(2);
                    vargs << Eil_vect[j].GP << endl;
                }
                else {
                    saun << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
                    saun << setprecision(2);
                    saun << Eil_vect[j].GP << endl;
                }
            }
            vargs.close();
            saun.close();
            failas.close();
    }


    else if (atsitiktiniai == "Ne" || atsitiktiniai == "ne"){
        cout << "Ar norite, kad mokinio balai( egzamino ir namu darbu) butu generuojami atsitiktinai?\n";
        cin >> generuojami;
        if (generuojami == "Ne" || generuojami == "ne"){
            cout << "Iveskite kaip bus skaiciuojamas galutinis balas (Vidurkis/Mediana):\n";
            cin >> tipas;
            cout << "Iveskite, kiek studentu noresite irasyti?\n";
            cin >> stud;

            /*Kai pasirenkamas galutinis balas isvestas is vidurkio*/
            if (tipas == "Vidurkis" || tipas == "vidurkis"){
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

                    Eil.GP=vidurkis(Eil.GP, Eil.pazymiai, Eil.egz);
                    Eil.GP=Eil.GP*0.4 + Eil.egz*0.6;
                    Eil_vect.push_back(Eil);
                }

                isvedimas_vid();
                for (int j=0; j<stud; j++){
                    cout << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
                    cout << setprecision(2);
                    cout << Eil_vect[j].GP << endl;
                }
            }


            /*Pasirenkamas galutinio balo skaiciavimas naudojant mediana*/
            else if (tipas == "Mediana" || tipas == "mediana"){
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

                    isvedimas_med();
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

        else if (generuojami == "Taip" || generuojami == "taip"){
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
            if (tipas == "Vidurkis" || tipas == "vidurkis"){
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

                    Eil.GP=vidurkis(Eil.GP, Eil.pazymiai, Eil.egz);
                    Eil.GP=Eil.GP*0.4 + Eil.egz*0.6;
                    Eil_vect.push_back(Eil);
                }

                isvedimas_vid();
                for (int j=0; j<stud; j++){
                    cout << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(4);
                    cout << setprecision(2);
                    cout << Eil_vect[j].GP << endl;
                }
            }


            /*Pasirenkamas galutinio balo skaiciavimas naudojant mediana*/
            else if (tipas == "Mediana" || tipas == "mediana"){
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

                isvedimas_med();
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
    else {
        try{
            throw invalid_argument("Irasyta netinkama reiksme!");
            }
            catch (invalid_argument gen){
                cout << gen.what();
            }
    }

}
