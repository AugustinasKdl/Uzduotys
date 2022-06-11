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
    int *paz;
    int egz = 0, paz_sk = 0;
    data* next;
};


void ListKurimas(int n, string b);
void Isvedimas();
int failcheck();
int amountcheck();

int main()
{
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
                        ListKurimas(a,tkr2);
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
                            run3 = false;
                        }
                        else if(tkr3 == "t" || tkr3 == "T")
                        {
                            cout << "Kiek namu darbu pazymiu vesite (tarp 1 ir 250)?"; cin >> a;
                            if(cin.fail()){
                                a = failcheck(); 
                                }
                            ListKurimas(a, tkr2);
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
    Isvedimas();
}
data* head = NULL;
data* New;
data* temp;
void ListKurimas(int n, string b) {
    if(head == NULL){
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (1,10);
        string V, P;
        cout <<"Veskite varda: "; cin >> V;
        cout <<"Veskite pavarde: "; cin >> P;
        New = (data*) malloc(sizeof(data));
        cout << sizeof(data);
        New->vardas = V;
        New->pavarde = P;
        New->paz_sk = n;
        New->paz = new int(n);
        if(b == "t" || b == "T"){
            for(int i = 0; i < n; i++)
            {
                New->paz[i] = dist(mt);
            }
            New->egz = dist(mt);
        }
        else if(b == "n" || b == "N"){
            for(int i = 0; i < n; i++)
            {
                cout<<"Isveskite " << i + 1 << "-a(-i) pazymi (nuo 1 iki 10): ";
                cin >> New->paz[i];
                if(cin.fail()){
                    New->paz[i] = failcheck(); 
                }
                if(New->paz[i] > 10 || New->paz[i] <= 0){
                    New->paz[i] = amountcheck(); 
                }
            cout << "Veskite egzamino iverti (nuo 1 iki 10): "; cin >> New->egz;
            if(cin.fail()) New->egz = failcheck();
            if(New->egz > 10 || New->egz <= 0) New->egz = amountcheck();
            }
        }
        temp = New;
        head = New;
    }
    else if(head == New){
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (1,10);
        string V, P;
        cout <<"Veskite varda: "; cin >> V;
        cout <<"Veskite pavarde: "; cin >> P;
        New = (data*) malloc(sizeof(data));
        cout << sizeof(data);
        New->vardas = V;
        New->pavarde = P;
        New->paz_sk = n;
        New->paz = new int(n);
        if(b == "t" || b == "T"){
            for(int i = 0; i < n; i++)
            {
                New->paz[i] = dist(mt);
            }
            New->egz = dist(mt);
        }
        else if(b == "n" || b == "N"){
            for(int i = 0; i < n; i++)
            {
                cout<<"Isveskite " << i + 1 << "-a(-i) pazymi (nuo 1 iki 10): ";
                cin >> New->paz[i];
                if(cin.fail()){
                    New->paz[i] = failcheck(); 
                }
                if(New->paz[i] > 10 || New->paz[i] <= 0){
                    New->paz[i] = amountcheck(); 
                }
            cout << "Veskite egzamino iverti (nuo 1 iki 10): "; cin >> New->egz;
            if(cin.fail()) New->egz = failcheck();
            if(New->egz > 10 || New->egz <= 0) New->egz = amountcheck();
            }
        }
        New->egz = dist(mt);
        temp->next = New;
        temp = temp->next;
    }
    else{
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (1,10);
        string V, P;
        cout <<"Veskite varda: "; cin >> V;
        cout <<"Veskite pavarde: "; cin >> P;
        New = new data;
        New->vardas = V;
        New->pavarde = P;
        New->paz_sk = n;
        cout << "kur";
        New->paz = new int(n);
        if(b == "t" || b == "T"){
            for(int i = 0; i < n; i++)
            {
                New->paz[i] = dist(mt);
            }
            New->egz = dist(mt);
        }
        else if(b == "n" || b == "N"){
            for(int i = 0; i < n; i++)
            {
                cout<<"Isveskite " << i + 1 << "-a(-i) pazymi (nuo 1 iki 10): ";
                cin >> New->paz[i];
                if(cin.fail()){
                    New->paz[i] = failcheck(); 
                }
                if(New->paz[i] > 10 || New->paz[i] <= 0){
                    New->paz[i] = amountcheck(); 
                }
            cout << "Veskite egzamino iverti (nuo 1 iki 10): "; cin >> New->egz;
            if(cin.fail()) New->egz = failcheck();
            if(New->egz > 10 || New->egz <= 0) New->egz = amountcheck();
            }
        }
        New->egz = dist(mt);
        temp->next = New;
    }
}
void Isvedimas()
{
    struct data* ptr;
    ptr = head;
    int sum = 0;
    double atsM;
    while (ptr != NULL) {
        cout << ptr->vardas << setw(19) << ptr->pavarde;
        // cout << ptr->egz << endl;
        // for(int i = 0; i < ptr->paz_sk; i++)
        // {
        //     sum = sum + ptr->paz[i];
        // }
        // for(int i = 0; i < ptr->paz_sk; i++)
        // {
        //     cout << std::setw(15) << ptr->paz[i];
        // }
        double atsV = sum / ptr->paz_sk * 0.4 + ptr->egz * 0.6;
        if ( ptr->paz_sk % 2 == 0)
        atsM = (ptr->paz[ptr->paz_sk/2-1] + ptr->egz) / 2.0 * 0.4 + ptr->egz * 0.6;
        else
        atsM = ptr->paz[ptr->paz_sk/2] * 0.4 + ptr->paz[0] * 0.6;
        cout << setw(15) << atsV;
        cout << setw(15) << atsM << endl;
        ptr = ptr->next;
   }
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