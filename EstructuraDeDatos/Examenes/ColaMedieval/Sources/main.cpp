#include <iostream>
#include <vector>
#include <cstdlib>
//#include <ctime>
//#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#include "../Headers/linkedList.hpp"

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
int main()
{
    

    LinkedList listaDePersonas;
    int tiempoTotal = 120;  // 120 segundos
    int tiempoTranscurrido = 0;

    while (tiempoTranscurrido < tiempoTotal) {
        // Generamos una persona aleatoria
        std::string persona = generarNombreAleatorio();
        
        // Insertamos la persona en la lista
        listaDePersonas.insertarFinal(persona);

        // Mostramos la persona que fue añadida a la lista
        std::cout << "Persona generada y añadida a la lista: " << persona << std::endl;

        // Esperamos un tiempo aleatorio entre 1 y 3 segundos antes de generar la siguiente persona
        int tiempoEspera = rand() % 3 + 1;  // Aleatorio entre 1 y 3 segundos
        std::this_thread::sleep_for(std::chrono::seconds(tiempoEspera));

        // Aumentamos el tiempo transcurrido
        tiempoTranscurrido += tiempoEspera;
    }




    return 0;
}


std::string generarNombreAleatorio() {
    srand(time(0));  // Inicializamos la semilla aleatoria

    int indiceNombre = rand() % nombres.size();     // Generamos un índice aleatorio para el nombre
    int indiceApellido = rand() % apellidos.size(); // Generamos un índice aleatorio para el apellido

    return nombres[indiceNombre] + " " + apellidos[indiceApellido];  // Combinamos nombre y apellido
}
