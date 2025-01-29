#include "Matriz.h"
#include <ostream>

int main() {

    //falta documentar todo el codigo
    
    using namespace std;

    try{
        unsigned int filas, columnas, NuevaFila, NuevaColumna;

        cout << "Ingrese el número de renglones para la matriz 1: ";
        cin >> filas;
        cout << "Ingrese el número de columnas para la matriz 1: ";
        cin >> columnas;

        Matriz mat1(filas, columnas);
        cout << "Ingrese los elementos de la matriz 1:" << endl;
        cin >> mat1;

        cout << "Ingrese el número de renglones para la matriz 2: ";
        cin >> filas;
        cout << "Ingrese el número de columnas para la matriz 2: ";
        cin >> columnas;

        Matriz mat2(filas, columnas);
        cout << "Ingrese los elementos de la matriz 2:" << endl;
        cin >> mat2;

        cout << std::endl;

        Matriz suma = mat1 + mat2;
        //incluir la suma
        cout << "Matriz 1:" << endl;
        cout << mat1;
        cout << "Matriz 2:" << endl;
        cout << mat2;
        cout << "Suma de las matrices:\n" << suma;

        Matriz resta = mat1 - mat2;
        //incluir la resta
        cout << "Resta de las matrices:\n" << resta;

        Matriz producto = mat1 * mat2;
        //incluir el producto
        cout << "Producto de las matrices:\n" << producto;

        Matriz producto_escalar = mat1 * 2;
        //incluir el producto
        cout << "Producto de la matriz 1 por 2:\n" << producto_escalar;

        Matriz trans = mat1.transpuesta();
        //incluir la matriz original
        cout << "Transpuesta de la matriz 1:\n" << trans;

        cout << "Ingresa el nuevo numero de columnas de la matriz 1: ";
        cin >> NuevaColumna;
        cout << "Ingresa el nuevo numero de filas de la matriz 1: ";
        cin >> NuevaFila;
        mat1.redimensionar(NuevaColumna, NuevaFila);
        //modificar para que el usuario elgia la redimension
        cout << "Matriz 1 redimensionada a " << NuevaColumna << "x" << NuevaFila << endl;
        cout << mat1;

        //hacer bien la matriz inversa

        /*Matriz inversa = mat1.inversa();
        std::cout << "Inversa de la matriz 1:\n" << inversa;*/

    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
