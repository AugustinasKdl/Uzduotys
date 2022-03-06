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
    vector<int> paz, egz;
    double rezult=0;
};

void isvestis(data& temp, int a, string b);
void isved(const data& temp, int a);
int failcheck();
int amountcheck();

int main()
{
    vector<data> sarasas;
    data laik;
    int n, a;
    string tkr, tkr2, tkr3;
    bool run = true, run2 = true, run3 = true;
    while(run)
    {
        cout << "Ar zinote studentu skaiciu? (t/n)"; cin >> tkr;
        if(tkr == "t" || tkr == "T")
        {
            cout << "Kiek studentu vesite (daugiau nei 0)?"; cin >> n;
            if(cin.fail()){
                n = failcheck(); 
                }
            if(n <= 0){
                n = amountcheck(); 
            }
            sarasas.reserve(n);
            while(run2)
            {
                cout << "Ar norite generuoti pazymius? (t/n)"; cin >> tkr2;
                if(tkr2 == "t" || tkr2 == "T" || tkr2 == "n" || tkr2 == "N")
                {
                    for(int i = 0; i<n; i++)
                    {
                        cout << "Kiek namu darbu pazymiu vesite (tarp 1 ir 250)?"; cin >> a;
                        if(cin.fail()){
                            a = failcheck(); 
                            }
                        laik.paz.reserve(a);
                        laik.egz.reserve(1);
                        isvestis(laik, a, tkr2);
                        sort(&laik.paz[0], &laik.paz[0]+a);
                        sarasas.push_back(laik);
                        
                    } 
                    run2 = false;
                }
                else
                {
                    cout << "Error! Ivedimas netinkamas. Prašome pakartoti." << endl;
                }
            }
            run = false;
        } 
        else if(tkr == "n" || tkr == "N")
        {
            while(run2)
            {
                cout << "Ar norite generuoti pazymius? (t/n)"; cin >> tkr2;
                if(tkr2 == "t" || tkr2 == "T" || tkr2 == "n" || tkr2 == "N")
                {
                    while(run3)
                    {
                        cout << "Ar norite vesti studenta (t/n)?"; cin >> tkr3;
                        if(tkr3 == "n" || tkr3 == "N")
                        {
                            cout << run3;
                            run3 = false;
                        }
                        else if(tkr3 == "t" || tkr3 == "T")
                        {
                            cout << "Kiek namu darbu pazymiu vesite (tarp 1 ir 250)?"; cin >> a;
                            if(cin.fail()){
                                a = failcheck(); 
                                }
                            laik.paz.reserve(a);
                            laik.egz.reserve(1);
                            isvestis(laik, a, tkr2);
                            sort(&laik.paz[0], &laik.paz[0]+a);
                            sarasas.push_back(laik);
                        }
                        else
                        {
                            cout << "Error! Ivedimas netinkamas. Prašome pakartoti." << endl;   
                        }
                    }   
                    run2 = false;
                }    
                else
                {
                    cout << "Error! Ivedimas netinkamas. Prašome pakartoti." << endl;
                }
                run = false;
            }
        }
        else
        {
            cout << "Error! Ivedimas netinkamas. Prašome pakartoti." << endl;
        }
    }
    cout << "Vardas" << setw(21) << "Pavarde" << setw(41) << "Galutinis(Vid.) / Galutinis(Med.)" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(const auto &el : sarasas)
    {
        isved(el, a);
    }
}

void isvestis(data& temp, int a, string b)
{
    if(b == "t" || b == "T")
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (1,10);
        cout <<"Veskite varda: "; cin >> temp.vardas;
        cout <<"Veskite pavarde: "; cin >> temp.pavarde;
        for(int i = 0; i < a; i++)
        {
            temp.paz[i] = dist(mt);
            cout << temp.paz[i] << " ";
        }
        temp.egz[0] = dist(mt);
    }
    else
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
        cout << "Veskite egzamino iverti (nuo 1 iki 10): "; cin >> temp.egz[0];
        if(cin.fail()) temp.egz[0] = failcheck();
        if(temp.egz[0] > 10 || temp.egz[0] <= 0) temp.egz[0] = amountcheck();
        }
    }
}

void isved(const data& temp, int a)
{
    int sum = 0;
    double atsM;
    cout << temp.vardas << setw(19) << temp.pavarde;
    cout << temp.egz[0] << endl;
    cout << temp.paz[0] << endl;
    for(int i = 0; i < a; i++)
    {
        sum = sum + temp.paz[i];
    }
    for(int i = 0; i < a; i++)
    {
        cout << std::setw(15) << temp.paz[i];
    }
    // double atsV = sum / a * 0.4 + temp.egz[0] * 0.6;
    // if ( a % 2 == 0)
    // atsM = (temp.paz[a/2-1] + temp.paz[a/2]) / 2.0 * 0.4 + temp.egz[0] * 0.6;
    // else
    // atsM = temp.paz[a/2] * 0.4 + temp.egz[0] * 0.6;
    // cout << setw(15) << atsV;
    // cout << setw(15) << atsM << endl;
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
            cout << "Error! Skaicus yra per didelis arba per mazas." << endl;
            cout << "Iveskite skaiciu is naujo: ";
            cin >> x;
            if(cin.fail()){
                x = failcheck(); 
            }
        }
    return x;
}