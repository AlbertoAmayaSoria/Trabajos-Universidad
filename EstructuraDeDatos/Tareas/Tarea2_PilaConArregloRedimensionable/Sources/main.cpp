#include <iostream>
#include <string>
#include "../Headers/Pila.hpp"
#include "../Headers/Vector.hpp"

using namespace std;

int main()
{
    try{
       /* Pila<Vector, 15> pilaVector;

        if(pilaVector.EstaVacia()) cout << "La pila est\240 vac\241a\n";
        else                   cout << "La pila no est\240 vac\241a\n";

        pilaVector.Apilar(Vector(2,1.5));
        //pilaVector.Apilar(3);

        Pila<Vector, 15> otraPilaVec;
        otraPilaVec = pilaVector;

        pilaVector.Desapilar();

        pilaVector.Imprimir();
        cout << endl;
        otraPilaVec.Imprimir();
        cout << endl;



        Pila<> pilaInt;
        pilaInt.Apilar(11);
        pilaInt.Apilar(22);
        pilaInt.Apilar(33);
        pilaInt.Apilar(44);
        pilaInt.Apilar(55);

        pilaInt.Imprimir();
        cout << "\n\n";

        pilaInt.Desapilar();
        pilaInt.Desapilar();

        pilaInt.Imprimir();
        cout << "\n\n";*/

        Pila<string, 3> PilaString;

        PilaString.Apilar("Hola");
        PilaString.Apilar("mundo");
        PilaString.Apilar("gente");

        PilaString.Imprimir();




        




    }catch(const char *mensaje){
        cerr << "Error: " << mensaje << endl;
    }








    return 0;
}
