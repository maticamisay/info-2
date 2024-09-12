#include <stdio.h>

int main() {
  int condition = 0, N, condA = 0;
  do {
    printf("Ingrese un entero (IMPAR para comenzar): ");
    scanf("%d", &N);

    // validar condicion
    if (N % 2 != 0) {
      condition = 1;
      printf("Se ingresó un número impar: %d. Continuamos con la carga.\n", N);
    }
  } while (!condition);
  int enteros[N];

  printf("------------------\n");
  printf("Ingrese %d valores enteros: \n", N);
  for (int i = 0; i < N; i++) {
    printf("Valor %d:  ", i + 1);
    scanf("%d", &enteros[i]);

    if (enteros[i] > -10 && enteros[i] < 10) {
      condA++;
    }
  }

  // Mostrar los números almacenados en el array
  printf("------------------\n");
  printf("A) Cantidad de datos comprendidos entre -10 y 10: %d\n", condA);
  printf("B) Valores pares distintos de 2 y 4: ");
  for (int i = 0; i < N; i++) {
    int a = enteros[i];
    if (a % 2 == 0 && a != 2 && a != 4) {
      printf("%d ", a);
    }
  }

  return 0;
}