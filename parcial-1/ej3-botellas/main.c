#include <stdio.h>

#define MAX_BOTELLAS 10

void validarVolumen(float *volumenBotella) {
  while (*volumenBotella != 0.5 && *volumenBotella != 0.75 &&
         *volumenBotella != 1) {
    printf("\nEl volumen ingresado es inválido. Valores permitidos (0.5 l - "
           "0.75 l - 1 litro)");
    printf("\nVolumen: ");
    scanf("%f", volumenBotella);
  }
}

void readData(char marca[][20], float volumenBotella[], float precioBotella[],
              int ventasBotella[], int *n) {
  int i = 0;
  printf("\nIngrese los datos de la botella Nro %d", i + 1);
  printf("\nMarca: ");
  scanf("%s", &marca[i]);
  printf("Volumen: ");
  scanf("%f", &volumenBotella[i]);
  validarVolumen(&volumenBotella[i]);
  printf("Precio: ");
  scanf("%f", &precioBotella[i]);
  printf("Cantidad vendida: ");
  scanf("%d", &ventasBotella[i]);

  while (i < MAX_BOTELLAS && precioBotella[i] > 0 && ventasBotella[i] > 0) {
    i++;
    printf("\nIngrese los datos de la botella Nro %d", i + 1);
    printf("\nMarca: ");
    scanf("%s", &marca[i]);
    printf("Volumen: ");
    scanf("%f", &volumenBotella[i]);
    validarVolumen(&volumenBotella[i]);
    printf("Precio: ");
    scanf("%f", &precioBotella[i]);
    printf("Cantidad vendida: ");
    scanf("%d", &ventasBotella[i]);
  }
  *n = i;
}

int main() {
  char marca[MAX_BOTELLAS][20];
  float volumenBotella[MAX_BOTELLAS], precioBotella[MAX_BOTELLAS];
  int ventasBotella[MAX_BOTELLAS], n = 0;

  readData(marca, volumenBotella, precioBotella, ventasBotella, &n);

  printf("\nse leyeron %d botellas\n", n);
  for (int i = 0; i < n; i++) {
    printf("\nBotella %d: marca %s - volumen %.2f - precio %.2f - cantidad "
           "vendida %d.",
           i + 1, marca[i], volumenBotella[i], precioBotella[i],
           ventasBotella[i]);
  }
  return 0;
}