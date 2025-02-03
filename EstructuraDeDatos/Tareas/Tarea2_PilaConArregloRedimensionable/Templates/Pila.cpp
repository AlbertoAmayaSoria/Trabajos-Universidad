#include "iostream"
/**
 * @file Pila.tpp
 * @brief Implementación de la clase plantilla Pila (LIFO)
 */

#include <iostream>

/**
 * @brief Constructor por defecto de la pila.
 *
 * Inicializa una pila vacía con una capacidad fija.
 */
template <typename Tipo, int cap>
Pila<Tipo, cap>::Pila() : tope(-1) {
    elemento = new Tipo[cap];
}

/**
 * @brief Constructor de copia.
 * @param p Pila a copiar.
 *
 * Crea una copia exacta de otra pila, copiando sus elementos.
 */
template <typename Tipo, int cap>
Pila<Tipo, cap>::Pila(const Pila &p) : tope(p.tope) {
    elemento = new Tipo[cap];
    for (int i = 0; i <= tope; ++i) {
        elemento[i] = p.elemento[i];
    }
}

/**
 * @brief Sobrecarga del operador de asignación.
 * @param p Pila a asignar.
 * @return Referencia a la pila asignada.
 */
template <typename Tipo, int cap>
Pila<Tipo, cap> & Pila<Tipo, cap>::operator=(const Pila<Tipo, cap> &p) {
    if (this == &p) return *this;

    delete[] elemento;
    tope = p.tope;
    elemento = new Tipo[cap];
    for (int i = 0; i <= tope; ++i) {
        elemento[i] = p.elemento[i];
    }
    return *this;
}

/**
 * @brief Destructor de la pila.
 *
 * Libera la memoria asignada dinámicamente.
 */
template <typename Tipo, int cap>
Pila<Tipo, cap>::~Pila() {
    delete[] elemento;
}

/**
 * @brief Agrega un elemento a la pila.
 * @param valor Elemento a agregar.
 * @throw const char* Excepción si la pila está llena.
 */
template <typename Tipo, int cap>
void Pila<Tipo, cap>::Apilar(Tipo valor) {
    elemento[++tope] = valor;
}

/**
 * @brief Elimina el elemento en el tope de la pila.
 * @throw const char* Excepción si la pila está vacía.
 */
template <typename Tipo, int cap>
void Pila<Tipo, cap>::Desapilar() {
    if (EstaVacia()) throw "Pila vacía...";
    --tope;
}

/**
 * @brief Obtiene el elemento en el tope de la pila.
 * @return Elemento en el tope.
 * @throw const char* Excepción si la pila está vacía.
 */
template <typename Tipo, int cap>
Tipo Pila<Tipo, cap>::ObtenerTope() const {
    if (EstaVacia()) throw "Pila vacía...";
    return elemento[tope];
}

/**
 * @brief Verifica si la pila está vacía.
 * @return true si está vacía, false en caso contrario.
 */
template <typename Tipo, int cap>
bool Pila<Tipo, cap>::EstaVacia() const {
    return tope == -1;
}

/**
 * @brief Vacía la pila eliminando todos los elementos.
 */
template <typename Tipo, int cap>
void Pila<Tipo, cap>::Vaciar() {
    tope = -1;
}

/**
 * @brief Obtiene la cantidad de elementos en la pila.
 * @return Número de elementos en la pila.
 */
template <typename Tipo, int cap>
int Pila<Tipo, cap>::ElementosPila() const {
    return tope + 1;
}

/**
 * @brief Obtiene la capacidad máxima de la pila.
 * @return Capacidad de la pila.
 */
template <typename Tipo, int cap>
int Pila<Tipo, cap>::CapacidadPila() const {
    return cap;
}

/**
 * @brief Imprime los elementos de la pila.
 *
 * Muestra los elementos de la pila desde el fondo hasta el tope.
 */
template <typename Tipo, int cap>
void Pila<Tipo, cap>::Imprimir() const {
    for (int i = 0; i <= tope; ++i) {
        std::cout << elemento[i];
        if (i < tope) std::cout << ", ";
    }
    std::cout << " <- TOPE\n";
}

