#include <cstddef>
#include <iostream>


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
    Elemento* actual = primero;
    while (actual != nullptr) {
        Elemento* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    primero = tope = nullptr;
    numElem = 0;
}


template <typename Tipo>
Lista<Tipo>& Lista<Tipo>::operator=(const Lista<Tipo>& c)
{
    if(this == &c) return *this;
    this->DesencolarInicio();
    
    

}


template <typename Tipo>
void Lista<Tipo>::EncolarInicio(Tipo valor)
{
    Elemento* nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->siguiente = primero; // Apunta al antiguo primero

    if (EstaVacia()) {
        tope = nuevo; // Si estaba vacía, tope y primero son el mismo
    }

    primero = nuevo; // El nuevo nodo es ahora el primero
    ++numElem;
}


template <typename Tipo>
void Lista<Tipo>::EncolarFinal(Tipo valor)
{
    Elemento* nuevo= new Elemento;
    if(EstaVacia())primero = nuevo;
    else tope->siguiente = nuevo;
    tope = nuevo;
    ++numElem;
}

template <typename Tipo>
void Lista<Tipo>::Vaciar()
{
    if(EstaVacia())return;
    while(!EstaVacia())DesencolarInicio();
}

template <typename Tipo>
void Lista<Tipo>::DesencolarInicio()
{
    if(EstaVacia())return;
    Elemento *aux = primero;
    primero = primero->siguiente;
    delete aux;
    --numElem;
}

template <typename Tipo>
bool Lista<Tipo>::EstaVacia()
{
    return numElem == 0;
}


template <typename Tipo>
void Lista<Tipo>::Imprimir()
{
    if (EstaVacia()) {
        std::cout << "Lista vacía\n";
        return;
    }

    Elemento *porImprimir = primero;
    std::cout << "Primero -> ";
    
    while (porImprimir != nullptr) {
        std::cout << porImprimir->valor << ", ";
        porImprimir = porImprimir->siguiente;
    }

    std::cout << "\b\b <- Último\n";
}
