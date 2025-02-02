#include <iostream>
#include "../Headers/Pila.hpp"
//#include "Vector.hpp"
//#include "Vector.cpp"


using namespace std;

int main()
{
    try{
        Pila<int> miPila;

        if(miPila.EstaVacia()) cout << "La pila est\240 vac\241a\n";
        else                   cout << "La pila no est\240 vac\241a\n";

        miPila.Apilar(2);
        miPila.Apilar(3);

        miPila.Imprimir();
        cout << "\n\n";



        miPila.Desapilar();
        miPila.Apilar(4);
        miPila.Imprimir();
        miPila.Apilar(5);
        miPila.Apilar(6);
        cout << "\n\n";
        miPila.Imprimir();
        cout << "\n\n";

        miPila.Vaciar();

        miPila.Desapilar();











    }catch(const char *mensaje){
        cerr << "Error: " << mensaje << endl;
    }








    return 0;
}
