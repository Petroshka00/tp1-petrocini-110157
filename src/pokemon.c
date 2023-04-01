#include "pokemon.h"
#include <string.h>
#include <stdio.h>
#include "pokemon_privado.h"

#define LECTURA_STR "%zu,%[^,],%zu,%[^,]"
pokemon_t *pokemon_crear_desde_string(const char *string)
{
	if (string == NULL) {
		return NULL;
	} else {
		pokemon_t *pokemon_nuevo = malloc(sizeof(pokemon_t));
		int leidos = sscanf(string, LECTURA_STR, &pokemon_nuevo->id,
				    pokemon_nuevo->nombre,
				    &pokemon_nuevo->salud,
				    pokemon_nuevo->nombre_entrenador);
		if (leidos == 4) {
			return pokemon_nuevo;
		} else {
			free(pokemon_nuevo);
			return NULL;
		}
	}
}

pokemon_t *pokemon_copiar(pokemon_t *poke)
{
	if (poke == NULL) {
		return NULL;
	}
	pokemon_t *copia_pokemon = malloc(sizeof(pokemon_t));
	*copia_pokemon = *poke;

	return copia_pokemon;
}

bool comparar_var_size(size_t var1, size_t var2)
{
	if (var1 == var2) {
		return true;
	} else {
		return false;
	}
}

bool pokemon_son_iguales(pokemon_t *pokemon1, pokemon_t *pokemon2)
{
	return (comparar_var_size(pokemon1->id, pokemon2->id) &&
		comparar_var_size(pokemon1->salud, pokemon2->salud) &&
		strcmp(pokemon1->nombre, pokemon2->nombre) == 0 &&
		strcmp(pokemon1->nombre_entrenador,
		       pokemon2->nombre_entrenador) == 0);
}

char *pokemon_nombre(pokemon_t *pokemon)
{
	if (pokemon == NULL) {
		return NULL;
	} else {
		return pokemon->nombre;
	}
}

char *pokemon_entrenador(pokemon_t *pokemon)
{
	if (pokemon == NULL) {
		return NULL;
	} else {
		return pokemon->nombre_entrenador;
	}
}

size_t pokemon_salud(pokemon_t *pokemon)
{
	if (pokemon == NULL) {
		return 0;
	} else {
		return pokemon->salud;
	}
}

size_t pokemon_id(pokemon_t *pokemon)
{
	if (pokemon == NULL) {
		return 0;
	} else {
		return pokemon->id;
	}
}

void pokemon_destruir(pokemon_t *pkm)
{
	free(pkm);
}
