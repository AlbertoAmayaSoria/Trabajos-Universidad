#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

double Potencia(double X, int exponente);

double EvaluaPolinomio2(const vector<double>& C, double X);

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
        
        EvaluaPolinomio2(polinomio_actual, x_evaluacion);
        
        auto tiempo_fin = chrono::high_resolution_clock::now();

        //Duración en microsegundos (usamos double para conservar precisión)
        chrono::duration<double, micro> duracion = tiempo_fin - tiempo_inicio;
        tiempos_ejecucion[i] = duracion.count();
    }

    cout << "\n=============================================" << endl;
    cout << " TAREA UNIDAD III: TABLA DE TIEMPOS (ALG. 2) " << endl;
    cout << "=============================================" << endl;
    cout << "  Tamaño (n)\t|\tTiempo (Microsegundos) " << endl;
    cout << "---------------------------------------------" << endl;
    
    for (size_t i = 0; i < cantidad_elementos.size(); ++i) {
        cout << "  " << cantidad_elementos[i] << "\t\t|\t" << tiempos_ejecucion[i] << " us" << endl;
    }
    
    cout << "=============================================" << endl;


    ofstream archivo_excel("../data/Eval_logaritmica_potencia.csv");

    if(archivo_excel.is_open()){
        archivo_excel << "Tamaño (n); Timepo (Microsegundos)\n";

        for(size_t i = 0; i < cantidad_elementos.size(); i++){
            archivo_excel << cantidad_elementos[i] << ";" << tiempos_ejecucion[i] << "\n";
        }

        archivo_excel.close();
        
        cout << "\nSe ha generado el archivo 'Eval_logaritmica_potencia.csv'." << endl;
    } else {
        cout << "\nNo se pudo crear el archivo para Excel." << endl;
    }


    return 0;
}

double Potencia(double X, int exponente){
    double potencia;
    double t;

    if(exponente == 0){
    
        potencia = 1.0;

    } else if ((exponente % 2) == 1){
    
        potencia = X  * Potencia(X, exponente - 1);
    
    } else {
    
        t = Potencia(X, exponente / 2);
        potencia = t * t;
    }

    return potencia;
}

double EvaluaPolinomio2(const vector<double>& C, double X) {
    
    double S = C[0];
    size_t N = C.size();

    for(int i = 0; i < N; i++){
        S = S + C[i] * Potencia(X, i);
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