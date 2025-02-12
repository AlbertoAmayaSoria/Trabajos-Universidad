#include <iostream>

//************************************************************************************************
template <typename Tipo>
Cola<Tipo>::Cola() : numElem(0) , primero(NULL) , ultimo(NULL) {}
//************************************************************************************************
template <typename Tipo>
Cola<Tipo>::Cola(const Cola<Tipo>& c)
{
    *this = c;
}
//************************************************************************************************
template <typename Tipo>
Cola<Tipo>::~Cola()
{
    Vaciar();
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
void Cola<Tipo>::Encolar(Tipo valor)
{
    Elemento *nuevo = new Elemento;
    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    if(EstaVacia()) primero = nuevo;
    else ultimo->siguiente = nuevo;
    ultimo = nuevo;
    ++numElem;
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
void Cola<Tipo>::Desencolar()
{
    if(EstaVacia()) throw "Cola vac\241a...\n";
    Elemento *porBorrar = primero;
    primero = primero->siguiente;
    if(numElem == 1) ultimo = NULL;
    delete porBorrar;
    --numElem;
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
Tipo Cola<Tipo>::ConocerPrim() const
{
    if(EstaVacia()) throw "Cola vac\241a...\n";
    return primero->valor;
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
Tipo Cola<Tipo>::ConocerUlt() const
{
    if(EstaVacia()) throw "Cola vac\241a...\n";
    return ultimo->valor;
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
bool Cola<Tipo>::EstaVacia() const
{
    return numElem == 0;
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
void Cola<Tipo>::Vaciar()
{
    while(!EstaVacia()) Desencolar();
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
int Cola<Tipo>::ObtenerCantElem() const
{
    return numElem;
}
//************************************************************************************************
template <typename Tipo/*  = int*/>
void Cola<Tipo>::Imprimir() const
{
    Elemento *porImprimir = primero;
    std::cout << "Primero -> ";
    for(int i = 0; i < numElem; ++i){
        std::cout << porImprimir->valor;
        std::cout << ", ";
        porImprimir = porImprimir->siguiente;
    }
    std::cout << "\b\b <- \351ltimo\n";
}
//************************************************************************************************
template <typename Tipo>
Cola<Tipo>& Cola<Tipo>::operator=(const Cola<Tipo>& c)
{
    if (this == &c) return *this;
    this->Vaciar();
    Elemento *copia;
    copia = c.primero;
    for(int i = 0; i < c.numElem; ++i){
        Encolar(copia->valor);
        copia = copia->siguiente;
    }

    return *this;
}
//************************************************************************************************
