#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

#include <iostream>
#include <ostream>
#include <istream>

/**
 * @brief Clase plantilla que implementa una fila (stack) gen�rica.
 *
 * La clase Stack permite almacenar elementos de cualquier tipo y
 * administra la memoria din�mica para su almacenamiento. La capacidad
 * inicial se define mediante el par�metro de plantilla \a Cap.
 *
 * @tparam Type Tipo de los elementos que se almacenar�n en la fila.
 * @tparam Cap Capacidad inicial de la fila.
 */
template <typename Type>
class Queue
{
    // --- M�todos externos (operadores de flujo)
    /**
     * @brief Operador de inserci�n en flujo.
     *
     * Permite imprimir el contenido de la fila a un flujo de salida.
     *
     * @param output Flujo de salida.
     * @param s Pila a imprimir.
     * @return std::ostream& Referencia al flujo de salida.
     */
    template<typename T>
    friend std::ostream& operator<<(std::ostream& output, const Queue<T>& s);

    /**
     * @brief Operador de extracci�n en flujo.
     *
     * Permite ingresar datos a la fila desde un flujo de entrada.
     *
     * @param input Flujo de entrada.
     * @param s Pila en la que se almacenar�n los datos.
     * @return std::istream& Referencia al flujo de entrada.
     */
    template<typename T>
    friend std::istream& operator>>(std::istream& input, Queue<T>& s);

public:
    // ----- Constructores ----------------------------------------

    /**
     * @brief Constructor por defecto.
     *
     * Crea una fila vac�a con una capacidad inicial definida por \a Cap.
     */
    explicit Queue();

    /**
     * @brief Constructor de copia.
     *
     * Crea una nueva fila copiando los elementos y la estructura de otra fila.
     *
     * @param s Pila de la cual se realiza la copia.
     */
    Queue(const Queue &s);

    /**
     * @brief Operador de asignaci�n.
     *
     * Asigna el contenido de la fila \a s a la fila actual.
     *
     * @param s Pila de la cual se asignan los valores.
     * @return Stack& Referencia a la fila actual.
     */
    Queue & operator=(const Queue &s);


    // ----- Destructor -------------------------------------------

    /**
     * @brief Destructor.
     *
     * Libera la memoria asignada y realiza la limpieza necesaria.
     */
    ~Queue();

    // --- M�todos p�blicos ----------------------------------------

    /**
     * @brief Inserta un elemento en la fila.
     *
     * Agrega el elemento \a val al tope de la fila. Si la fila est� llena,
     * se redimensiona para poder insertar el nuevo elemento.
     *
     * @param val Elemento a insertar.
     */
    void Enqueue(Type val);

    /**
     * @brief Elimina el elemento del tope de la fila.
     *
     * Remueve el elemento que se encuentra en el tope de la fila.
     */
    void Dequeue();

    /**
     * @brief Retorna el elemento al frente de la fila.
     *
     * @return Type Elemento que se encuentra en el tope.
     * @throws Lanza una excepci�n si la fila est� vac�a.
     */
    Type Front() const;

    /**
     * @brief Retorna el elemento atr�s de la fila.
     *
     * @return Type Elemento que se encuentra en el tope.
     * @throws Lanza una excepci�n si la fila est� vac�a.
     */
    Type Rear() const;

    /**
     * @brief Verifica si la fila est� vac�a.
     *
     * @return true Si la fila no contiene elementos.
     * @return false Si la fila tiene elementos.
     * @throws Lanza una excepci�n si la capacidad de la fila es 0.
     */
    bool IsEmpty() const;

    /**
     * @brief Elimina todos los elementos de la fila.
     *
     * Reinicia la fila, liberando la memoria asignada y recreando el espacio.
     */
    void ClearQueue();

    /**
     * @brief Retorna la cantidad de elementos almacenados en la fila.
     *
     * @return unsigned N�mero de elementos actualmente en la fila.
     */
    unsigned QueueSize() const;

    /**
     * @brief Imprime los elementos de la fila.
     *
     * Muestra en consola cada uno de los elementos almacenados en la fila.
     */
    void PrintElements();



private:
    // ----- Atributos --------------------------------------------

    /**
     * @brief Capacidad actual de la fila.
     *
     * Se inicializa con el valor de \a Cap y se actualiza al redimensionar la fila.
     */
    unsigned size;

    struct Element
    {
        Type value;
        Element *nextElement;
    };

    Element *frontElement;
    Element *rearElement;

    // ----- M�todos privados -------------------------------------

};

#include "../Templates/Cola.tpp"


#endif // COLA_HPP_INCLUDED
