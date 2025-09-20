#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include "../Headers/ListaDobleCircular.hpp"

// Lista de nombres
std::vector<std::string> nombres = {"Ana", "Pablo", "Laura", "Javier", "Marta", "Luis", "Sofia", "Juan", "Carlos", "Elena", 
                                    "Diego", "Isabel", "Sergio", "Maria", "Jose", "Rosa", "David", "Lucia", "Manuel", "Raquel", 
                                    "Jorge", "Carmen", "Alberto", "Patricia", "Ricardo", "Teresa", "Fernando", "Beatriz", 
                                    "Francisco", "Gloria", "Eduardo", "Teresa", "Sergio", "Pilar", "Vicente", "Yolanda", "Antonio", 
                                    "Victoria", "Felipe", "Marta", "Ruben", "Alicia", "Guillermo", "Clara", "Enrique", "Rosa", 
                                    "Javier", "Andrea", "Guillermo", "Blanca"};

// Lista de apellidos
std::vector<std::string> apellidos = {"García", "López", "Martínez", "Pérez", "Sánchez", "Rodríguez", "González", 
                                      "Fernández", "Gómez", "Díaz", "Álvarez", "Jiménez", "Romero", "Muñoz", "Ruiz", 
                                      "Hernández", "Moreno", "Martín", "Castro", "López", "Torres", "Navarro", "Díaz", 
                                      "Vázquez", "Jiménez", "García", "Ortega", "Delgado", "Ramos", "Sánchez", "Moreno", 
                                      "García", "Pérez", "Gómez", "Molina", "Álvarez", "Ruiz", "Torres", "Fernández", "Romero", 
                                      "Díaz", "Soto", "Aguilar", "González", "Martín", "Hernández", "Navarro", "Castillo", 
                                      "Herrera", "Paredes"};

std::string generarNombreAleatorio();

int main() {
    system("clear");
    int n, k;
    std::cout << "Ingrese el número de personas (n): ";
    std::cin >> n;
    std::cout << "Ingrese el valor de k (pasos para eliminar): ";
    std::cin >> k;

    if (n <= 1 || k <= 1) {
        std::cerr << "Error: n y k deben ser mayores a 1." << std::endl;
        return 1;
    }

    // Crear lista circular de personas (n personas)
    ListaDobleCircular<std::string> lista;
    for (int i = 1; i <= n; ++i) {
        lista.insertar(generarNombreAleatorio());
        std::this_thread::sleep_for(std::chrono::seconds(1));
        //std::this_thread::sleep_for(std::chrono::milliseconds(900));
    }

    std::cout << "Personas en la mesa circular: " << std::endl;
    //lista.imprimirAdelante();
    lista.retrocederCabeza();
    
    while (lista.obtenerTamaño() > 1) {
        std::cout << std::endl;
        //lista.retrocederCabeza();
        std::cout << "->";
        lista.imprimirAdelante();
        for (int i = 0; i < k - 1; ++i) {
            std::cout << std::endl;
            std::cout << "->";
            lista.avanzarCabeza();
            lista.imprimirAdelante();
        }

        // Solo eliminar si hay más de un elemento
        if (lista.obtenerTamaño() > 1) {
            std::cout << std::endl;
            lista.eliminar();
            std::cout << std::endl;
        }

        if (lista.obtenerTamaño() > 1) { 
            std::cout << "Lista actual: " << std::endl;
            lista.imprimirAdelante();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }


    // Cuando el bucle termina solo queda el ganador
    std::cout << "El ganador es: "; 
    lista.imprimirAdelante();  

    return 0;
}


std::string generarNombreAleatorio() {
    srand(time(0));  // Inicializamos la semilla aleatoria

    int indiceNombre = rand() % nombres.size();     // Generamos un índice aleatorio para el nombre
    int indiceApellido = rand() % apellidos.size(); // Generamos un índice aleatorio para el apellido

    return nombres[indiceNombre] + " " + apellidos[indiceApellido];  // Combinamos nombre y apellido
}
