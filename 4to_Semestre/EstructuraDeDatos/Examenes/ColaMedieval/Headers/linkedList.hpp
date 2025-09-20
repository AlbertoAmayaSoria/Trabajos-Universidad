#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>


using namespace std;

class LinkedList {

public:
    LinkedList();
    LinkedList(const LinkedList& otra);
    ~LinkedList();
    LinkedList& operator=(const LinkedList& otra);
    

    void insertarInicio(string valor);
    void insertarFinal(string valor);
    void insertarPosicion(string valor, size_t pos);


    void eliminarInicio();
    void eliminarFinal();
    void eliminarPosicion(size_t pos);
    void eliminarValor(string valor);


    bool buscar(string valor);


    string obtenerPrimero() const;
    string obtenerUltimo();
    string obtenerEnPosicion(size_t posicion);
    int obtenerIndice(const string& valor);
    
    
    

    
    size_t obtenerTamaño();


    void imprimir();

private:
    struct Nodo {
        string dato;
        Nodo* siguiente;
        Nodo(string valor) : dato(valor), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    size_t tamaño;
};



#endif // LINKEDLIST_HPP

