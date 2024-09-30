## Trabajo con `snprintf`, `strcpy`, `strcat`, `strcmp`, y `strncmp` en C

En C, las funciones para trabajar con cadenas (`char[]`) como `snprintf`, `strcpy`, `strcat`, `strcmp`, y `strncmp` son fundamentales para manipular y comparar texto. A continuación, te explico cómo funcionan estas cinco funciones, con ejemplos.

### 1. **`snprintf`**

`snprintf` es una función segura para formatear y escribir cadenas en un buffer con un límite de tamaño. Se usa principalmente para prevenir desbordamientos de buffer, ya que asegura que nunca escribirá más caracteres de los especificados.

#### **Sintaxis:**

```c
int snprintf(char *str, size_t size, const char *format, ...);
```

- `str`: El buffer donde se escribirá la cadena formateada.
- `size`: El tamaño máximo del buffer (incluye el carácter nulo `\0`).
- `format`: La cadena de formato (igual que en `printf`).
- `...`: Los argumentos que se insertarán en el formato.

#### **Ejemplo:**

```c
#include <stdio.h>

int main() {
    char buffer[50];
    int edad = 25;
    char nombre[] = "Juan";

    snprintf(buffer, sizeof(buffer), "Nombre: %s, Edad: %d", nombre, edad);

    printf("%s\n", buffer);  // Salida: Nombre: Juan, Edad: 25
    return 0;
}
```

#### **Ventajas de `snprintf`:**

- Control del tamaño del buffer.
- Previenes desbordamientos de memoria.
- Puedes formatear números y cadenas en una sola operación.

---

### 2. **`strcpy`**

`strcpy` se utiliza para copiar una cadena de caracteres a otra. **No** realiza comprobaciones de tamaño, lo que significa que si el destino es más pequeño que la fuente, se produce un desbordamiento de buffer.

#### **Sintaxis:**

```c
char *strcpy(char *dest, const char *src);
```

- `dest`: El buffer donde se copiará la cadena.
- `src`: La cadena de origen que se copiará.

#### **Ejemplo:**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char origen[] = "Hola Mundo";
    char destino[20];

    strcpy(destino, origen);  // Copia "Hola Mundo" a destino

    printf("%s\n", destino);  // Salida: Hola Mundo
    return 0;
}
```

#### **Advertencias sobre `strcpy`:**

- `strcpy` **no** verifica si el buffer de destino es lo suficientemente grande para contener la cadena de origen.
- Siempre asegúrate de que el buffer de destino tiene espacio suficiente para la cadena más el carácter nulo `\0`.

---

### 3. **`strcat`**

`strcat` se utiliza para concatenar dos cadenas de caracteres. Agrega la cadena de origen al final de la cadena de destino. Al igual que `strcpy`, no verifica el tamaño del buffer, lo que puede causar desbordamientos.

#### **Sintaxis:**

```c
char *strcat(char *dest, const char *src);
```

- `dest`: La cadena de destino (debe tener suficiente espacio para la concatenación).
- `src`: La cadena que se agregará al final de `dest`.

#### **Ejemplo:**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char destino[50] = "Hola, ";
    char origen[] = "Mundo";

    strcat(destino, origen);  // Concatenar "Mundo" al final de "Hola, "

    printf("%s\n", destino);  // Salida: Hola, Mundo
    return 0;
}
```

#### **Advertencias sobre `strcat`:**

- El buffer de destino debe ser lo suficientemente grande para contener tanto la cadena original como la concatenada.
- No realiza comprobaciones de tamaño.

---

### 4. **`strcmp`**

`strcmp` compara dos cadenas de caracteres. Devuelve un valor negativo, cero, o positivo dependiendo de si la primera cadena es menor, igual o mayor que la segunda.

#### **Sintaxis:**

```c
int strcmp(const char *str1, const char *str2);
```

- `str1`: Primera cadena a comparar.
- `str2`: Segunda cadena a comparar.

#### **Ejemplo:**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hola";
    char str2[] = "Mundo";

    if (strcmp(str1, str2) == 0) {
        printf("Las cadenas son iguales.\n");
    } else {
        printf("Las cadenas son diferentes.\n");  // Este será el resultado
    }
    return 0;
}
```

#### **Uso típico de `strcmp`:**

- Comparar si dos cadenas son iguales o diferentes.
- El resultado es 0 si son iguales, un valor negativo si `str1` es menor que `str2`, y un valor positivo si `str1` es mayor que `str2`.

---

### 5. **`strncmp`**

`strncmp` es similar a `strcmp`, pero solo compara los primeros `n` caracteres de las cadenas. Esto es útil cuando solo necesitas comparar una parte de las cadenas.

#### **Sintaxis:**

```c
int strncmp(const char *str1, const char *str2, size_t n);
```

- `str1`: Primera cadena a comparar.
- `str2`: Segunda cadena a comparar.
- `n`: Número de caracteres a comparar.

#### **Ejemplo:**

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hola Mundo";
    char str2[] = "Hola";

    if (strncmp(str1, str2, 4) == 0) {
        printf("Los primeros 4 caracteres son iguales.\n");  // Este será el resultado
    } else {
        printf("Los primeros 4 caracteres son diferentes.\n");
    }
    return 0;
}
```

#### **Uso típico de `strncmp`:**

- Comparar solo los primeros `n` caracteres de dos cadenas.
- Devuelve 0 si los primeros `n` caracteres son iguales, de lo contrario devuelve un valor distinto de 0.

---

### Comparación de `snprintf`, `strcpy`, `strcat`, `strcmp`, y `strncmp`

| Función    | Características                                                           | Seguridad                       |
| ---------- | ------------------------------------------------------------------------- | ------------------------------- |
| `snprintf` | Formatea y escribe cadenas, limitando la cantidad de caracteres escritos. | Alta: previene desbordamientos. |
| `strcpy`   | Copia una cadena de origen a un destino sin control del tamaño.           | Baja: no controla el tamaño.    |
| `strcat`   | Concatenar cadenas sin verificar el tamaño del buffer.                    | Baja: no controla el tamaño.    |
| `strcmp`   | Compara dos cadenas completas.                                            | N/A                             |
| `strncmp`  | Compara solo los primeros `n` caracteres de dos cadenas.                  | N/A                             |

---

### Resumen de buenas prácticas:

- **Usar `snprintf`** para formatear cadenas con control del tamaño del buffer.
- **Evitar desbordamientos de buffer** con `strcpy` y `strcat`, asegurándote de que el buffer de destino tiene suficiente espacio.
- **Usar `strcmp` y `strncmp`** para comparar cadenas de manera eficiente, dependiendo de si necesitas comparar cadenas completas o solo una parte.

---

### Ejemplo completo:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[50];
    char origen[] = "Hola";
    char concatenado[50] = "Mundo";
    int numero = 123;

    // Copiar una cadena con strcpy
    strcpy(buffer, origen);
    printf("Después de strcpy: %s\n", buffer);  // Salida: Hola

    // Concatenar con strcat
    strcat(concatenado, " Programador");
    printf("Después de strcat: %s\n", concatenado);  // Salida: Mundo Programador

    // Formatear con snprintf (controlando tamaño)
    snprintf(buffer, sizeof(buffer), "Nombre: %s, Número: %d", origen, numero);
    printf("Después de snprintf: %s\n", buffer);  // Salida: Nombre: Hola, Número: 123

    // Comparar cadenas con strcmp
    if (strcmp(origen, concatenado) == 0) {
        printf("Las cadenas son iguales.\n");
    } else {
        printf("Las cadenas son diferentes.\n");  // Este será el resultado
    }

    // Comparar los primeros 4 caracteres con strncmp
    if (strncmp(origen, concatenado, 4) == 0) {
        printf("Los primeros 4 caracteres son iguales.\n");  // Este será el resultado
    } else {
        printf("Los primeros 4 caracteres son diferentes.\n");
    }

    return 0;
}
```

Este ejemplo muestra cómo usar `snprintf`, `strcpy`, `strcat`, `strcmp`, y `strncmp` en un solo programa, destacando las diferencias y

las buenas prácticas en el uso de estas funciones.
