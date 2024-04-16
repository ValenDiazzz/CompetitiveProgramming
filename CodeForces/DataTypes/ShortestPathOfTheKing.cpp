#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    char let1,let2;
    int n1,n2;
    cin >> let1 >> n1 >> let2 >> n2;

    int from_i= 8 - n1 + 1;
    int to_i= 8 - n2 + 1;
    int from_j= let1-'a'+1;
    int to_j= let2 -'a'+1;
    int dx=abs(from_i-to_i);
    int dy=abs(from_j-to_j);
    cout << max(dx,dy) << endl;

    if(max(dx,dy)==0) return 0;

    if(to_i < from_i){// esta arriba
        if(to_j<from_j){//esta a izq
            for(int i=0;i<min(dx,dy);i++){
                cout << "LU"<<endl;
                from_i-=1;
                from_j-=1;
            }
        }
        if(to_j>from_j){//esta a derecha
            for(int i=0;i<min(dx,dy);i++){
                cout << "RU"<<endl;
                from_i-=1;
                from_j+=1;
            }         
        }
    }else{
        if(to_i > from_i){//esta a ABAJO
            if(to_j<from_j){//esta a izq
                for(int i=0;i<min(dx,dy);i++){
                    cout << "LD"<<endl;
                    from_i+=1;
                    from_j-=1;
                }
            }
            if(to_j>from_j){//esta a derecha
                for(int i=0;i<min(dx,dy);i++){
                    cout << "RD"<<endl;
                    from_i+=1;
                    from_j+=1;
                }         
            }
        }
    }
    
    while(from_i!=to_i || from_j!=to_j){
        if(to_i > from_i){
            cout << "D" << endl;
            from_i+=1;
        }
        if(to_i < from_i){
            cout << "U" << endl;
            from_i-=1;
        }
        if(to_j > from_j){
            cout << "R" << endl;
            from_j+=1;
        }
        if(to_j < from_j){
            cout << "L" << endl;
            from_j-=1;
        }
    }
    return 0;
}