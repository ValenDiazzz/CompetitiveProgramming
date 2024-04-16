#include <iostream>
using namespace std;

int main(){
    int it;
    cin >> it;
    
    int lista[3*it];
    
    for (int i=0; i<it; i++){
        for(int k=0; k<3; k++){
            cin >> lista[3*i + k];
        }
    }
    
    int sum1=0;
    int sum2=0;
    int sum3=0;
    for (int j=0; j<it; j++){
        sum1+=lista[3*j];
        sum2+=lista[3*j + 1];
        sum3+=lista[3*j + 2];
    }

    if (sum1==0 && sum2==0 && sum3==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}