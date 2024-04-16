#include <iostream>
#include <cstring>
using namespace std;
/*Recibimos un vector de tamaño n, una cantidad q de
queries, luego los numeros de cada posicion. La idea 
es saber cuanto es la suma de los elementos desde la
posicion i hasta la j*/
int main(){
    int n,q;
    cin >> n >> q;

    int DP[n+1];
    memset(DP,0,n+1); //inicializa el arreglo en ceros.
    int v;
    for(int k=1;k<=n;k++){
        cin >> v;
        DP[k]= DP[k-1] + v;
    }
    int res[q];
    
    for(int k=0;k<q;k++){
        int i,j;
        cin >> i >> j;
        res[k]=DP[j]-DP[i-1];
    }

    for(int k=0;k<q;k++){
        cout << res[k] << endl;
    }
    return 0;
}
/*
8 5
2 5 7 3 8 1 4 4
1 5
3 6
8 8
3 4
2 8
*/