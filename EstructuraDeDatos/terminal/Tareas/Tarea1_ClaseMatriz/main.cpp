#include <iostream>
#include <ostream>

#include "Matriz.h"

using namespace std;

int main()
{
    unsigned int filas, columnas;

    cout << "Programa que realiza operaciones con matrices" << endl << endl;

    cout << "Ingrese el numero de columnas de la matriz: " << endl;

    do{
        cout << "Ingresa el numero de columnas de la matriz: " << endl;
        cin >> columnas;
    }while(columnas < 1);

    do{

    }while(filas < 1);

    cout << filas << " + " << columnas << endl;
    

    return 0;
}
