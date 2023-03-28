#include "pokemon.h"
#include <string.h>
#include <stdio.h>
#include "pokemon_privado.h"

#define LECTURA "%i,%[^,],%i,%[^,]"
pokemon_t *pokemon_crear_desde_string(const char *string)
{	
	pokemon_t *pokemon_nuevo = malloc(sizeof(pokemon_t));
	int* id_nueva = 0;
	int *salud_nueva = 0;
	char nombre_nuevo[MAX_NOMBRE], nombre_entrenador_nuevo[MAX_NOMBRE];
	int leidos = sscanf(string, LECTURA, id_nueva, nombre_nuevo, salud_nueva, nombre_entrenador_nuevo);
	if(leidos == 4){
		pokemon_nuevo->id = (size_t) id_nueva;
		strcpy(pokemon_nuevo->nombre, nombre_nuevo);
		pokemon_nuevo->salud = (size_t) salud_nueva;
		strcpy(pokemon_nuevo->nombre_entrenador, nombre_entrenador_nuevo);
		return pokemon_nuevo;
	} else {
		return NULL;
	}
}

pokemon_t *pokemon_copiar(pokemon_t *poke)
{
	return NULL;
}

bool comparar_var_size(size_t var1, size_t var2)
{
	if(&var1 == &var2){
		return true;
	} else {
		return false;
	}
}

bool comparar_var_char(char var1, char var2)
{
	if(strcmp(&var1, &var2) == 0){
		return true;
	} else {
		return false;
	}
}

bool pokemon_son_iguales(pokemon_t *pokemon1, pokemon_t *pokemon2)
{
	int aux = 0;
	if(comparar_var_size(pokemon1->id, pokemon2->id))
		aux++;
	if(comparar_var_size(pokemon1->salud, pokemon2->salud))
		aux++;
	if(comparar_var_char(*pokemon1->nombre, *pokemon2->nombre))
		aux++;
	if(comparar_var_char(*pokemon1->nombre_entrenador, *pokemon2->nombre_entrenador))
		aux++;

	if(aux == 4){
		return true;
	} else {
		return false;
	}
}

char *pokemon_nombre(pokemon_t *pokemon)
{
	return 0;
}

char *pokemon_entrenador(pokemon_t *pokemon)
{
	return 0;
}

size_t pokemon_salud(pokemon_t *pokemon)
{
	return 0;
}

size_t pokemon_id(pokemon_t *pokemon)
{
	return 0;
}

void pokemon_destruir(pokemon_t *pkm)
{
}
