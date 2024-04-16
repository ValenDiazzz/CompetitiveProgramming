#include <iostream>
using namespace std;


int main(){
    pair <int, char> par1={1,'c'};
    par1.first=3;
    cout << par1.first << par1.second << endl;

    pair <string, pair<string, int>> par2={"Lionel",{"Sabado", 11}};
    cout << par2.first << par2.second.first << par2.second.second  << endl;

    return 0;
}