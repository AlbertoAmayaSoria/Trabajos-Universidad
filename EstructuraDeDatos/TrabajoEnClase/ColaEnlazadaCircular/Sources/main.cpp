#include <iostream>
#include "../Headers/Cola.hpp"

using namespace std;

int main()
{
    try{
        Cola<> cola;
        cola.Encolar(1);
        cola.Encolar(2);
        cola.Encolar(3);
        cola.Encolar(4);
        cout << "La cola original es: \n";
        cola.Imprimir();
        cout << "\n\n El nuevo cambio es :\nCola: ";
        Cola<> colaCopia;
        colaCopia = cola;
        cola.Desencolar();
        cola.Desencolar();
        cola.Imprimir();
        cout << "\nCopia de cola: ";
        colaCopia.Imprimir();
        cout << endl;






    }catch(const char *mensaje){
        cerr << "\nError: " << mensaje << endl;
    }

    system("pause");
    return 0;
}
