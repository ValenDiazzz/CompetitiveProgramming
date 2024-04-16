#include <iostream> 
#include <set>
using namespace std;


int main(){
    set <int> loteria;
    int consultas[4]={1, 99, 4, 44};
    loteria.insert(12);
    loteria.insert(1);
    loteria.insert(44);
    loteria.insert(15);
    //agregar n elementos a un set tiene un costo de log(n)
    
    cout << "{"<<consultas[0]<<" "<<consultas[1]<<" "<<consultas[2]
    <<" "<<consultas[3]<<"}"<<endl;
    for(int j=0;j<4;j++){
        cout << "Consulta por el elemento: "<< consultas[j]<<endl;
        if(loteria.count(consultas[j])==0){
            cout <<"  No existe el elemento"<<endl;
        }else{
            cout <<"  Si existe el elemento"<<endl;
        }
    }
    //Buscar 1 elemento a un set tiene un costo de log(n) pues no busca sobre todo el set.
    return 0;
}