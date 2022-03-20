#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>
#include <ratio>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::endl;
using std::setw;
using namespace std::chrono;
typedef std::chrono::high_resolution_clock Clock;


struct data {
    string vardas="", pavarde="";
    vector<int> paz;
    int egz = 0, paz_sk = 0;
    int rezult1 = 0, rezult2 = 0;
    string eilute;
};

void input(data& temp, string b);
void output(data& temp);
void skaiciavimai(data& temp);
void skaiciavimai2(data& temp);
int failcheck();
int amountcheck();
int amountcheck2();
void mix(string read_file, string write_file);
bool isNumber(const string& str);
void toString(data& temp, string& line);
void toString2(data& temp, string& line);
void mix_generate(string gen_file, int n, int k);
void mix2(string read_file);