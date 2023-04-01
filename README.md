<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TP1

## Repositorio de Tomas Petrocini - 110157 - petrocinitomas@gmail.com 

- Para compilar:

```bash
línea de compilación
```

- Para ejecutar:

```bash
línea de ejecución
```

- Para ejecutar con valgrind:
```bash
línea con valgrind
```
---
##  Funcionamiento
El programa esta divido en dos archivos .c que se ocupan de distintas partes de la funcionalidad total, pokemon.c, que maneja todo lo relacionado a la estructura pokemon y tp1.c que maneja las estructuras de hospital, que tienen dentro suyo las estructuras pokemon.

En general el programa funciona recibiendo un archivo .txt el cual es recorrido linea a linea, generando registros pokemon y almacenandolos en un hospital a medida que avanza por el archivo, todo este proceso esta compuesto por varios pasos de comprobacion de parametros y datos (en general todas las funciones del programa tienen alguna comprobacion de este estilo), reservacion de memoria y posteriormente de liberacion de memoria en caso de ser necesario. Si algun dato o parametro es "incorrecto"/nulo/en el formato equivocado entonces el proceso se interrumpe. En caso de que todo este en orden, la funcion principal devuelve un registro hospital con sus pokemones dentro.

Al finalizar este proceso tambien se ordenan los pokemones dentro del hospital en base a su salud ya que es importante para otras funciones. El ordenamiento es por burbujeo.

Ademas hay una funcion que es un iterador para poder realizar operaciones decididas por el usuario a cada pokemon de un hospital y otra funcion para agregar mas pokemones a un hospital ya creado, los pokemones simplemente se agregan al final del vector (aumentando la memoria que se reservo para el vector de pokemones previamente) y luego son ordenados una vez mas por burbujeo.

Ambos archivos .c tambien cuentan con funciones que devuelven variables dentro de estructuras como pokemon_id por ejemplo, todas estas funciones comprueban que su parametro exista y sea correcto y luego devuelven lo que se les pide. Ademas de contar con funciones para liberar memoria de estructuras enteras o de punteros, dependiendo la funcion.

Este es un ejemplo de como se guarda un hospital en memoria
<div align="center">
<img width="70%" src="img/memoria.jpg">
</div>

Y esto es como se libera la memoria de un hospital
<div align="center">
<img width="70%" src="img/liberar:memoria.jpg">
</div>

**
Explicación de cómo funcionan las estructuras desarrolladas en el TP y el funcionamiento general del mismo.

Aclarar en esta parte todas las decisiones que se tomaron al realizar el TP, cosas que no se aclaren en el enunciado, fragmentos de código que necesiten explicación extra, etc.

Incluír **EN TODOS LOS TPS** los diagramas relevantes al problema (mayormente diagramas de memoria para explicar las estructuras, pero se pueden utilizar otros diagramas si es necesario).

### Por ejemplo:
**

El programa funciona abriendo el archivo pasado como parámetro y leyendolo línea por línea. Por cada línea crea un registro e intenta agregarlo al vector. La función de lectura intenta leer todo el archivo o hasta encontrar el primer error. Devuelve un vector con todos los registros creados.

<div align="center">
<img width="70%" src="img/diagrama1.svg">
</div>

En el archivo `sarasa.c` la función `funcion1` utiliza `realloc` para agrandar la zona de memoria utilizada para conquistar el mundo. El resultado de `realloc` lo guardo en una variable auxiliar para no perder el puntero original en caso de error:

```c
int *vector = realloc(vector_original, (n+1)*sizeof(int));

if(vector == NULL)
    return -1;
vector_original = vector;
```


<div align="center">
<img width="70%" src="img/diagrama2.svg">
</div>

---

## Respuestas a las preguntas teóricas
Incluír acá las respuestas a las preguntas del enunciado (si aplica).
