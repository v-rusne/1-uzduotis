#ifndef FUNKC_H_INCLUDED
#define FUNKC_H_INCLUDED

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

double mediana(vector<int>, int);
bool yra_skaicius(string);
double vidurkis(float, vector<int>, int);
void isvedimas_med();
void isvedimas_vid();
void isvedimas();

#endif // FUNKC_H_INCLUDED
