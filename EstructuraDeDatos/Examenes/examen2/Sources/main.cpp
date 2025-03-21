#include <iostream>
#include <thread>
#include <chrono>
#include "../Headers/ListaDobleCircular.hpp"

int main() {
    int n, k;
    std::cout << "Ingrese el número de personas (n): ";
    std::cin >> n;
    std::cout << "Ingrese el valor de k (pasos para eliminar): ";
    std::cin >> k;

    if (n <= 1 || k <= 1) {
        std::cerr << "Error: n y k deben ser mayores a 1." << std::endl;
        return 1;
    }

    // Crear lista circular de personas numeradas del 1 al n
    ListaDobleCircular<int> lista;
    for (int i = 1; i <= n; ++i) {
        lista.insertar(i);
    }

    std::cout << "Personas en la mesa circular: ";
    lista.imprimirAdelante();

    
    
    while (lista.obtenerTamaño() > 1) {
        
        for (int i = 0; i < k - 1; ++i) {
            lista.avanzarCabeza();
        }

        // Solo eliminar si hay más de un elemento
        if (lista.obtenerTamaño() > 1) {
            lista.eliminar();
        }

        if (lista.obtenerTamaño() > 1) { 
            std::cout << "Lista actual: ";
            lista.imprimirAdelante();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }


    // Cuando el bucle termina, solo queda un elemento: es el ganador
    std::cout << "El ganador es: "; 
    lista.imprimirAdelante();  

    return 0;
}
