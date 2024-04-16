#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string number;
    int count=0;
    for(int i=0;i<n;i++){
        cin >> number;
        for(int j=0;j<(int)number.size();j++){
            if(number[j]=='+'){
                count++;
                break;
            }
            if(number[j]=='-'){
                count--;
                break;
            }
        }
    }
    cout << count <<endl;
    return 0;
}