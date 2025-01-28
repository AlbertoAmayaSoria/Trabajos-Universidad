#include <chrono>
#include <iostream>

#include "Pila.hpp"

//************************************************************************************************
//
template <typename Tipo>
Pila<Tipo>::Pila() : tope(-1){}
//************************************************************************************************
//
template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor)
{
    if(EstaLlena()) throw "Pila llena...";
    ++tope;
    elemento[tope] = valor;
}
//************************************************************************************************
template <typename Tipo>

void Pila<Tipo>::Desapilar()
{
    if(EstaVacia()) throw "Pila vacia...";
    --tope;
}
//************************************************************************************************
template <typename Tipo>
Pila<Tipo>::ObtenerTope() const
{
    if(EstaVacia()) throw "Pila vacia...";
    return elemento[tope];
}
//************************************************************************************************
//
template <typename Tipo>
bool Pila<Tipo>::EstaVacia() const
{
    return tope == -1;
}
//************************************************************************************************
//
template <typename Tipo>
bool Pila<Tipo>::EstaLlena() const
{
    return tope + 1 == MAX_TAM;
}
//************************************************************************************************
//
template <typename Tipo>
void Pila<Tipo>::Imprimir() const
{
    for(int i = 0; i <= tope; ++i){
        std::cout << elemento[i] << ", ";
    }
    std::cout << "\b\b <- TOPE";
}
//************************************************************************************************

void Pila::Vaciar()
{
    tope = -1;
}

//
