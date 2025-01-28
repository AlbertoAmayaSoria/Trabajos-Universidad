#include "Matriz.h"

int main() {
    try {
        unsigned int filas, columnas;

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

        Matriz suma = mat1 + mat2;
        std::cout << "Suma de las matrices:\n" << suma;

        Matriz resta = mat1 - mat2;
        std::cout << "Resta de las matrices:\n" << resta;

        Matriz producto = mat1 * mat2;
        std::cout << "Producto de las matrices:\n" << producto;

        Matriz producto_escalar = mat1 * 2;
        std::cout << "Producto de la matriz por 2:\n" << producto_escalar;

        Matriz trans = mat1.transpuesta();
        std::cout << "Transpuesta de la matriz 1:\n" << trans;

        mat1.redimensionar(3, 3);
        std::cout << "Matriz 1 redimensionada a 3x3:\n" << mat1;

        Matriz inversa = mat1.inversa();
        std::cout << "Inversa de la matriz 1:\n" << inversa;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
