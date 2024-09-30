#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES_PLANILLA 5 // lo reducimos para trabajar
#define TOTAL_CLIENTES 40       // 5 * 8 = 40
#define MAX_LLAMADAS 15         // máximo de 15 llamadas por cliente
#define MAX_STRING_LENGTH 50    // Longitud máxima para las cadenas formateadas

void checkB(char result[], int *count) {
  if (strcmp(result, "E") == 0) {
    (*count)++;
  }
}

// Función para contar la cantidad de "E" en los resultados de un cliente
int contarE(char resultadoLlamadas[][MAX_LLAMADAS][2], int clienteNro,
            unsigned int numLlamadas[]) {
  int count = 0;
  for (int i = 0; i < numLlamadas[clienteNro]; i++) {
    if (strcmp(resultadoLlamadas[clienteNro][i], "E") == 0) {
      count++;
    }
  }
  return count;
}

// Función para formatear el CUIL a la forma XX-XXXXXXXX-X
void formatearCUIL(char *originalCUIL, char *formattedCUIL) {
  snprintf(formattedCUIL, 13, "%c%c-%c%c%c%c%c%c%c%c-%c", originalCUIL[0],
           originalCUIL[1], originalCUIL[2], originalCUIL[3], originalCUIL[4],
           originalCUIL[5], originalCUIL[6], originalCUIL[7], originalCUIL[8],
           originalCUIL[9], originalCUIL[10]);
}

// Función para generar la lista de clientes con más "E" que el promedio
void generarListaClientes(char CUILs[][12],
                          char resultadoLlamadas[][MAX_LLAMADAS][2],
                          unsigned int numLlamadas[], float promedioE,
                          int clienteNro,
                          char listaClientes[][MAX_STRING_LENGTH]) {
  int count, pos = 0;
  char formattedCUIL[13]; // CUIL formateado con guiones

  for (int i = 0; i < clienteNro; i++) {
    count = contarE(resultadoLlamadas, i, numLlamadas);
    if ((float)count / numLlamadas[i] > promedioE) {
      // Formatear el CUIL
      formatearCUIL(CUILs[i], formattedCUIL);
      // Crear la cadena "CUIL - Planilla X"
      snprintf(listaClientes[pos], MAX_STRING_LENGTH, "%s - Planilla %d",
               formattedCUIL, (i / MAX_CLIENTES_PLANILLA) + 1);
      pos++;
    }
  }
}

int main() {
  int nroPlanillas, maxCustomer;
  printf("\nIngrese la cantidad de planillas a procesar (entran 5 clientes x "
         "planilla): ");
  scanf("%d", &nroPlanillas);
  while (nroPlanillas > 8) {
    printf("Solo se permite hasta 8. Intente de nuevo: ");
    scanf("%d", &nroPlanillas);
  }
  maxCustomer = nroPlanillas * MAX_CLIENTES_PLANILLA;

  unsigned int telefonos[TOTAL_CLIENTES], numLlamadas[TOTAL_CLIENTES];
  char CUILs[TOTAL_CLIENTES][12],
      resultadoLlamadas[TOTAL_CLIENTES][MAX_LLAMADAS][2];
  int j = 0, finalizado = 0;
  int clienteNro = 0, counterE = 0;

  // Carga de datos
  while (clienteNro < maxCustomer && !finalizado) {
    printf("\nDatos del cliente #%d", clienteNro + 1);
    printf("\nTelefono: ");
    scanf("%u", &telefonos[clienteNro]); // %u para unsigned int
    printf("CUIL: ");
    scanf("%s", CUILs[clienteNro]);
    printf("Numero de llamadas: ");
    scanf("%u", &numLlamadas[clienteNro]); // %u para unsigned int
    printf("--Resultado de cada llamada--\n");
    j = 0;
    while (j < numLlamadas[clienteNro] && !finalizado) {
      printf("Resultado llamada #%d: ", j + 1);
      scanf("%s", resultadoLlamadas[clienteNro][j]);
      if (strcmp(resultadoLlamadas[clienteNro][j], "#") == 0) {
        finalizado =
            1; // Marcamos que hemos ingresado el carácter de finalización
      } else {
        checkB(resultadoLlamadas[clienteNro][j], &counterE);
        j++;
      }
    }
    if (!finalizado) {
      clienteNro++;
    }
  }

  // Calcular el promedio de "E"
  float promedioE = (float)counterE / clienteNro;
  printf("\nPromedio de E: %.2f\n", promedioE);

  char listaClientes[TOTAL_CLIENTES]
                    [MAX_STRING_LENGTH]; // Array para guardar los clientes con
                                         // tasa de E mayor al promedio
  // Generar la lista de clientes con tasa de E mayor al promedio
  generarListaClientes(CUILs, resultadoLlamadas, numLlamadas, promedioE,
                       clienteNro, listaClientes);

  // Mostrar la lista generada
  printf("\nClientes con tasa de E mayor al promedio:\n");
  for (int i = 0; i < clienteNro; i++) {
    if (strlen(listaClientes[i]) >
        0) { // Solo mostrar los clientes que tienen entradas válidas
      printf("%s\n", listaClientes[i]);
    }
  }

  return 0;
}
