#include <stdio.h>
#include <string.h>

#define MAX_LINEAS 520
#define MAX_AEROLINEAS 2 // Solo nos interesan aero31 y aero44
#define MAX_COCINEROS 20
#define MAX_MENUS 25

// Función para procesar los datos de facturación
void calcularFacturacion(char aerolineas[][10], int codigosMenu[], int cocineros[], int bandejas[], float preciosUnitarios[], int cantidadLineas, float *totalAero31, float *totalAero44, int *menuMasPedidoAero31, int *menuMasPedidoAero44)
{
    int pedidosMenuAero31[MAX_MENUS + 1] = {0};
    int pedidosMenuAero44[MAX_MENUS + 1] = {0};

    // Procesamos los datos de la planilla
    for (int i = 0; i < cantidadLineas; i++)
    {
        float montoTotal = bandejas[i] * preciosUnitarios[i];

        // Para "aero31"
        if (strcmp(aerolineas[i], "aero31") == 0)
        {
            *totalAero31 += montoTotal;
            pedidosMenuAero31[codigosMenu[i]] += bandejas[i]; // Contamos cuántas bandejas de cada menú fueron pedidas
        }

        // Para "aero44"
        if (strcmp(aerolineas[i], "aero44") == 0)
        {
            *totalAero44 += montoTotal;
            pedidosMenuAero44[codigosMenu[i]] += bandejas[i]; // Contamos cuántas bandejas de cada menú fueron pedidas
        }
    }

    // Encontramos el menú más pedido para "aero31"
    *menuMasPedidoAero31 = 0;
    for (int i = 1; i <= MAX_MENUS; i++)
    {
        if (pedidosMenuAero31[i] > pedidosMenuAero31[*menuMasPedidoAero31])
        {
            *menuMasPedidoAero31 = i;
        }
    }

    // Encontramos el menú más pedido para "aero44"
    *menuMasPedidoAero44 = 0;
    for (int i = 1; i <= MAX_MENUS; i++)
    {
        if (pedidosMenuAero44[i] > pedidosMenuAero44[*menuMasPedidoAero44])
        {
            *menuMasPedidoAero44 = i;
        }
    }
}

// Función para calcular el cocinero con más menús preparados y el monto total que cobrará
void calcularCocineroConMasMenus(int cocineros[], int bandejas[], float preciosUnitarios[], int cantidadLineas, int *cocineroMaxMenus, float *montoCocineroMax)
{
    int bandejasPorCocinero[MAX_COCINEROS + 1] = {0};
    float totalDineroPorCocinero[MAX_COCINEROS + 1] = {0};

    for (int i = 0; i < cantidadLineas; i++)
    {
        bandejasPorCocinero[cocineros[i]] += bandejas[i];                          // Cantidad de bandejas por cocinero
        totalDineroPorCocinero[cocineros[i]] += bandejas[i] * preciosUnitarios[i]; // Monto total generado por cocinero
    }

    *cocineroMaxMenus = 1;
    *montoCocineroMax = totalDineroPorCocinero[1] * 0.27;

    for (int i = 2; i <= MAX_COCINEROS; i++)
    {
        if (bandejasPorCocinero[i] > bandejasPorCocinero[*cocineroMaxMenus])
        {
            *cocineroMaxMenus = i;
            *montoCocineroMax = totalDineroPorCocinero[i] * 0.27; // 27% del monto generado
        }
    }
}

// Función para calcular el menú más solicitado por todas las aerolíneas y obtener los cocineros que lo prepararon
void calcularMenuMasSolicitado(int codigosMenu[], int cocineros[], int bandejas[], int cantidadLineas, int *menuMasSolicitado, char stringCocineros[])
{
    int bandejasPorMenu[MAX_MENUS + 1] = {0};
    int cocinerosDelMenu[MAX_COCINEROS + 1] = {0}; // Para evitar repetir cocineros

    // Contamos cuántas bandejas se pidieron por menú
    for (int i = 0; i < cantidadLineas; i++)
    {
        bandejasPorMenu[codigosMenu[i]] += bandejas[i];
    }

    // Encontramos el menú más solicitado
    *menuMasSolicitado = 1;
    for (int i = 2; i <= MAX_MENUS; i++)
    {
        if (bandejasPorMenu[i] > bandejasPorMenu[*menuMasSolicitado])
        {
            *menuMasSolicitado = i;
        }
    }

    // Crear el string con los cocineros que prepararon el menú más solicitado
    stringCocineros[0] = '\0'; // Inicializamos el string vacío
    for (int i = 0; i < cantidadLineas; i++)
    {
        if (codigosMenu[i] == *menuMasSolicitado && cocinerosDelMenu[cocineros[i]] == 0)
        {
            if (strlen(stringCocineros) > 0)
            {
                strcat(stringCocineros, "###");
            }
            char temp[10];
            sprintf(temp, "%d", cocineros[i]);
            strcat(stringCocineros, temp);
            cocinerosDelMenu[cocineros[i]] = 1; // Marcamos el cocinero como ya incluido
        }
    }
}

int main()
{
    char aerolineas[MAX_LINEAS][10];
    int codigosMenu[MAX_LINEAS];
    int cocineros[MAX_LINEAS];
    int bandejas[MAX_LINEAS];
    float preciosUnitarios[MAX_LINEAS];
    int cantidadLineas = 0;

    // Variables para los cálculos
    float totalAero31 = 0.0, totalAero44 = 0.0;
    int menuMasPedidoAero31 = 0, menuMasPedidoAero44 = 0;
    int cocineroMaxMenus = 0;
    float montoCocineroMax = 0.0;
    int menuMasSolicitado = 0;
    char stringCocineros[1000] = "";

    // Ingreso de datos con un while
    printf("Ingrese los datos de los servicios de catering (máximo 520 líneas):\n");

    // Leer el primer código de aerolínea antes del bucle
    printf("Código de aerolínea (ej. aero10): ");
    scanf("%s", aerolineas[cantidadLineas]);

    while (cantidadLineas < MAX_LINEAS && strncmp(aerolineas[cantidadLineas], "aero", 4) == 0)
    {
        printf("Código de menú (1-25): ");
        scanf("%d", &codigosMenu[cantidadLineas]);

        printf("Número del cocinero (1-20): ");
        scanf("%d", &cocineros[cantidadLineas]);

        printf("Cantidad de bandejas entregadas: ");
        scanf("%d", &bandejas[cantidadLineas]);

        printf("Precio unitario de cada bandeja: ");
        scanf("%f", &preciosUnitarios[cantidadLineas]);

        cantidadLineas++;

        // Leer el siguiente código de aerolínea para la próxima iteración
        if (cantidadLineas < MAX_LINEAS)
        {
            printf("Código de aerolínea (ej. aero10): ");
            scanf("%s", aerolineas[cantidadLineas]);
        }
    }

    // a) Facturación total para "aero31" y "aero44" y menú más pedido
    calcularFacturacion(aerolineas, codigosMenu, cocineros, bandejas, preciosUnitarios, cantidadLineas, &totalAero31, &totalAero44, &menuMasPedidoAero31, &menuMasPedidoAero44);
    printf("Facturación total para aero31: %.2f\n", totalAero31);
    printf("Menú más pedido por aero31: %d\n", menuMasPedidoAero31);
    printf("Facturación total para aero44: %.2f\n", totalAero44);
    printf("Menú más pedido por aero44: %d\n", menuMasPedidoAero44);

    // b) Cocinero con más menús preparados y su pago
    calcularCocineroConMasMenus(cocineros, bandejas, preciosUnitarios, cantidadLineas, &cocineroMaxMenus, &montoCocineroMax);
    printf("El cocinero con más menús preparados es: %d\n", cocineroMaxMenus);
    printf("El monto total que cobrará es: %.2f\n", montoCocineroMax);

    // c) Menú más solicitado por todas las aerolíneas y string de cocineros que lo prepararon
    calcularMenuMasSolicitado(codigosMenu, cocineros, bandejas, cantidadLineas, &menuMasSolicitado, stringCocineros);
    printf("El menú más solicitado por todas las aerolíneas es: %d\n", menuMasSolicitado);
    printf("Cocineros que prepararon el menú más solicitado: %s\n", stringCocineros);

    return 0;
}
