#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue <string> fila_tramite;
    fila_tramite.push("Jorge");
    fila_tramite.push("Maria");
    fila_tramite.push("Santino");

    while(fila_tramite.size()>0){
        cout << fila_tramite.front() << endl;
        fila_tramite.pop();
    }

    return 0;
}