# Rush01: explicación para principiantes

Este programa resuelve el puzle **Skyscrapers** de tamaño 4 × 4. El usuario
entrega 16 pistas y el programa busca una cuadrícula que cumpla todas ellas.

## 1. ¿En qué consiste el puzle?

Cada casilla contiene una altura entre `1` y `4`:

- `1` es el edificio más bajo.
- `4` es el edificio más alto.
- En cada fila deben aparecer `1`, `2`, `3` y `4` sin repetirse.
- En cada columna deben aparecer `1`, `2`, `3` y `4` sin repetirse.

Las pistas indican cuántos edificios se ven desde cada lado. Un edificio tapa
a todos los edificios más bajos situados detrás de él.

Por ejemplo, mirando la secuencia `2 1 4 3` desde la izquierda:

1. Se ve el `2`.
2. El `1` queda oculto por el `2`.
3. Se ve el `4`, porque es más alto que el máximo anterior.
4. El `3` queda oculto por el `4`.

Por tanto, desde la izquierda se ven **2** edificios. Desde la derecha también
se ven **2**: primero el `3` y después el `4`.

## 2. Formato de entrada

El programa espera exactamente un argumento con 16 números separados por un
único espacio:

```text
"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

El orden de las pistas es:

```text
índices  0  1  2  3     columnas vistas desde arriba
índices  4  5  6  7     columnas vistas desde abajo
índices  8  9 10 11     filas vistas desde la izquierda
índices 12 13 14 15     filas vistas desde la derecha
```

Visualmente, se colocan así alrededor del tablero:

```text
                 clues[0..3]
                    arriba
                  4 3 2 1
                    ↓ ↓ ↓ ↓

clues[8..11]  4 →  _ _ _ _  ← 1  clues[12..15]
 izquierda    3 →  _ _ _ _  ← 2       derecha
              2 →  _ _ _ _  ← 2
              1 →  _ _ _ _  ← 2

                    ↑ ↑ ↑ ↑
                  1 2 2 2
                    abajo
                 clues[4..7]
```

La cadena tiene 31 caracteres: 16 dígitos y 15 espacios. Solo se aceptan los
dígitos del `1` al `4`.

## 3. Compilación y ejecución

Desde la raíz del repositorio:

```sh
cc -Wall -Wextra -Werror Rush01/src/ex00/*.c -o rush01
./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```

Salida:

```text
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```

El programa imprime `Error` si el argumento tiene un formato incorrecto o si
no encuentra ninguna solución.

## 4. Responsabilidad de cada archivo

| Archivo | Responsabilidad |
| --- | --- |
| `main.c` | Coordina todo el programa. |
| `input.c` | Valida la cadena y guarda sus 16 pistas como enteros. |
| `solver.c` | Inicializa el tablero y busca una solución mediante backtracking. |
| `validation.c` | Evita repeticiones y comprueba las pistas de filas y columnas completas. |
| `visibility.c` | Cuenta cuántos edificios son visibles desde cada dirección. |
| `output.c` | Imprime la solución o `Error`. |

## 5. Flujo general del programa

```text
main
 │
 ├─ ¿argc es 2? ─────────────── no ─→ Error
 │
 ├─ valid_arg(argv[1]) ──────── no ─→ Error
 │
 ├─ fill_clues(clues, argv[1])
 │
 ├─ init_tab(tab)
 │
 ├─ solve(tab, 0, clues) ────── no ─→ Error
 │
 └─ print_tab(tab)
```

### Paso 1: comprobar el número de argumentos

En `main.c`, `argc` debe valer `2`:

- `argv[0]` contiene el nombre del ejecutable.
- `argv[1]` contiene la cadena con las pistas.

Si falta la cadena o hay argumentos adicionales, se imprime `Error`.

### Paso 2: validar la cadena

`valid_arg` llama a tres funciones de `input.c`:

1. `valid_chars` comprueba que solo haya espacios o dígitos entre `1` y `4`.
2. `valid_length` comprueba que haya exactamente 31 caracteres.
3. `valid_pos` comprueba la alternancia: dígito, espacio, dígito, espacio...

Las funciones devuelven `1` cuando la condición se cumple y `0` cuando falla.
En C se usan habitualmente estos enteros como valores booleanos.

### Paso 3: convertir las pistas a enteros

`fill_clues` recorre la cadena. Cuando encuentra un dígito, convierte su código
de carácter a un número:

```c
clues[j] = str[i] - '0';
```

Por ejemplo, `'3' - '0'` produce el entero `3`. Los espacios se ignoran.

### Paso 4: inicializar el tablero

`init_tab` recorre la matriz `tab[4][4]` y coloca un `0` en cada casilla. El
`0` significa que esa posición todavía está vacía.

### Paso 5: buscar una solución

`solve` usa **backtracking**, es decir, prueba valores y retrocede cuando una
decisión conduce a un tablero imposible.

El parámetro `pos` representa una posición lineal entre `0` y `15`. Para
convertirlo en fila y columna se usan:

```c
fila    = pos / 4;
columna = pos % 4;
```

La división entera indica la fila y el resto de la división indica la columna:

```text
pos:      0  1  2  3
          4  5  6  7
          8  9 10 11
         12 13 14 15
```

Para cada posición, `solve` prueba en orden los valores `1`, `2`, `3` y `4`:

```text
colocar un valor
      │
      ├─ no es válido → borrarlo y probar el siguiente
      │
      └─ es válido → resolver la siguiente posición
                          │
                          ├─ encuentra solución → terminar
                          └─ falla → volver atrás y probar otro valor
```

Ese “volver atrás” ocurre al ejecutar:

```c
tab[pos / 4][pos % 4] = 0;
```

Cuando `pos == 16`, las 16 casillas ya son válidas y `solve` devuelve `1`.
Si se agotan los cuatro valores posibles, devuelve `0` a la llamada anterior
para que esta cambie su última decisión.

## 6. ¿Cómo se decide si una posición es válida?

Después de colocar un valor, `solve` llama a `pos_is_valid`.

Primero se aplican dos reglas rápidas:

- `is_row_valid` busca el mismo valor en las casillas anteriores de la fila.
- `is_col_valid` busca el mismo valor en las casillas anteriores de la columna.

No hace falta mirar las casillas posteriores: el algoritmo rellena el tablero
de izquierda a derecha y de arriba abajo, así que todavía están vacías.

Después se comprueban las pistas, pero solo cuando la línea está completa:

- Si `pos / 4 == 3`, se acaba de completar una columna y se validan sus pistas
  superior e inferior.
- Si `pos % 4 == 3`, se acaba de completar una fila y se validan sus pistas
  izquierda y derecha.

Esperar a que una fila o columna esté completa evita comparar una pista final
con datos que todavía faltan.

## 7. ¿Cómo se cuenta la visibilidad?

Las cuatro funciones de `visibility.c` usan la misma idea. Solo cambia el punto
desde el que empiezan y la dirección en la que recorren el tablero:

- `count_visible_row_left`: fila de izquierda a derecha.
- `count_visible_row_right`: fila de derecha a izquierda.
- `count_visible_col_top`: columna de arriba abajo.
- `count_visible_col_bottom`: columna de abajo arriba.

Durante el recorrido se guardan dos variables:

- `max`: edificio más alto visto hasta ese momento.
- `count`: número de edificios visibles.

Cada vez que la altura actual es mayor que `max`, el edificio es visible, se
actualiza `max` y aumenta `count`.

Ejemplo con `1 3 2 4` desde la izquierda:

| Altura actual | `max` anterior | ¿Se ve? | Nuevo `count` |
| --- | ---: | --- | ---: |
| 1 | 0 | Sí | 1 |
| 3 | 1 | Sí | 2 |
| 2 | 3 | No | 2 |
| 4 | 3 | Sí | 3 |

La pista izquierda de esta fila tendría que ser `3`.

## 8. Recorrido resumido con un intento

Al comenzar, el tablero contiene ceros. `solve(tab, 0, clues)` prueba un `1` en
la posición 0. Como no se repite, avanza a la posición 1. Allí prueba primero
un `1`, pero `is_row_valid` lo rechaza; después prueba un `2` y puede continuar.

Si más adelante completa una fila que no coincide con sus dos pistas, esa rama
se rechaza. La recursión vuelve a la posición anterior, borra su valor y prueba
el siguiente. Este proceso continúa hasta encontrar una solución completa o
hasta agotar todas las combinaciones.

## 9. Ideas importantes que practica este ejercicio

- Recorrer cadenas y matrices con bucles.
- Convertir caracteres numéricos en enteros.
- Separar un programa en archivos con una responsabilidad concreta.
- Usar división y módulo para recorrer una matriz con un único índice.
- Usar recursividad para explorar decisiones.
- Aplicar backtracking: probar, validar, avanzar y retroceder.
- Devolver `1` o `0` para comunicar éxito o fallo entre funciones.

Una buena forma de estudiar el programa es comenzar por `main.c` y seguir las
llamadas en este orden: `input.c` → `solver.c` → `validation.c` →
`visibility.c` → `output.c`.
