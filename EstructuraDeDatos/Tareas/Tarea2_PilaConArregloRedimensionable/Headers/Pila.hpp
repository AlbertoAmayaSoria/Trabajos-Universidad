#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#define MAX_TAM 100
/**
 * Contenedor tipo LIFO de datos doble
 * \tparam Tipo Tipo de dato
 */
template <typename Tipo = int, int cap = 10>
class Pila{
public:
    /** \brief Constructor de la Pila. Genera una pila vac&iacute;a
     */
     Pila(); //dinamica----------------------------------------------------------------------------
    
     /** \brief Constructor de copias. Genera una copia de la Pila
      *
      * \param p. La pila a copiar
      */
     Pila(const Pila &p); //dinamica----------------------------------------------------------------------
    

    /** \brief Sobrecarga del operador = para que funcione con Pilas
      *
      * \param p Pila a igualar
      * \return Pila igualada
      */
     Pila & operator=(const Pila &p); //dinamica----------------------------------------------------------------
    

     /** \brief Destructor de un objeto Pila
      */
     ~Pila();


    /** \brief Permite agregar un elemento a la pila
     *
     * \param valor Valor a agregar
     * \return Ninguno
     * \exception const char * Cuando se intenta agregar en una pila llena
     */
    void Apilar(Tipo valor);

    /** \brief Permite eliminar un elemento de la pila
     *
     * \return Ninguno
     * \exception char * Cuando se intenta eliminar de una pila vac&iacute;a
     */
    void Desapilar();

    /** \brief Obtiene el elemento que se encuentra en el tope de la pila
     *
     * \return El valor del tope
     * \exception char * Cuando se intenta obtener el valor del tope de una pila vac&iacute;a
     */
    Tipo ObtenerTope() const;

    /** \brief Indica si la pila est&aacute; vac&iacute
     *
     * \return true si la pila est&aacute; vac&iacute;, false en caso contrario
     */
    bool EstaVacia() const;


    //este metodo no
    /** \brief Indica si la pila est&aacute; llena
     *
     * \return true si la pila est&aacute; llena, false en caso contrario
     *
     */
    bool EstaLlena() const;

    /** \brief Vac&iacute la pila
     *
     * \return Ninguno
     *
     */
    void Vaciar();

    /** \brief 
     *
     * return numero de elementos en la pila
     */
    int ElementosPila();

    /** \brief Capacidad de la pila
     *
     * return Capacidad de la pila
     */
    int CapacidadPila();

    /** \brief Imprime los elementos de la pla del fondo hasta el tope
     *
     * \return Ninguno
     *
     */
    void Imprimir() const; //para pruebas

private:
    Tipo elemento[cap];
    int tope;
}
;

#include "../Templates/Pila.tpp"

#endif // PILA_HPP_INCLUDED
