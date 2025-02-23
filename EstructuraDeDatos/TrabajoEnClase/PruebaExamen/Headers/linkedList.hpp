#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

template <typename T>
class LinkedList {

public:
    LinkedList();
    LinkedList(const LinkedList& otra);
    ~LinkedList();
    LinkedList& operator=(const LinkedList& otra);
    

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
        Nodo* siguiente;
        Nodo(T valor) : dato(valor), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    size_t tamaño;
};

#include "../Templates/linkedList.tpp"

#endif // LINKEDLIST_HPP

