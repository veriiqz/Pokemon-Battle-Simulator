//	main.c - programa principal.

#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"
#include "lista.h"
#include "arbol.h"
#include "batalla.h"
#include "jugador.h"
#include "archivo.h"

int main() {		// crea las estructuras principales y anade unos pokmeon salvajes por defecto (para que puedas capturar y batallar sin cargar desde archivo).
    // CORRECCIÓN: Debe ser Nodo* para la lista enlazada
    Nodo *pokemonesSalvajes = NULL; 
    NodoA *pokedex = NULL;		// queda vsacio hasta que captures.
    Jugador jugador;

    inicializarJugador(&jugador);		// inicializa Jugador (pide el nombre).

// aca se preparan los pokemon de ej.
    insertarFinal(&pokemonesSalvajes, crearPokemon("Pikachu", 5));
    insertarFinal(&pokemonesSalvajes, crearPokemon("Charmander", 4));
    insertarFinal(&pokemonesSalvajes, crearPokemon("Bulbasaur", 3));
    insertarFinal(&pokemonesSalvajes, crearPokemon("Squirtle", 3)); // si queres otro.

// nota: el menu se encarga de guardar/cargar y de manejar la pokedex.
    mostrarMenu(&jugador, &pokemonesSalvajes, &pokedex);

// al salir, libera memoria.
    liberarLista(&pokemonesSalvajes);
    liberarArbol(&pokedex);

    return 0;
}
