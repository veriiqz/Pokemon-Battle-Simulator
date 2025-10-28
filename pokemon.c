//	pokemon.c - define como se crean y muestran los pokemon.

#include <stdio.h>
#include <string.h>
#include "pokemon.h"

Pokemon crearPokemon(const char *nombre, int nivel) {
    Pokemon p;
    strcpy(pNombre, nombre);
    pNivel = nivel;
    pAtaque = 10 + nivel * 2;
    pDefensa = 8 + nivel * 2;
    return p;
}

void mostrarPokemon(Pokemon p) {
    printf("Nombre: %s | Nivel: %d | Ataque: %d | Defensa: %d\n",
           pNombre, pNivel, pAtaque, pDefensa);
}

