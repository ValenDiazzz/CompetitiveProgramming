#include <iostream>
#include <vector>

using namespace std;

/*Check if there is a cycle in bidirectional graph*/
/*easy to change to non-bidirectional graph*/

vector <vector<int>> adj;
vector <int> state;
bool cycles=false;

void DFS(int node){
    if(state[node]==2) return;
    
    if(state[node]==1){
        cycles=true; //pues si ya pase 2 veces por el mismo
        return;      //nodo con diferentes caminos => hay ciclo
    }
    state[node]=1;
    for(auto nb:adj[node]){
        DFS(nb);
    }
    state[node]=2;
}

int main(){
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    state.resize(n+1,0);

    int e1,e2;
    for(int i=1;i<=m;i++){
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    for(int j=1;j<=n;j++){
        DFS(j);
    }
    cout << cycles << endl;
    return 0;
}