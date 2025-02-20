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
        Lista<int> ListaInt;
        for(int i = 0; i < 10; ++i)
        {
        ListaInt.EncolarInicio(i);
        }
        ListaInt.Imprimir();





    }catch(const char *mensaje){
        cerr << "\nError: " << mensaje << endl;
    }


    system("pause");
    return 0;
}
