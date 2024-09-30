#include <stdio.h>
#include <string.h>

#define MAX_BOTELLAS 10

void validarVolumen(float *volumenBotella) {
  while (*volumenBotella != 0.5 && *volumenBotella != 0.75 &&
         *volumenBotella != 1 && *volumenBotella != 1.5) {
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
  fgets(marca[i], 20, stdin);
  marca[i][strcspn(marca[i], "\n")] = 0;
  printf("Volumen: ");
  scanf("%f", &volumenBotella[i]);
  validarVolumen(&volumenBotella[i]);
  printf("Precio: ");
  scanf("%f", &precioBotella[i]);
  printf("Cantidad vendida: ");
  scanf("%d", &ventasBotella[i]);
  getchar();

  while (i < MAX_BOTELLAS && precioBotella[i] > 0 && ventasBotella[i] > 0) {
    i++;
    printf("\nIngrese los datos de la botella Nro %d", i + 1);
    printf("\nMarca: ");
    fgets(marca[i], 20, stdin);
    marca[i][strcspn(marca[i], "\n")] = 0;
    printf("Volumen: ");
    scanf("%f", &volumenBotella[i]);
    validarVolumen(&volumenBotella[i]);
    printf("Precio: ");
    scanf("%f", &precioBotella[i]);
    printf("Cantidad vendida: ");
    scanf("%d", &ventasBotella[i]);
    getchar();
  }
  *n = i;
}

void calcularPromedioSolicitado(char marca[][20], float volumenBotella[],
                                float precioBotella[], int ventasBotella[],
                                int n, char query[]) {
  int counter = 0;
  float suma = 0, promedio = 0;
  for (int i = 0; i < n; i++) {
    if (strcmp(marca[i], query) == 0 &&
        (volumenBotella[i] == 0.75 || volumenBotella[i] == 1)) {
      printf("\nla marca en posicion %d es igual a la marca buscada", i + 1);
      counter++;
      suma += precioBotella[i];
    }
  }
  promedio = suma / counter;
  printf("El valor del promedio para la marca %s con volúmenes entre 750ml y "
         "1000ml es: %.2f",
         query, promedio);
}

void filtrarMarcasBien(char marca[][20], float precioBotella[],
                       int ventasBotella[], float volumenBotella[], int n,
                       char marcasBien[][20], float ventasBien[],
                       float volumenBien[], int *m) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (strncmp(marca[i], "Bien", 4) == 0) {
      int found = 0;
      int k = 0;
      while (found != 1 && k < j) {
        if (strcmp(marcasBien[k], marca[i]) == 0) {
          ventasBien[k] += precioBotella[i] * ventasBotella[i];
          volumenBien[k] += volumenBotella[i] * ventasBotella[i];
          found = 1;
        }
        k++;
      }
      if (!found) {
        strcpy(marcasBien[j], marca[i]);
        ventasBien[j] = precioBotella[i] * ventasBotella[i];
        volumenBien[j] += volumenBotella[i] * ventasBotella[i];
        j++;
      }
    }
  }
  *m = j;
}

int main() {
  char marca[MAX_BOTELLAS][20], query[20];
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

  // punto a)
  printf("\n\nIngrese el nombre de una marca para buscar su promedio: ");
  scanf("%s", &query);
  calcularPromedioSolicitado(marca, volumenBotella, precioBotella,
                             ventasBotella, n, query);

  // punto b) Filtrar marcas que comienzan con "Bien"
  char marcasBien[MAX_BOTELLAS][20];
  float ventasBien[MAX_BOTELLAS], volumenBien[MAX_BOTELLAS];
  int m = 0;
  filtrarMarcasBien(marca, precioBotella, ventasBotella, volumenBotella, n,
                    marcasBien, ventasBien, volumenBien, &m);

  // punto c)
  int posicionC[MAX_BOTELLAS], counterC = 0;

  printf("\n\nMarcas que comienzan con 'Bien' y sus ventas totales:\n");
  float ventaTotal = 0;
  for (int i = 0; i < m; i++) {
    printf("Marca: %s - Ventas Totales: %.2f\n", marcasBien[i], ventasBien[i]);
    ventaTotal += ventasBien[i];
    if (ventasBien[i] > 50000) {
      posicionC[counterC] = i;
      counterC++;
    }
  }

  printf("\nVenta total de todas las marcas que comienzan con 'Bien': %.2f\n",
         ventaTotal);

  printf("\nMarcas más vendidas: ");
  for (int i = 0; i < counterC; i++) {
    printf("\nMarca: %s - Volumen: %.2f", marcasBien[posicionC[i]],
           volumenBien[posicionC[i]]);
  }

  return 0;
}