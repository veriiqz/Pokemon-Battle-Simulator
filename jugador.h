//	jugador.h -

#ifndef JUGADOR_H
#define JUGADOR_H
#include "pokemon.h"
#define EQUIPO 30

typedef struct {
    char nombre[30];
    Pokemon equipo[EQUIPO];
    int cantidad;
} Jugador;		// jugador contiene nombre, un arreglo estatico equipo y la cantidad de pokemon.

void inicializarJugador(Jugador *j);
void mostrarMenu(Jugador *j, Nodo **pokemonesSalvajes, NodoA **pokedex);
void agregarPokemonAlJugador(Jugador *j, const Pokemon *dato);
void mostrarEquipo(const Jugador *j);

#endif
