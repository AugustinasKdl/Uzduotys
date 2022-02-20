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
void isved(const data& temp);

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
        isved(el);
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
    }
    cout << "Veskite egzamino iverti: "; cin >> temp.egz;
}

void isved(const data& temp)
{
    cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;
    for(int i = 0; i < 3; i++)
    {
        cout << std::setw(10) << temp.paz[i];
    }
    cout << std::setw(10) << temp.egz << std::endl;
}