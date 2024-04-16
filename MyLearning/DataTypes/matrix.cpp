#include <iostream>
#include <vector>
using namespace std;

// Con Vectores
/*Te permite utilizar las funciones de vectores por ejemplo
size_filas=mtx.size()
size_columnas=mtx[0].size()
*/
vector <vector <int>> init_mtx(int filas, int columnas, int value){
    // inicializa la matriz con elementos value
    vector <vector <int>> mtx(filas,vector <int> (columnas, value));
    return mtx;
}
int main(){
    int filas=3;
    int columnas=4;
    vector <vector <int>> mtx;
    mtx=init_mtx(filas, columnas, 0);
    
    int ini=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            mtx[i][j]=ini;
            ini++;
        }
    }
    
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Filas=" << mtx.size() << endl;
    cout << "Columnas=" << mtx[0].size() << endl;
    return EXIT_SUCCESS;
}
// Con Listas
/*
int main(){
    int filas=3;
    int columnas=4;
    int mtx[filas][columnas];
    int ini=0;
    
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            mtx[i][j]=ini;
            ini++;
        }
    }

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
*/