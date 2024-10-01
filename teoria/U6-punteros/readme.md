# Unidad 6: Punteros

## Introducción

Los punteros son una característica fundamental en el lenguaje de programación C que permite manipular directamente las direcciones de memoria. Comprender cómo funcionan los punteros es esencial para aprovechar al máximo las capacidades de C y para gestionar eficientemente los recursos del sistema.

## Conceptos básicos

Un puntero es una variable que almacena la dirección de memoria de otra variable. En lugar de contener un valor directo, un puntero "apunta" a la ubicación donde se almacena ese valor.

```c
int numero = 10;
int *puntero_numero = &numero; // 'puntero_numero' almacena la dirección de 'numero'
```

- `&`: Operador de dirección que obtiene la dirección de una variable.
- `*`: Operador de indireccionamiento que accede al valor en una dirección de memoria.

## Declaración de punteros

Para declarar un puntero, se especifica el tipo de dato al que apuntará seguido de un asterisco `*` y el nombre del puntero.

```c
tipo_dato *nombre_puntero;
```

Ejemplos:

```c
int *p;       // Puntero a entero
char *c;      // Puntero a caracter
float *f;     // Puntero a flotante
double *d;    // Puntero a doble precisión
```

## Paso de punteros a una función

Al pasar un puntero a una función, ésta puede modificar el valor de la variable original.

```c
void aumentar_en_uno(int *num) {
    (*num)++;
}

int main() {
    int valor = 5;
    aumentar_en_uno(&valor);
    printf("%d", valor); // Salida: 6
    return 0;
}
```

## Punteros y arreglos unidimensionales

En C, el nombre de un arreglo es equivalente a un puntero al primer elemento del arreglo.

```c
int arreglo[5] = {1, 2, 3, 4, 5};
int *ptr = arreglo;

printf("%d", *(ptr + 2)); // Accede al tercer elemento: 3
```

## Operaciones con punteros

Se pueden realizar operaciones aritméticas con punteros para navegar por direcciones de memoria.

- **Incremento y decremento**: `ptr++`, `ptr--`
- **Suma y resta**: `ptr + n`, `ptr - n`

```c
int arreglo[3] = {10, 20, 30};
int *ptr = arreglo;

printf("%d\n", *ptr);     // Salida: 10
ptr++;
printf("%d\n", *ptr);     // Salida: 20
```

## Asignación dinámica de memoria

Los punteros son esenciales para asignar memoria en tiempo de ejecución usando funciones como `malloc`, `calloc` y `realloc`.

```c
int *ptr = (int *)malloc(5 * sizeof(int));
if (ptr == NULL) {
    printf("Error al asignar memoria");
    exit(1);
}
// Uso de 'ptr'
free(ptr); // Liberar memoria asignada
```

## Punteros y arreglos multidimensionales

Los punteros pueden utilizarse para manipular arreglos multidimensionales.

```c
int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
int (*ptr)[3] = matriz; // Puntero a un arreglo de 3 enteros

printf("%d", ptr[1][2]); // Accede al elemento '6'
```

## Arreglo de punteros

Un arreglo puede contener punteros como sus elementos.

```c
char *nombres[] = {"Ana", "Luis", "Carlos"};
printf("%s", nombres[0]); // Salida: Ana
```

## Punteros a funciones

Los punteros pueden apuntar a funciones, lo que permite pasar funciones como argumentos o almacenarlas para uso posterior.

```c
int suma(int a, int b) {
    return a + b;
}

int (*func_ptr)(int, int) = suma;
printf("%d", func_ptr(5, 3)); // Salida: 8
```

## Callbacks

Un callback es una función pasada como argumento a otra función, que puede ser llamada (o "llamada de vuelta") en algún punto.

```c
void ejecutar_operacion(int (*operacion)(int, int), int x, int y) {
    printf("Resultado: %d\n", operacion(x, y));
}

int multiplicar(int a, int b) {
    return a * b;
}

int main() {
    ejecutar_operacion(multiplicar, 4, 5); // Salida: Resultado: 20
    return 0;
}
```

## Más sobre declaración de punteros

Las declaraciones de punteros pueden ser más complejas al combinar diferentes niveles de indirección o tipos de datos.

- **Puntero a puntero**:

  ```c
  int **pptr;
  ```

- **Puntero a arreglo**:

  ```c
  int (*parreglo)[10]; // Puntero a un arreglo de 10 enteros
  ```

- **Puntero a función que devuelve puntero**:

  ```c
  int *(*func_ptr)(int);
  ```

Es importante leer las declaraciones de derecha a izquierda para entender el tipo de dato al que apuntan.
