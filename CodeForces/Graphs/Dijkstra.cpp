#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

struct edge{
    int node, value;
};

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

    vtx=1;
    long long INF=LLONG_MAX/2;
    vector <long long> dist(n+1,INF);
    vector <int> p(n+1,-1);
    priority_queue <pair<int,int>> pq;
    
    dist[vtx]=0;
    pq.push({0, vtx});

    while(pq.size()!=0){
        int actual= pq.top().second;
        pq.pop();
        
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

    int padre=p[n];
    stack <int> padres;
    while(padre!=-1){
        padres.push(padre);
        padre=p[padre];
    }
    if(padres.empty()==true){
        cout << -1;
    }else{
        while(padres.size()){
            cout<<padres.top()<< " ";
            padres.pop();
        }
        cout<<n<<" ";
    }
    cout << endl;
    return 0;
}