#include <cstdlib>
#include <iostream>
#include <math.h>

#include "../Headers/Matriz.h"

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
    /*int datos[muestras][criterios];

    int calificaciones[muestras] = {85, 74, 76, 90, 85, 87, 94, 98, 81, 91,76, 74};
    int examen[muestras] = {65, 50, 55, 65, 55, 70, 65, 70, 55, 70, 50, 55};
    int clasesP[muestras] = {1, 7, 5, 2, 6, 3, 2, 5, 4, 3, 1, 4};

    for(int i = 0 ; i < muestras ; ++i){
        datos[i][0] = calificaciones[i];
        datos[i][1] = examen[i];
        datos[i][2] = clasesP[i];
    }

    /*for(int i = 0 ; i < muestras ; ++i){
        //cout << "Ingresa la calificacion del alumno " << i + 1  << " : ";
        for(int j = 0 ; j < criterios ; ++j){
            if(j == 0){
                cout << "Ingresa la calificacion del alumno " << i + 1  << " : ";
                cin >> datos[i][j];
            }else {
                cout << "criterio " << j + 1 << " :" << endl;
                cin >> datos[i][j];
            }
        }
    }*

    int sum_y = 0;
    int sum_x1 = 0;
    int sum_x2 = 0;
    int sum_x1_cuadrado = 0;
    int sum_x2_cuadrado = 0;
    int sum_x1x2 = 0;
    int sum_x1y = 0;
    int sum_x2y = 0;


    for(int i = 0 ; i < muestras ; ++i){
        sum_y = calificaciones[i] + sum_y;
        sum_x1 = examen[i] + sum_x1;
        sum_x2 = clasesP[i] + sum_x2;
        sum_x1_cuadrado = examen[i] * examen[i] + sum_x1_cuadrado;
        sum_x2_cuadrado = clasesP[i] * clasesP[i] + sum_x2_cuadrado;
        sum_x1x2 = examen[i] * clasesP[i] + sum_x1x2;
        sum_x1y = examen[i] * calificaciones[i] + sum_x1y;
        sum_x2y = clasesP[i] * calificaciones[i] + sum_x2y;
    }
    
    
    for(int i = 0 ; i < muestras ; ++i){
        for(int j = 0 ; j < criterios ; ++j){
            if(j == 0){
                cout << "Datos del alumno " << i + 1 << endl;
            }
            cout << datos[i][j];
            if(j < (criterios - 1)){
                cout<< " ,";
            }
        }
        cout << endl;
    }

    /*cout << "Σ(y) = \t\t" << sum_y << endl;
    cout << "Σ(x_1) = \t" << sum_x1 << endl;
    cout << "Σ(x_2) = \t" << sum_x2 << endl;
    cout << "Σ(x_1)^2 = \t" << sum_x1_cuadrado << endl;
    cout << "Σ(x_2)^2 = \t" << sum_x2_cuadrado << endl;
    cout << "Σ(x_1*x_2) = \t" << sum_x1x2 << endl;
    cout << "Σ(x_1*y) = \t" << sum_x1y << endl;
    cout << "Σ(x_2*y) = \t" << sum_x2y << endl;*/

    //Matriz matX(criterios, criterios);
    int cantSumatoriasX = 0;
    for(int i = 0, i < criterios ; ++i){
        if(i != 0){
        cantSumatoriasX = i + 1 + cantSumatoriasX;    
        }
    }

    Matriz sumatoriasX();

    Matriz grande(criterios + 1, criterios + 1);
    Matriz conY(criterios + 1, 1);
    Matriz conAB(criterios + 1, 1);

    return 0;
}
