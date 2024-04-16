#include <iostream>
#include <set>
using namespace std;

int main(){
    set <int> contador;
    int n,value;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> value;
        contador.insert(value);
    }
    cout << (int)contador.size()<<endl;    

    return 0;
}