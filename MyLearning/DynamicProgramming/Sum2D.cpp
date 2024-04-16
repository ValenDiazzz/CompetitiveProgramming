#include <iostream>
#include <vector>
using namespace std;
/*Recibimos una matriz de tamaño nxm, una cantidad q de
queries, luego los numeros de cada posicion. La idea 
es saber cuanto es la suma de los elementos de la submatriz
(a,b) (c,d) donde estos representan al esquina superior
izquierda y la esquina inferior derecha respectivamente.*/

int main(){
    int n,m,q;
    cin >> n >> m>> q;
    int v[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    vector <vector<int>> DP(n+1,vector <int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            DP[i][j]= v[i-1][j-1]+DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1];
        }//le resto 1 a la posicion de v porq la index de DP arranca en 1
    }
    
    int a,b,c,d;
    int res[q];
    for(int k=0;k<q;k++){
        cin >> a >> b >> c >> d;
        res[k]= DP[c][d] - DP[c][b-1] - DP[a-1][d] + DP[a-1][b-1];
    }
    //El ultimo elemento lo sumamos porq lo restamos 2 veces en el acumulado
    for(int k=0;k<q;k++){
        cout << res[k] << endl;
    }
    return 0;
}
