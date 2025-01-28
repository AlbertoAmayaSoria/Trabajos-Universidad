#include <stdexcept>
#include <iostream>
#include <cmath>

#include "Matriz.h"

// Constructor por defecto
Matriz::Matriz(unsigned int r, unsigned int c) : renglones(r), columnas(c) {
    datos = new int*[renglones];
    for (unsigned int i = 0; i < renglones; ++i) {
        datos[i] = new int[columnas]();
    }
}

// Destructor
Matriz::~Matriz() {
    for (unsigned int i = 0; i < renglones; ++i) {
        delete[] datos[i];
    }
    delete[] datos;
}

// Constructor de copia
Matriz::Matriz(const Matriz& otra) : renglones(otra.renglones), columnas(otra.columnas) {
    datos = new int*[renglones];
    for (unsigned int i = 0; i < renglones; ++i) {
        datos[i] = new int[columnas];
        for (unsigned int j = 0; j < columnas; ++j) {
            datos[i][j] = otra.datos[i][j];
        }
    }
}

// Operador de asignación
Matriz& Matriz::operator=(const Matriz& otra) {
    if (this == &otra) return *this;

    for (unsigned int i = 0; i < renglones; ++i) {
        delete[] datos[i];
    }
    delete[] datos;

    renglones = otra.renglones;
    columnas = otra.columnas;
    datos = new int*[renglones];
    for (unsigned int i = 0; i < renglones; ++i) {
        datos[i] = new int[columnas];
        for (unsigned int j = 0; j < columnas; ++j) {
            datos[i][j] = otra.datos[i][j];
        }
    }
    return *this;
}

// Operador de suma
Matriz Matriz::operator+(const Matriz& otra) const {
    if (renglones != otra.renglones || columnas != otra.columnas) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para sumarlas.");
    }

    Matriz resultado(renglones, columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] + otra.datos[i][j];
        }
    }
    return resultado;
}

// Operador de resta
Matriz Matriz::operator-(const Matriz& otra) const {
    if (renglones != otra.renglones || columnas != otra.columnas) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para restarlas.");
    }

    Matriz resultado(renglones, columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] - otra.datos[i][j];
        }
    }
    return resultado;
}

// Operador de producto (multiplicación de matrices)
Matriz Matriz::operator*(const Matriz& otra) const {
    if (columnas != otra.renglones) {
        throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de renglones de la segunda.");
    }

    Matriz resultado(renglones, otra.columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < otra.columnas; ++j) {
            resultado.datos[i][j] = 0;
            for (unsigned int k = 0; k < columnas; ++k) {
                resultado.datos[i][j] += datos[i][k] * otra.datos[k][j];
            }
        }
    }
    return resultado;
}

// Producto por escalar
Matriz Matriz::operator*(int escalar) const {
    Matriz resultado(renglones, columnas);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[i][j] = datos[i][j] * escalar;
        }
    }
    return resultado;
}

// Método para calcular la transpuesta de la matriz
Matriz Matriz::transpuesta() const {
    Matriz resultado(columnas, renglones);
    for (unsigned int i = 0; i < renglones; ++i) {
        for (unsigned int j = 0; j < columnas; ++j) {
            resultado.datos[j][i] = datos[i][j];
        }
    }
    return resultado;
}

// Método para calcular la inversa de una matriz cuadrada
/*Matriz Matriz::inversa() const {
    if (renglones != columnas) {
        throw std::invalid_argument("Solo las matrices cuadradas tienen inversa.");
    }

    // Determinante de la matriz
    int det = 0;
    if (renglones == 2) {
        det = datos[0][0] * datos[1][1] - datos[0][1] * datos[1][0];
    }

    if (det == 0) {
        throw std::invalid_argument("La matriz no tiene inversa (determinante 0).");
    }

    Matriz inversa(renglones, columnas);
    if (renglones == 2) {
        inversa.datos[0][0] = datos[1][1] / det;
        inversa.datos[0][1] = -datos[0][1] / det;
        inversa.datos[1][0] = -datos[1][0] / det;
        inversa.datos[1][1] = datos[0][0] / det;
    }

    return inversa;
}*/

// Método para redimensionar la matriz
void Matriz::redimensionar(unsigned int nuevas_renglones, unsigned int nuevas_columnas) {
    int** nueva_matriz = new int*[nuevas_renglones];
    for (unsigned int i = 0; i < nuevas_renglones; ++i) {
        nueva_matriz[i] = new int[nuevas_columnas]();
    }

    for (unsigned int i = 0; i < std::min(renglones, nuevas_renglones); ++i) {
        for (unsigned int j = 0; j < std::min(columnas, nuevas_columnas); ++j) {
            nueva_matriz[i][j] = datos[i][j];
        }
    }

    for (unsigned int i = 0; i < renglones; ++i) {
        delete[] datos[i];
    }
    delete[] datos;

    renglones = nuevas_renglones;
    columnas = nuevas_columnas;
    datos = nueva_matriz;
}

// Operador de entrada
std::istream& operator>>(std::istream& in, Matriz& mat) {
    for (unsigned int i = 0; i < mat.renglones; ++i) {
        for (unsigned int j = 0; j < mat.columnas; ++j) {
            in >> mat.datos[i][j];
        }
    }
    return in;
}

// Operador de salida
std::ostream& operator<<(std::ostream& out, const Matriz& mat) {
    for (unsigned int i = 0; i < mat.renglones; ++i) {
        for (unsigned int j = 0; j < mat.columnas; ++j) {
            out << mat.datos[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

// Operador no miembro para el producto por escalar conmutativo
Matriz operator*(int escalar, const Matriz& mat) {
    return mat * escalar;
}
