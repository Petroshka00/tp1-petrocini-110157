#include "tp1.h"

#include "pokemon.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LECTURA_ARC "%s"

struct _hospital_pkm_t {
	pokemon_t **pokemones;
	size_t cantidad_pokemon;
	size_t cantidad_entrenadores;
};

hospital_t *hospital_crear_desde_archivo(const char *nombre_archivo)
{
	FILE *archivo = malloc(sizeof(FILE));
	archivo = fopen(nombre_archivo, "r");
	if (archivo == NULL) {
		fclose(archivo);
		return NULL;
	}

	hospital_t *hospital_nuevo = malloc(sizeof(hospital_t));
	int leidos = 0;
	char string_para_crear_pkm[1000];
	hospital_nuevo->cantidad_pokemon = 0;
	do {
		leidos = fscanf(archivo, LECTURA_ARC, string_para_crear_pkm);
		hospital_nuevo->pokemones[hospital_nuevo->cantidad_pokemon] =
			pokemon_crear_desde_string(string_para_crear_pkm);
		hospital_nuevo->cantidad_pokemon += 1;
	} while (leidos == 1);
	fclose(archivo);
	return hospital_nuevo;
}

size_t hospital_cantidad_pokemones(hospital_t *hospital)
{
	return (hospital->cantidad_pokemon);
}

size_t hospital_a_cada_pokemon(hospital_t *hospital,
			       bool (*funcion)(pokemon_t *p, void *aux),
			       void *aux)
{
	int i = 0;
	do {
		funcion(hospital->pokemones[i], aux);
		i++;
	} while (funcion(hospital->pokemones[i], aux));
	return (size_t)i;
}

int hospital_aceptar_emergencias(hospital_t *hospital,
				 pokemon_t **pokemones_ambulancia,
				 size_t cant_pokes_ambulancia)
{
	return ERROR;
}

pokemon_t *hospital_obtener_pokemon(hospital_t *hospital, size_t prioridad)
{
	if (hospital == NULL) {
		return NULL;
	}
	return (hospital->pokemones[prioridad]);
}

void hospital_destruir(hospital_t *hospital)
{
	free(hospital);
}
