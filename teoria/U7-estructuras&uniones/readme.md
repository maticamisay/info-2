# Unidad 7: Estructuras y Uniones

## Introducción

En el lenguaje de programación C, las **estructuras** y **uniones** son herramientas fundamentales que permiten agrupar diferentes tipos de datos bajo un mismo nombre. Esto facilita la organización, manipulación y representación de datos complejos, reflejando mejor las entidades del mundo real en el código.

---

## Definición de una estructura

Una **estructura** es un conjunto de variables (llamadas miembros o campos) que pueden ser de diferentes tipos y que están agrupadas bajo un mismo nombre. Las estructuras permiten crear tipos de datos personalizados.

### Sintaxis de declaración

```c
struct NombreEstructura {
    tipo miembro1;
    tipo miembro2;
    // Otros miembros...
};
```

### Ejemplo

```c
struct Libro {
    char titulo[100];
    char autor[50];
    int anioPublicacion;
    float precio;
};
```

En este ejemplo, hemos definido una estructura llamada `Libro` que contiene:

- `titulo`: una cadena de caracteres.
- `autor`: otra cadena de caracteres.
- `anioPublicacion`: un entero.
- `precio`: un número flotante.

---

## Procesamiento de los miembros de una estructura

### Declaración de variables de estructura

Después de definir una estructura, podemos declarar variables de ese tipo:

```c
struct Libro miLibro;
```

También es posible declarar variables al mismo tiempo que se define la estructura:

```c
struct Libro {
    char titulo[100];
    char autor[50];
    int anioPublicacion;
    float precio;
} libro1, libro2;
```

### Acceso a los miembros

Para acceder a los miembros de una estructura, usamos el operador punto `.`:

```c
strcpy(miLibro.titulo, "C Programming Language");
strcpy(miLibro.autor, "Kernighan and Ritchie");
miLibro.anioPublicacion = 1988;
miLibro.precio = 39.99;

printf("Título: %s\n", miLibro.titulo);
printf("Autor: %s\n", miLibro.autor);
printf("Año de Publicación: %d\n", miLibro.anioPublicacion);
printf("Precio: $%.2f\n", miLibro.precio);
```

---

## Tipos de datos definidos por el usuario (`typedef`)

El keyword `typedef` permite crear un alias para un tipo de dato existente. Esto es útil para simplificar declaraciones y mejorar la legibilidad del código.

### Uso con estructuras

```c
typedef struct {
    char nombre[50];
    int edad;
    float salario;
} Empleado;
```

Ahora, podemos declarar variables de tipo `Empleado` sin usar la palabra clave `struct`:

```c
Empleado emp1, emp2;
```

### Ventajas

- **Simplicidad**: Las declaraciones son más cortas y claras.
- **Legibilidad**: El código es más fácil de leer y mantener.
- **Reutilización**: Podemos reutilizar tipos personalizados en diferentes partes del programa.

---

## Estructuras y punteros

Podemos utilizar punteros para referenciar estructuras, lo que es especialmente útil al pasar estructuras a funciones o al manejar arreglos dinámicos de estructuras.

### Declaración de punteros a estructuras

```c
Empleado *ptrEmpleado;
```

### Acceso a miembros a través de punteros

Cuando tenemos un puntero a una estructura, usamos el operador de acceso `->` para acceder a sus miembros:

```c
ptrEmpleado = &emp1;
ptrEmpleado->edad = 30;
printf("Edad: %d\n", ptrEmpleado->edad);
```

**Nota**: El operador `->` es una forma abreviada de `(*ptrEmpleado).edad`.

---

## Paso de estructuras a una función

Las estructuras pueden pasarse a funciones tanto por valor como por referencia.

### Paso por valor

Al pasar una estructura por valor, se crea una copia de la misma:

```c
void mostrarEmpleado(Empleado e) {
    printf("Nombre: %s\n", e.nombre);
    printf("Edad: %d\n", e.edad);
}

mostrarEmpleado(emp1);
```

### Paso por referencia

Al pasar una estructura por referencia, se pasa su dirección de memoria:

```c
void actualizarSalario(Empleado *e, float nuevoSalario) {
    e->salario = nuevoSalario;
}

actualizarSalario(&emp1, 50000.0f);
```

**Ventajas del paso por referencia**:

- **Eficiencia**: No se crea una copia de la estructura.
- **Modificación directa**: La función puede modificar los valores originales.

---

## Uniones

Una **unión** es similar a una estructura, pero sus miembros comparten el mismo espacio de memoria. Esto significa que en una unión, solo un miembro puede contener un valor válido en un momento dado.

### Definición de una unión

```c
union NombreUnion {
    tipo miembro1;
    tipo miembro2;
    // Otros miembros...
};
```

### Ejemplo

```c
union Datos {
    int entero;
    float flotante;
    char cadena[20];
};
```

### Uso de una unión

```c
union Datos d;

d.entero = 10;
printf("Entero: %d\n", d.entero);

d.flotante = 3.14f;
printf("Flotante: %.2f\n", d.flotante);

// El valor de 'd.entero' ya no es válido, ya que 'd.flotante' ha sobrescrito la memoria.
```

**Nota importante**: Las uniones se utilizan cuando se desea ahorrar memoria y solo se necesita almacenar una de las posibles opciones a la vez.

---

## Diferencias entre estructuras y uniones

- **Estructuras**: Cada miembro tiene su propio espacio de memoria; todos los miembros pueden tener valores válidos simultáneamente.
- **Uniones**: Todos los miembros comparten el mismo espacio de memoria; solo un miembro puede tener un valor válido en un momento dado.

---

## Resumen

- Las **estructuras** permiten agrupar variables de diferentes tipos bajo un mismo nombre, facilitando la organización de datos complejos.
- El uso de **`typedef`** simplifica la declaración de estructuras y mejora la legibilidad del código.
- Los **punteros a estructuras** permiten manipular estructuras de manera eficiente, especialmente al pasarlas a funciones.
- Las **uniones** son útiles cuando se necesita almacenar diferentes tipos de datos en el mismo espacio de memoria, pero solo uno a la vez.

---

**Consejos para el uso de estructuras y uniones**:

- Utiliza estructuras para representar entidades con múltiples atributos que pueden ser utilizados simultáneamente.
- Aplica `typedef` para crear tipos más intuitivos y fáciles de manejar.
- Emplea punteros a estructuras para evitar copias innecesarias y para modificar directamente los datos originales.
- Las uniones son ideales para ahorrar memoria en sistemas con recursos limitados o cuando se trabaja con formatos de datos variables.
