#include "funkcijos.h"

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
                n = amountcheck2(); 
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
                        cout << "Kiek namu darbu pazymiu vesite (daugiau nei 0)?"; cin >> laik_tust.paz_sk;
                        if(cin.fail()){
                            laik_tust.paz_sk = failcheck(); 
                        }
                        if(laik_tust.paz_sk <= 0){
                            laik_tust.paz_sk = amountcheck2(); 
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
                            cout << "Kiek namu darbu pazymiu vesite (daugiau nei 0)?"; cin >> laik_tust.paz_sk;
                            if(cin.fail()){
                                laik_tust.paz_sk = failcheck(); 
                            }
                            if(laik_tust.paz_sk <= 0){
                                laik_tust.paz_sk = amountcheck2(); 
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
    return 0;
}