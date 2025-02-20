#ifndef LISTASENLAZADASSIMPLES_HPP_INCLUDED
#define LISTASENLAZADASSIMPLES_HPP_INCLUDED


/**
 * Contenedor tipo LIFO de datos doble
 * \tparam Tipo Tipo de dato
 */
template <typename Tipo = int>
class Lista{
public:
    
    Lista();

    Lista(const Lista<Tipo>& c);

    ~Lista();

    Lista<Tipo>& operator=(const Lista<Tipo>& c);

    void EncolarInicio(Tipo valor);

    void EncolarFInal(Tipo valor);

    void EncolarEnPosicion(Tipo valor);

    bool EstaVacia();

    void Imprimir();
    

private:
    int numElem;

    struct Elemento{
        Tipo valor;
        Elemento *siguiente;
    } *primero ,*tope;


};
#include "../Templates/ListasEnlazadasSimples.tpp"
#endif //   LISTASENLAZADASSIMPLES_HPP_INCLUDED
