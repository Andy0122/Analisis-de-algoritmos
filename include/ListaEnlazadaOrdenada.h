#ifndef LISTA_ENLAZADA_ORDENADA_H
#define LISTA_ENLAZADA_ORDENADA_H

// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Definición de la clase ListaEnlazadaOrdenada
class ListaEnlazadaOrdenada {
private:
    Nodo* cabeza;

public:
    // Constructor
    ListaEnlazadaOrdenada();

    // Destructor
    ~ListaEnlazadaOrdenada();

    // Función para insertar un nuevo nodo de forma ordenada
    void insertar(int valor);

    // Función para buscar un valor en la lista
    bool buscar(int valor);

    // Función para eliminar un nodo con un valor específico
    bool eliminar(int valor);

    // Función para imprimir la lista
    void imprimir();
};

#endif

