#include <stdio.h>
#define MAX 10

int main() {
  int condition = 0, count = 0, frecuencia, arrFrecuencia[MAX];
  float oxigeno;

  printf("Bienvenido a nuestro sistema de salud\n");
  printf("Vamos a analizar la frecuencia cardiaca y oxígeno en sangre de "
         "distintos pacientes\n");
  do {
    printf("Para el paciente %d", count + 1);

    // lectura datos
    printf("\nIngrese su frecuencia cardiaca(negativo para detenerse): ");
    scanf("%d", &frecuencia);
    printf("\nIngrese su % de oxigeno en sangre(negativo para detenerse): ");
    scanf("%f", &oxigeno);
    if (frecuencia < 0 || oxigeno < 0) {
      condition = 1;
      break;
    }

    // cargar el array
    arrFrecuencia[count] = frecuencia;
    count++;
  } while (count < MAX && !condition);

  //   calcular promedio de frecuencias
  int sum = 0;
  for (int i = 0; i < count; i++) {
    sum += arrFrecuencia[i];
  }
  float promedio = (float)sum / count;

  // generar un nuevo array de frecuencias que esten por debajo del promedio
  int arrFrecuenciaBajoPromedio[MAX];
  int countBajoPromedio = 0;
  for (int i = 0; i < count; i++) {
    if (arrFrecuencia[i] < promedio) {
      arrFrecuenciaBajoPromedio[countBajoPromedio] = arrFrecuencia[i];
      countBajoPromedio++;
    }
  }

  // mostrar nuevo array
  printf("Las frecuencias por debajo del promedio (%.2f) son: ", promedio);
  for (int i = 0; i < countBajoPromedio; i++) {
    printf("%d ", arrFrecuenciaBajoPromedio[i]);
  }

  return 0;
}