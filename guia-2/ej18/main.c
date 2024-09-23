#include <stdio.h>
#include <stdbool.h>

// Función para leer tres valores reales
void leerValores(float valores[3]) {
    printf("Ingrese tres valores reales: ");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &valores[i]);
    }
}

// Función para calcular el promedio de tres valores
float calcularPromedio(float valores[3]) {
    return (valores[0] + valores[1] + valores[2]) / 3.0;
}

// Función para calcular el producto de tres valores
float calcularProducto(float valores[3]) {
    return valores[0] * valores[1] * valores[2];
}

// Función para verificar si los tres valores son iguales
bool sonIguales(float valores[3]) {
    return (valores[0] == valores[1] && valores[1] == valores[2]);
}

int main() {
    float valores[3]; // Arreglo para almacenar la terna de valores
    float promedio, producto;

    // Leer los valores inicialmente antes de entrar al while
    leerValores(valores);

    // Validar antes de ejecutar el ciclo while
    while (!sonIguales(valores)) {
        // 1. Procesamiento de datos
        promedio = calcularPromedio(valores);
        producto = calcularProducto(valores);

        // 2. Mostrar resultados
        printf("Promedio de la terna: %.2f\n", promedio);
        printf("Producto de la terna: %.2f\n", producto);

        // 3. Volver a leer los valores
        leerValores(valores);
    }

    // Mensaje final al salir del ciclo
    printf("Los tres valores son iguales. Finalizando...\n");

    return 0;
}
