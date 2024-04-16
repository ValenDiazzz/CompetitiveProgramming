#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Persona{
        string nombre, apellido, facultad;
        int dni;
};

bool operator<(const Persona &a,const Persona &b){
    return a.dni<b.dni;
}
int main(){
    string nombres[4]={"Lionel", "Sergio","Angel","Nicolas"};
    string apellidos[4]={"Messi", "Aguero","Di Maria","Otamendi"};
    string facultades[4]={"FAMAF", "FCEFYN","FADU","FAMAF"};
    int dnis[4]={30182933,34578426 ,32968875 ,33144485};
    vector <Persona> jugadores(4);
    
    for(int i=0;i<4;i++){
        jugadores[i].nombre=nombres[i];
        jugadores[i].apellido=apellidos[i];
        jugadores[i].facultad=facultades[i];
        jugadores[i].dni=dnis[i];
    }
    sort(jugadores.begin(),jugadores.end());

    for(int j=0;j<4;j++){
        cout << jugadores[j].nombre << endl;
    }
    return 0;
}