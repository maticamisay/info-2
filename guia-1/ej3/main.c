#include <stdio.h>

int main() {
    int N, i, rechazada = 0, aptas = 0, aptasBlanco = 0;
    float densidad, sumaDensidades = 0.0, promedio;
    char color;

    // 1. Lectura de datos
    printf("Ingrese la cantidad de muestras (N): ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        // 1.2.1 Leer el valor de la densidad
        printf("Ingrese la densidad de la muestra %d: ", i + 1);
        scanf("%f", &densidad);

        // 1.2.2 Leer la letra del color
        printf("Ingrese la letra del color de la muestra %d: ", i + 1);
        scanf(" %c", &color); // El espacio antes de %c es importante para capturar correctamente el carácter

        // 2. Procesamiento de datos
        if (densidad < 100 || densidad > 120) {
            // 2.1.1 Muestra rechazada
            rechazada++;
        } else {
            // 2.2.1 Muestra apta
            sumaDensidades += densidad;
            aptas++;

            // 2.2.3 Verificar si es de color blanco (consideramos mayúsculas o minúsculas)
            if (color == 'B' || color == 'b') {
                aptasBlanco++;
            }
        }
    }

    // 3. Cálculos finales
    if (aptas > 0) {
        promedio = sumaDensidades / aptas;
    }

    // 4. Mostrar resultados
    printf("Cantidad de muestras rechazadas: %d\n", rechazada);

    if (aptas > 0) {
        printf("Promedio de densidad de las muestras aptas: %.2f\n", promedio);
    } else {
        printf("No hay muestras aptas.\n");
    }

    printf("Cantidad de muestras aptas de color blanco: %d\n", aptasBlanco);

    return 0;
}
