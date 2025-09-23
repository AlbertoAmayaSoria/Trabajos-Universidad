#include <cstdlib>
#include <iostream>
#include <math.h>

//#include "../Headers/Regresion_lineal.hpp"

using namespace std;

int main(){
    
    /*
     *  Regresión líneal simple para 2 variables
     *  Datos predefinidos
     */
    int cantDatos = 9;
    int ejeX[cantDatos] = {7, 1, 10, 5, 4, 3, 13, 10, 2};
    int ejeY[cantDatos] = {2, 9, 2, 5, 7, 11, 2, 5, 14};/**/
    
    /*
     *  Regresión lineal simple para 2 variables
     *  Ingresar datos desde terminal
     */

    /*cout << "Cantidad de datos a tratar: ";
    int cantDatos;
    cin >> cantDatos;

    float ejeX[cantDatos];
    float ejeY[cantDatos];
    for(int i = 0 ; i < cantDatos ; ++i){
        cout << "X = "; 
        cin >> ejeX[i];
        cout << "Y = ";
        cin >> ejeY[i];
        cout << "(" << ejeX[i] << ", " << ejeY[i] << ")" << endl;
    }
    (1, 2)*/

    cout << endl;

    /*
     *  Imprimir datos (puntos)
     */

    for(int i = 0 ; i < cantDatos ; ++i){
        cout << "(" << ejeX[i] << ", " << ejeY[i] << ")";
        if(i < (cantDatos - 1)) cout << ", ";
    }

    /*
     *  Calculos necesarios
     */

    float sum_X = 0;                //  Σx
    float sum_Y =  0;               //  Σy
    float sum_XY = 0;               //  Σ(xy)
    float sum_X_cuadrado = 0;       //  Σ(x^2)
    float cuadrado_sum_X = 0;       //  (Σx)^2
    float /*m*/ pendiente = 0;      //  Pendiente
    float /*b*/ interseccion = 0;   //  Intersección en y

    /*
     * Sumatorias
     */

    for(int i = 0; i < cantDatos ; ++i){
        sum_X = sum_X + ejeX[i];
        sum_Y = sum_Y + ejeY[i];
        sum_XY = sum_XY + (ejeX[i] * ejeY[i]);
        sum_X_cuadrado = ejeX[i] * ejeX[i] + sum_X_cuadrado;
    }
    
    cuadrado_sum_X = sum_X * sum_X;

    pendiente = ((cantDatos * sum_XY) - (sum_X * sum_Y)) / ((cantDatos * sum_X_cuadrado) - cuadrado_sum_X);

    interseccion = ((sum_Y * sum_X_cuadrado) - (sum_X * sum_XY)) / ((cantDatos * sum_X_cuadrado) - cuadrado_sum_X) /*((sum_Y - (pendiente * sum_X)) / cantDatos)*/;

    cout << "\n\nΣx = " << sum_X << ", Σy = " << sum_Y << ", Σxy = " << sum_XY << "\n\n";

    cout << "Σ(xy) = " << sum_XY << ", Σ(x^2) = " << sum_X_cuadrado << ", (Σx)^2 = " << cuadrado_sum_X << "\n\n";

    cout << "pendiente = " << pendiente << ", interseccion = " << interseccion << "\n\n";

    if(interseccion > 0){
        cout << "Función: " << pendiente << "x + " << interseccion << "\n";
    } else cout << "Función: " << pendiente << "x - " << abs(interseccion) << "\n";

    return 0;
}
