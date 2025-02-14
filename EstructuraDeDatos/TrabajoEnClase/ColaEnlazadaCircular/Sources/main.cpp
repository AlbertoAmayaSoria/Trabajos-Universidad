#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "../Headers/Cola.hpp"

using namespace std;

int main()
{
    //Despues de un tiempo random, encolar un numero y desencolar un numero bajo la misma premisa
    //tarea, apilar nombres con apellidos random
    int tiempo = rand % (15 + 1);
    try{
        Cola<> cola;
       
        for(int i = 0; i < 120; ++i)
        {
            cout << i + 1 << endl;
            this_thread::sleep_for(chrono::seconds(1));
            if(i == tiempo)
            {
                cola.Encolar(i + 1);
                tiempo = rand % 15 + 1;
                tiempo = i + tiempo;
                cola.Imprimir();
            }


        }





    }catch(const char *mensaje){
        cerr << "\nError: " << mensaje << endl;
    }

    system("pause");
    return 0;
}
