#include "tp1.h"

#include "pokemon.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LECTURA "%zu,%[^,],%zu,%[^,]"

struct _hospital_pkm_t {
	pokemon_t **pokemones;
	size_t cantidad_pokemon;
	size_t cantidad_entrenadores;
};

hospital_t *hospital_crear_desde_archivo(const char *nombre_archivo)
{
	// FILE* archivo = fopen(nombre_archivo, "r");
	// int leidos = 0;
	// hospital_t *hospital_nuevo = malloc(sizeof(hospital_t));
	// if(archivo == NULL){
	// 	fclose(archivo);
	// 	return NULL;
	// } else {
	// 	do{
	// 	leidos = fscanf(archivo, LECTURA, hospital_nuevo->pokemones)
	// 	} while (leidos == 4);
	// }
	return NULL;
}

size_t hospital_cantidad_pokemones(hospital_t *hospital)
{
	return (hospital->cantidad_pokemon);
}

size_t hospital_a_cada_pokemon(hospital_t *hospital,
			       bool (*funcion)(pokemon_t *p, void *aux),
			       void *aux)
{
	return 0;
}

int hospital_aceptar_emergencias(hospital_t *hospital,
				 pokemon_t **pokemones_ambulancia,
				 size_t cant_pokes_ambulancia)
{
	return ERROR;
}

pokemon_t *hospital_obtener_pokemon(hospital_t *hospital, size_t prioridad)
{
	return NULL;
}

void hospital_destruir(hospital_t *hospital)
{
	free(hospital);
}
