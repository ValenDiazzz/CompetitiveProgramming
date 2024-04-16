#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge{
    int nb,c;
};

int main(){
    int n;
    cin >> n;
    vector <vector<edge>> adj(n+1);
    int e1,e2,cost;
    for(int i=0;i<n;i++){
        cin >> e1 >> e2 >> cost;
        adj[e1].push_back({e2,0});
        adj[e2].push_back({e1,cost});
    }
    vector <int> path_cost(n);
    vector <int> dist(2,0);
    int actual=1;
    for(int j=0;j<2;j++){
        vector <int> visited(n+1,0);
        visited[actual]=1;
        dist[j]+=adj[actual][j].c;
        actual=adj[actual][j].nb;
        for(int k=1;k<n-1;k++){
            visited[actual]=1;
            edge e=visited[adj[actual][0].nb]==0?adj[actual][0]:adj[actual][1];
            dist[j]+=e.c;
            actual=e.nb;
        }
        dist[j]=adj[actual][0].nb==1?dist[j]+adj[actual][0].c:dist[j]+adj[actual][1].c;
        actual=1;
    }
    cout << min(dist[0],dist[1])<<endl;
    return 0;
}