#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::endl;
using std::setw;

struct data {
    string vardas="", pavarde="";
    vector<int> paz;
    int egz = 0, paz_sk = 0;
    double rezult=0;
};

void isvestis(data& temp, string b);
void isved(const data& temp);
int failcheck();
int amountcheck();
int amountcheck2();

void isvestis(data& temp, string b)
{
    int laikinas;
    if(b == "t" || b == "T")
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (1,10);
        cout <<"Veskite varda: "; cin >> temp.vardas;
        cout <<"Veskite pavarde: "; cin >> temp.pavarde;
        for(int i = 0; i < temp.paz_sk; i++)
        {
            laikinas = dist(mt);
            temp.paz.push_back(laikinas);
        }
        temp.egz = dist(mt);
    }
    else
    {
        cout <<"Veskite varda: "; cin >> temp.vardas;
        cout <<"Veskite pavarde: "; cin >> temp.pavarde;
        for(int i = 0; i < temp.paz_sk; i++)
        {
            cout<<"Isveskite " << i + 1 << "-a(-i) pazymi (nuo 1 iki 10): ";
            cin >> laikinas;
            if(cin.fail()){
                laikinas = failcheck(); 
            }
            if(laikinas > 10 || laikinas <= 0){
                laikinas = amountcheck(); 
            }
            temp.paz.push_back(laikinas);
        }
        cout << "Veskite egzamino iverti (nuo 1 iki 10): "; cin >> temp.egz;
        if(cin.fail()) temp.egz = failcheck();
        if(temp.egz > 10 || temp.egz <= 0) temp.egz = amountcheck();
    }
}

void isved(const data& temp)
{
    int sum = 0;
    double atsM;
    cout << temp.vardas << setw(19) << temp.pavarde;
    for(int i = 0; i < temp.paz_sk; i++)
    {
         sum = sum + temp.paz[i];
    }
    double atsV = sum / temp.paz_sk * 0.4 + temp.egz * 0.6;
    if ( temp.paz_sk % 2 == 0)
    {
        atsM = (temp.paz[temp.paz_sk/2-1] + temp.paz[temp.paz_sk/2]) / 2.0 * 0.4 + temp.egz * 0.6;
    }
    else
    {
        atsM = temp.paz[temp.paz_sk/2] * 0.4 + temp.egz * 0.6;
    }
    cout << setw(15) << atsV;
    cout << setw(15) << atsM << endl;
}

int failcheck()
{
    int x;
    while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error! Neivedete skaiciaus. " << endl;
            cout << "Iveskite skaiciu is naujo: ";
            cin >> x;
        }
    return x;
}

int amountcheck()
{
    int x;
    while (x > 10 || x <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Error! Skaicus nera tarp 0 ir 10!." << endl;
            cout << "Iveskite skaiciu is naujo: ";
            cin >> x;
            if(cin.fail()){
                x = failcheck(); 
            }
        }
    return x;
}
int amountcheck2()
{
    int x;
    while (x <= 0)
        {
            cin.clear();
            cin.ignore();
            cout << "Error! Skaicus yra mazesnis uz 0!." << endl;
            cout << "Iveskite skaiciu is naujo: ";
            cin >> x;
            if(cin.fail()){
                x = failcheck(); 
            }
        }
    return x;
}