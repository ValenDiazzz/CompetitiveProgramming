#include <iostream>
#include <vector>
using namespace std;

void adj_mtx(){
    // matriz de adjacencia
    int n,m;
    cin >> n >> m;
    vector <vector <bool>> adj(n+1,vector <bool> (n+1,0));
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;           
        adj[a][b]=true;
        adj[b][a]=true;
    }
    
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            cout << adj[j][k] << " ";
        }
        cout << endl;
    }
}

void adj_list(){
    int n,m;
    cin >> n >> m;
    //solo instanciamos el tamaño de vector que contiene a los otros.
    //el tamaño de los que estan dentro se asignaran dinamicamente.
    vector <vector <int>> adj(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int j=0;j<=n;j++){
        for(int k=0;k<(int)adj[j].size();k++){
            cout << adj[j][k] << " ";
        }
        cout << endl;
    }
}

int main(){
    adj_mtx();
    adj_list();
    return 0;
}
/*
9 9
1 2
2 4
2 5
4 3
4 5
5 6
3 6
7 9
7 8
*/