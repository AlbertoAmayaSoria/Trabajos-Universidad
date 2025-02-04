#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED


/**
 * \file Vector.hpp
 * \brief Definici�n de la clase Vector para operaciones algebraicas.
 * 
 * Esta clase representa un vector algebraico y permite realizar operaciones 
 * como suma, resta, producto escalar y multiplicaci�n por un escalar.
 * Tambi�n proporciona m�todos para la captura e impresi�n de datos.
 * 
 * \author Amaya Soria Angel Alberto
 * \author Altamirano Ocejo Michell Berenice 
 * \date 01/02/2025
 */

#include <iostream>

/**
 * \class Vector
 * \brief Clase para la manipulaci�n de vectores algebraicos.
 * 
 * Implementa operaciones b�sicas como suma, resta, producto escalar y 
 * multiplicaci�n por un escalar, adem�s de m�todos para la impresi�n y captura de datos.
 */
class Vector {
    /**
     * \brief Sobrecarga del operador de multiplicaci�n por un escalar.
     * 
     * Permite multiplicar un escalar por un vector, devolviendo un nuevo vector escalado.
     * \param escalar Valor escalar por el que se multiplica el vector.
     * \param v Vector a multiplicar.
     * \return Vector resultante de la multiplicaci�n.
     */
    friend Vector operator*(double escalar, const Vector v);

    /**
     * \brief Sobrecarga del operador de salida.
     * 
     * Permite imprimir un vector en un flujo de salida.
     * \param salida Flujo de salida.
     * \param v Vector a imprimir.
     * \return Referencia al flujo de salida.
     */
    friend std::ostream &operator<<(std::ostream &salida, const Vector v);

    /**
     * \brief Sobrecarga del operador de entrada.
     * 
     * Permite capturar un vector desde un flujo de entrada.
     * \param entrada Flujo de entrada.
     * \param v Vector donde se almacenar�n los valores ingresados.
     * \return Referencia al flujo de entrada.
     */
    friend std::istream &operator>>(std::istream &entrada, Vector &v);

public:
    /** 
     * \brief Constructor con valores predeterminados.
     * 
     * Crea un vector de la dimensi�n especificada con todos sus componentes inicializados 
     * a un valor determinado.
     * \param dimension N�mero de componentes del vector (m�nimo 1).
     * \param valor Valor inicial para todas las componentes del vector (por defecto 0).
     */
    explicit Vector(int dimension = 1, double valor = 0);

    /** 
     * \brief Constructor de copia.
     * 
     * Crea una copia exacta de otro vector.
     * \param v Vector a copiar.
     */
    Vector(const Vector &v);

    /** 
     * \brief Destructor de la clase Vector.
     * 
     * Libera la memoria din�mica utilizada para almacenar las componentes del vector.
     */
    ~Vector();

    /** 
     * \brief Sobrecarga del operador de asignaci�n.
     * 
     * Copia el contenido de un vector en otro, asegurando una correcta gesti�n de memoria.
     * \param v Vector a asignar.
     * \return Referencia al vector actual tras la asignaci�n.
     */
    Vector &operator=(const Vector &v);

    /** 
     * \brief Obtiene la dimensi�n del vector.
     * \return N�mero de componentes del vector.
     */
    int ObtenerDim() const;

    /** 
     * \brief Imprime el vector en consola.
     */
    void Imprimir() const;

    /** 
     * \brief Captura los valores del vector desde la entrada est�ndar.
     */
    void Capturar();

    /** 
     * \brief Sobrecarga del operador de suma.
     * 
     * Realiza la suma de dos vectores del mismo tama�o.
     * \param v Vector a sumar.
     * \return Vector resultante de la suma.
     */
    Vector operator+(const Vector v) const;

    /** 
     * \brief Sobrecarga del operador de resta.
     * 
     * Realiza la resta de dos vectores del mismo tama�o.
     * \param v Vector a restar.
     * \return Vector resultante de la resta.
     */
    Vector operator-(const Vector v) const;

    /** 
     * \brief Sobrecarga del operador de producto escalar.
     * 
     * Calcula el producto escalar entre dos vectores.
     * \param v Vector con el que se realizar� el producto escalar.
     * \return Resultado del producto escalar.
     */
    int operator*(const Vector v) const;

    /** 
     * \brief Sobrecarga del operador de multiplicaci�n por un escalar.
     * 
     * Multiplica el vector por un escalar.
     * \param esc Valor escalar.
     * \return Vector resultante de la multiplicaci�n.
     */
    Vector operator*(double esc) const;

    /** 
     * \brief Calcula la norma del vector.
     * 
     * \param v Vector del que se calcular� la norma.
     * \return Valor de la norma del vector.
     */
    double Norma(Vector v) const;

    /** 
     * \brief Sobrecarga del operador de acceso por �ndice (lectura).
     * 
     * Permite acceder a los elementos del vector de manera segura.
     * \param i �ndice del elemento a obtener.
     * \return Valor del componente en la posici�n i.
     */
    double operator[](int i) const;

    /** 
     * \brief Sobrecarga del operador de acceso por �ndice (modificaci�n).
     * 
     * Permite modificar los elementos del vector de manera segura.
     * \param i �ndice del elemento a modificar.
     * \return Referencia al componente en la posici�n i.
     */
    double &operator[](int i);

private:
    int dim;            ///< Dimensi�n del vector (n�mero de componentes).
    double *componente; ///< Arreglo din�mico que almacena los valores del vector.

    /** 
     * \brief Establece la dimensi�n del vector.
     * 
     * Asigna memoria para almacenar los componentes del vector.
     * \param dimension Nueva dimensi�n del vector.
     */
    void EstablecerDim(int dimension);
};



#endif // VECTOR_HPP_INCLUDED
