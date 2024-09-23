#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cantidadTiradas, cara = 0, cruz = 0;

    // 1. Lectura de datos
    printf("Ingrese la cantidad de veces que se desea tirar la moneda: ");
    scanf("%d", &cantidadTiradas);

    // Inicializar el generador de números aleatorios
    srand(time(NULL));

    // 2. Simulación de las tiradas
    for (int i = 0; i < cantidadTiradas; i++) {
        int tirada = rand() % 2; // Generar 0 o 1: 0 = Cara, 1 = Cruz
        printf("Tirada %d: %d\n", i + 1, tirada);
        if (tirada == 0) {
            cara++; // Si es 0, es "Cara"
        } else {
            cruz++; // Si es 1, es "Cruz"
        }
    }

    // 3. Cálculos finales
    float porcentajeCara = (cara / (float)cantidadTiradas) * 100;
    float porcentajeCruz = (cruz / (float)cantidadTiradas) * 100;

    // 4. Mostrar resultados
    printf("Resultado de la simulación:\n");
    printf("Cantidad de veces que salió Cara: %d (%.2f%%)\n", cara, porcentajeCara);
    printf("Cantidad de veces que salió Cruz: %d (%.2f%%)\n", cruz, porcentajeCruz);

    return 0;
}
