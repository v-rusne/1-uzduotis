#include <iostream>
#include<string>
#include<vector>
#include<system_error>
#include<iomanip>
#include<stdexcept>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::invalid_argument;


struct duomuo {
    int num;
    string Vard;
    string Pav;
    int paz[1];
    int egz;
    float GP=0;
};

int main()
{
    duomuo Eil;duomuo Eil_mas[5];
    vector<duomuo> Eil_vect;
    cout << "Sveiki. Iveskite Eil. duom. (Vardas, Pavarde, Egzamino rezultatas, 5 semestro pazymiai):\n";
    cin >> Eil.Vard >> Eil.Pav >> Eil.egz;

        for (int i=0; i<5; i++){
            cin>>Eil.paz[i];
                Eil.GP=Eil.GP+(float)Eil.paz[i];
        }

try {
    if(Eil.egz<=0 || Eil.egz>10){
        throw invalid_argument("Netinkama egzamino rezultato reiksme!");
    }
}
catch (invalid_argument er){
    cout<<er.what();
}

try{
    if(Eil.paz[5]<=0 || Eil.paz[5]>10){
        throw invalid_argument("Netinkama pazymio reiksme!");
    }
}
catch (invalid_argument pr){
    cout<<pr.what();
}

/*try{
    int num;
    num=1;
    if(Eil.Vardnum){
        throw invalid_argument("Netinkama vardo reiksme!");
    }
}
catch(invalid_argument v){
    cout<<v.what();
}*/

Eil.GP=Eil.GP/5.0;
Eil.GP=Eil.GP*0.4+Eil.egz*0.6;
cout<<"Vardas"<<" "<<"Pavarde"<<" "<<"Galutinis (Vid.)\n";
cout<<"--------------------------------------\n";
cout << "\n"<<Eil.Vard<<" "<<Eil.Pav;
cout << std::setprecision(2);
cout << " " << Eil.GP <<std::endl;
}
