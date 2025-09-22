#include <iostream>

//#include "../Headers/Regresion_lineal.hpp"

using namespace std;

int main(){
    
    cout << "Hola mundo" << endl;
    
    /*
     *  Regresión líneal simple para 2 variables
     */ 
    int cantDatos = 9;
    int ejeX[cantDatos] = {7, 1, 10, 5, 4, 3, 13, 10, 2};
    int ejeY[cantDatos] = {2, 9, 2, 5, 7, 11, 2, 5, 14};

    float sum_X = 0;              //  Σx
    float sum_Y =  0;             //  Σy
    float sum_XY = 0;             //  Σ(xy)
    float sum_X_cuadrado = 0;     //  Σ(x^2)
    float cuadrado_sum_X = 0;     //  (Σx)^2
    //float /*m*/ pendiente = 0;                //  Pendiente
    //float /*b*/ interseccion = 0;                //  Intersección en y

    for(int i = 0; i < cantDatos ; ++i){
        sum_X = sum_X + ejeX[i];
        sum_Y = sum_Y + ejeY[i];
        sum_XY = sum_XY + (ejeX[i] * ejeY[i]);
        sum_X_cuadrado = ejeX[i] * ejeX[i] + sum_X_cuadrado;
    }
    
    cuadrado_sum_X = sum_X * sum_X;

    float pendiente = ((cantDatos * sum_XY) - (sum_X * sum_Y)) / ((cantDatos * sum_X_cuadrado) - cuadrado_sum_X);
      
    float interseccion = ((sum_Y * sum_X_cuadrado) - (sum_X * sum_XY)) / ((cantDatos * sum_X_cuadrado) - cuadrado_sum_X) /*((sum_Y - (pendiente * sum_X)) / cantDatos)*/;

    cout << endl << "ΣX = " << sum_X << " ΣY = " << sum_Y << " ΣXY = " << sum_XY << endl;

    cout << "Σ(xy) = " << sum_XY << " Σ(x^2) = " << sum_X_cuadrado << " (Σx)^2 = " << cuadrado_sum_X << " pendiente =" << pendiente << " interseccion = " << interseccion << endl;

    cout << "Función: " << pendiente << "x + " << interseccion << "\n";

    /*for(int i = 0; i < 10 ; i++){
        cout << ejeX[i] << " ";
    }*/



    return 0;
}
