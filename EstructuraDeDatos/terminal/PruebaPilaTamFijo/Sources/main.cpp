#include <iostream>


#include "../Headers/Pila.hpp"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
    try
    {
        Pila miPila;
        if(miPila.EstaVacia()) cout << "La pila esta vacia";
        else                    cout << "La pila no esta vacia";

        /*miPila.Apilar(3.2);
        miPila.Apilar(8.16);
        miPila.Apilar(81.8);
        miPila.Apilar(5);*/

        for(int i = 0 ; i < 101 ; ++i)
        {
            miPila.Apilar(i+1);
        }

        miPila.Imprimir();

        cout << endl;

        miPila.Desapilar();
        miPila.Desapilar();

        miPila.Imprimir();

        cout << endl;

        miPila.Vaciar();

        miPila.Imprimir();

        cout << endl;

        miPila.Desapilar();

        cout << endl;

    }catch(const char *msg)
    {
        cerr << "Error: " << msg << endl; 
    }
}
