#include <iostream>
using namespace std;


struct Persona{
        string nombre, apellido, facultad;
        int dni;
};

int main(){
    Persona n_10;
    n_10.nombre="Lionel";
    n_10.apellido="Messi";
    n_10.facultad="Famaf";
    n_10.dni=30182933;
    
    cout <<n_10.nombre<<" "<<n_10.apellido<<" "<<n_10.facultad<<" "<<n_10.dni<<endl;

    return 0;
}