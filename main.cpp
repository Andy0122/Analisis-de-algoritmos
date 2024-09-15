#include <iostream>
#include "include/ListaEnlazadaOrdenada.h"

using namespace std;

#include "include/BinarySearchTree.h"
#include <iostream>


int main() {
    BinarySearchTree arbol;

    // Insertar valores en el árbol
    arbol.insertar(50);
    arbol.insertar(30);
    arbol.insertar(70);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(60);
    arbol.insertar(80);

    cout << "Árbol en orden después de las inserciones: ";
    arbol.imprimir();

    // Buscar valores en el árbol
    cout << "Buscar 40: " << (arbol.buscar(40) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscar 90: " << (arbol.buscar(90) ? "Encontrado" : "No encontrado") << endl;

    // Eliminar valores del árbol
    arbol.eliminar(20);
    cout << "Árbol en orden después de eliminar 20: ";
    arbol.imprimir();

    arbol.eliminar(30);
    cout << "Árbol en orden después de eliminar 30: ";
    arbol.imprimir();

    arbol.eliminar(50);
    cout << "Árbol en orden después de eliminar 50: ";
    arbol.imprimir();

    return 0;
}

