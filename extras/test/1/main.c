#include <stdio.h>
#include <string.h>

// Función para leer el apellido y nombre del dueño
void leerNombre(char apellidoNombre[]) {
    printf("Ingrese el apellido y nombre del dueño: ");
    getchar(); // Consumir el salto de línea previo
    fgets(apellidoNombre, 100, stdin);
    apellidoNombre[strcspn(apellidoNombre, "\n")] = 0; // Eliminar el salto de línea del final
}

// Función para leer el cateto de base
float leerBase() {
    float base;
    printf("Ingrese el cateto de base del terreno (m): ");
    scanf("%f", &base);
    return base;
}

// Función para leer el cateto de altura
float leerAltura() {
    float altura;
    printf("Ingrese el cateto de altura del terreno (m): ");
    scanf("%f", &altura);
    return altura;
}

// Función para calcular la superficie del terreno
float calcularSuperficie(float base, float altura) {
    return (base * altura) / 2;
}

// Función para concatenar el apellido y nombre al string si la superficie es menor a 30 m²
void concatenarNombre(char nombres[], char nuevoNombre[]) {
    if (strlen(nombres) > 0) {
        strcat(nombres, " "); // Agregar espacio si ya hay nombres
    }
    strcat(nombres, nuevoNombre); // Concatenar el nuevo nombre
}

int main() {
    char nombresMenores30[1000] = "";  // String para almacenar los nombres concatenados
    char apellidoNombre[100];          // Variable para almacenar temporalmente el apellido y nombre
    float base, altura, superficie;
    
    // Primer lectura y verificación antes de entrar al bucle
    leerNombre(apellidoNombre);
    base = leerBase();
    altura = leerAltura();

    // Verificar si podemos seguir operando
    while (base > 0 && altura > 0) {
        // Calcular la superficie
        superficie = calcularSuperficie(base, altura);

        // Si la superficie es menor a 30 m², concatenar el nombre
        if (superficie < 30) {
            concatenarNombre(nombresMenores30, apellidoNombre);
        }

        // Volver a leer y verificar
        leerNombre(apellidoNombre);
        base = leerBase();
        altura = leerAltura();
    }

    // Mostrar el resultado final
    printf("Nombres de dueños con terrenos menores a 30m²: %s\n", nombresMenores30);

    return 0;
}
