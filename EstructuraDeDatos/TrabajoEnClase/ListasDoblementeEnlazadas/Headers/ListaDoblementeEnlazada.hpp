#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template <typename T>
class ListaDoblementeEnlazada {

public:
    ListaDoblementeEnlazada();
    ListaDoblementeEnlazada(const ListaDoblementeEnlazada& otra);
    ~ListaDoblementeEnlazada();
    ListaDoblementeEnlazada& operator=(const ListaDoblementeEnlazada& otra);
    

    void insertarInicio(T valor);
    void insertarFinal(T valor);
    void insertarPosicion(T valor, size_t pos);


    void eliminarInicio();
    void eliminarFinal();
    void eliminarPosicion(size_t pos);
    void eliminarValor(T valor);


    bool buscar(T valor);


    T obtenerPrimero() const;
    T obtenerUltimo() const;
    T obtenerEnPosicion(size_t posicion) const;
    int obtenerIndice(const T& valor) const;
    
    
    

    
    size_t obtenerTamaño() const;


    void imprimir() const;

private:
    struct Nodo {
        T dato;
        Nodo* anterior;
        Nodo* siguiente;
        Nodo(T valor) : dato(valor), anterior(nullptr), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    Nodo* ultimo;
    size_t tamaño;
};

#include "../Templates/ListaDoblementeEnlazada.tpp"

#endif // LINKEDLIST_HPP

