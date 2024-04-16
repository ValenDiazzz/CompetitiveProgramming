#include <iostream>
#include <vector>
using namespace std;

int main(){
    int value;
    int n=0;
    for(unsigned int i=0; i<25; i++){
        cin >> value;
        if (value!=0){
            n=i;
        }
    }
    int fila=int(n/5);
    int columna= n%5;
    cout << abs(fila-2) + abs(columna-2) << endl;
    return 0;
}