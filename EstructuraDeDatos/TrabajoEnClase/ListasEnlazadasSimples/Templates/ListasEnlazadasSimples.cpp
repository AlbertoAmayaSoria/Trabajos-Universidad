#include <cstddef>
#include <iostream>

/**
 * @brief Constructor por defecto de la clase Lista.
 * 
 * Inicializa una Lista vacía, estableciendo el número de elementos en 0
 * y el puntero `tope` en NULL.
 */
template <typename Tipo>
Lista<Tipo>::Lista() : numElem(0), primero(NULL), tope(NULL) {}

template <typename Tipo>
Lista<Tipo>::Lista(const Lista<Tipo> &c) : numElem(0), primero(NULL), tope(NULL)
{
    *this = c;
}

template <typename Tipo>
Lista<Tipo>::~Lista()
{
    Vaciar();
}

template <typename Tipo>
void Lista<Tipo>::ApilarInicio(Tipo valor)
{
    Elemento* nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->siguiente = tope;
    if(EstaVacia()) primero = nuevo;
    else tope->siguiente = nuevo;
    ultimo = nuevo;
    ++numElem;
}
