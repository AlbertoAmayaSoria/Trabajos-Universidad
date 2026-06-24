#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

double Sum(const vector<double>& a, int n);

vector<double> GenerarCoeficientesAleatorios(int tamano, mt19937& generador);

int main() {
    
    vector<int> cantidad_elementos = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    
    vector<double> tiempos_ejecucion(cantidad_elementos.size());

    unsigned semilla = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generador(semilla);

    double x_evaluacion = 2.0; 

    for (size_t i = 0; i < cantidad_elementos.size(); i++) {
        int n_actual = cantidad_elementos[i];

        vector<double> polinomio_actual = GenerarCoeficientesAleatorios(n_actual, generador);

        auto tiempo_inicio = chrono::high_resolution_clock::now();
        
        Sum(polinomio_actual, cantidad_elementos[i]);
        
        auto tiempo_fin = chrono::high_resolution_clock::now();

        //Duración en microsegundos
        chrono::duration<double, micro> duracion = tiempo_fin - tiempo_inicio;
        tiempos_ejecucion[i] = duracion.count();
    }

    cout << "\n=============================================" << endl;
    cout << " TAREA UNIDAD III: TABLA DE TIEMPOS (ALG. 5) " << endl;
    cout << "=============================================" << endl;
    cout << "  Tamaño (n)\t|\tTiempo (Microsegundos) " << endl;
    cout << "---------------------------------------------" << endl;
    
    for (size_t i = 0; i < cantidad_elementos.size(); ++i) {
        cout << "  " << cantidad_elementos[i] << "\t\t|\t" << tiempos_ejecucion[i] << " us" << endl;
    }
    
    cout << "=============================================" << endl;


    ofstream archivo_excel("../data/Eval_sum.csv");

    if(archivo_excel.is_open()){
        archivo_excel << "Tamaño (n); Timepo (Microsegundos)\n";

        for(size_t i = 0; i < cantidad_elementos.size(); i++){
            archivo_excel << cantidad_elementos[i] << ";" << tiempos_ejecucion[i] << "\n";
        }

        archivo_excel.close();
        
        cout << "\nSe ha generado el archivo 'Eval_sum.csv'." << endl;
    } else {
        cout << "\nNo se pudo crear el archivo para Excel." << endl;
    }


    return 0;
}


double Sum(const vector<double>& a, int n){

    double S = 0.0;

    for(size_t i = 1; i < n; i++){
        S = S + a[i];
    }

    return S;
}

vector<double> GenerarCoeficientesAleatorios(int tamano, mt19937& generador) {
    vector<double> v(tamano);
    uniform_real_distribution<double> distribucion(1.0, 100.0);

    for (int i = 0; i < tamano; ++i) {
        v[i] = distribucion(generador);
    }
    
    return v;
}