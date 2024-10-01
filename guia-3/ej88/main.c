// Ingrese en un arreglo dinámico las notas obtenidas en los exámenes que rindió
// un alumno. La cantidad de exámenes rendidos deberá ser ingresada por teclado.
// Se pide:
// a) Calcular el promedio de notas. Mostrar el promedio en el main.
// b) Generar un nuevo arreglo dinámico con aquellas notas superiores al
// promedio obtenido en el punto anterior. Mostrar las notas en el main.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int cantidadExamenes;
  float *notas;
} Estudiante;

// Función para ingresar las notas del estudiante
void ingresarNotas(Estudiante *estudiante) {
  printf("Ingrese la cantidad de exámenes rendidos: ");
  scanf("%d", &(estudiante->cantidadExamenes));

  // Validar que la cantidad de exámenes sea positiva
  if (estudiante->cantidadExamenes <= 0) {
    printf("La cantidad de exámenes debe ser mayor a cero.\n");
    exit(1);
  }

  // Asignación dinámica de memoria para las notas
  estudiante->notas =
      (float *)malloc(estudiante->cantidadExamenes * sizeof(float));
  if (estudiante->notas == NULL) {
    printf("Error al asignar memoria.\n");
    exit(1);
  }

  // Ingreso de las notas
  for (int i = 0; i < estudiante->cantidadExamenes; i++) {
    printf("Ingrese la nota del examen %d: ", i + 1);
    scanf("%f", &(estudiante->notas[i]));

    // Validar que la nota esté en el rango válido (0 a 10)
    if (estudiante->notas[i] < 0 || estudiante->notas[i] > 10) {
      printf("La nota debe estar entre 0 y 10.\n");
      i--; // Repetir la entrada de esta nota
    }
  }
}

// Función para calcular el promedio de las notas
float calcularPromedio(Estudiante estudiante) {
  float suma = 0;
  for (int i = 0; i < estudiante.cantidadExamenes; i++) {
    suma += estudiante.notas[i];
  }
  return suma / estudiante.cantidadExamenes;
}

// Función para obtener las notas superiores al promedio
float *obtenerNotasSuperiores(Estudiante estudiante, float promedio,
                              int *cantidadNotasSuperiores) {
  // Contar cuántas notas son superiores al promedio
  int contador = 0;
  for (int i = 0; i < estudiante.cantidadExamenes; i++) {
    if (estudiante.notas[i] > promedio) {
      contador++;
    }
  }

  *cantidadNotasSuperiores = contador;

  // Si no hay notas superiores al promedio, retornar NULL
  if (contador == 0) {
    return NULL;
  }

  // Asignación dinámica de memoria para las notas superiores
  float *notasSuperiores = (float *)malloc(contador * sizeof(float));
  if (notasSuperiores == NULL) {
    printf("Error al asignar memoria.\n");
    exit(1);
  }

  // Almacenar las notas superiores
  int index = 0;
  for (int i = 0; i < estudiante.cantidadExamenes; i++) {
    if (estudiante.notas[i] > promedio) {
      notasSuperiores[index] = estudiante.notas[i];
      index++;
    }
  }

  return notasSuperiores;
}

// Función para guardar las notas superiores en un archivo
void guardarNotasEnArchivo(float *notas, int cantidad,
                           const char *nombreArchivo) {
  FILE *archivo = fopen(nombreArchivo, "w");
  if (archivo == NULL) {
    printf("Error al abrir el archivo %s.\n", nombreArchivo);
    return;
  }

  fprintf(archivo, "Notas superiores al promedio:\n");
  for (int i = 0; i < cantidad; i++) {
    fprintf(archivo, "Nota %d: %.2f\n", i + 1, notas[i]);
  }

  fclose(archivo);
  printf("\nLas notas superiores al promedio se han guardado en el archivo "
         "'%s'.\n",
         nombreArchivo);
}

int main() {
  Estudiante estudiante;
  ingresarNotas(&estudiante);

  float promedio = calcularPromedio(estudiante);
  printf("\nEl promedio de notas es: %.2f\n", promedio);

  int cantidadNotasSuperiores;
  float *notasSuperiores =
      obtenerNotasSuperiores(estudiante, promedio, &cantidadNotasSuperiores);

  if (notasSuperiores != NULL) {
    printf("\nNotas superiores al promedio:\n");
    for (int i = 0; i < cantidadNotasSuperiores; i++) {
      printf("Nota %d: %.2f\n", i + 1, notasSuperiores[i]);
    }

    // Guardar las notas superiores en un archivo
    guardarNotasEnArchivo(notasSuperiores, cantidadNotasSuperiores,
                          "notas_superiores.txt");

    // Liberar la memoria asignada para las notas superiores
    free(notasSuperiores);
  } else {
    printf("\nNo hay notas superiores al promedio.\n");
  }

  // Liberar la memoria asignada para las notas del estudiante
  free(estudiante.notas);

  return 0;
}
