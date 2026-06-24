#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

void Transpuesta(
    vector<vector<double>>& a, 
    int n
);

vector<vector<double>> GenerarMatrizAleatoria(
    int filas, 
    int columnas, 
    mt19937& 
    generador
);

int main() {
    
    vector<int> dimensiones = {500, 1000, 1500, 2000, 3000, 3500, 4000, 4500, 5000, 5500};
    
    vector<double> tiempos_ejecucion(dimensiones.size());

    unsigned semilla = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 generador(semilla);

    double x_evaluacion = 2.0; 

    for (size_t i = 0; i < dimensiones.size(); i++) {
        int n_actual = dimensiones[i];
        //int m_actual = n_actual;

        vector<vector<double>> a = GenerarMatrizAleatoria(n_actual, n_actual, generador);
        //vector<vector<double>> b = GenerarMatrizAleatoria(m_actual, n_actual, generador);

        Transpuesta(a, n_actual);

        //vector<vector<double>> c(m_actual, vector<double>(n_actual, 0.0));

        auto tiempo_inicio = chrono::high_resolution_clock::now();
        
        Transpuesta(a, n_actual);
        
        auto tiempo_fin = chrono::high_resolution_clock::now();

        //Duración en microsegundos (usamos double para conservar precisión)
        chrono::duration<double, micro> duracion = tiempo_fin - tiempo_inicio;
        tiempos_ejecucion[i] = duracion.count();
    }

    cout << "\n=============================================" << endl;
    cout << " TAREA UNIDAD III: TABLA DE TIEMPOS (ALG. 9) " << endl;
    cout << "=============================================" << endl;
    cout << "  Tamaño (n)\t|\tTiempo (Microsegundos) " << endl;
    cout << "---------------------------------------------" << endl;
    
    for (size_t i = 0; i < dimensiones.size(); ++i) {
        cout << "  " << dimensiones[i] <<"\t\t|\t" << tiempos_ejecucion[i] << " us" << endl;
    }
    
    cout << "=============================================" << endl;


    ofstream archivo_excel("../data/Eval_transpuesta.csv");

    if(archivo_excel.is_open()){
        archivo_excel << "Tamaño (n); Timepo (Microsegundos)\n";

        for(size_t i = 0; i < dimensiones.size(); i++){
            archivo_excel << dimensiones[i] << ";" << tiempos_ejecucion[i] << "\n";
        }

        archivo_excel.close();
        
        cout << "\nSe ha generado el archivo 'Eval_Transpuesta.csv'." << endl;
    } else {
        cout << "\nNo se pudo crear el archivo para Excel." << endl;
    }


    return 0;
}

void Transpuesta(
    vector<vector<double>>& a, 
    int n) {

        double t;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            t = a [i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}


vector<vector<double>> GenerarMatrizAleatoria(
    int filas,
    int columnas, 
    mt19937& generador) {

    vector<vector<double>> v(filas, vector<double>(columnas));
    uniform_real_distribution<double> distribucion(1.0, 100.0);

    for (int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; j++)
            v[i][j] = distribucion(generador);
    }
    
    return v;
}