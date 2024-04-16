#include <iostream>
#include <vector>
using namespace std;

vector<int> get_digits(int year){
    vector<int> digits(4);
    digits[0]=(int) year/1000;
    digits[1]=(int)((year- digits[0]*1000) / 100);
    digits[2]=(int)((year- digits[0]*1000 - digits[1]*100) / 10);
    digits[3]=(int)((year- digits[0]*1000 - digits[1]*100 - digits[2]*10));
    return digits;
}
bool checker(int year){
    bool cond;
    vector<int> digits = get_digits(year);
    cond= digits[0]!=digits[1] && digits[0]!=digits[2] && digits[0]!=digits[3];
    cond= cond && digits[1]!=digits[2] && digits[1]!=digits[3];
    cond= cond && digits[2]!=digits[3];
    return cond;
}
int main(){
    int year;
    cin >> year;
    
    int number= year + 1;
    while(!checker(number)){
        number++;
    }
    cout << number << endl;
    return 0;
}