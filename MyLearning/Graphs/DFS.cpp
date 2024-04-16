#include <iostream>
#include <vector>
using namespace std;

/*Con este algoritmo contaremos la
cantidad de componentes conexas de un grafo*/

vector <vector <int>> adj;
vector <bool> visited;

void DFS(int node){
    visited[node]=true;
    for(int nb:adj[node]){
        if(visited[nb]==0){
            DFS(nb);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m; 
    adj.resize(n+1);
    visited.resize(n+1,0);
    int e1,e2;
    for(int i=0;i<m;i++){
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    int comp=0;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            comp++;
            DFS(i); //visita todos los vertices de una componente.
        }
    }
    cout << comp << endl;
    return 0;
}   