/*
Descripción: Programa que utiliza la clase Pila para redimensionarla al doble de su capacidad cuando se llena
Autor: Amaya Soria Angel Alberto
Fecha: 04 de Febrero de 2025
*/


#include <iostream>
#include "../Headers/Pila.hpp"
#include "../Headers/Pila.hpp"

using namespace std;

int main()
{
    try{
        Pila<> pilaInt;
        Pila<> otraPila;
        pilaInt.Apilar(5);
        pilaInt.Apilar(6);
        pilaInt.Imprimir();
        cout << "\n\n";

        otraPila = pilaInt;
        pilaInt.Desapilar();
        pilaInt.Imprimir();
        cout << endl;
        otraPila.Imprimir();
        cout << endl;





    }catch(const char *mensaje){
        cerr << "\nError: " << mensaje << endl;
    }


    system("pause");
    return 0;
}
