#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;

struct data {
    string vardas="", pavarde="";
    int paz[3] = {0}, egz=0;
    double rezult=0;
};

void isvestis(data& temp, int a);
void isved(const data& temp, int a);

int main()
{
    vector<data> sarasas;
    data laik;
    int n, a;
    cout << "Kiek studentu vesite?"; cin >> n;
    cout << "Kiek namu darbu pazymiu vesite?"; cin >> a;
    sarasas.reserve(n);
    for(int i = 0; i<n; i++)
    {
        isvestis(laik,a);
        sort(&laik.paz[0], &laik.paz[0]+a-1);
        sarasas.push_back(laik);
    }

    for(const auto &el : sarasas)
    {
        isved(el, a);
    }
}

void isvestis(data& temp, int a)
{
    cout <<"Veskite varda: "; cin >> temp.vardas;
    cout <<"Veskite pavarde: "; cin >> temp.pavarde;
    for(int i = 0; i < a; i++)
    {
        cout<<"Isveskite " << i + 1 << "-a(-i) pazymi:";
        cin >> temp.paz[i];
        while (temp.paz[i] > 10 || temp.paz[i] <= 0)
        {
            cout << "Error! Skaicus turetu buti tarp (1 ir 10)." << std::endl;
            cout << "iveskite skaiciu is naujo: ";
            cin >> temp.paz[i];
        }
    }
    cout << "Veskite egzamino iverti: "; cin >> temp.egz;
}

void isved(const data& temp, int a)
{
    int sum = 0;
    cout << temp.vardas << std::setw(20) << temp.pavarde;
    for(int i = 0; i < a; i++)
    {
        sum = sum + temp.paz[i];
    }
    double atsV = sum/a*0.4+temp.egz*0.6;
    cout << std::setw(10) << atsV << std::endl;
}