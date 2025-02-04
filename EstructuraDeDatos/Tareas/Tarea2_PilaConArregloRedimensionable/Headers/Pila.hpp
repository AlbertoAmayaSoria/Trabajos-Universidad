#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED
/**
 * \file Pila.hpp
 * Contiene la definici&oacute;n de una clase que representa una pila
 * \author Amaya Soria Angel Alberto
 * \author Altamirano Ocejo Michell Berenice 
 * \date 01/02/2025
*/
#include <iostream>

/**
 * Contenedor tipo LIFO de datos doble
 * \tparam Tipo Tipo de dato
 * \tparam cap Capacidad máxima de la pila
 */
template <typename Tipo>
class Pila {
public:
    /** \brief Constructor de la Pila. Genera una pila vacía */
    Pila(); 

    /** \brief Constructor por copia */
    Pila(const Pila &p);

    /** \brief Sobrecarga del operador de asignación */
    Pila & operator=(const Pila &p);

    /** \brief Destructor de la Pila */
    ~Pila();

    /** \brief Agregar un elemento a la pila */
    void Apilar(Tipo valor);

    /** \brief Eliminar un elemento de la pila */
    void Desapilar();

    /** \brief Obtener el elemento en el tope de la pila */
    Tipo ObtenerTope() const;

    /** \brief Indicar si la pila está vacía */
    bool EstaVacia() const; 

    /** \brief Vaciar la pila */
    void Vaciar();

    /** \brief Obtener el número de elementos en la pila */
    int ElementosPila() const;

    /** \brief Obtener la capacidad máxima de la pila */
    int CapacidadPila() const;

    /** \brief Imprimir los elementos de la pila */
    void Imprimir() const;

private:
    Tipo *elemento;  // Puntero dinámico para almacenar los elementos
    int tope;        // Índice del tope de la pila
    int capacidad;   // Capacidad dinámica de la pila
    void Redimensionar(); // Redimensiona la pila cuando está llena
    bool EstaLlena() const; // Indica si la pila está llena
};

#include "../Templates/Pila.tpp"

#endif // PILA_HPP_INCLUDED
