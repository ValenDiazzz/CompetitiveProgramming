#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> adj;
vector <int> cats;
vector <bool> visited;

int DFS(int node,int c_count,int limit){
    bool hoja=true;
    int ret=0;
    c_count=cats[node]? c_count+1 : 0;
    visited[node]=1;
    
    if(c_count > limit){
        return 0;        
    }
    for(auto nb:adj[node]){
        if(visited[nb]==0){
            hoja=false;
            ret+= DFS(nb,c_count,limit);
        } 
    }
    return ret + hoja;
}

int main(){
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    cats.resize(n+1);
    visited.resize(n+1,0);
    int c,e1,e2;
    for(int j=1;j<=n;j++){
        cin >> c;
        cats[j]=c;
    }
    for(int i=0;i<n-1;i++){
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }   

    cout << DFS(1,0,m) << endl;
    return 0;
}