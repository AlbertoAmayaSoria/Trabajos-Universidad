#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

void fibonacci(int n);

int main() {
    
    vector<int> dimensiones = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    
    vector<double> tiempos_ejecucion(dimensiones.size());

    unsigned semilla = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generador(semilla);
    
    for(int i = 0; i < dimensiones.size(); i++){
        
        auto tiempo_inicio = chrono::high_resolution_clock::now();
        
        fibonacci(dimensiones[i]);
    
        auto tiempo_fin = chrono::high_resolution_clock::now();

        //Duración en microsegundos (usamos double para conservar precisión)
        chrono::duration<double, micro> duracion = tiempo_fin - tiempo_inicio;
        tiempos_ejecucion[i] = duracion.count();
    }
    

    cout << "\n=============================================" << endl;
    cout << " TAREA UNIDAD III: TABLA DE TIEMPOS (ALG. 8) " << endl;
    cout << "=============================================" << endl;
    cout << "  Tamaño (n)\t|\tTiempo (Microsegundos) " << endl;
    cout << "---------------------------------------------" << endl;
    
    for (size_t i = 0; i < dimensiones.size(); ++i) {
        cout << "  " << dimensiones[i] << "\t\t|\t" << tiempos_ejecucion[i] << " us" << endl;
    }
    
    cout << "=============================================" << endl;


    ofstream archivo_excel("../data/Eval_fibonacci.csv");

    if(archivo_excel.is_open()){
        archivo_excel << "Tamaño (n); Timepo (Microsegundos)\n";

        for(size_t i = 0; i < dimensiones.size(); i++){
            archivo_excel << dimensiones[i] << ";" << tiempos_ejecucion[i] << "\n";
        }

        archivo_excel.close();
        
        cout << "\nSe ha generado el archivo 'Eval_fibonacci.csv'." << endl;
    } else {
        cout << "\nNo se pudo crear el archivo para Excel." << endl;
    }


    return 0;
}

void fibonacci(int n){
    
    if(n <= 1) {
        
        double resultado_base = static_cast<double>(n);
    
    } else {
        
        double fnm2 = 0.0, fnm1 = 1.0, fn = 0.0;

        for(int i = 2; i <= n; i++){
            fn = fnm1 + fnm2;
            fnm2 = fnm1;
            fnm1 = fn;
        }    
    }
}