#include "funkcijos_list.h"

void toString(data& temp, string& line)
{
    string s1, s2, s3;
    std::stringstream ss;
    ss << temp.rezult1;
    ss >> s1;
    std::stringstream ss2;
    ss2 << temp.rezult2;
    ss2 >> s2;
    s3 = line;
    if(temp.rezult1 == 10) s3+= "        " + s1;
    else s3+= "         " + s1;
    if(temp.rezult2 == 10) s3+= "        " + s2;
    else s3+= "         " + s2;
    temp.eilute = s3;
}

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void input(data& temp, string b)
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
void output(data& temp)
{
    cout<< temp.vardas << setw(21) << temp.pavarde << setw(21) << temp.rezult1 << setw(15) << temp.rezult2 << endl;
}
void skaiciavimai(data& temp)
{
    int sum = 0;
    double atsM = 0;
    double atsV = 0;
    sort(&temp.paz[0], &temp.paz[0]+temp.paz_sk);
    for(int i = 0; i < temp.paz_sk; i++)
    {
        sum = sum + temp.paz[i];
    }
    atsV = sum / temp.paz_sk * 0.4 + temp.egz * 0.6;
    temp.rezult1 = atsV;
    if ( temp.paz_sk % 2 == 0)
    {
        atsM = (temp.paz[temp.paz_sk/2-1] + temp.paz[temp.paz_sk/2]) / 2.0 * 0.4 + temp.egz * 0.6;
        temp.rezult2 = atsM;
    }
    else
    {
        atsM = temp.paz[temp.paz_sk/2] * 0.4 + temp.egz * 0.6;
        temp.rezult2 = atsM;
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

void mix_generate(string gen_file, int n, int k, string tkr)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist (1,10);
    auto t1 = Clock::now();
    duration<double> diff;
    string outputas="Vardas                   Pavarde                    ";
    string gapV = "                  ", gapP = "                    ", gap = " ", gapND = "       ";
    int x = 10;
    for(int i = 0; i < n; i++)
    {
        if(i+1 == x)
        {
            gapND.pop_back();
            x = x * 10;
        }
        string a;
        std::stringstream ss;
        ss << i+1;
        ss >> a;
        outputas = outputas + "ND" + (a) + gapND;
    }
    outputas = outputas + "Egz.\n";
    for(int i = 0; i < k; i++)
    {
        string a, c;
        std::stringstream ss;
        ss << i+1;
        ss >> a;
        if(i+1 == x)
        {
            gapV.pop_back();
            gapV.pop_back();
            x = x * 10;
        }
        for(int j = 0; j < n+1; j++)
        {
            int temp = dist(mt);
            string b, z = "         ";
            if(temp == 10){
                z.pop_back();
            }
            std::stringstream ss;
            ss << temp;
            ss >> b;
            c += b + z;
        }
        outputas += "Vardas"+ a + gapV + "Pavarde" + a + gapP + c + "\n";
    }
    outputas.pop_back();
    auto t2 = Clock::now();
    diff = t2-t1;
    cout << "Uztruko: " << diff.count() << " s. Sukurti duomenis: " << k << " skaic. studentu. \n";
    auto t3 = Clock::now();
    std::ofstream in(gen_file);
    in << outputas;
    in.close();
    auto t4 = Clock::now();
    diff = t4-t3;
    cout << "Uztruko: " << diff.count() << " s. ikelti duomenis. \n";
    if(tkr == "t" || tkr == "T"){
        auto t5 = Clock::now();
        mix2(gen_file, k);
        auto t6 = Clock::now();
        cout << "Uztruko: " << diff.count() << " s. Padalinti duomenis i du failus. \n";
    }
}

void mix2(string read_file, int k)
{
    int kodel = 0;
    vector<std::string> splited;
    vector<data> sarasas;
    data laik;
    data laik_tust;
    string eil;
    string outputas, outputas2;
    //----------------------------------------------------------------------
    try{
        std::ifstream open_f(read_file);
        if(open_f.peek() == EOF)
        {
            throw 1;
        }
        else
        {
           while (open_f){ 
                if (!open_f.eof()) {
                    std::getline(open_f, eil);
                    splited.push_back(eil);}
                else break;
            }
            open_f.close(); 
        }
    }
    catch(int x){
        cout << "Failas tuscias!! ERROR Nr. " << x;
        std::terminate;
    }
    //-----------------------------------------------------------------------              
    for(string &el : splited)
    {
        if(&el == &splited.front())
        {
            outputas= "Vardas                   Pavarde                  gal/vid\n";
            outputas2= "Vardas                   Pavarde                  gal/vid\n";
        }
        else
        {
            std::string buf;            // buffer vektorius
            std::stringstream ss(el);       // I stream idedame eilute
            vector<string> tokens; // sukuriame elementus laikanti vektoriu
            laik = laik_tust;  //istustiname laik vektoriu;
            while (ss >> buf){
                tokens.push_back(buf);
            }
            int j = 0; 
            for(string &el2 : tokens)
            {
                if(isNumber(el2) == true)
                {
                    int i = 0;
                    if(&el2 == &tokens.back())
                    {
                        std::istringstream(el2) >> i;
                        laik.egz = i;
                        laik.paz_sk = j;
                    }
                    else{
                        std::istringstream(el2) >> i;
                        laik.paz.push_back(i);
                    }
                    j++;
                }
            }
            skaiciavimai2(laik);
            toString2(laik,el);
            sarasas.push_back(laik); 
            kodel++;
        }
    }
    //----------------------------------------------------------------------
    for (auto &a: sarasas){
        outputas += a.eilute;
        outputas2 += a.eilute2; 
    }
    //----------------------------------------------------------------------
    string outf_name = "nuskriaustukai", outf2_name = "galvociai", temps="";
    std::stringstream ss;
    ss << k;
    ss >> temps;
    outf_name += temps + ".txt"; 
    outf2_name += temps + ".txt";
    std::ofstream out_f(outf_name);
    out_f << outputas;
    out_f.close();
    std::ofstream out2_f(outf2_name);
    out2_f << outputas2;
    out2_f.close();
}
void skaiciavimai2(data& temp)
{
    int sum = 0;
    double atsV = 0;
    for(int i = 0; i < temp.paz_sk; i++)
    {
        sum = sum + temp.paz[i];
    }
    atsV = sum / temp.paz_sk * 0.4 + temp.egz * 0.6;
    temp.rezult1 = atsV;
}
void toString2(data& temp, string& line)
{
    string s1, s2, s3, s4;
    std::stringstream ss;
    if(temp.rezult1 < 5)
    {
        ss << temp.rezult1;
        ss >> s1;
        s3 = line.substr(0, 53) + s1 + "\n";
    }
    else
    {
        ss << temp.rezult1;
        ss >> s2;
        s4 = line.substr(0, 53) + s2 + "\n";   
    }
    temp.eilute = s3;
    temp.eilute2 = s4;
}