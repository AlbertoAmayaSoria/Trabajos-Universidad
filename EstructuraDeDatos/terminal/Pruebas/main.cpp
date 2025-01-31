#include <iostream>

#include "Matriz.h"

int main() {



    using namespace std;
    //Declaracion de variables para almacenar el numero de filas y columnas de las matrices
    try{
        unsigned int filas, columnas, NuevaFila, NuevaColumna;

        //Solicita al usuario las dimensiones de la primera matriz
        cout << "Ingrese el número de renglones para la matriz 1: ";
        cin >> filas;
        cout << "Ingrese el número de columnas para la matriz 1: ";
        cin >> columnas;

        //Crea la matriz con las dimensiones ingresadas
        Matriz mat1(filas, columnas);
        //solicita al usuario los valores de la primera matriz
        cout << "Ingrese los elementos de la matriz 1:" << endl;
        cin >> mat1;

        //Solicta al usuario las dimensiones de la segunda matriz
        cout << "Ingrese el número de renglones para la matriz 2: ";
        cin >> filas;
        cout << "Ingrese el número de columnas para la matriz 2: ";
        cin >> columnas;

        //Crea la segunda matriz
        Matriz mat2(filas, columnas);

        //Solicita al usuario los valores de la segunda matriz
        cout << "Ingrese los elementos de la matriz 2:" << endl;
        cin >> mat2;

        cout << std::endl;
        cout << mat1 << endl;//

        //Realiza la suma de las matrices ingresadas
        Matriz suma = mat1 + mat2;
        //incluir la suma
        cout << "Matriz 1:" << endl;
        cout << mat1;
        cout << "Matriz 2:" << endl;
        cout << mat2;
        cout << "Suma de las matrices:\n" << suma;

        //Realiza la resta de las matrices ingresadas
        Matriz resta = mat1 - mat2;
        //incluir la resta
        cout << "Resta de las matrices:\n" << resta;

        //Realiza la multiplicacion de las matrices ingresadas
        Matriz multiplicacion = mat1 * mat2;
        Matriz producto = mat1 * mat2;
        //incluir el producto
        cout << "Producto de las matrices:\n" << producto;

        //Realiza el producto escalar de las matrices ingresadas
        Matriz producto_escalar = mat1 * 2;
        //incluir el producto
        cout << "Producto de la matriz 1 por 2:\n" << producto_escalar;

        //Realiza la matriz transpuesta de las matrices ingresadas
        Matriz trans = mat1.transpuesta();
        //incluir la matriz original
        cout << "Transpuesta de la matriz 1:\n" << trans;

        do{
            cout << "Ingresa el nuevo numero de columnas de la matriz 1: ";
            cin >> NuevaColumna;
        }while (NuevaColumna < 1);
        
        do{
            cout << "Ingresa el nuevo numero de filas de la matriz 1: ";
            cin >> NuevaFila;
        }while (NuevaFila < 1);
        Matriz red = mat1.redimensionar(NuevaColumna, NuevaFila);
        //modificar para que el usuario elgia la redimension
        cout << "Matriz 1 redimensionada a " << NuevaColumna << "x" << NuevaFila << endl;
        cout << red;

        //Calcula y muestra la inversa de la matriz ingresada
        if(filas == columnas) {  //Verifica que la matriz sea cuadrada
            try {

                //Calcula la inversa de la matriz
                Matriz inversa = mat1.inversa();
                cout << "Inversa de la matriz 1:\n" << inversa;
            } catch (const std::exception& e) {
                cout <<"No se puede calcular la inversa:"<<e.what()<<endl;
            }
        }else {
            cout<< " La matriz 1 no es cuadrada,por lo cual no tiene inversa.\n";
        }

    } catch (const std::exception& e) {  //Captura cualquier otra excepcion que pueda ocurrir en el programa
        cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
