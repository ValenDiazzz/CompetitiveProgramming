#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string name1,name2,trash;
    cin >> n;
    vector <vector <int>> adj(n+2);
    int node=1;
    map <string, int> rp;
    for(int i=0;i<n;i++){
        cin >> name1 >> trash >> name2;
        for(auto &x: name1){
            x=tolower(x);
        }
        for(auto &y: name2){
            y=tolower(y);
        }
        if(rp.find(name2)==rp.end()){
            rp[name2]=node;
            node++;
        }
        if(rp.find(name1)==rp.end()){
            rp[name1]=node;
            node++;
        }
        adj[rp[name2]].push_back(rp[name1]);
    }
    vector <int> dist(n+2,-1);
    queue <int> visit;
    dist[1]=0;
    visit.push(1);

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

    cout << *max_element(dist.begin(),dist.end()) + 1 <<endl;
    return 0;
}