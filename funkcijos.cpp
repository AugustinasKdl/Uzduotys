#include "funkcijos.h"

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void mix(std::string read_file, std::string write_file)
{
    vector<std::string> splited;
    vector<data> sarasas;
    data laik;
    data laik_tust;
    string eil;
    //----------------------------------------------------------------------
    std::ifstream open_f(read_file);
    while (open_f){ 
        if (!open_f.eof()) {
            std::getline(open_f, eil);
            splited.push_back(eil);}
        else break;
    }
    open_f.close();
    //-----------------------------------------------------------------------              
    for(string &el : splited)
    {
        std::string buf;            // Have a buffer string
        std::stringstream ss(el);       // Insert the string into a stream
        vector<string> tokens; // Create vector to hold our words
        laik = laik_tust;
        int j = 0;
        while (ss >> buf){
            tokens.push_back(buf);
        }
        for(string &el2 : tokens)
        {
            if(isNumber(el2) == true)
            {
                int i = 0;
                if(&el == &tokens.back()){
                    std::istringstream(el2) >> i;
                    laik.egz = i;
                    laik.paz_sk = j - 3;
                }
                else{
                    std::istringstream(el2) >> i;
                    laik.paz.push_back(i);
                } 
            }
            else if(j == 0){
                laik.vardas = el2;
            }
            else if(j == 1){
                laik.pavarde = el2; 
            } 
            j++;
        }
        sarasas.push_back(laik);
    }
    
    //----------------------------------------------------------------------
    string outputas="";
    for (string &a: splited) (a.compare(*splited.rbegin()) !=0) ? outputas+=a+"\n": outputas+=a ;
    //----------------------------------------------------------------------
    std::ofstream out_f(write_file);
    out_f << outputas;
    out_f.close();
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