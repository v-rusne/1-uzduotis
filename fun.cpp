#include "fun.h"

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
