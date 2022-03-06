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

int main()
{
    vector<data> sarasas;
    data laik;
    data laik_tust;
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
                        laik_tust = laik;
                        cout << "Kiek namu darbu pazymiu vesite (tarp 1 ir 250)?"; cin >> laik_tust.paz_sk;
                        if(cin.fail()){
                            laik_tust.paz_sk = failcheck(); 
                        }
                        isvestis(laik_tust, tkr2);
                        sort(&laik_tust.paz[0], &laik_tust.paz[0]+laik_tust.paz_sk);
                        sarasas.push_back(laik_tust);
                        
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
                        laik_tust = laik;
                        cout << "Ar norite vesti studenta (t/n)?"; cin >> tkr3;
                        if(tkr3 == "n" || tkr3 == "N")
                        {
                            run3 = false;
                        }
                        else if(tkr3 == "t" || tkr3 == "T")
                        {
                            cout << "Kiek namu darbu pazymiu vesite ?"; cin >> laik_tust.paz_sk;
                            if(cin.fail()){
                                laik_tust.paz_sk = failcheck(); 
                            }
                            isvestis(laik_tust, tkr2);
                            sort(&laik_tust.paz[0], &laik_tust.paz[0]+a);
                            sarasas.push_back(laik_tust);
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
        isved(el);
    }
}

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
            cout << "Error! Skaicus yra per didelis arba per mazas." << endl;
            cout << "Iveskite skaiciu is naujo: ";
            cin >> x;
            if(cin.fail()){
                x = failcheck(); 
            }
        }
    return x;
}