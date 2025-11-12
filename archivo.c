//	archivo.c - guardo el progreso, evolucion/nivel.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"

// archivo binario: "partida.dat"
void guardarProgreso(const Jugador *j) {
    if (!j) return;
    FILE *f = fopen("partida.dat", "wb");
// "partida.dat" simplifica guardar Jugador en una sola fwrite. incluye el nombre, cantidad y el arreglo equipo con todos los pokemon.
    if (!f) {
        printf("Error al abrir partida.dat para escritura.\n");
        return;
    }

// escribimos la estructura Jugador completa (incluye equipo y cantidad).
    if (fwrite(j, sizeof(Jugador), 1, f) != 1) {
        printf("Error al escribir Jugador en archivo.\n");
    } else {
        printf("Partida guardada en partida.dat\n");
    }
    fclose(f);
}

// argar y reconstruir structures auxiliares.
// formato: simplemente escribimos o leemos la struct Jugador completa.
void cargarProgreso(Jugador *j, Nodo **pokemonesSalvajes, NodoA **pokedex) {
    if (!j) return;
    FILE *f = fopen("partida.dat", "rb");
    if (!f) {
        printf("No se encontro partida.dat (no hay partida guardada).\n");
        return;
    }

// leer Jugador.
    if (fread(j, sizeof(Jugador), 1, f) != 1) {		// hace fread de la misma estructura y luego reconstruye el pokedex a partir del equipo guardado.
        printf("Error al leer Jugador desde archivo.\n");
        fclose(f);
        return;
    }
    fclose(f);

    printf("Partida cargada. Jugador: %s | Pokemon: %d\n", j->nombre, j->cantidad);

// reconstruir pokemonesSalvajes (opcional): pero se deja vacio.
// reconstruir pokedex con los pokemon del equipo.
    liberarLista(pokemonesSalvajes); // si hay algo previo.
    liberarArbol(*pokedex);
    *pokedex = NULL;

    for (int i = 0; i < j->cantidad; i++) {
        *pokedex = insertarArbol(*pokedex, &j->equipo[i]);
    }
    printf("Pokedex reconstruida desde el equipo.\n");
}
