#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> adj;
bool bipartite=true;
vector <int> color; //-1 not visited, 0 -> color 1, 1 -> color 2

void DFS(int node, int col){
    if(color[node]!=-1){
        if(color[node]!=col){
            bipartite=false;
        }
        return;
    }
    color[node]=col;
    for(auto nb:adj[node]){
        DFS(nb,1-col);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    color.resize(n+1,-1);

    int e1,e2;
    for(int i=1;i<=m;i++){
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    for(int j=1;j<=n;j++){
        if(color[j]==-1){
            DFS(j,0); //I could started with color 1.
        }   
    }
    cout << bipartite << endl;
    return 0;
}

//otro resultado: es bipartito <=> NO contiene ciclos de long impar.