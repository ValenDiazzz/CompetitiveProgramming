#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector <int> sorter(vector <int> v, bool tipo){
    //tipo=0 ordena de mayor a menor
    //tipo=1 ordena de menor a mayor
    sort(v.begin(), v.end());
    if (tipo==0){
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
    }
    
    return v;
}

int main(){
    vector <int> v(3);
    v[0]=5;
    v[1]=4;
    v[2]=3;
    v=sorter(v, 1);
    for(int i=0;i<3;i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v=sorter(v, 0);
    for(int i=0;i<3;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}