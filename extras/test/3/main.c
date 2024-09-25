#include <stdio.h>
#include <string.h>

#define MAX_DIAS 100
#define MAX_NOMBRE 50

// Función para leer los datos de la estación
void leerDatos(char estaciones[MAX_DIAS][MAX_NOMBRE], int horas[MAX_DIAS], float temperaturas[MAX_DIAS], int dias) {
    for (int i = 0; i < dias; i++) {
        printf("Ingrese el nombre de la estacion (dia %d): ", i + 1);
        scanf("%s", estaciones[i]);
        printf("Ingrese la hora (12 o 24): ");
        scanf("%d", &horas[i]);
        printf("Ingrese la temperatura en °C: ");
        scanf("%f", &temperaturas[i]);
    }
}

// Función para encontrar el día con la mayor temperatura a medianoche para estaciones que comienzan con "El C"
int buscarMayorTemperatura(char estaciones[MAX_DIAS][MAX_NOMBRE], int horas[MAX_DIAS], float temperaturas[MAX_DIAS], int dias) {
    int diaMayorTemp = -1; // Inicialmente no hay día
    float mayorTemp = -1000; // Inicializamos con un valor bajo

    for (int i = 0; i < dias; i++) {
        // Filtrar estaciones que comiencen con "El C" y que sea la medianoche (hora 24)
        if (horas[i] == 24 && strncmp(estaciones[i], "El C", 4) == 0) {
            if (temperaturas[i] > mayorTemp) {
                mayorTemp = temperaturas[i];
                diaMayorTemp = i; // Guardamos el índice del día con la mayor temperatura
            }
        }
    }

    return diaMayorTemp; // Retorna el día (índice) con la mayor temperatura
}

int main() {
    int dias;
    char estaciones[MAX_DIAS][MAX_NOMBRE];
    int horas[MAX_DIAS];
    float temperaturas[MAX_DIAS];

    // Lectura de cantidad de días
    printf("Ingrese la cantidad de dias a procesar: ");
    scanf("%d", &dias);

    // Llamada a la función para leer los datos
    leerDatos(estaciones, horas, temperaturas, dias);

    // Llamada a la función para buscar la mayor temperatura a la medianoche
    int diaMayorTemp = buscarMayorTemperatura(estaciones, horas, temperaturas, dias);

    // Mostrar el resultado
    if (diaMayorTemp != -1) {
        printf("El dia con la mayor temperatura a la medianoche para estaciones que comienzan con 'El C' es: Dia %d, con una temperatura de %.2f°C\n", diaMayorTemp + 1, temperaturas[diaMayorTemp]);
    } else {
        printf("No se encontraron estaciones que comiencen con 'El C' o con temperaturas a la medianoche.\n");
    }

    return 0;
}
