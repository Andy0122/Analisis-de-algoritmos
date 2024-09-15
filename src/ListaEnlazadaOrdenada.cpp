#include "../include/ListaEnlazadaOrdenada.h"
#include <iostream>

using namespace std;

// Constructor para inicializar la lista
ListaEnlazadaOrdenada::ListaEnlazadaOrdenada() : cabeza(nullptr) {}

// Destructor para liberar la memoria de los nodos
ListaEnlazadaOrdenada::~ListaEnlazadaOrdenada() {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// Función para insertar un nodo de forma ordenada
void ListaEnlazadaOrdenada::insertar(int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    // Si la lista está vacía o el nuevo valor es menor o igual que el primer valor
    if (cabeza == nullptr || cabeza->dato >= valor) {
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    } else {
        // Buscar el lugar adecuado para insertar el nuevo nodo
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato < valor) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

// Función para buscar un valor en la lista
bool ListaEnlazadaOrdenada::buscar(int valor) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// Función para eliminar un nodo con un valor específico
bool ListaEnlazadaOrdenada::eliminar(int valor) {
    if (cabeza == nullptr) {
        return false; // La lista está vacía
    }

    // Si el valor a eliminar es el primer nodo
    if (cabeza->dato == valor) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }

    // Buscar el nodo a eliminar
    Nodo* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual->siguiente == nullptr) {
        return false; // El valor no se encontró
    }

    // Eliminar el nodo
    Nodo* temp = actual->siguiente;
    actual->siguiente = actual->siguiente->siguiente;
    delete temp;
    return true;
}

// Función para imprimir la lista
void ListaEnlazadaOrdenada::imprimir() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "nullptr" << endl;
}
