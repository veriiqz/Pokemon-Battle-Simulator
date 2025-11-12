//	archivo.h

#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "jugador.h"
#include "lista.h"
#include "arbol.h"
#include "pokemon.h"
#include "batalla.h"

// guarda y carga el jugador (incluye equipo).
void guardarProgreso(const Jugador *j);
void cargarProgreso(Jugador *j, Nodo **pokemonesSalvajes, NodoA **pokedex);

#endif

