//	jugador.c -

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "pokemon.h"
#include "jugador.h"
#include "archivo.h"
#include "lista.h"
#include "arbol.h"
#include "batalla.h"

void inicializarJugador(Jugador *j) {		// pide nombre con fgets y setea cantidad = 0.
    if (!j) return;
    printf("Ingrese su nombre: ");
    if (fgets(j->nombre, NOMBRE_LEN, stdin) == NULL)
        strcpy(j->nombre, "Entrenador");
    j->nombre[strcspn(j->nombre, "\n")] = '\0';
    j->cantidad = 0;
}

void agregarPokemonAlJugador(Jugador *j, const Pokemon *dato) {		// añade un Pokemon al arreglo equipo si hay espacio.
    if (!j || !p) return;
    if (j->cantidad >= EQUIPO) {
        printf("Tu equipo esta lleno (%d/%d).\n", j->cantidad, EQUIPO);
        return;
    }
    j->equipo[j->cantidad] = *dato; // copia
    j->cantidad++;
    printf("%s fue agregado a tu equipo.\n", dato->nombre);
}

void mostrarEquipo(const Jugador *j) {		// imprime el equipo actual.
    if (!j) return;
    if (j->cantidad == 0) {
        printf("No tienes Pokemon en tu equipo.\n");
        return;
    }
    printf("\n--- TU EQUIPO ---\n");
    for (int i = 0; i < j->cantidad; i++) {
        printf("%d) ", i+1);
        mostrarPokemon(&j->equipo[i]);
    }
}

/*	bucle principal del programa:
opcion 1: captura un Pokemon de la lista pokemonesSalvajes, lo agrega al Jugador y lo inserta en la pokedex (arbol).
opcion 3: realiza batalla entre el primer Pokémon del jugador y el primer salvaje.
opcion 5; guardarProgreso: guarda usando archivo.c.
opcion 6; cargarProgreso: carga la partida.
*/

void mostrarMenu(Jugador *j, Nodo **pokemonesSalvajes, NodoA **pokedex) {
    int opcion;
    srand((unsigned)time(NULL)); // inicializa rand para las batallas
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Capturar Pokemon (aleatorio de lista)\n");
        printf("2. Ver equipo\n");
        printf("3. Batallar (tu primer Pokemon vs. un salvaje)\n");
        printf("4. Mostrar Pokedex (orden alfabrtico)\n");
        printf("5. Guardar partida\n");
        printf("6. Cargar partida\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n'); // limpiar
            opcion = -1;
        }
        
        getchar();

        if (opcion == 1) {
            // capturar: tomar primer elemento de pokemonesSalvajes si existe.
            if (*pokemonesSalvajes == NULL) {
                printf("No hay Pokemon salvajes disponibles.\n");
            } else {
                Pokemon capturado = (*pokemonesSalvajes)->dato;
                printf("Aparece un salvaje: %s (Nv %d)\n", capturado.nombre, capturado.nivel);
                agregarPokemonAlJugador(j, &capturado);
                // insertar en pokedex.
                *pokedex = insertarArbol(*pokedex, &capturado);
                // eliminar cabeza de la lista de salvajes.
                Nodo *aux = *pokemonesSalvajes;
                *pokemonesSalvajes = (*pokemonesSalvajes)->sig;
                free(aux);
            }
        } else if (opcion == 2) {
            mostrarEquipo(j);
        } else if (opcion == 3) {
            if (j->cantidad == 0) {
                printf("No tenes Pokemon para pelear.\n");
            } else if (*pokemonesSalvajes == NULL) {
                printf("No hay enemigos salvajes para batallar.\n");
            } else {
                // batalla entre primer pokemon del jugador y primer salvaje.
                batalla(&j->equipo[0], &(*pokemonesSalvajes)->dato);
                // si tu pokemon gana, mantiene nivel aumentado automaticamente, si pierde, el salvaje sube.
            }
        } else if (opcion == 4) {
            printf("\n=== POKEDEX (orden alfabetico) ===\n");
            if (*pokedex == NULL) printf("Pokedex vacia.\n");
            else mostrarEnOrden(*pokedex);
        } else if (opcion == 5) {
            guardarProgreso(j);
        } else if (opcion == 6) {
            cargarProgreso(j, pokemonesSalvajes, pokedex);
        } else if (opcion == 0) {
            printf("Saliendo...\n");
        } else {
            printf("Opcion invalida.\n");
        }

    } while (opcion != 0);
}

