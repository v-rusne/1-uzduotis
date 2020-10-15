#include "funkc.h"

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

double vidurkis(float gp, vector<int> paz, int egz){
    gp = accumulate(paz.begin(), paz.end(), 0);
    gp = gp / paz.size();
    return gp;
}

void isvedimas_med(){
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Med.)\n";
    cout << "------------------------------------------------------------------\n";
}
void isvedimas_vid(){
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(4) << "Galutinis (Vid.)\n";
    cout << "------------------------------------------------------------------\n";

}
