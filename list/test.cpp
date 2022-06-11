#include "funkcijos_list.h"


int main()
{
    list<int> intiger;
    list<int>::iterator it;
    int sum = 0;
    int temp;
    for(int i = 5; i < 10; i++){
        temp = i;
        intiger.push_back(temp);
    }
    temp = intiger.front();
    cout << temp;
    return 0;
}