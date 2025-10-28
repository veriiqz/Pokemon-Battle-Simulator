//	pokemon.h - contiene las estructuras y funciones de los pokemon.

#ifndef POKEMON_H
#define POKEMON_H

void mostrarPokemon(Pokemon p);
Pokemon crearPokemon(const char *nombre, int nivel);

typedef struct {
    char nombre[30];
    int nivel;
    int ataque;
    int defensa;
} Pokemon;

#endif
