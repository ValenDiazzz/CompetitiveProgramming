#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*Sirve para grafos no pesados*/

/* Vamos a calcular la minima distancia de
los nodos al vtx */
int main(){
    int n,m,vtx;
    cin >> n >> m; 
    vector <vector <int>> adj(n+1);

    int e1,e2;
    for(int i=0;i<m;i++){
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }
    cin >> vtx;
    
    vector <int> dist(n+1,-1);
    queue <int> visit;
    dist[vtx]=0;
    visit.push(vtx);

    while(visit.size() > 0){
        int node=visit.front();
        visit.pop();

        for(int i=0;i<(int)adj[node].size();i++){
            int adjs_node = adj[node][i];
            if(dist[adjs_node]==-1){
                dist[adjs_node]=dist[node] + 1;
                visit.push(adjs_node);
            }
        }
    }
    
    for(int j=1;j<=n;j++){
        cout << dist[j] << " ";
    }
    cout << endl;
    return 0;
}