//	lista.c - ver pokemon capturados

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void insertarFinal(Nodo **lista, Pokemon dato) {		// crea nodo y lo añade al final y "nodo **lista" permite modificar la cabeza desde el llamador.
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevo) {
        printf("Error: malloc fallo en insertar al final.\n");
        return;
}
	nuevo->dato = dato;
    nuevo->sig = NULL;
    
   if (*lista == NULL) {
        *lista = nuevo;
    } else {
        Nodo *aux = *lista;
        while (aux->sig != NULL) aux = aux->sig;
        aux->sig = nuevo;
    }
}

void mostrarLista(Nodo *lista) {		// itera e imprime cada pokemon.
    if (lista == NULL) {
        printf("\nNo hay Pokemon capturados.\n");
        return;
    }
    Nodo *aux = lista;
    while (aux != NULL) {
        mostrarPokemon(&aux->dato);
        aux = aux->sig;
    }
}

void liberarLista(Nodo **lista) {		// itera y libera memoria.
    Nodo *aux;
    while (*lista != NULL) {
        aux = *lista;				
        *lista = (*lista)->sig;
        free(aux);
    }
}

