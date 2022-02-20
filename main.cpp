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
    int paz[250] = {0}, egz=0;
    double rezult=0;
};

void isvestis(data& temp, int a);
void isved(const data& temp, int a);
int failcheck();
int amountcheck();

int main()
{
    vector<data> sarasas;
    data laik;
    int n, a;
    cout << "Kiek studentu vesite (daugiau nei 0)?"; cin >> n;
    if(cin.fail()){
           n = failcheck(); 
        }
    if(n <= 0){
        n = amountcheck(); 
    }
    sarasas.reserve(n);
    for(int i = 0; i<n; i++)
    {
        cout << "Kiek namu darbu pazymiu vesite (tarp 1 ir 250)?"; cin >> a;
        if(cin.fail()){
            a = failcheck(); 
            }
        if(a > 250 || a <= 0){
            a = amountcheck(); 
        }
        isvestis(laik,a);
        sort(&laik.paz[0], &laik.paz[0]+a);
        sarasas.push_back(laik);
    }

    cout << "Vardas" << std::setw(21) << "Pavarde" << std::setw(41) << "Galutinis(Vid.) / Galutinis(Med.)" << std::endl;
    cout << "------------------------------------------------------------------" << std::endl;
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
        cout<<"Isveskite " << i + 1 << "-a(-i) pazymi (nuo 1 iki 10): ";
        cin >> temp.paz[i];
        if(cin.fail()){
           temp.paz[i] = failcheck(); 
        }
        if(temp.paz[i] > 10 || temp.paz[i] <= 0){
           temp.paz[i] = amountcheck(); 
        }
    }
    cout << "Veskite egzamino iverti (nuo 1 iki 10): "; cin >> temp.egz;
    if(cin.fail()) temp.egz = failcheck();
    if(temp.egz > 10 || temp.egz <= 0) temp.egz = amountcheck();
    
}

void isved(const data& temp, int a)
{
    int sum = 0;
    double atsM;
    cout << temp.vardas << std::setw(19) << temp.pavarde;
    for(int i = 0; i < a; i++)
    {
        sum = sum + temp.paz[i];
    }
    // for(int i = 0; i < a; i++)
    // {
    //     cout << std::setw(15) << temp.paz[i];
    // }
    double atsV = sum/a*0.4+temp.egz*0.6;
    if ( a % 2 == 0)
    atsM = (temp.paz[a/2-1] + temp.paz[a/2]) / 2.0;
    else
    atsM = temp.paz[a/2];
    cout << std::setw(15) << atsV;
    cout << std::setw(15) << atsM << std::endl;
}
int failcheck()
{
    int x;
    while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error! Neivedete skaiciaus. " << std::endl;
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
            cout << "Error! Skaicus yra per didelis arba per mazas." << std::endl;
            cout << "Iveskite skaiciu is naujo: ";
            cin >> x;
            if(cin.fail()){
                x = failcheck(); 
            }
        }
    return x;
}