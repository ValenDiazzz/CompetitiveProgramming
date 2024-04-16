#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Given a Directed Acyclic Graph, it returns a possible
topological sort of its nodes*/


int main(){
    int n,m;
    cin >> n >> m;
    vector <vector<int>> adj(n+1);
    vector <int> deg(n+1,0);
    vector <int> sorting;
    queue <int> q;

    int e1,e2;
    for(int i=0;i<m;i++){
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        deg[e2]++;
    }
    for(int j=1;j<=n;j++){
        if(deg[j]==0){
            q.push(j); //root
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int x:adj[node]){
            deg[x]--;
            if(deg[x]==0){
                q.push(x);
            }
        }
        sorting.push_back(node);
    }

    for(int k=0;k<(int)sorting.size();k++){
        cout << sorting[k];
    }
    cout << endl;
    return 0;
}