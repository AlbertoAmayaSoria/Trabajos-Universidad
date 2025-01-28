#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

class Matriz{

public:

    explicit Matriz(int renglones = 1, int columnas = 1);
    
    
private:
    
    unsigned int renglones;
    unsigned int columnas;

    double **componente;

 
}

#endif // !MATRIZ_HPP_INCLUDED
