#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    long long costos[n+1];
    for(int i=1;i<=n;i++){
        cin >> costos[i];
    }

    vector <vector <int>> adj(n+1,vector <int> (1,-1));
    int f1,f2; //friends
    for(int i=0;i<m;i++){
        cin >> f1 >> f2;
        adj[f1].push_back(f2);
        adj[f2].push_back(f1);
    }


    long long min_costo=0;
    queue <int> conn; //sirve para discriminar por componentes conexas
    vector <int> visited(n+1,0);

    for(int k=1;k<=n;k++){
        if (visited[k]==0){
            visited[k]=1;
            conn.push(k);
            long long costo=costos[k];

            while(conn.size() > 0){
                int node=conn.front();
                conn.pop();

                for(int i=1;i<(int)adj[node].size();i++){
                    int adjs_node=adj[node][i];
                    if(visited[adjs_node]==0){
                        costo=min(costo,costos[adjs_node]);
                        conn.push(adjs_node);
                        visited[adjs_node]=1;
                    }
                }
            }
            min_costo+=costo;
        }
    }

    cout << min_costo << endl;
    return 0;
}

