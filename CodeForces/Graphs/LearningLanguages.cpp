#include <iostream>
#include <vector>
using namespace std;

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
    adj.resize(n+m+1);
    visited.resize(n+m+1,0);
    int n_lan,lan;
    for(int i=1;i<=n;i++){
        cin >> n_lan;
        for(int j=0;j<n_lan;j++){
            cin >> lan;
            adj[i].push_back(lan+n);
            adj[lan+n].push_back(i);
        }
    }
    //contamos cuantos lenguajes no tienen ninguna conexion
    int l_count=0;
    for(int j=n+1;j<=n+m;j++){ 
        if(adj[j].size()==0){
            l_count++;
        }
    }
    if(l_count==m){ //caso trivial
        cout << n << endl;
        return 0;
    }
    //Si no es el caso trivial
    int comp=0;
    for(int i=1;i<=n+m;i++){
        if(visited[i]==0){
            comp++;
            DFS(i);
        }
    }

    cout << comp-l_count-1 << endl;
    return 0;
}