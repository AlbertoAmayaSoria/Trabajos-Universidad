#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

template <typename Tipo = int>
class Cola{
public:
    /** \brief Constructor de la Cola. Genera una cola vac&iacute;a
     */
     Cola(); //dinamica-----------------------------------------------------------------------------

    /** \brief Constructor de copias de la cola. Genera una cola nueva con las medidas actuales
     */
     Cola(const Cola<Tipo>& c);

     /** \brief Destructor. Libera memoria en la cola.
     */
    ~Cola();

    /** \brief Operador de asignacion sobrecargado para copiar una cola de forma segura.
     */
    Cola<Tipo>& operator=(const Cola<Tipo>& c);

    /** \brief Permite agregar un elemento a la cola
     *
     * \param valor Valor a agregar
     * \return Ninguno
     */
    void Encolar(Tipo valor);

    /** \brief Permite eliminar un elemento de la cola
     *
     * \return Ninguno
     * \exception char * Cuando se intenta eliminar de una cola vac&iacute;a
     */
    void Desencolar();

    /** \brief Indica si la cola est&aacute; vac&iacute;a
     *
     * \return true si la cola est&aacute; vac&iacute;a, false en caso contrario
     */
    bool EstaVacia() const;

    /** \brief Vac&iacute;a la cola
     *
     * \return Ninguno
     */
    void Vaciar();

    /** \brief Indica el n&uacute;mero de elementos que tiene la cola
     *
     * \return N&uacute;mero de elementos en la cola
     */
    int ObtenerCantElem() const;

    // Para pruebas
    /** \brief Imprime los elementos de la cola del fondo hasta el tope
     *
     * \return Ninguno
     */
    void Imprimir() const;

    /** \brief Obtiene el elemento que se encuentra al principio de la cola
     *
     * \return El valor del primer elemento de la cola
     * \exception char * Cuando se intenta obtener el valor de una cola vac&iacute;a
     */
    Tipo ConocerPrim() const;

    /** \brief Obtiene el elemento que se encuentra al final de la cola
     *
     * \return El valor del &uacute;ltimo elemento de la cola
     * \exception char * Cuando se intenta obtener el valor de una cola vac&iacute;a
     */
    Tipo ConocerUlt() const;



private:
    int numElem;

    struct Elemento{
        Tipo valor;
        Elemento *siguiente;
    } * primero, * ultimo;


};
#include "../Templates/Cola.tpp"

#endif // COLA_HPP_INCLUDED
