#include <iostream>
using namespace std;

int DP[(int)1e6 +1];

int main(){
    int n;
    cin >> n;
    DP[0]=1;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=6;i++){
            if(j-i>=0){
                DP[j]+=DP[j-i];
                DP[j]%=(int(1e9) + 7);
            }
        }
    }
    cout << DP[n] << endl;
    return 0;
}