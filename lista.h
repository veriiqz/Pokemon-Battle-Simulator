// lista.h - 

#ifndef LISTA_H
#define LISTA_H
#include "pokemon.h"

typedef struct Nodo {
    // CORRECCIÓN: Cambiado de 'dato' a 'p' para consistencia con arbol.h
    Pokemon dato; 
    struct Nodo *sig;
} Nodo;		// representa un nodo de la lista que guarda un pokemon.
typedef Nodo* Lista;

// prototipado
void insertarFinal(Nodo **lista, Pokemon dato);
void mostrarLista(Nodo *lista);
void liberarLista(Nodo **lista);

#endif
