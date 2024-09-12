#include <stdio.h>

int main() {
  int condition = 0, count = 0, condA = 0, condB = 0;
  int edad;
  float peso, sumaCondB = 0.0;

  printf("Bienvenido a nuestro software para carga de pacientes.\n");
  printf("Se producirá la carga de 400 pacientes, si desea deterse antes "
         "ingrese un peso con valor NEGATIVO para detenerse.\n");
  do {
    printf("\nPaciente %d\n", count + 1);
    printf("Peso: ");
    scanf("%f", &peso);
    if (peso < 0) {
      condition = 1;
      break;
    }
    printf("Edad: ");
    scanf("%d", &edad);

    if (edad > 7 && edad < 11) {
      printf("Este paciente cumple con una condición para el estudio.\n");
      condA++;
      if (peso > 50) {
        condB++;
        sumaCondB += peso;
      }
    }
    count++;
  } while (count < 10 && !condition);

  if (condA > 0) {
    printf("Se encontraron un total de %d pacientes con edad entre 7 y 11\n",
           condA);
    float prom = sumaCondB / condB;
    printf("El promedio de peso de pacientes mayores de 50kg: %.2f", prom);
  }
  return 0;
}