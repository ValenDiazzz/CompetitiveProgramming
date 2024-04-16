#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack <string> libros;
    libros.push("Matematica");
    libros.push("Filosofia");
    libros.push("Quimica");
    libros.push("Biologia");

    while(libros.size()>0){
        cout << libros.top() << endl;
        libros.pop();
    }

    return 0;
}