// Constructor
template <typename T>
ListaDoblementeEnlazada<T>::ListaDoblementeEnlazada() : cabeza(nullptr), ultimo(nullptr), tamaño(0) {
    // Inicializa una lista vacía. La cabeza y el último nodo son nullptr,
    // y el tamaño es 0.
}

// Constructor de copias
template <typename T>
ListaDoblementeEnlazada<T>::ListaDoblementeEnlazada(const ListaDoblementeEnlazada& otra) : cabeza(nullptr), ultimo(nullptr), tamaño(0) {
    // Usamos el operador de asignación para copiar los datos de otra lista.
    *this = otra; // Reutilizamos el operador de asignación
}

// Destructor
template <typename T>
ListaDoblementeEnlazada<T>::~ListaDoblementeEnlazada() {
    // Liberamos la memoria de todos los nodos de la lista.
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp; // Eliminamos el nodo actual
    }
}

// Sobrecarga del operador =
template <typename T>
ListaDoblementeEnlazada<T>& ListaDoblementeEnlazada<T>::operator=(const ListaDoblementeEnlazada& otra) {
    // Evitar autoasignación (si la lista se asigna a sí misma)
    if (this == &otra) return *this;

    // Liberamos la memoria de la lista actual
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    tamaño = 0;

    // Copiamos los nodos de la lista "otra"
    if (!otra.cabeza) {
        cabeza = nullptr;
        ultimo = nullptr;
        return *this;
    }

    // Copiamos los nodos de la otra lista
    cabeza = new Nodo(otra.cabeza->dato);  // Creamos el primer nodo
    Nodo* actual = cabeza;
    Nodo* otraActual = otra.cabeza->siguiente;

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
void ListaDoblementeEnlazada<T>::insertarInicio(T valor) {
    // Creamos un nuevo nodo con el valor dado
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = cabeza; // El siguiente del nuevo nodo apunta a la cabeza actual
    if (cabeza) {
        cabeza->anterior = nuevo; // Actualizamos el anterior de la cabeza
    }
    cabeza = nuevo; // La cabeza ahora apunta al nuevo nodo

    // Si la lista estaba vacía, el último nodo también debe ser el nuevo
    if (!ultimo) {
        ultimo = nuevo;
    }

    tamaño++; // Incrementamos el tamaño de la lista
}

// Insertar al final
template <typename T>
void ListaDoblementeEnlazada<T>::insertarFinal(T valor) {
    Nodo* nuevo = new Nodo(valor); // Creamos un nuevo nodo con el valor dado
    if (!cabeza) {
        cabeza = nuevo;
        ultimo = nuevo; // Si la lista está vacía, cabeza y último apuntan al nuevo nodo
    } else {
        ultimo->siguiente = nuevo; // El siguiente del último nodo apunta al nuevo
        nuevo->anterior = ultimo; // El anterior del nuevo nodo apunta al último nodo
        ultimo = nuevo; // El último nodo ahora es el nuevo
    }
    tamaño++; // Incrementamos el tamaño de la lista
}

// Insertar en una posición específica
template <typename T>
void ListaDoblementeEnlazada<T>::insertarPosicion(T valor, size_t pos) {
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
    Nodo* temp = cabeza;

    // Buscamos el nodo en la posición dada
    for (size_t i = 0; i < pos - 1; ++i) {
        temp = temp->siguiente;
    }

    // Insertamos el nuevo nodo en la posición correcta
    nuevo->siguiente = temp->siguiente;
    if (temp->siguiente) {
        temp->siguiente->anterior = nuevo; // Actualizamos el anterior del siguiente nodo
    }
    temp->siguiente = nuevo; // El nodo actual apunta al nuevo nodo
    nuevo->anterior = temp; // El nuevo nodo apunta al nodo actual

    // Si se insertó al final, actualizamos el puntero último
    if (!nuevo->siguiente) {
        ultimo = nuevo;
    }

    tamaño++; // Incrementamos el tamaño de la lista
}

//*******************************************************************

// Eliminar el primer nodo
template <typename T>
void ListaDoblementeEnlazada<T>::eliminarInicio() {
    if (!cabeza) return; // Si la lista está vacía, no hacemos nada

    // Eliminamos la cabeza y actualizamos el puntero cabeza
    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;

    if (cabeza) {
        cabeza->anterior = nullptr; // Actualizamos el anterior de la nueva cabeza
    } else {
        ultimo = nullptr; // Si la lista se vacía, el último también debe ser nullptr
    }

    delete temp; // Liberamos la memoria del nodo eliminado
    tamaño--; // Decrementamos el tamaño de la lista
}

// Eliminar el último nodo
template <typename T>
void ListaDoblementeEnlazada<T>::eliminarFinal() {
    if (!cabeza) return; // Si la lista está vacía, no hacemos nada

    if (!cabeza->siguiente) {
        // Si la lista tiene un solo nodo, eliminamos la cabeza y vaciamos la lista
        delete cabeza;
        cabeza = nullptr;
        ultimo = nullptr;
    } else {
        // Eliminamos el último nodo
        Nodo* temp = ultimo;
        ultimo = ultimo->anterior;
        ultimo->siguiente = nullptr; // Actualizamos el siguiente del nuevo último
        delete temp; // Liberamos la memoria del nodo eliminado
    }

    tamaño--; // Decrementamos el tamaño de la lista
}

// Eliminar por posición
template <typename T>
void ListaDoblementeEnlazada<T>::eliminarPosicion(size_t pos) {
    if (pos >= tamaño) {
        std::cerr << "Posición inválida\n";
        return;
    }

    if (pos == 0) {
        eliminarInicio();
        return;
    }

    // Buscamos el nodo en la posición dada
    Nodo* temp = cabeza;
    for (size_t i = 0; i < pos - 1; ++i) {
        temp = temp->siguiente;
    }

    Nodo* nodoAEliminar = temp->siguiente;
    temp->siguiente = nodoAEliminar->siguiente; // Conectamos el anterior con el siguiente del nodo a eliminar
    if (nodoAEliminar->siguiente) {
        nodoAEliminar->siguiente->anterior = temp; // Actualizamos el anterior del siguiente nodo
    }

    if (!temp->siguiente) {
        // Si se eliminó el último, actualizamos el puntero último
        ultimo = temp;
    }

    delete nodoAEliminar; // Liberamos la memoria del nodo eliminado
    tamaño--; // Decrementamos el tamaño de la lista
}

// Eliminar por valor
template <typename T>
void ListaDoblementeEnlazada<T>::eliminarValor(T valor) {
    if (!cabeza) return; // Si la lista está vacía, no hacemos nada

    if (cabeza->dato == valor) {
        eliminarInicio();
        return;
    }

    // Buscamos el nodo con el valor dado
    Nodo* temp = cabeza;
    while (temp->siguiente && temp->siguiente->dato != valor) {
        temp = temp->siguiente;
    }

    if (temp->siguiente) {
        // Si encontramos el nodo, lo eliminamos
        Nodo* nodoAEliminar = temp->siguiente;
        temp->siguiente = nodoAEliminar->siguiente; // Conectamos el anterior con el siguiente
        if (nodoAEliminar->siguiente) {
            nodoAEliminar->siguiente->anterior = temp; // Actualizamos el anterior del siguiente nodo
        }

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
bool ListaDoblementeEnlazada<T>::buscar(T valor) {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->dato == valor) return true; // Si encontramos el valor, retornamos true
        temp = temp->siguiente; // Continuamos con el siguiente nodo
    }
    return false; // Si no encontramos el valor, retornamos false
}

//*******************************************************************

// Obtener el primer elemento de la lista
template <typename T>
T ListaDoblementeEnlazada<T>::obtenerPrimero() const {
    if (!cabeza) {
        throw std::out_of_range("La lista está vacía."); // Lanzamos excepción si la lista está vacía
    }
    return cabeza->dato; // Retornamos el dato de la cabeza
}

// Obtener el último elemento de la lista
template <typename T>
T ListaDoblementeEnlazada<T>::obtenerUltimo() const {
    if (!ultimo) {
        throw std::out_of_range("La lista está vacía."); // Lanzamos excepción si la lista está vacía
    }
    return ultimo->dato; // Retornamos el dato del último nodo
}

// Obtener un elemento en una posición específica
template <typename T>
T ListaDoblementeEnlazada<T>::obtenerEnPosicion(size_t posicion) const {
    if (posicion >= tamaño) {
        throw std::out_of_range("Índice fuera de rango."); // Lanzamos excepción si la posición está fuera de rango
    }

    Nodo* actual = cabeza;
    for (size_t i = 0; i < posicion; ++i) {
        actual = actual->siguiente; // Nos movemos hasta la posición deseada
    }

    return actual->dato; // Retornamos el dato del nodo en la posición especificada
}

// Obtener el índice de un elemento en la lista
template <typename T>
int ListaDoblementeEnlazada<T>::obtenerIndice(const T& valor) const {
    Nodo* actual = cabeza;
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
size_t ListaDoblementeEnlazada<T>::obtenerTamaño() const {
    return tamaño; // Retornamos el tamaño de la lista
}

//*******************************************************************

// Imprimir lista
template <typename T>
void ListaDoblementeEnlazada<T>::imprimir() const {
    Nodo* temp = cabeza;
    while (temp) {
        std::cout << temp->dato << " <-> "; // Imprimimos el dato del nodo y el enlace a siguiente
        temp = temp->siguiente;
    }
    std::cout << "NULL\n"; // Imprimimos NULL al final para indicar que hemos llegado al final de la lista
}

