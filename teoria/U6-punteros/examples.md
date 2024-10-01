# Unidad 6: Punteros - Ejemplos

## Introducción

Los punteros son esenciales en C para manipular direcciones de memoria y gestionar recursos dinámicamente. A continuación, se presentan ejemplos y ejercicios resueltos para reforzar tu comprensión sobre punteros.

---

## Conceptos básicos

### Ejemplo 1: Uso básico de punteros

```c
#include <stdio.h>

int main() {
    int numero = 42;
    int *puntero_numero = &numero;

    printf("Valor de numero: %d\n", numero);
    printf("Dirección de numero: %p\n", &numero);
    printf("Valor del puntero: %p\n", puntero_numero);
    printf("Valor apuntado por el puntero: %d\n", *puntero_numero);

    return 0;
}
```

**Salida:**

```
Valor de numero: 42
Dirección de numero: 0x7ffeefbff5ac
Valor del puntero: 0x7ffeefbff5ac
Valor apuntado por el puntero: 42
```

**Explicación:**

- `&numero` obtiene la dirección de memoria de `numero`.
- `puntero_numero` almacena la dirección de `numero`.
- `*puntero_numero` accede al valor almacenado en la dirección apuntada.

### Ejercicio 1: Intercambiar valores usando punteros

Escribe una función que intercambie los valores de dos variables enteras usando punteros.

**Solución:**

```c
#include <stdio.h>

void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("Antes: x = %d, y = %d\n", x, y);

    intercambiar(&x, &y);

    printf("Después: x = %d, y = %d\n", x, y);
    return 0;
}
```

**Salida:**

```
Antes: x = 5, y = 10
Después: x = 10, y = 5
```

---

## Declaración de punteros

### Ejercicio 2: Declaración y uso de diferentes tipos de punteros

Declara punteros para los tipos `char`, `float` y `double`, asigna valores y muestra los resultados.

**Solución:**

```c
#include <stdio.h>

int main() {
    char caracter = 'A';
    float flotante = 3.14f;
    double doble = 9.81;

    char *pCaracter = &caracter;
    float *pFlotante = &flotante;
    double *pDoble = &doble;

    printf("Caracter: %c\n", *pCaracter);
    printf("Flotante: %.2f\n", *pFlotante);
    printf("Doble: %.2f\n", *pDoble);

    return 0;
}
```

**Salida:**

```
Caracter: A
Flotante: 3.14
Doble: 9.81
```

---

## Paso de punteros a una función

### Ejercicio 3: Función para calcular el cuadrado de un número

Escribe una función que calcule el cuadrado de un número y modifique el valor original usando punteros.

**Solución:**

```c
#include <stdio.h>

void cuadrado(int *num) {
    *num = (*num) * (*num);
}

int main() {
    int numero = 7;
    printf("Original: %d\n", numero);

    cuadrado(&numero);

    printf("Al cuadrado: %d\n", numero);
    return 0;
}
```

**Salida:**

```
Original: 7
Al cuadrado: 49
```

---

## Punteros y arreglos unidimensionales

### Ejemplo 2: Recorrer un arreglo usando punteros

```c
#include <stdio.h>

int main() {
    int arreglo[] = {10, 20, 30, 40, 50};
    int *ptr = arreglo;

    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, *(ptr + i));
    }

    return 0;
}
```

**Salida:**

```
Elemento 0: 10
Elemento 1: 20
Elemento 2: 30
Elemento 3: 40
Elemento 4: 50
```

### Ejercicio 4: Sumar elementos de un arreglo usando punteros

Calcula la suma de todos los elementos de un arreglo usando punteros.

**Solución:**

```c
#include <stdio.h>

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int *ptr = numeros;
    int suma = 0;

    for (int i = 0; i < 5; i++) {
        suma += *(ptr + i);
    }

    printf("La suma es: %d\n", suma);
    return 0;
}
```

**Salida:**

```
La suma es: 15
```

---

## Operaciones con punteros

### Ejercicio 5: Encontrar el máximo de un arreglo

Usa punteros para encontrar el valor máximo en un arreglo de enteros.

**Solución:**

```c
#include <stdio.h>

int main() {
    int datos[] = {17, 23, 5, 100, 56};
    int *ptr = datos;
    int max = *ptr;

    for (int i = 1; i < 5; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

    printf("El valor máximo es: %d\n", max);
    return 0;
}
```

**Salida:**

```
El valor máximo es: 100
```

---

## Asignación dinámica de memoria

### Ejemplo 3: Uso de `malloc` y `free`

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Introduce el número de elementos: ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        ptr[i] = i * 2;
    }

    printf("Elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}
```

**Salida (ejemplo con n=5):**

```
Introduce el número de elementos: 5
Elementos del arreglo:
0 2 4 6 8
```

### Ejercicio 6: Calcular promedio con memoria dinámica

Solicita al usuario n calificaciones, almacénalas dinámicamente y calcula el promedio.

**Solución:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float suma = 0;

    printf("Ingrese el número de calificaciones: ");
    scanf("%d", &n);

    float *calificaciones = (float *)malloc(n * sizeof(float));
    if (calificaciones == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Calificación %d: ", i + 1);
        scanf("%f", calificaciones + i);
        suma += *(calificaciones + i);
    }

    printf("Promedio: %.2f\n", suma / n);

    free(calificaciones);
    return 0;
}
```

**Salida (ejemplo):**

```
Ingrese el número de calificaciones: 3
Calificación 1: 85
Calificación 2: 90
Calificación 3: 95
Promedio: 90.00
```

---

## Punteros y arreglos multidimensionales

### Ejercicio 7: Acceder a elementos de una matriz usando punteros

Accede y muestra los elementos de una matriz 2x2 usando punteros.

**Solución:**

```c
#include <stdio.h>

int main() {
    int matriz[2][2] = {{1, 2}, {3, 4}};
    int (*ptr)[2] = matriz;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Elemento [%d][%d]: %d\n", i, j, *(*(ptr + i) + j));
        }
    }

    return 0;
}
```

**Salida:**

```
Elemento [0][0]: 1
Elemento [0][1]: 2
Elemento [1][0]: 3
Elemento [1][1]: 4
```

---

## Arreglo de punteros

### Ejercicio 8: Lista de cadenas de texto

Crea un programa que almacene una lista de nombres y los muestre utilizando un arreglo de punteros.

**Solución:**

```c
#include <stdio.h>

int main() {
    char *nombres[] = {"María", "José", "Pedro", "Lucía"};
    int n = sizeof(nombres) / sizeof(nombres[0]);

    for (int i = 0; i < n; i++) {
        printf("Nombre %d: %s\n", i + 1, nombres[i]);
    }

    return 0;
}
```

**Salida:**

```
Nombre 1: María
Nombre 2: José
Nombre 3: Pedro
Nombre 4: Lucía
```

---

## Punteros a funciones

### Ejercicio 9: Operaciones aritméticas usando punteros a funciones

Implementa un programa que realice operaciones aritméticas básicas usando punteros a funciones.

**Solución:**

```c
#include <stdio.h>

int sumar(int a, int b) { return a + b; }
int restar(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }
int dividir(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    int (*operacion)(int, int);
    int opcion, x = 20, y = 5;

    printf("Seleccione una operación:\n1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            operacion = sumar;
            break;
        case 2:
            operacion = restar;
            break;
        case 3:
            operacion = multiplicar;
            break;
        case 4:
            operacion = dividir;
            break;
        default:
            printf("Opción no válida\n");
            return 1;
    }

    printf("Resultado: %d\n", operacion(x, y));
    return 0;
}
```

**Salida (ejemplo seleccionando multiplicar):**

```
Seleccione una operación:
1. Sumar
2. Restar
3. Multiplicar
4. Dividir
3
Resultado: 100
```

---

## Callbacks

### Ejemplo 4: Uso de callbacks para ordenar un arreglo

```c
#include <stdio.h>

void ordenar(int *arr, int n, int (*criterio)(int, int)) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (criterio(arr[i], arr[j])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int ascendente(int a, int b) {
    return a > b;
}

int descendente(int a, int b) {
    return a < b;
}

int main() {
    int datos[] = {5, 2, 9, 1, 6};
    int n = sizeof(datos) / sizeof(datos[0]);

    ordenar(datos, n, ascendente);

    printf("Arreglo ordenado ascendentemente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    ordenar(datos, n, descendente);

    printf("Arreglo ordenado descendentemente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", datos[i]);
    }
    printf("\n");

    return 0;
}
```

**Salida:**

```
Arreglo ordenado ascendentemente:
1 2 5 6 9
Arreglo ordenado descendentemente:
9 6 5 2 1
```

---

## Más sobre declaración de punteros

### Ejercicio 10: Uso de puntero a puntero

Escribe un programa que modifique el valor de una variable usando un puntero a puntero.

**Solución:**

```c
#include <stdio.h>

int main() {
    int valor = 50;
    int *ptr = &valor;
    int **pptr = &ptr;

    printf("Valor original: %d\n", valor);

    **pptr = 100;

    printf("Valor modificado: %d\n", valor);
    return 0;
}
```

**Salida:**

```
Valor original: 50
Valor modificado: 100
```

### Ejercicio 11: Puntero a función que devuelve puntero

Crea una función que devuelve un puntero y usa un puntero a esa función.

**Solución:**

```c
#include <stdio.h>

int *crear_entero(int valor) {
    int *p = (int *)malloc(sizeof(int));
    if (p != NULL) {
        *p = valor;
    }
    return p;
}

int main() {
    int *(*func_ptr)(int) = crear_entero;

    int *numero = func_ptr(25);
    if (numero != NULL) {
        printf("Valor: %d\n", *numero);
        free(numero);
    } else {
        printf("Error al asignar memoria\n");
    }
    return 0;
}
```

**Salida:**

```
Valor: 25
```
