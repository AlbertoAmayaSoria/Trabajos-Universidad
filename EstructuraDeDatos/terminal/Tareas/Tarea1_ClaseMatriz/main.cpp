#include "Matriz.h"

int main() {

    //falta documentar todo el codigo

    try{
        unsigned int filas, columnas, NuevaFila, NuevaColumna;

        std::cout << "Ingrese el número de renglones para la matriz 1: ";
        std::cin >> filas;
        std::cout << "Ingrese el número de columnas para la matriz 1: ";
        std::cin >> columnas;

        Matriz mat1(filas, columnas);
        std::cout << "Ingrese los elementos de la matriz 1:" << std::endl;
        std::cin >> mat1;

        std::cout << "Ingrese el número de renglones para la matriz 2: ";
        std::cin >> filas;
        std::cout << "Ingrese el número de columnas para la matriz 2: ";
        std::cin >> columnas;

        Matriz mat2(filas, columnas);
        std::cout << "Ingrese los elementos de la matriz 2:" << std::endl;
        std::cin >> mat2;

        std::cout << std::endl;

        Matriz suma = mat1 + mat2;
        //incluir la suma
        std::cout << "Matriz 1:" << std::endl;
        std::cout << mat1 << std::endl; 
        std::cout << "Matriz 2:" << std::endl;
        std::cout << mat2 << std::endl;
        std::cout << "Suma de las matrices:\n" << suma;

        Matriz resta = mat1 - mat2;
        //incluir la resta
        std::cout << "Resta de las matrices:\n" << resta;

        Matriz producto = mat1 * mat2;
        //incluir el producto
        std::cout << "Producto de las matrices:\n" << producto;

        Matriz producto_escalar = mat1 * 2;
        //incluir el producto
        std::cout << "Producto de la matriz 1 por 2:\n" << producto_escalar;

        Matriz trans = mat1.transpuesta();
        //incluir la matriz original
        std::cout << "Transpuesta de la matriz 1:\n" << trans;

        std::cout << "Ingresa el nuevo numero de columnas de la matriz 1: ";
        std::cin >> NuevaColumna;
        std::cout << "Ingresa el nuevo numero de filas de la matriz 1: ";
        std::cin >> NuevaFila;
        mat1.redimensionar(NuevaColumna, NuevaFila);
        //modificar para que el usuario elgia la redimension
        std::cout << "Matriz 1 redimensionada a " << NuevaColumna << "x" << NuevaFila << std::endl;
        std::cout << mat1;

        //hacer bien la matriz inversa

        /*Matriz inversa = mat1.inversa();
        std::cout << "Inversa de la matriz 1:\n" << inversa;*/

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
