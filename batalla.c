#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "batalla.h"
#include "pokemon.h"

void batalla(Pokemon *aliado, Pokemon *enemigo) {
    if (!aliado || !enemigo) return;

    printf("\n--- BATALLA ---\n");
    printf("%s (Nv %d) VS %s (Nv %d)\n",
           aliado->nombre, aliado->nivel, enemigo->nombre, enemigo->nivel);

    int vidaA = 50 + aliado->defensa;		// vidaA y vidaE se calculan en base a defensa mas valor base.
    int vidaE = 50 + enemigo->defensa;

    while (vidaA > 0 && vidaE > 0) {		// en cada vuelta, el aliado ataca primero y luego si el enemigo sigue con vida, ataca.
        int golpeA = (rand() % aliado->ataque) + 1;		// rand es el randomizer y se inicializa en el main - produce daño entre 1 y ataque.
        vidaE -= golpeA;
        printf("%s hace %d de daño. Vida enemiga: %d\n", aliado->nombre, golpeA, (vidaE>0)?vidaE:0);
        if (vidaE <= 0) break;

        int golpeE = (rand() % enemigo->ataque) + 1;
        vidaA -= golpeE;
        printf("%s hace %d de daño. Vida tuya: %d\n", enemigo->nombre, golpeE, (vidaA>0)?vidaA:0);
    }

if (vidaA > 0) {		// al ganador se le incrementan el nivel y se recalculan las stats.
        printf("\n¡%s gana la batalla y sube de nivel!\n", aliado->nombre);
        // CORRECCIÓN: Llamar a la función existente y corregida
        subirNivel(aliado); 
    } else {
        printf("\n%s gana la batalla y sube de nivel.\n", enemigo->nombre);
        // CORRECCIÓN: Llamar a la función existente y corregida
        subirNivel(enemigo); 
    }
}
