
#include "iostream"
/**
 * @file Pila.tpp
 * @brief Implementación de la clase plantilla Pila (LIFO)
 */

#include <iostream>

/**
 * @brief Constructor por defecto de la pila.
 *
 * Inicializa una pila vacía con una capacidad predeterminada.
 */
template <typename Tipo>
Pila<Tipo>::Pila() : tope(-1), capacidad(5) {
    // Inicializa una pila vacía con una capacidad predeterminada (5 por defecto)
    elemento = new Tipo[capacidad];
}

/**
 * @brief Constructor de copia.
 * @param p Pila a copiar.
 *
 * Crea una copia exacta de otra pila, copiando sus elementos y capacidad.
 */
template <typename Tipo>
Pila<Tipo>::Pila(const Pila &p) : tope(p.tope), capacidad(p.capacidad) {
    // Asigna la capacidad de la pila fuente
    elemento = new Tipo[capacidad];
    for (int i = 0; i <= tope; ++i) {
        elemento[i] = p.elemento[i];
    }
}

/**
 * @brief Sobrecarga del operador de asignación.
 * @param p Pila a asignar.
 * @return Referencia a la pila asignada.
 *
 * Realiza una copia de los elementos y ajusta la capacidad si es necesario.
 */
template <typename Tipo>
Pila<Tipo>& Pila<Tipo>::operator=(const Pila<Tipo>& p) {
    if (this == &p) return *this;

    // Liberar la memoria del arreglo actual
    delete[] elemento;

    // Si la capacidad de la pila fuente es mayor que la de la pila destino, redimensionar
    if (capacidad < p.capacidad) {
        // Redimensionar el arreglo
        capacidad = p.capacidad;
        elemento = new Tipo[capacidad];
    } else {
        // Usar la capacidad original si la pila fuente no excede el tamaño de la pila destino
        elemento = new Tipo[capacidad];
    }

    // Copiar los elementos de la pila fuente a la pila destino
    tope = p.tope;
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
template <typename Tipo>
Pila<Tipo>::~Pila() {
    delete[] elemento;
}

/**
 * @brief Agrega un elemento a la pila.
 * @param valor Elemento a agregar.
 * @throw const char* Excepción si la pila está llena.
 */
template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor) {
    if (EstaLlena()) {
        // Redimensionar si la pila está llena
        Redimensionar();
    }
    elemento[++tope] = valor;
}

/**
 * @brief Elimina el elemento en el tope de la pila.
 * @throw const char* Excepción si la pila está vacía.
 */
template <typename Tipo>
void Pila<Tipo>::Desapilar() {
    if (EstaVacia()) throw "Pila vacía...";
    --tope;
}

/**
 * @brief Obtiene el elemento en el tope de la pila.
 * @return Elemento en el tope.
 * @throw const char* Excepción si la pila está vacía.
 */
template <typename Tipo>
Tipo Pila<Tipo>::ObtenerTope() const {
    if (EstaVacia()) throw "Pila vacía...";
    return elemento[tope];
}

/**
 * @brief Verifica si la pila está vacía.
 * @return true si está vacía, false en caso contrario.
 */
template <typename Tipo>
bool Pila<Tipo>::EstaVacia() const {
    return tope == -1;
}

/**
 * @brief Vacía la pila eliminando todos los elementos.
 */
template <typename Tipo>
void Pila<Tipo>::Vaciar() {
    tope = -1;
}

/**
 * @brief Obtiene la cantidad de elementos en la pila.
 * @return Número de elementos en la pila.
 */
template <typename Tipo>
int Pila<Tipo>::ElementosPila() const {
    return tope + 1;
}

/**
 * @brief Obtiene la capacidad máxima de la pila.
 * @return Capacidad de la pila.
 */
template <typename Tipo>
int Pila<Tipo>::CapacidadPila() const {
    return capacidad;
}

/**
 * @brief Imprime los elementos de la pila.
 *
 * Muestra los elementos de la pila desde el fondo hasta el tope.
 */
template <typename Tipo>
void Pila<Tipo>::Imprimir() const {
    for (int i = 0; i <= tope; ++i) {
        std::cout << elemento[i];
        if (i < tope) std::cout << ", ";
    }
    std::cout << " <- TOPE\n";
}

/**
 * @brief Redimensiona la pila.
 *
 * Duplica la capacidad de la pila cuando esta se llena.
 */
template <typename Tipo>
void Pila<Tipo>::Redimensionar() {
    // Doblar la capacidad actual
    capacidad *= 2;
    Tipo* nuevoElemento = new Tipo[capacidad];

    // Copiar los elementos existentes
    for (int i = 0; i <= tope; ++i) {
        nuevoElemento[i] = elemento[i];
    }

    // Liberar el antiguo arreglo
    delete[] elemento;

    // Actualizar el puntero al nuevo arreglo
    elemento = nuevoElemento;
}

/**
 * @brief Verifica si la pila está llena.
 * @return true si está llena, false en caso contrario.
 */
template <typename Tipo>
bool Pila<Tipo>::EstaLlena() const {
    return tope + 1 == capacidad;
}

