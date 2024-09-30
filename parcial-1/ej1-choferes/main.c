#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VIAJES 500
#define MAX_CHOFERES 12
#define MAX_MOVILES 34

// Función para validar si un código de móvil es válido
int esCodigoMovilValido(char movil[]) {
    return strncmp(movil, "rms", 3) == 0 && atoi(movil + 3) >= 1 && atoi(movil + 3) <= MAX_MOVILES;
}

// Función para calcular el promedio de montos
float calcularPromedio(float montos[], int cantidadViajes) {
    float total = 0;
    for (int i = 0; i < cantidadViajes; i++) {
        total += montos[i];
    }
    return (cantidadViajes > 0) ? total / cantidadViajes : 0;
}

// Función para mostrar la cantidad de viajes entre los días 10 al 22 y cuyo costo supera en un 15% el monto promedio
void mostrarViajesCostoMayor(float montos[], int dias[], int cantidadViajes, float promedio) {
    int cantidad = 0;
    for (int i = 0; i < cantidadViajes; i++) {
        if (dias[i] >= 10 && dias[i] <= 22 && montos[i] > promedio * 1.15) {
            cantidad++;
        }
    }
    printf("Cantidad de viajes con monto mayor al 15%% del promedio entre los dias 10 y 22: %d\n", cantidad);
}

// Función para calcular el total recaudado por cada chofer y mostrar el que más recaudó
void calcularRecaudacionChoferes(char choferes[][10], float montos[], char codigosChoferes[][10], int cantidadViajes) {
    float recaudacion[MAX_CHOFERES] = {0}; // Monto total recaudado por cada chofer
    int maxChofer = -1;
    float maxMonto = -1;

    for (int i = 0; i < cantidadViajes; i++) {
        int choferIdx = atoi(choferes[i] + 4) - 1; // Convertimos "chof01" a un índice (0-11)
        recaudacion[choferIdx] += montos[i];
    }

    // Mostrar cuánto se paga a cada chofer y determinar el que más recaudó
    for (int i = 0; i < MAX_CHOFERES; i++) {
        float pago = recaudacion[i] * 0.62;
        printf("Monto para %s: %.2f\n", codigosChoferes[i], pago); // Imprime el chofer y el monto que le corresponde
        if (recaudacion[i] > maxMonto) {
            maxMonto = recaudacion[i];
            maxChofer = i;
        }
    }

    // Mostrar el chofer que más recaudó
    if (maxChofer != -1) {
        printf("El chofer con mayor monto recaudado es: %s con un monto total de %.2f\n", codigosChoferes[maxChofer], recaudacion[maxChofer]);
    }
}

// Función para crear el string con los códigos de los móviles que no realizaron viajes
void crearStringMovilesSinViajes(char movilesRealizados[][10], int cantidadViajes, char stringFinal[]) {
    int movilesSinViajes[MAX_MOVILES] = {0}; // Inicializamos todos los móviles como no usados

    // Verificamos los móviles que realizaron viajes
    for (int i = 0; i < cantidadViajes; i++) {
        int movilIdx = atoi(movilesRealizados[i] + 3) - 1;
        if (movilIdx >= 0 && movilIdx < MAX_MOVILES) {
            movilesSinViajes[movilIdx] = 1; // Marcamos el móvil como que realizó un viaje
        }
    }

    // Concatenamos los móviles que no realizaron viajes en el string final
    for (int i = 0; i < MAX_MOVILES; i++) {
        if (!movilesSinViajes[i]) {
            char movil[10];
            sprintf(movil, "rms%02d", i + 1); // Formateamos el código del móvil
            if (strlen(stringFinal) > 0) {
                strcat(stringFinal, "!=!");
            }
            strcat(stringFinal, movil);
        }
    }
}

int main() {
    int mes, dia, cantidadViajes = 0;
    float montos[MAX_VIAJES];
    char choferes[MAX_VIAJES][10];
    char moviles[MAX_VIAJES][10];
    int dias[MAX_VIAJES];  // Arreglo para almacenar los días
    char codigosChoferes[MAX_CHOFERES][10] = {"chof01", "chof02", "chof03", "chof04", "chof05", "chof06", "chof07", "chof08", "chof09", "chof10", "chof11", "chof12"};
    char stringMovilesSinViajes[1000] = "";

    // Leer el mes
    printf("Ingrese el mes (1-12): ");
    scanf("%d", &mes);

    // Ingreso de datos
    while (cantidadViajes < MAX_VIAJES) {
        char movil[10];

        // Leer código del móvil
        printf("Ingrese el código del móvil (ej. rms01) o un código no válido para terminar: ");
        scanf("%s", movil);

        // Validar código del móvil
        if (!esCodigoMovilValido(movil)) {
            break; // Salir si el código de móvil no es válido
        }

        // Leer día y validar según el mes
        printf("Ingrese el día del viaje (1-31): ");
        scanf("%d", &dia);
        if ((mes == 2 && dia > 28) || ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) || dia < 1 || dia > 31) {
            printf("Día no válido según el mes. Intente de nuevo.\n");
            continue;
        }

        // Guardar el día
        dias[cantidadViajes] = dia;

        // Leer código del chofer
        printf("Ingrese el código del chofer (ej. chof01): ");
        scanf("%s", choferes[cantidadViajes]);

        // Leer el monto
        printf("Ingrese el monto cobrado por el viaje: ");
        scanf("%f", &montos[cantidadViajes]);

        // Guardar móvil y aumentar contador de viajes
        strcpy(moviles[cantidadViajes], movil);
        cantidadViajes++;
    }

    // a) Mostrar cantidad de viajes entre los días 10-22 y cuyo costo es mayor al 15% del promedio
    float promedio = calcularPromedio(montos, cantidadViajes);
    mostrarViajesCostoMayor(montos, dias, cantidadViajes, promedio);

    // b) Calcular y mostrar el monto total recaudado por cada chofer, y el chofer con mayor recaudación
    calcularRecaudacionChoferes(choferes, montos, codigosChoferes, cantidadViajes);

    // c) Crear string con móviles que no realizaron viajes
    crearStringMovilesSinViajes(moviles, cantidadViajes, stringMovilesSinViajes);
    printf("Móviles que no realizaron viajes: %s\n", stringMovilesSinViajes);

    return 0;
}
