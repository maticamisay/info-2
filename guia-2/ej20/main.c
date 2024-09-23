#include <stdio.h>

// Función para calcular la potencia de x elevado a y mediante productos sucesivos
int potencia(int x, int y) {
    int resultado = 1;
    for (int i = 0; i < y; i++) {
        resultado *= x;
    }
    return resultado;
}

// Función para mostrar los valores intermedios entre x e y
void mostrarIntermedios(int x, int y) {
    printf("Valores intermedios entre %d y %d: ", x, y);
    for (int i = x + 1; i < y; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int x, y;
    int sumaX = 0, cantidadXPositivos = 0;
    int paresConCero = 0, cantidadPares = 0;

    // Lectura inicial de valores
    printf("Ingrese un par de valores enteros x e y (ingrese 0 0 para finalizar): ");
    scanf("%d %d", &x, &y);

    // Mientras la diferencia entre x e y no sea impar y divisible por 7
    while ((x - y) % 2 == 0 || (x - y) % 7 != 0) {
        cantidadPares++; // Contador de pares procesados

        // a) Si y es mayor que x, mostrar los valores intermedios
        if (y > x) {
            mostrarIntermedios(x, y);
        }

        // b) Si y es mayor que 0, calcular x elevado a y
        if (y > 0) {
            int resultadoPotencia = potencia(x, y);
            printf("%d elevado a %d es: %d\n", x, y, resultadoPotencia);
        }

        // c) Calcular el promedio de los valores x para los x > 0
        if (x > 0) {
            sumaX += x;
            cantidadXPositivos++;
        }

        // d) Contar los pares donde al menos uno de los valores sea 0
        if (x == 0 || y == 0) {
            paresConCero++;
        }

        // Leer otro par de valores
        printf("Ingrese un par de valores enteros x e y: ");
        scanf("%d %d", &x, &y);
    }

    // 3. Cálculos finales

    // c) Promedio de los valores x > 0
    float promedioXPositivos = 0.0;
    if (cantidadXPositivos > 0) {
        promedioXPositivos = (float)sumaX / cantidadXPositivos;
    }

    // d) Porcentaje de pares con al menos un valor igual a 0
    float porcentajeConCero = 0.0;
    if (cantidadPares > 0) {
        porcentajeConCero = ((float)paresConCero / cantidadPares) * 100;
    }

    // 4. Mostrar resultados finales
    printf("Promedio de los valores x > 0: %.2f\n", promedioXPositivos);
    printf("Porcentaje de pares con al menos un valor igual a 0: %.2f%%\n", porcentajeConCero);

    return 0;
}
