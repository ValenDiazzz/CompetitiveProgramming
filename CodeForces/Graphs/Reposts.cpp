#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


vector <vector <int>> adj;

int DFS(int node){
    int ret=0;
    for(int nb:adj[node]){
        ret = max(ret,DFS(nb));
    }
    return ret+1;
}

int main(){
    int n;
    string name1,name2,trash;
    cin >> n;
    adj.resize(n+2);
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
    cout << DFS(1) << endl;
    return 0;
}