#include "fun.h"
#include "struct.h"

int main(){
    duomuo Eil;
    std::vector <duomuo> Eil_vect;
    int stud;
    string n, tipas, failas;

    cout << "Ar norite, duomenis skaityti is .txt failo? (Taip/Ne)\n";
    cin >> failas;

    if (failas == "Taip" || failas == "taip"){
            int nd[5];
            char nm; //namu darbu skaicius
            cout << "Kiek studentai atliko namu darbu?\n";
            cin >> nm;
                if (isdigit(nm)){
                    int eilutes = 0;
                    fstream newfile("kursiokai.txt");
                    string pirma;
                    getline(newfile, pirma);

                    if (newfile.is_open()){
                        while (newfile>>Eil.Vard){
                            newfile >> Eil.Pav ;
                            for (int i =0; i < nm; i++){
                                    newfile>>nd[i];
                                    Eil.GP = Eil.GP+nd[i];
                                    Eil.pazymiai.push_back(nd[i]);
                            }
                            newfile >> Eil.egz;
                            Eil.GP = Eil.GP / nm;
                            Eil.GP = Eil.GP*0.4 + Eil.egz*0.6;
                            Eil.gp = mediana(Eil.pazymiai, Eil.pazymiai.size());
                            Eil.gp = Eil.gp*0.4 + Eil.egz*0.6;
                            Eil_vect.push_back(Eil);
                            ++eilutes;
                        }
                    }

                    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)\n" << setw(20) << endl;
                    cout << "------------------------------------------------------------------------------\n";
                    for (int j=0; j<eilutes; j++){
                        cout << left << setw(20) << Eil_vect[j].Vard << setw(20) << Eil_vect[j].Pav << setw(20);
                        cout << setprecision(2);
                        cout << left << setw(20) << Eil_vect[j].GP << setw(20) << Eil_vect[j].gp << setw(20) << endl;
                    }
                    newfile.close();
                }

                else {
                    try{
                        throw invalid_argument("Neivesta skaitine reiksme!");
                    }
                    catch (invalid_argument nmr){
                        cout << nmr.what();
                        exit(EXIT_FAILURE);
                    }
                }
    }


    else if (failas == "Ne" || failas == "ne"){
        cout << "Ar norite, kad mokinio balai( egzamino ir namu darbu) butu generuojami atsitiktinai? (Taip/Ne)\n";
        cin >> n;

        if (n == "Ne" || n == "ne"){
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
                cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Med.)\n";
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

    else if (n == "Taip" || n == "taip"){
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

    else {
        try{
            throw invalid_argument("Irasyta netinkama reiksme!");
        }
        catch (invalid_argument sr){
            cout << sr.what();
        }
    }


    }

   else {
        try{
            throw invalid_argument("Irasyta netinkama reiksme!");
        }
        catch (invalid_argument sb){
            cout << sb.what();
        }
    }
}


