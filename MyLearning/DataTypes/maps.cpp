#include <iostream>
#include <map>
using namespace std;
// Un map es un diccionario de pyhton

int main(){
    int n;
    cout << "Inserte la cantidad de alumnos:" << endl;
    cin >> n;
    map <string, int> notas;
    string nombre;
    int nota;
    for(int i=0;i<n;i++){
        cout << "Inserte el nombre del alumno:" << endl;
        cin >> nombre;
        cout << "Inserte la nota del alumno:" << endl;
        cin >> nota;
        notas[nombre]=nota;
    }

    cout << notas[nombre] << endl; //imprimo la nota del ultimo en ser agregado
    return 0;
}