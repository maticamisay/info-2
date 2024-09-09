#include <stdio.h>

int main() {
    float resistencia1, resistencia2, aislamiento1, aislamiento2;
    int cablesAnalizados = 0, primeraCalidad = 0, segundaCalidad = 0;
    float sumaResistencias = 0.0;
    float porcentajePrimera, porcentajeSegunda, promedioResistencias;
    
    // 1. Lectura de datos
    while (1) {
        // 1.2.1 Leer la resistencia del primer cable
        printf("Ingrese la resistencia del primer cable (0 para finalizar): ");
        scanf("%f", &resistencia1);
        
        if (resistencia1 == 0) {
            break; // Finaliza el ingreso de datos
        }

        // 1.2.2 Leer el aislamiento del primer cable
        printf("Ingrese el aislamiento del primer cable: ");
        scanf("%f", &aislamiento1);

        // 1.2.3 Leer la resistencia del segundo cable
        printf("Ingrese la resistencia del segundo cable: ");
        scanf("%f", &resistencia2);

        // 1.2.4 Leer el aislamiento del segundo cable
        printf("Ingrese el aislamiento del segundo cable: ");
        scanf("%f", &aislamiento2);

        // Incrementar la cantidad de cables analizados
        cablesAnalizados++;
        
        // Sumar resistencias para el cálculo posterior del promedio
        sumaResistencias += (resistencia1 + resistencia2) / 2;

        // 2. Procesamiento de datos
        int cumplePrimero = (resistencia1 >= 90 && resistencia1 <= 110) && (aislamiento1 > 10);
        int cumpleSegundo = (resistencia2 >= 90 && resistencia2 <= 110) && (aislamiento2 > 10);

        if (cumplePrimero && cumpleSegundo) {
            // 2.2.1 Ambos cables cumplen con las especificaciones - primera calidad
            primeraCalidad++;
        } else if (cumplePrimero || cumpleSegundo) {
            // 2.2.2 Uno de los cables no cumple con las especificaciones - segunda calidad
            segundaCalidad++;
        }
        // 2.2.3 Si ninguno cumple, no se cuenta como primera ni segunda calidad (malo)
    }

    // 3. Cálculos finales
    if (cablesAnalizados > 0) {
        // 3.1 Calcular el porcentaje de cables de primera calidad
        porcentajePrimera = ((float)primeraCalidad / cablesAnalizados) * 100;
        
        // 3.2 Calcular el porcentaje de cables de segunda calidad
        porcentajeSegunda = ((float)segundaCalidad / cablesAnalizados) * 100;
        
        // 3.3 Calcular el promedio de la resistencia de los cables
        promedioResistencias = sumaResistencias / cablesAnalizados;
    }

    // 4. Mostrar resultados
    printf("Cantidad de cables analizados: %d\n", cablesAnalizados);
    
    if (cablesAnalizados > 0) {
        printf("Porcentaje de cables de primera calidad: %.2f%%\n", porcentajePrimera);
        printf("Porcentaje de cables de segunda calidad: %.2f%%\n", porcentajeSegunda);
        printf("Promedio de la resistencia de los cables: %.2f Ohm\n", promedioResistencias);
    } else {
        printf("No se analizaron cables.\n");
    }

    return 0;
}
