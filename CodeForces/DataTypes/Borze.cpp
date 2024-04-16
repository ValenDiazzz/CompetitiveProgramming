#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string borze;
    string result;
    cin >> borze;
    
    int i=0;
    while(i<static_cast<int>(borze.size())){
        if(borze[i]=='.'){
            result= result + "0";
            i++;
        }else{
            if(borze[i+1]=='.'){
                result= result + "1";
                i+=2;
            }else{
                result= result + "2";
                i+=2;
            }
        }
    }
    cout << result << endl;
    return 0;
}