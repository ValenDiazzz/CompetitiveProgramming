#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;


/*shortest path bidirectional positive weihted graph*/

struct edge{
    int node, value;
};
/*Vamos a calcular coste de llegar desde un nodo 
cualquiera al nodo vtx*/
int main(){
    int n,m,vtx;
    cin >> n >> m;
    vector <vector <edge>> adj(n+1);
    int e1,e2,v;
    for(int i=0;i<m;i++){
        cin >> e1 >> e2 >> v;
        adj[e1].push_back({e2,v});
        adj[e2].push_back({e1,v});
    }
    cin >> vtx;
    int INF=1000000000;
    vector <int> dist(n+1,INF);
    vector <int> p(n+1,-1); //Ver el camino
    priority_queue <pair<int,int>> pq; //{dist, nodo}
    
    dist[vtx]=0;
    pq.push({0, vtx});

    while(pq.size()!=0){
        int actual= pq.top().second;
        pq.pop();
        
        //vemos los vecinos
        for(int i=0;i<(int)adj[actual].size();i++){
            int nb=adj[actual][i].node;
            int cost=adj[actual][i].value;

            if(dist[actual]+cost<dist[nb]){
                dist[nb]=dist[actual]+cost;
                pq.push({-dist[nb],nb});
                p[nb]=actual;
            }
        }
    }
    cout <<"Distancias:";
    for(int i=1;i<=n;i++){
        cout << " "<<dist[i];
    }
    cout << endl;
    for(int i=1;i<=n;i++){
        cout << "Camino para llegar a "<<i<<" es:";
        int padre=p[i];
        while(padre!=-1){
            cout <<padre;
            padre=p[padre];
        }
        cout << endl; 
    }
    return 0;
}
/*
6 7
1 2 5
1 4 9
1 5 2
2 3 2
3 4 3
4 6 2
5 6 3
1
*/