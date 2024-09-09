#include <stdio.h>

int main() {
    int N, i, mayoresPrimero = 0, positivosMenoresR = 0, positivosPares = 0;
    float R, numeros[100], sumaPositivosMenoresR = 0.0, promedio, porcentaje;
    
    // 1. Lectura de datos
    printf("Ingrese el valor de R: ");
    scanf("%f", &R);
    
    printf("Ingrese la cantidad de numeros (N, maximo 100): ");
    scanf("%d", &N);
    
    if (N > 100) {
        printf("El valor de N excede el limite de 100.\n");
        return 1; // Salir si N es mayor a 100
    }
    
    // 1.3 Leer los valores del conjunto
    printf("Ingrese los %d numeros reales:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%f", &numeros[i]);
    }

    // El primer número es numeros[0]
    
    // 2. Procesamiento de datos
    for (i = 1; i < N; i++) {  // Empezamos desde el segundo número
        // 2.2.1 Verificar si es mayor que el primero ingresado
        if (numeros[i] > numeros[0]) {
            mayoresPrimero++;
        }

        // 2.2.2 Verificar si el número es positivo
        if (numeros[i] > 0) {
            // 2.2.2.1 Si es menor que R
            if (numeros[i] < R) {
                sumaPositivosMenoresR += numeros[i];
                positivosMenoresR++;
            }
            
            // 2.2.2.2 Verificar si es par
            if ((int)numeros[i] % 2 == 0) {
                positivosPares++;
            }
        }
    }

    // 3. Cálculos finales
    if (positivosMenoresR > 0) {
        promedio = sumaPositivosMenoresR / positivosMenoresR;
    }

    porcentaje = ((float)positivosPares / N) * 100;

    // 4. Mostrar resultados
    printf("Cantidad de valores mayores que el primero(%.2f): %d\n", numeros[0], mayoresPrimero);
    
    if (positivosMenoresR > 0) {
        printf("Promedio de los valores positivos menores que R(%.2f): %.2f\n", R,promedio);
    } else {
        printf("No hay valores positivos menores que R(%.2f).\n",R);
    }

    printf("Porcentaje de valores positivos pares: %.2f%%\n", porcentaje);

    return 0;
}
