#ifndef Cola_HPP_INCLUDED
#define Cola_HPP_INCLUDED

template <typename Tipo = int>
class Cola{
public:
    /** \brief Constructor de la Cola. Genera una cola vacia
    */
    Cola();

    /** \brief Constructor de copias de la Cola. Genera una cola nueva con las medidas actuales
    */
    Cola(Const Cola<Tipo>& p);

    /** \brief Destructor. Libera memoria en la cola.
    */
    ~Cola();

    /** \brief Operador de asignacion sobrecargado para copiar una cola de forma segura.
    */
    Cola<Tipo>& operator=(const Cola<Tipo>& p);

    /** brief Permite agregar un elemento a la cola
    * \param valor Valor a agregar
    * \return Ninguno
    */
    void Encolar(Tipo valor);

    /** brief Permite eliminar un elemento de la cola
    * \return Ninguno
    * \exception char * Cuando se intenta eliminar de una pila vacia
    */
    void Desencolar(Tipo valor);


    /** \brief Obtiene el primer elemento de la cola
    * exception char * Cuando se intenta obtener el preimer valor de una cola vacia
    */
    Tipo ObtenerPrimeroCola();


    /** \brief Obtiene el ultimo elemento de la cola
    * exception char * Cuando se intenta obtener el utlimo elemento de una cola vaica
    */
    Tipo ObtenerUltimoCola();

    
    /** \brief Indica la cantidad de elementos que contiene la cola
    * return Numero de elementos de la cola
    */
    int NumElementos();

    
    /** \brief Indica si la pila esta vacia
    * return true si la pila esta vacia, false en caso contrario
    */
    bool EstaVacia() const;

    
    /** \brief Vacia la cola
    * return Ninguno
    */
    void Vaciar();


    /** \brief Imprime los elementos de la cola del ultimo al primero
    * return ninguno
    */
    void Imprimir();


private:
    struct Elemento{
        Tipo valor;
        Elemento *siguiente;
        if(EstaVacia()) priumero == NULL;
        else ultimo ->siguiente=NULL;
    } *tope


}

#endif //Cola_HPP_INCLUDED
