//	arbol.h - funciones para la pokedex ordenada alfabeticamente

#ifndef ARBOL_H
#define ARBOL_H
#include "pokemon.h"

typedef struct Nodo {
    Pokemon dato;
    struct Nodo *izq, *der;
} NodoA;		// (BST)

// prototipado
void insertarArbol(NodoA *raiz, const Pokemon *dato);
void mostrarEnOrden(NodoA *raiz);
void liberarArbol(NodoA **raiz);

#endif

