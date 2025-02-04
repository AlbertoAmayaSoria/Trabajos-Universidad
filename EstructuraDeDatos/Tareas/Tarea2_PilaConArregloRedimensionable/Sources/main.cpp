#include <iostream>
#include <string>
#include <complex>
#include "../Headers/Pila.hpp"
#include "../Headers/Vector.hpp"

using namespace std;

int main()
{
    try {
        // Crear una pila de vectores con capacidad 15
        Pila<Vector> pilaVector;

        // Comprobar si la pila está vacía
        if(pilaVector.EstaVacia())  
            cout << "La pila está vacía\n";
        else                        
            cout << "La pila no está vacía\n";

        // Apilar un objeto Vector
        pilaVector.Apilar(Vector(2,1.5));
        cout << "Capacidad pila Vector: " << pilaVector.CapacidadPila() << endl;
        pilaVector.Imprimir();
        pilaVector.Apilar(Vector(2,1.5));
        pilaVector.Apilar(Vector(2,1.5));
        pilaVector.Apilar(Vector(2,1.5));
        pilaVector.Apilar(Vector(2,1.5));
        pilaVector.Apilar(Vector(2,1.5));
        cout << "Capacidad pila Vector: " << pilaVector.CapacidadPila() << endl;
        pilaVector.Imprimir();

        // Crear otra pila de vectores con capacidad 11
        Pila<Vector> otraPilaVec;
        otraPilaVec = pilaVector; // Operador de asignación (usará redimensionamiento si es necesario)
        cout << "Esta es otra pila: " << endl;
        otraPilaVec.Imprimir();

        // Desapilar un elemento
        pilaVector.Desapilar();
        
        cout << endl;
        cout << "Pila 1: " << endl;
        // Imprimir ambas pilas
        pilaVector.Imprimir();
        cout << "Pila 2: " << endl;

        otraPilaVec.Imprimir();
        cout << endl;

        // Crear una pila de enteros con capacidad por defecto (5)
        Pila<int> pilaInt;
        pilaInt.Apilar(11);
        pilaInt.Apilar(22);
        pilaInt.Apilar(33);
        pilaInt.Apilar(44);
        pilaInt.Apilar(55);

        // Imprimir la pila de enteros
        pilaInt.Imprimir();
        cout << "capacidad pila enteros: " << pilaInt.CapacidadPila() << endl;

        // Desapilar algunos elementos
        pilaInt.Desapilar();
        pilaInt.Desapilar();

        // Imprimir después de desapilar
        pilaInt.Imprimir();
        cout << "\n\n";

        // Ejemplo comentado con pilas de enteros
        Pila<int> PilaEnteros;
        PilaEnteros.Apilar(1);
        PilaEnteros.Apilar(1); 
        PilaEnteros.Apilar(1);
        PilaEnteros.Imprimir();
        cout << "Capacidad pila: " << PilaEnteros.CapacidadPila() << endl;
        PilaEnteros.Apilar(1);
        PilaEnteros.Apilar(1); 
        PilaEnteros.Apilar(1);
        PilaEnteros.Imprimir();
        cout << "Capacidad pila: "<<PilaEnteros.CapacidadPila() << endl << endl;

        cout << "Numeros complejos: " << endl;
        Pila<complex<double>> PilaComplejos;
        PilaComplejos.Apilar(complex<double>(3.0,4.0));
        PilaComplejos.Apilar(complex<double>(1.0,-2.0));
        PilaComplejos.Imprimir();
        

        
    } catch (const char* mensaje) {
        cerr << "Error: " << mensaje << endl;
    }

    return 0;
}

