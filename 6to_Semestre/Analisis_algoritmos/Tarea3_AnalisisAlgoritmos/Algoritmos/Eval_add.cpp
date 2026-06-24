#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

void Add(
    const vector<vector<double>>& a, 
    const vector<vector<double>>& b, 
    vector<vector<double>>& c, 
    int m, 
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
        int m_actual = n_actual;

        vector<vector<double>> a = GenerarMatrizAleatoria(m_actual, n_actual, generador);
        vector<vector<double>> b = GenerarMatrizAleatoria(m_actual, n_actual, generador);

        vector<vector<double>> c(m_actual, vector<double>(n_actual, 0.0));

        auto tiempo_inicio = chrono::high_resolution_clock::now();
        
        Add(a, b, c, n_actual, m_actual);
        
        auto tiempo_fin = chrono::high_resolution_clock::now();

        //Duración en microsegundos (usamos double para conservar precisión)
        chrono::duration<double, micro> duracion = tiempo_fin - tiempo_inicio;
        tiempos_ejecucion[i] = duracion.count();
    }

    cout << "\n=============================================" << endl;
    cout << " TAREA UNIDAD III: TABLA DE TIEMPOS (ALG. 7) " << endl;
    cout << "=============================================" << endl;
    cout << "  Tamaño (n)\t|\tTiempo (Microsegundos) " << endl;
    cout << "---------------------------------------------" << endl;
    
    for (size_t i = 0; i < dimensiones.size(); ++i) {
        cout << "  " << dimensiones[i] << " x " << dimensiones[i] <<"\t\t|\t" << tiempos_ejecucion[i] << " us" << endl;
    }
    
    cout << "=============================================" << endl;


    ofstream archivo_excel("../data/Eval_add.csv");

    if(archivo_excel.is_open()){
        archivo_excel << "Tamaño (n); Timepo (Microsegundos)\n";

        for(size_t i = 0; i < dimensiones.size(); i++){
            archivo_excel << dimensiones[i] << ";" << tiempos_ejecucion[i] << "\n";
        }

        archivo_excel.close();
        
        cout << "\nSe ha generado el archivo 'Eval_add.csv'." << endl;
    } else {
        cout << "\nNo se pudo crear el archivo para Excel." << endl;
    }


    return 0;
}


void Add(const vector<vector<double>>& a, 
    const vector<vector<double>>& b, 
    vector<vector<double>>& c, 
    int m, 
    int n) 
    {

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}


vector<vector<double>> GenerarMatrizAleatoria(
    int filas,
    int columnas, 
    mt19937& generador) 
    {

    vector<vector<double>> v(filas, vector<double>(columnas));
    uniform_real_distribution<double> distribucion(1.0, 100.0);

    for (int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; j++)
            v[i][j] = distribucion(generador);
    }
    
    return v;
}