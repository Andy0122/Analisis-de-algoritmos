#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

// Estructura para el árbol binario de búsqueda
struct NodoArbol {
    int dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};

class BinarySearchTree {
private:
    NodoArbol* raiz;

    NodoArbol* insertar(NodoArbol* nodo, int valor);
    bool buscar(NodoArbol* nodo, int valor);
    NodoArbol* eliminar(NodoArbol* nodo, int valor);
    NodoArbol* encontrarMinimo(NodoArbol* nodo);
    void imprimirInOrden(NodoArbol* nodo);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(int valor);
    bool buscar(int valor);
    void eliminar(int valor);
    void imprimir();
    void limpiar(NodoArbol* nodo);
};

#endif
