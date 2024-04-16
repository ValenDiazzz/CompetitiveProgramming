#include <iostream>
using namespace std;

int main(){
    string queue;
    int n, time;
    cin >> n >> time >> queue;
    for(int i=0;i<time;i++){
        int j=0;
        while(j<n){
            if(queue[j]=='B' && j!=n-1 && queue[j+1]!='B'){
                queue[j]='G';
                queue[j+1]='B';
                j+=2;
            }else{
                j++;
            }
            
        }
    }
    cout << queue << endl;
    return 0;
}