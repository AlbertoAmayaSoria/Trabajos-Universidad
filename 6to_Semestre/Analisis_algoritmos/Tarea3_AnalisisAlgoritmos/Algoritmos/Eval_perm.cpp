#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

void permutaciones(vector<int>& a, int k, int n);

int main(){
    vector<int> dimensiones = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    vector<double> tiempos_ejecucion(dimensiones.size());

    for(size_t i = 0; i < dimensiones.size(); i++){
        int n_actual = dimensiones[i];

        vector<int> arreglo(n_actual);
        iota(arreglo.begin(), arreglo.end(), 0);

        auto tiempo_inicio = chrono::high_resolution_clock::now();

        permutaciones(arreglo, 0, n_actual);

        auto tiempo_fin = chrono::high_resolution_clock::now();

        chrono::duration<double, micro> duracion = tiempo_fin - tiempo_inicio;
        tiempos_ejecucion[i] = duracion.count();

    }

    cout << "\n=============================================" << endl;
    cout << " TAREA UNIDAD III: TABLA DE TIEMPOS (PERM)   " << endl;
    cout << "=============================================" << endl;
    cout << "  Tamaño (n)\t|\tTiempo (Microsegundos) " << endl;
    cout << "---------------------------------------------" << endl;
    for (size_t i = 0; i < dimensiones.size(); ++i) {
        cout << "  " << dimensiones[i] << "\t\t|\t" << tiempos_ejecucion[i] << " us" << endl;
    }
    cout << "=============================================" << endl;

    ofstream archivo_excel("../data/Eval_perm.csv");

    if(archivo_excel.is_open()){
        archivo_excel << "Tamaño (n) ; Tiempo (Microsegundos)\n";

        for(size_t i = 0; i < dimensiones.size(); i++){
            archivo_excel << dimensiones[i] << ";" << tiempos_ejecucion[i] << "\n";
        }

        archivo_excel.close();
        cout << "\nSe ha generado el archivo 'Eval_perm.csv' exitosamente." << endl;
    } else {
        cout << "\nNo se pudo crear el archivo para Excel." << endl;
    }

    return 0;
}


void permutaciones(vector<int>& a, int k, int n){
    if(k == n - 1){
        int dummy = a[0];
    }  else {
        for(int i = k; i < n; i++){
            swap(a[k], a[i]);

            permutaciones(a, k + 1, n);

            swap(a[k], a[i]);
        }
    }
}