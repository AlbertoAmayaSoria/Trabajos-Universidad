#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>


class Matriz {
    
    //Operadores de flujo
    friend std::istream& operator >>(std::istream& cin, Matriz& mat);
    friend std::ostream& operator <<(std::ostream& cout, const Matriz& mat);

    //Operador no miembro para producto por escalar conmutativo
    friend Matriz operator*(int escalar, const Matriz& mat);

public:
    // Constructor por defecto
    Matriz(unsigned int r = 1, unsigned int c = 1);

    // Destructor
    ~Matriz();

    // Constructor de copia
    Matriz(const Matriz& otra);

    // Operador de asignación
    Matriz& operator=(const Matriz& otra);

    // Operadores para:
    Matriz operator+(const Matriz& otra) const;
    Matriz operator-(const Matriz& otra) const;
    Matriz operator*(const Matriz& otra) const;
    Matriz operator*(int escalar) const;

    // Métodos
    Matriz transpuesta() const;
    Matriz inversa() const;  // Inversa de una matriz cuadrada
    void redimensionar(unsigned int nuevas_renglones, unsigned int nuevas_columnas);


private:

    unsigned int renglones;
    unsigned int columnas;
    int** datos;
    
};

#endif
