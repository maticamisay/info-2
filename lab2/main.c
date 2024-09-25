// ENUNCIADO
//  Un hospital necesita procesar la informacion de sus medicos, cuyos datos son
//  los siguientes:
// - apellido (string)
// - sueldo (real)
// La carga finaliza cuando se ingrese el exacto apellido "FIN"
// a) identificar mostrar el apellido más más el sueldo de ese médico, y la
// letra con la cual comienza y termina el apellido.

#include <stdio.h>
#include <string.h>

#define MAX_MEDICOS 130
#define MAX_APELLIDOS 50

// leer un apellido a la vez, calidar si es diferente a "FIN"
// guardarlo y preguntar el salario
void readData(char apellidos[][MAX_APELLIDOS],
              float sueldos[], int *n) {
  char apellido[MAX_APELLIDOS];
  float sueldo;
  int i = 0;

  printf("Ingrese el apellido del medico %d: ", i + 1);
  scanf("%s", apellido);

  while (strcmp(apellido, "FIN") != 0 && i < MAX_MEDICOS) {
    strcpy(apellidos[i], apellido);
    printf("Ingrese el sueldo del medico %d: ", i + 1);
    scanf("%f", &sueldos[i]);
    
    i++;

    if (i < MAX_MEDICOS) {
      printf("Ingrese el apellido del medico %d: ", i + 1);
      scanf("%s", apellido);
    }
  }

  *n = i;
}

// Funcion para procesar los datos de los medicos: encontrar el apellido más largo
void processMedicos(char apellidos[MAX_MEDICOS][MAX_APELLIDOS],
                    float sueldos[MAX_MEDICOS], int n) {
  int maxLength = 0;
  int maxIndex = 0;

  for (int i = 0; i < n; i++) {
    int length = strlen(apellidos[i]);
    if (length > maxLength) {
      maxLength = length;
      maxIndex = i;
    }
  }

  printf("Apellido más largo: %s\n", apellidos[maxIndex]);
  printf("Sueldo: %.3f\n", sueldos[maxIndex]);
  printf("Primera letra: %c\n", apellidos[maxIndex][0]);
  printf("Última letra: %c\n", apellidos[maxIndex][maxLength - 1]);
}

int main() {
  char apellidos[MAX_MEDICOS][MAX_APELLIDOS];
  float sueldos[MAX_MEDICOS];

  int n;
  readData(apellidos, sueldos, &n);

  processMedicos(apellidos, sueldos, n);

  return 0;
}
