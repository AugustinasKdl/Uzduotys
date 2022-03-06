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
int amountcheck2();
void bufer_nusk(string read_file, string write_file);
void mix(std::string read_file, std::string write_file);
bool isNumber(const string& str);