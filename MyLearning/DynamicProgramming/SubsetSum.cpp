#include <iostream>
#include <vector>
using namespace std;

/*Dado una cantidad n de numeros nos haran una
cantidad q de queries que son enteros <=m. La 
query es un numero y tenemos que decir si es 
posible formar ese numero sumando los n numeros
que nos dieron al principio, sin repetirlos. 
Ademas decir cuales son esos numeros.*/

int main(){
    int n,m,q;
    cin >> n >> m >> q ;
    int v[n];
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector <bool> DP(m+1,0);
    DP[0]=true;
    vector <int> p(m+1,-1);

    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            if(DP[j] && j+v[i]<=m && !DP[j+v[i]]){
                DP[j+v[i]]=true;
                p[j+v[i]]=v[i];
            }
            //primera cond es para que se frene cuanto encuentre uno ya armado
            //segunda cond es para no repetir numeros
        }
    }
    //busqueda de padres
    vector<vector<int>> pp(q);
    int sum,pad;
    for(int i=0;i<q;i++){
        cin >> sum;
        if(DP[sum]==true){
            pad=p[sum];
            while(pad!=-1){
                pp[i].push_back(pad);
                sum-=p[sum];
                pad=p[sum];
            }
        }
    }
    //imprimir resultados
    for(int i=0;i<q;i++){
        for(int j=0;j<(int)pp[i].size();j++){
            cout << pp[i][j] << " ";
        }
        if(pp[i].size()==0){
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}