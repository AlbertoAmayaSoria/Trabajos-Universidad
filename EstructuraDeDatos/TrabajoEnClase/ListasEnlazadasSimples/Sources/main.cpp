/*
Descripción: Programa que utiliza la clase Pila para redimensionarla al doble de su capacidad cuando se llena
Autor: Amaya Soria Angel Alberto
Fecha: 04 de Febrero de 2025
*/


//incluyir o eliminar elementos en una posicion especifica (trabajo realizado en clase 18/Febrero/2025)


#include <iostream>
#include "../Headers/ListasEnlazadasSimples.hpp"
//#include "../Headers/Pila.hpp"

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
        //pilaInt.Desapilar();
        cout << "Pila 1: " << endl;
        pilaInt.Imprimir();
        cout << "Copia de la pila 1" <<endl;
        otraPila.Imprimir();
        cout << endl;





    }catch(const char *mensaje){
        cerr << "\nError: " << mensaje << endl;
    }


    system("pause");
    return 0;
}
