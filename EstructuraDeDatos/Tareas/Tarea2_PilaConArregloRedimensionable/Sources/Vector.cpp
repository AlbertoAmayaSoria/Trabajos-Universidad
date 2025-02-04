/**
 * \file Vector.cpp
 * \brief Implementaci�n de la clase Vector para operaciones algebraicas.
 * 
 * Esta clase permite realizar operaciones algebraicas b�sicas sobre vectores,
 * incluyendo suma, resta, producto escalar y multiplicaci�n por un escalar.
 * 
 * \author Amaya Soria Angel Alberto
 * \author Altamirano Ocejo Michell Berenice 
 * \date 01/02/2025
 */

#include <iostream>
#include <cmath>
#include "../Headers/Vector.hpp"

using std::cout;
using std::cin;

/**
 * \brief Constructor de la clase Vector.
 * 
 * Inicializa un vector con una dimensi�n dada y un valor inicial para todas sus componentes.
 * 
 * \param dimension N�mero de componentes del vector (m�nimo 1).
 * \param valor Valor inicial para todas las componentes (por defecto 0).
 */
Vector::Vector(int dimension /* = 1 */, double valor /* = 0*/) {
    EstablecerDim(dimension);
    try {
        componente = new double[dim];
        for(int i = 0; i < dim; ++i) {
            componente[i] = valor;
        }
    } catch (std::bad_alloc &) {
        throw "Problemas de asignaci�n de memoria";
    }
}

/**
 * \brief Constructor de copia.
 * 
 * Crea un nuevo vector copiando los valores de otro vector.
 * 
 * \param v Vector a copiar.
 */
Vector::Vector(const Vector &v) : componente(nullptr) {
    *this = v;
}

/**
 * \brief Destructor de la clase Vector.
 * 
 * Libera la memoria din�mica utilizada por el vector.
 */
Vector::~Vector() {
    delete[] componente;
}

/**
 * \brief Sobrecarga del operador de asignaci�n.
 * 
 * Permite asignar un vector a otro, asegurando la correcta gesti�n de memoria.
 * 
 * \param v Vector a asignar.
 * \return Referencia al vector actual tras la asignaci�n.
 */
Vector &Vector::operator=(const Vector &v) {
    if (this == &v) return *this;
    delete[] componente;
    dim = v.dim;
    try {
        componente = new double[dim];
        for (int i = 0; i < dim; ++i) {
            componente[i] = v.componente[i];
        }
    } catch (std::bad_alloc &) {
        throw "Problemas de asignaci�n de memoria";
    }
    return *this;
}

/**
 * \brief Imprime el vector en consola.
 */
void Vector::Imprimir() const {
    cout << "(";
    for (int i = 0; i < dim; ++i) {
        cout << componente[i] << ", ";
    }
    cout << "\b\b)";
}

/**
 * \brief Captura los valores del vector desde la entrada est�ndar.
 */
void Vector::Capturar() {
    for (int i = 0; i < dim; ++i) {
        cout << "Componente " << i + 1 << ": ";
        cin >> componente[i];
    }
}

/**
 * \brief Obtiene la dimensi�n del vector.
 * \return N�mero de componentes del vector.
 */
int Vector::ObtenerDim() const {
    return dim;
}

/**
 * \brief Sobrecarga del operador de suma.
 * 
 * Realiza la suma de dos vectores del mismo tama�o.
 * 
 * \param v Vector a sumar.
 * \return Vector resultante de la suma.
 */
Vector Vector::operator+(const Vector v) const {
    if (dim != v.dim) throw "Vectores incompatibles para la suma";
    Vector s(dim);
    for (int i = 0; i < dim; ++i) {
        s.componente[i] = componente[i] + v.componente[i];
    }
    return s;
}

/**
 * \brief Sobrecarga del operador de resta.
 * 
 * Realiza la resta de dos vectores del mismo tama�o.
 * 
 * \param v Vector a restar.
 * \return Vector resultante de la resta.
 */
Vector Vector::operator-(const Vector v) const {
    if (dim != v.dim) throw "Vectores incompatibles para la resta";
    Vector r(dim);
    for (int i = 0; i < dim; ++i) {
        r.componente[i] = componente[i] - v.componente[i];
    }
    return r;
}

/**
 * \brief Sobrecarga del operador de producto escalar.
 * 
 * Calcula el producto escalar entre dos vectores.
 * 
 * \param v Vector con el que se realizar� el producto escalar.
 * \return Resultado del producto escalar.
 */
int Vector::operator*(const Vector v) const {
    if (dim != v.dim) throw "Vectores incompatibles para el producto punto";
    int resultado = 0;
    for (int i = 0; i < dim; ++i) {
        resultado += componente[i] * v.componente[i];
    }
    return resultado;
}

/**
 * \brief Sobrecarga del operador de acceso por �ndice.
 * 
 * Permite acceder o modificar los elementos del vector de manera segura.
 * 
 * \param i �ndice del elemento.
 * \return Valor del componente en la posici�n i.
 */
double Vector::operator[](int i) const {
    if (i < 0 || i >= dim) throw "�ndice inv�lido";
    return componente[i];
}

double &Vector::operator[](int i) {
    if (i < 0 || i >= dim) throw "�ndice inv�lido";
    return componente[i];
}

/**
 * \brief Establece la dimensi�n del vector.
 * 
 * Asigna memoria para almacenar los componentes del vector.
 * 
 * \param dimension Nueva dimensi�n del vector.
 */
void Vector::EstablecerDim(int dimension) {
    if (dimension < 1) {
        throw "Dimensi�n inv�lida";
    }
    dim = dimension;
}

/**
 * \brief Sobrecarga del operador de salida.
 * 
 * Permite imprimir un vector en un flujo de salida.
 * 
 * \param salida Flujo de salida.
 * \param v Vector a imprimir.
 * \return Referencia al flujo de salida.
 */
std::ostream &operator<<(std::ostream &salida, const Vector v) {
    salida << "(";
    for (int i = 0; i < v.dim; ++i) {
        salida << v.componente[i] << ", ";
    }
    salida << "\b\b)";
    return salida;
}

