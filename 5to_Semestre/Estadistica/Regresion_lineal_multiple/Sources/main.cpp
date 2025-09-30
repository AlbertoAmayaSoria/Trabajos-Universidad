#include <cstdlib>
#include <iostream>
#include <math.h>

//#include "../Headers/Regresion_lineal.hpp"

using namespace std;

int main(){
    
    int muestras = 12;
    int criterios = 2 + 1;

    //  (0, criterios) = valores reales
    //  (1, criterios) = valores de x_1
    //  (2, criterios) = valores de x_2
    //  ...
    //  (muestras, criterios) = valores de x_criterios
    int datos[muestras][criterios];

    for(int i = 0 ; i < muestras ; ++i){
        cout << "Ingresa la calificacion del alumno " << i + 1  " : "
        for(int j = 0 ; j < criterios ; ++j){
            cout << "criterios"
        }
    }



    return 0;
}
