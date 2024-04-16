#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <vector<int>> adj(2*n +1);
    map <int,int> mp1,mp2;
    int c1,c2;
    int node=1;
    for(int i=0;i<n;i++){
        cin >> c1 >> c2;
        if(mp1.find(c1)==mp1.end()){
            mp1[c1]=node;
            mp2[node]=c1;
            node++;
        }
        if(mp1.find(c2)==mp1.end()){
            mp1[c2]=node;
            mp2[node]=c2;
            node++;
        }
        adj[mp1[c1]].push_back(mp1[c2]);
        adj[mp1[c2]].push_back(mp1[c1]);
    }
    //me fijo algun nodo que tenga una sola arista
    int city;
    for(int i=1;i<=(int)mp1.size();i++){
        if(adj[i].size()==1){
            city=i;
            break;
        }
    }
    vector <int> visited((int)mp1.size()+1,0);
    vector<int> path((int)mp1.size());
    visited[city]=1;
    path[0]=mp2[city];
    for(int j=1;j<(int)mp1.size();j++){
        for(auto nb:adj[city]){
            if(visited[nb]==0){
                city=nb;
                visited[city]=1;
                path[j]=mp2[city];
            }
        }
    }
    for(int k=0;k<(int)mp1.size();k++){
        cout << path[k]<<" ";
    }
    cout << endl;
    return 0;   
}