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

void hospital_ordenar(hospital_t *hospital_a_ordenar){
	for(size_t i = 0; i < hospital_a_ordenar->cantidad_pokemon-1; i++){
		for(size_t j = 0; j < hospital_a_ordenar->cantidad_pokemon - i - 1; j++){
			if(pokemon_salud(hospital_a_ordenar->pokemones[j+1]) < pokemon_salud(hospital_a_ordenar->pokemones[j])){
				void *aux;
				aux = hospital_a_ordenar->pokemones[j];
				hospital_a_ordenar->pokemones[j] = hospital_a_ordenar->pokemones[j+1];
				hospital_a_ordenar->pokemones[j+1] = aux;
			}
		}
	}
}

hospital_t *hospital_crear_desde_archivo(const char *nombre_archivo)
{
	if (nombre_archivo == NULL) {
		return NULL;
	}
	FILE *archivo = fopen(nombre_archivo, "r");
	if (archivo == NULL) {
		return NULL;
	}
	hospital_t *hospital_nuevo = calloc(1, sizeof(hospital_t));
	hospital_nuevo->pokemones = malloc(sizeof(hospital_t));
	if (hospital_nuevo == NULL) {
		return NULL;
	}

	char *string_para_crear_pkm = malloc(40 * sizeof(char));
	if(string_para_crear_pkm == NULL){
		return NULL;
	}
	int leidos = fscanf(archivo, LECTURA_ARC, string_para_crear_pkm);

	if(leidos != 1){
		return NULL;
	}

	while(leidos == 1){
		if(string_para_crear_pkm == NULL){
			return NULL;
		}
		hospital_nuevo->pokemones[hospital_nuevo->cantidad_pokemon] = pokemon_crear_desde_string(string_para_crear_pkm);
		hospital_nuevo->cantidad_pokemon += 1;
		hospital_nuevo->cantidad_entrenadores += 1;
		leidos = fscanf(archivo, LECTURA_ARC, string_para_crear_pkm);
	}
	hospital_ordenar(hospital_nuevo);
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
	hospital_ordenar(hospital);
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
	hospital_ordenar(hospital);
	if(hospital->cantidad_pokemon < prioridad){
		return NULL;
	} else {
		return (hospital->pokemones[prioridad]);
	}
}

void hospital_destruir(hospital_t *hospital)
{
	free(hospital);
}
