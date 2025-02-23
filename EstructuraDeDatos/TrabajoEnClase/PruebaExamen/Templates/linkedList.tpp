
// Constructor
template <typename T>
LinkedList<T>::LinkedList() : cabeza(nullptr), tamaño(0) {}


// Constructor de copias
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& otra) : cabeza(nullptr), tamaño(0) {
    *this = otra; // Reutilizamos el operador de asignación
}


// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// Sobrecarga del operador =
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& otra) {
    if (this == &otra) return *this; // Evitar autoasignación

    // Primero, liberamos la memoria de la lista actual
    while (cabeza) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    tamaño = 0;

    // Luego, copiamos los nodos de "otra"
    if (!otra.cabeza) {
        cabeza = nullptr;
        return *this;
    }

    cabeza = new Nodo(otra.cabeza->dato);
    Nodo* actual = cabeza;
    Nodo* otraActual = otra.cabeza->siguiente;

    while (otraActual) {
        actual->siguiente = new Nodo(otraActual->dato);
        actual = actual->siguiente;
        otraActual = otraActual->siguiente;
    }

    tamaño = otra.tamaño;
    return *this;
}

//*******************************************************************

// Insertar al inicio
template <typename T>
void LinkedList<T>::insertarInicio(T valor) {
    Nodo* nuevo = new Nodo(valor);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
    tamaño++;
}

// Insertar al final
template <typename T>
void LinkedList<T>::insertarFinal(T valor) {
    Nodo* nuevo = new Nodo(valor);
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    tamaño++;
}

// Insertar en una posición específica
template <typename T>
void LinkedList<T>::insertarPosicion(T valor, size_t pos) {
    if (pos > tamaño) {
        std::cerr << "Posición inválida\n";
        return;
    }
    if (pos == 0) {
        insertarInicio(valor);
        return;
    }
    Nodo* nuevo = new Nodo(valor);
    Nodo* temp = cabeza;
    for (size_t i = 0; i < pos - 1; ++i) {
        temp = temp->siguiente;
    }
    nuevo->siguiente = temp->siguiente;
    temp->siguiente = nuevo;
    tamaño++;
}

//*******************************************************************

// Eliminar el primer nodo
template <typename T>
void LinkedList<T>::eliminarInicio() {
    if (!cabeza) return;
    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;
    delete temp;
    tamaño--;
}

// Eliminar el último nodo
template <typename T>
void LinkedList<T>::eliminarFinal() {
    if (!cabeza) return;
    if (!cabeza->siguiente) {
        delete cabeza;
        cabeza = nullptr;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente->siguiente) {
            temp = temp->siguiente;
        }
        delete temp->siguiente;
        temp->siguiente = nullptr;
    }
    tamaño--;
}

// Eliminar por posición
template <typename T>
void LinkedList<T>::eliminarPosicion(size_t pos) {
    if (pos >= tamaño) {
        std::cerr << "Posición inválida\n";
        return;
    }
    if (pos == 0) {
        eliminarInicio();
        return;
    }
    Nodo* temp = cabeza;
    for (size_t i = 0; i < pos - 1; ++i) {
        temp = temp->siguiente;
    }
    Nodo* nodoAEliminar = temp->siguiente;
    temp->siguiente = nodoAEliminar->siguiente;
    delete nodoAEliminar;
    tamaño--;
}

// Eliminar por valor
template <typename T>
void LinkedList<T>::eliminarValor(T valor) {
    if (!cabeza) return;
    if (cabeza->dato == valor) {
        eliminarInicio();
        return;
    }
    Nodo* temp = cabeza;
    while (temp->siguiente && temp->siguiente->dato != valor) {
        temp = temp->siguiente;
    }
    if (temp->siguiente) {
        Nodo* nodoAEliminar = temp->siguiente;
        temp->siguiente = nodoAEliminar->siguiente;
        delete nodoAEliminar;
        tamaño--;
    }
}


//*******************************************************************

// Buscar un elemento
template <typename T>
bool LinkedList<T>::buscar(T valor) {
    Nodo* temp = cabeza;
    while (temp) {
        if (temp->dato == valor) return true;
        temp = temp->siguiente;
    }
    return false;
}


//*******************************************************************

// Obtener el primer elemento de la lista
template <typename T>
T LinkedList<T>::obtenerPrimero() const {
    if (!cabeza) {
        throw std::out_of_range("La lista está vacía.");
    }
    return cabeza->dato;
}


// Obtener el último elemento de la lista
template <typename T>
T LinkedList<T>::obtenerUltimo() const {
    if (!cabeza) {
        throw std::out_of_range("La lista está vacía.");
    }

    Nodo* temp = cabeza;
    while (temp->siguiente) {
        temp = temp->siguiente;
    }

    return temp->dato;
}


// Obtener un elemento en una posición específica
template <typename T>
T LinkedList<T>::obtenerEnPosicion(size_t posicion) const {
    if (posicion >= tamaño) {
        throw std::out_of_range("Índice fuera de rango.");
    }

    Nodo* actual = cabeza;
    for (size_t i = 0; i < posicion; ++i) {
        actual = actual->siguiente;
    }

    return actual->dato;
}


// Obtener el índice de un elemento en la lista
template <typename T>
int LinkedList<T>::obtenerIndice(const T& valor) const {
    Nodo* actual = cabeza;
    int indice = 0;

    while (actual) {
        if (actual->dato == valor) {
            return indice; // Se encontró el elemento
        }
        actual = actual->siguiente;
        indice++;
    }

    return -1; // No se encontró el elemento
}



//*******************************************************************

// Obtener tamaño
template <typename T>
size_t LinkedList<T>::obtenerTamaño() const {
    return tamaño;
}




//*******************************************************************

// Imprimir lista
template <typename T>
void LinkedList<T>::imprimir() const {
    Nodo* temp = cabeza;
    while (temp) {
        std::cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    std::cout << "NULL\n";
}

