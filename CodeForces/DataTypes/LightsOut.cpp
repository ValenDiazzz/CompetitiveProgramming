#include <iostream>
using namespace std;

int main(){
    int lights[9];
    for(int i=0;i<9;i++){
        cin >> lights[i];
    }

    cout << (lights[0]+lights[1]+lights[3] + 1)%2;
    cout << (lights[0]+lights[1]+lights[2] + lights[4] + 1)%2;
    cout << (lights[1]+lights[2]+lights[5] + 1)%2 << endl;
    cout << (lights[0]+lights[3]+lights[4]+lights[6] + 1)%2;
    cout << (lights[1]+lights[3]+lights[4]+lights[5]+lights[7] + 1)%2;
    cout << (lights[2]+lights[4]+lights[5]+lights[8] + 1)%2 << endl;
    cout << (lights[3]+lights[6]+lights[7] + 1)%2;
    cout << (lights[4]+lights[6]+lights[7]+lights[8] + 1)%2;
    cout << (lights[5]+lights[7]+lights[8] + 1)%2 << endl;
    return 0;
}