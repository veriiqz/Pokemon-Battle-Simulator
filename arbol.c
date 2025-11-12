//	arbol.c - pokedex
//	arbol.c - pokedex

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "pokemon.h" // Necesario para mostrarPokemon

// CORRECCIÓN: Se asegura que retorna NodoA* en todos los caminos (incluyendo malloc fallido)
NodoA* insertarArbol(NodoA *raiz, const Pokemon *dato) {		// usa strcmp para decidir colocar el pokemon a la izquierda (menor) o derecha (mayor o igual) en orden alfabetico por nombre.
    if (raiz == NULL) {
        NodoA *nuevo = (NodoA*)malloc(sizeof(NodoA));
        if (!nuevo) {
            fprintf(stderr, "Error: malloc fallo en insertarArbol.\n");
            return NULL; // Devuelve NULL en caso de fallo
        }
        nuevo->dato = *dato;		// copia el pokemon.
        nuevo->izq = nuevo->der = NULL;
        return nuevo;
    }
        if (strcmp(dato->nombre, raiz->dato.nombre) < 0)
        	raiz->izq = insertarArbol(raiz->izq, dato);
   		else
        	raiz->der = insertarArbol(raiz->der, dato);
  		return raiz; // Se asegura que retorna la raíz
}

void mostrarEnOrden(NodoA *raiz) {		// es recursivo.
    if (raiz == NULL) return;
        mostrarEnOrden(raiz->izq);
        // CORRECCIÓN: Pasa la dirección del struct Pokemon
        mostrarPokemon(&raiz->dato); 
        mostrarEnOrden(raiz->der);
    } // CORRECCIÓN: Se cerró el bloque correctamente.

void liberarArbol(NodoA **raiz) {		// libera en post-orden.
    if (*raiz != NULL){
    	// CORRECCIÓN 1: No existe la variable 'raiz' en el scope de la función, solo *raiz.
    	// Se usa (*raiz)->izq y (*raiz)->der.
    	liberarArbol(&(*raiz)->izq); 
    	liberarArbol(&(*raiz)->der);
    	free(*raiz);
    	*raiz = NULL; 
    }
}

