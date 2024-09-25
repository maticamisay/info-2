#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Función para leer el código del dron
void leerCodigo(char codigo[]) {
    printf("Codigo: ");
    scanf("%s", codigo);
}

// Función para leer el precio del dron
float leerPrecio() {
    float precio;
    printf("Precio (USD): ");
    scanf("%f", &precio);
    return precio;
}

// Función para verificar si el código comienza con "M" y termina en "3"
bool esCodigoValido(char codigo[]) {
    int longitudCodigo = strlen(codigo);
    return (codigo[0] == 'M' && codigo[longitudCodigo - 1] == '3');
}

int main() {
    char codigo[10];
    float precio;
    float recaudacionTotal = 0.0;

    // 1. Lectura inicial de datos
    leerCodigo(codigo);
    precio = leerPrecio();

    // 2. Validar el precio antes de entrar en el ciclo
    while (precio <= 1000) {
        // 3. Verificar si el código es válido
        if (esCodigoValido(codigo)) {
            recaudacionTotal += precio;
        }

        // 4. Volver a leer los datos
        leerCodigo(codigo);
        precio = leerPrecio();
    }

    // 5. Mostrar resultados
    printf("Recaudacion total para los drones con codigo que comienzan con 'M' y terminan en '3': %.2f USD\n", recaudacionTotal);

    return 0;
}
