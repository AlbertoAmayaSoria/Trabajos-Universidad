// Constructor
template <typename T>
ListaEnlazada<T>::ListaEnlazada() : primero(nullptr), ultimo(nullptr), tamaño(0) {
    // Inicializa una lista vacía. El primer nodo y el último nodo son nullptr,
    // y el tamaño es 0.
}

// Constructor de copias
template <typename T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada& otra) : primero(nullptr), ultimo(nullptr), tamaño(0) {
    // Usamos el operador de asignación para copiar los datos de otra lista.
    *this = otra; // Reutilizamos el operador de asignación
}

// Destructor
template <typename T>
ListaEnlazada<T>::~ListaEnlazada() {
    // Liberamos la memoria de todos los nodos de la lista.
    while (primero) {
        Nodo* temp = primero;
        primero = primero->siguiente;
        delete temp; // Eliminamos el nodo actual
    }
}

// Sobrecarga del operador =
template <typename T>
ListaEnlazada<T>& ListaEnlazada<T>::operator=(const ListaEnlazada& otra) {
    // Evitar autoasignación (si la lista se asigna a sí misma)
    if (this == &otra) return *this;

    // Liberamos la memoria de la lista actual
    while (primero) {
        Nodo* temp = primero;
        primero = primero->siguiente;
        delete temp;
    }
    tamaño = 0;

    // Copiamos los nodos de la lista "otra"
    if (!otra.primero) {
        primero = nullptr;
        ultimo = nullptr;
        return *this;
    }

    // Copiamos los nodos de la otra lista
    primero = new Nodo(otra.primero->dato);  // Creamos el primer nodo
    Nodo* actual = primero;
    Nodo* otraActual = otra.primero->siguiente;

    // Copiamos el resto de los nodos
    while (otraActual) {
        actual->siguiente = new Nodo(otraActual->dato);
        actual = actual->siguiente;
        otraActual = otraActual->siguiente;
    }

    // Apuntamos el último nodo
    ultimo = actual;
    tamaño = otra.tamaño; // Copiamos el tamaño
    return *this;
}

//*******************************************************************

// Insertar al inicio
template <typename T>
void ListaEnlazada<T>::insertarInicio(T valor) {
    // Creamos un nuevo nodo con el valor dado
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = primero; // El siguiente del nuevo nodo apunta al primero actual
    primero = nuevo; // El primero ahora apunta al nuevo nodo

    // Si la lista estaba vacía, el último nodo también debe ser el nuevo
    if (!ultimo) {
        ultimo = nuevo;
    }

    tamaño++; // Incrementamos el tamaño de la lista
}

// Insertar al final
template <typename T>
void ListaEnlazada<T>::insertarFinal(T valor) {
    Nodo* nuevo = new Nodo(valor); // Creamos un nuevo nodo con el valor dado
    if (!primero) {
        primero = nuevo;
        ultimo = nuevo; // Si la lista está vacía, primero y último apuntan al nuevo nodo
    } else {
        ultimo->siguiente = nuevo; // El siguiente del último nodo apunta al nuevo
        ultimo = nuevo; // El último nodo ahora es el nuevo
    }
    tamaño++; // Incrementamos el tamaño de la lista
}

// Insertar en una posición específica
template <typename T>
void ListaEnlazada<T>::insertarPosicion(T valor, size_t pos) {
    if (pos > tamaño) {
        std::cerr << "Posición inválida\n";
        return;
    }

    // Si la posición es 0, insertamos al inicio
    if (pos == 0) {
        insertarInicio(valor);
        return;
    }

    // Creamos el nuevo nodo
    Nodo* nuevo = new Nodo(valor);
    Nodo* temp = primero;

    // Buscamos el nodo en la posición dada
    for (size_t i = 0; i < pos - 1; ++i) {
        temp = temp->siguiente;
    }

    // Insertamos el nuevo nodo en la posición correcta
    nuevo->siguiente = temp->siguiente;
    temp->siguiente = nuevo;

    // Si se insertó al final, actualizamos el puntero último
    if (!nuevo->siguiente) {
        ultimo = nuevo;
    }

    tamaño++; // Incrementamos el tamaño de la lista
}

//*******************************************************************

// Eliminar el primer nodo
template <typename T>
void ListaEnlazada<T>::eliminarInicio() {
    if (!primero) return; // Si la lista está vacía, no hacemos nada

    // Eliminamos el primero y actualizamos el puntero primero
    Nodo* temp = primero;
    primero = primero->siguiente;

    if (!primero) {
        ultimo = nullptr; // Si la lista se vacía, el último también debe ser nullptr
    }

    delete temp; // Liberamos la memoria del nodo eliminado
    tamaño--; // Decrementamos el tamaño de la lista
}

// Eliminar el último nodo
template <typename T>
void ListaEnlazada<T>::eliminarFinal() {
    if (!primero) return; // Si la lista está vacía, no hacemos nada

    if (!primero->siguiente) {
        // Si la lista tiene un solo nodo, eliminamos el primero y vaciamos la lista
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
    } else {
        // Eliminamos el último nodo
        Nodo* temp = primero;
        while (temp->siguiente != ultimo) {
            temp = temp->siguiente; // Nos movemos hasta el penúltimo nodo
        }

        delete ultimo;
        temp->siguiente = nullptr; // El penúltimo nodo ahora es el último
        ultimo = temp; // Actualizamos el puntero último
    }

    tamaño--; // Decrementamos el tamaño de la lista
}

// Eliminar por posición
template <typename T>
void ListaEnlazada<T>::eliminarPosicion(size_t pos) {
    if (pos >= tamaño) {
        std::cerr << "Posición inválida\n";
        return;
    }

    if (pos == 0) {
        eliminarInicio();
        return;
    }

    // Buscamos el nodo en la posición dada
    Nodo* temp = primero;
    for (size_t i = 0; i < pos - 1; ++i) {
        temp = temp->siguiente;
    }

    Nodo* nodoAEliminar = temp->siguiente;
    temp->siguiente = nodoAEliminar->siguiente; // Conectamos el anterior con el siguiente del nodo a eliminar
    if (!temp->siguiente) {
        // Si se eliminó el último, actualizamos el puntero último
        ultimo = temp;
    }

    delete nodoAEliminar; // Liberamos la memoria del nodo eliminado
    tamaño--; // Decrementamos el tamaño de la lista
}

// Eliminar por valor
template <typename T>
void ListaEnlazada<T>::eliminarValor(T valor) {
    if (!primero) return; // Si la lista está vacía, no hacemos nada

    if (primero->dato == valor) {
        eliminarInicio();
        return;
    }

    // Buscamos el nodo con el valor dado
    Nodo* temp = primero;
    while (temp->siguiente && temp->siguiente->dato != valor) {
        temp = temp->siguiente;
    }

    if (temp->siguiente) {
        // Si encontramos el nodo, lo eliminamos
        Nodo* nodoAEliminar = temp->siguiente;
        temp->siguiente = nodoAEliminar->siguiente; // Conectamos el anterior con el siguiente
        if (!temp->siguiente) {
            // Si se eliminó el último, actualizamos el puntero último
            ultimo = temp;
        }

        delete nodoAEliminar; // Liberamos la memoria del nodo eliminado
        tamaño--; // Decrementamos el tamaño de la lista
    }
}

//*******************************************************************

// Buscar un elemento
template <typename T>
bool ListaEnlazada<T>::buscar(T valor) {
    Nodo* temp = primero;
    while (temp) {
        if (temp->dato == valor) return true; // Si encontramos el valor, retornamos true
        temp = temp->siguiente; // Continuamos con el siguiente nodo
    }
    return false; // Si no encontramos el valor, retornamos false
}

//*******************************************************************

// Obtener el primer elemento de la lista
template <typename T>
T ListaEnlazada<T>::obtenerPrimero() const {
    if (!primero) {
        throw std::out_of_range("La lista está vacía."); // Lanzamos excepción si la lista está vacía
    }
    return primero->dato; // Retornamos el dato del primer nodo
}

// Obtener el último elemento de la lista
template <typename T>
T ListaEnlazada<T>::obtenerUltimo() const {
    if (!ultimo) {
        throw std::out_of_range("La lista está vacía."); // Lanzamos excepción si la lista está vacía
    }
    return ultimo->dato; // Retornamos el dato del último nodo
}

// Obtener un elemento en una posición específica
template <typename T>
T ListaEnlazada<T>::obtenerEnPosicion(size_t posicion) const {
    if (posicion >= tamaño) {
        throw std::out_of_range("Índice fuera de rango."); // Lanzamos excepción si la posición está fuera de rango
    }

    Nodo* actual = primero;
    for (size_t i = 0; i < posicion; ++i) {
        actual = actual->siguiente; // Nos movemos hasta la posición deseada
    }

    return actual->dato; // Retornamos el dato del nodo en la posición especificada
}

// Obtener el índice de un elemento en la lista
template <typename T>
int ListaEnlazada<T>::obtenerIndice(const T& valor) const {
    Nodo* actual = primero;
    int indice = 0;

    while (actual) {
        if (actual->dato == valor) {
            return indice; // Se encontró el elemento, retornamos su índice
        }
        actual = actual->siguiente; // Continuamos con el siguiente nodo
        indice++;
    }

    return -1; // Si no se encuentra el valor, retornamos -1
}

//*******************************************************************

// Obtener tamaño
template <typename T>
size_t ListaEnlazada<T>::obtenerTamaño() const {
    return tamaño; // Retornamos el tamaño de la lista
}

//*******************************************************************

// Imprimir lista
template <typename T>
void ListaEnlazada<T>::imprimir() const {
    Nodo* temp = primero;
    while (temp) {
        std::cout << temp->dato << " -> "; // Imprimimos el dato del nodo y el enlace a siguiente
        temp = temp->siguiente;
    }
    std::cout << "NULL\n"; // Imprimimos NULL al final para indicar que hemos llegado al final de la lista
}

