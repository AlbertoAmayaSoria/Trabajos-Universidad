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

std::vector<std::string> posicion = {"plebeyo","noble"};

bool cadena(std::string texto);

std::string generarNombreAleatorio();
int main()
{    

    LinkedList<std::string> plebeyosEspera;
    LinkedList<std::string> noblesEspera;
    LinkedList<std::string> personasEspera;
    LinkedList<std::string> personasAtendidas;
    int tiempoTotal = 5;  // 120 segundos
    int tiempoTranscurrido = 0;
    int tiempoEspera;
    int tiempoEsperaReal = 15;
    char posicion;


    //while (tiempoTranscurrido < tiempoTotal) {
        
    for(int i = 0; i < tiempoTotal; ++i)
    {
        posicion = rand() % 2;
        // Generamos una persona aleatoria
        std::string persona = generarNombreAleatorio() + posicion;
        //posicion = rand() % 2;
        
        //char posicionL = posicion;
        //persona += posicionL;
        // Insertamos la persona en la lista
        personasEspera.insertarFinal(persona);

        // Mostramos la persona que fue añadida a la lista
        //std::cout << "Persona generada y añadida a la lista: " << persona << std::endl;

        while(tiempoTranscurrido == (tiempoEsperaReal || tiempoEsperaReal*2 || tiempoEsperaReal*3 || tiempoEsperaReal*4 || tiempoEsperaReal*5 || tiempoEsperaReal*6 
            || tiempoEsperaReal*7 || tiempoEsperaReal*8))
        {
            if(noblesEspera.obtenerTamaño() == 0)
            {
            personasAtendidas.insertarInicio(plebeyosEspera.obtenerPrimero());
            plebeyosEspera.eliminarInicio();
            }else 
            {
                personasAtendidas.insertarInicio(noblesEspera.obtenerPrimero());
                noblesEspera.eliminarInicio();
            }
        }
        if(cadena(personasEspera.obtenerPrimero()))
        {
            plebeyosEspera.insertarFinal(persona);
        }else noblesEspera.insertarFinal(persona);

        if(personasAtendidas.obtenerTamaño())


        // Esperamos un tiempo aleatorio entre 1 y 3 segundos antes de generar la siguiente persona
        tiempoEspera = rand() % 3 + 1;  // Aleatorio entre 1 y 3 segundos
        std::this_thread::sleep_for(std::chrono::seconds(tiempoEspera));

        

        // Aumentamos el tiempo transcurrido
        tiempoTranscurrido += tiempoEspera;
    }

    std::cout << "personas en atendidads: ";
    personasAtendidas.imprimir();

    std::cout << "\nLa generación de personas ha terminado." << std::endl;
    std::cout << "Total de personas generadas: " << personasEspera.obtenerTamaño() << std::endl;

    // Mostrar el contenido de la lista
    personasEspera.imprimir();
    plebeyosEspera.imprimir();
    personasAtendidas.imprimir();

    return 0;
}


std::string generarNombreAleatorio() {
    srand(time(0));  // Inicializamos la semilla aleatoria

    int indiceNombre = rand() % nombres.size();     // Generamos un índice aleatorio para el nombre
    int indiceApellido = rand() % apellidos.size(); // Generamos un índice aleatorio para el apellido
    int indicePosicion = rand() % posicion.size();

    return nombres[indiceNombre] + " " + apellidos[indiceApellido] + " " +  posicion[indicePosicion];  // Combinamos nombre y apellido
}


bool cadena(std::string texto)
{

size_t posicion = texto.find("plebeyo");

    if (posicion != std::string::npos) 
    {
        return true;
        //std::cout << "La cadena '" << buscar << "' se encontró en la posición: " << posicion << std::endl;
    } else return false;
        //std::cout << "La cadena '" << buscar << "' no se encontró." << std::endl
}
