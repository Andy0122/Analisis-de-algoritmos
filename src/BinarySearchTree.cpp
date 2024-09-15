#include "../include/BinarySearchTree.h"
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree() : raiz(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    limpiar(raiz);
}

void BinarySearchTree::limpiar(NodoArbol* nodo) {
    if (nodo != nullptr) {
        limpiar(nodo->izquierda);
        limpiar(nodo->derecha);
        delete nodo;
    }
}

void BinarySearchTree::insertar(int valor) {
    raiz = insertar(raiz, valor);
}

NodoArbol* BinarySearchTree::insertar(NodoArbol* nodo, int valor) {
    if (nodo == nullptr) {
        NodoArbol* nuevoNodo = new NodoArbol();
        nuevoNodo->dato = valor;
        nuevoNodo->izquierda = nuevoNodo->derecha = nullptr;
        return nuevoNodo;
    }

    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }

    return nodo;
}

bool BinarySearchTree::buscar(int valor) {
    return buscar(raiz, valor);
}

bool BinarySearchTree::buscar(NodoArbol* nodo, int valor) {
    if (nodo == nullptr) {
        return false;
    }

    if (valor == nodo->dato) {
        return true;
    } else if (valor < nodo->dato) {
        return buscar(nodo->izquierda, valor);
    } else {
        return buscar(nodo->derecha, valor);
    }
}

void BinarySearchTree::eliminar(int valor) {
    raiz = eliminar(raiz, valor);
}

NodoArbol* BinarySearchTree::eliminar(NodoArbol* nodo, int valor) {
    if (nodo == nullptr) {
        return nodo;
    }

    if (valor < nodo->dato) {
        nodo->izquierda = eliminar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = eliminar(nodo->derecha, valor);
    } else {
        if (nodo->izquierda == nullptr) {
            NodoArbol* temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            NodoArbol* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }

        NodoArbol* temp = encontrarMinimo(nodo->derecha);
        nodo->dato = temp->dato;
        nodo->derecha = eliminar(nodo->derecha, temp->dato);
    }

    return nodo;
}

NodoArbol* BinarySearchTree::encontrarMinimo(NodoArbol* nodo) {
    while (nodo->izquierda != nullptr) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

void BinarySearchTree::imprimir() {
    imprimirInOrden(raiz);
    cout << endl;
}

void BinarySearchTree::imprimirInOrden(NodoArbol* nodo) {
    if (nodo != nullptr) {
        imprimirInOrden(nodo->izquierda);
        cout << nodo->dato << " ";
        imprimirInOrden(nodo->derecha);
    }
}
