#include "funkcijos.h"

int main()
{
    vector<data> sarasas;
    data laik;
    data laik_tust;
    int n, a;
    string tkr, tkr2, tkr3, tkr4;
    bool run = true, run2 = true, run3 = true, run4 = true;
    while(run4) // Patikrina ar vartotojas nori skaityti duomenis is failo
    {
        cout << "Ar norite nuskaityti is failo (t/n)? "; cin >> tkr4;
        if(tkr4 == "t" || tkr4 == "T")
        {
            cout<<"Miksuotas variantas (skaito eilutemis, iraso per buferi):\n";
            mix("studentai10000.txt", "studentai_copy.txt");
            cout <<"Pirmas baigtas!" << endl;
            mix("studentai100000.txt", "studentai2_copy.txt");
            cout <<"Antras baigtas!" << endl;
            mix("studentai1000000.txt", "studentai3_copy.txt");
            cout <<"Trecias baigtas!" << endl;
            run4 = false;
        }
        else if(tkr4 == "n" || tkr4 == "N")
        {
            while(run) // Patikrina ar vartotojas zino studentu skaiciu
            {
                cout << "Ar zinote studentu skaiciu (t/n)? "; cin >> tkr;
                if(tkr == "t" || tkr == "T")
                {
                    cout << "Kiek studentu vesite (daugiau nei 0)? "; cin >> n;
                    if(cin.fail()){
                        n = failcheck(); 
                        }
                    if(n <= 0){
                        n = amountcheck2(); 
                    }
                    sarasas.reserve(n);
                    while(run2) // Patikrina ar vartotojas nori automatiskai generuti pazimius
                    {
                        cout << "Ar norite generuoti pazymius (t/n)? "; cin >> tkr2;
                        if(tkr2 == "t" || tkr2 == "T" || tkr2 == "n" || tkr2 == "N")
                        {
                            for(int i = 0; i<n; i++)
                            {
                                laik = laik_tust;
                                cout << "Kiek namu darbu pazymiu vesite (daugiau nei 0)? "; cin >> laik.paz_sk;
                                if(cin.fail()){
                                    laik.paz_sk = failcheck(); 
                                }
                                if(laik.paz_sk <= 0){
                                    laik.paz_sk = amountcheck2(); 
                                }
                                input(laik, tkr2);
                                skaiciavimai(laik);
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
                    while(run2) // Patikrina ar vartotojas nori automatiskai generuti pazimius
                    {
                        cout << "Ar norite generuoti pazymius (t/n)? "; cin >> tkr2;
                        if(tkr2 == "t" || tkr2 == "T" || tkr2 == "n" || tkr2 == "N")
                        {
                            while(run3) // Patikrina ar nori ivesti nauja studenta
                            {
                                laik = laik_tust;
                                cout << "Ar norite vesti studenta (t/n)? "; cin >> tkr3;
                                if(tkr3 == "n" || tkr3 == "N")
                                {
                                    run3 = false;
                                }
                                else if(tkr3 == "t" || tkr3 == "T")
                                {
                                    cout << "Kiek namu darbu pazymiu vesite (daugiau nei 0)? "; cin >> laik.paz_sk;
                                    if(cin.fail()){
                                        laik.paz_sk = failcheck(); 
                                    }
                                    if(laik.paz_sk <= 0){
                                        laik.paz_sk = amountcheck2(); 
                                    }
                                    input(laik, tkr2);
                                    skaiciavimai(laik);
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
            for(auto &el : sarasas)
            {
                skaiciavimai(el);
            }
            run4 = false;
        }
        else
        {
            cout << "Error! Ivedimas netinkamas. Prašome pakartoti." << endl;
        }
    }
    return 0;
}