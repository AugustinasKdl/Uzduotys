#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <string>
#include <deque>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>
#include <ratio>

using std::cout;
using std::cin;
using std::string;
using std::deque;
using std::sort;
using std::endl;
using std::setw;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::stringstream;
using std::istringstream;
using std::isdigit;
using std::ifstream;
using std::ofstream;
using std::terminate;
using std::getline;
using namespace std::chrono;
typedef std::chrono::high_resolution_clock Clock;

struct data {
    string vardas="", pavarde="";
    deque<int> paz;
    int egz = 0, paz_sk = 0;
    int rezult1 = 0, rezult2 = 0;
    string eilute, eilute2;
};  

void input(data& temp, string b);
void output(data& temp);
void skaiciavimai(data& temp);
void skaiciavimai2(data& temp);
int failcheck();
int amountcheck();
int amountcheck2();
bool isNumber(const string& str);
void toString(data& temp, string& line);
void toString2(data& temp, string& line);
void mix_generate(string gen_file, int n, int k, string tkr);
void mix2(string read_file, int k);