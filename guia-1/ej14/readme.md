# Problema 4: Control de calidad de cables trenzados

## Enunciado

Una empresa de cables trenzados desea controlar la calidad de sus productos. Para ello se ha pedido un algoritmo que lea datos relevantes de la producción. El cable producido se obtiene trenzando dos cables, los que deben cumplir con las siguientes condiciones para formar un cable trenzado bueno:
- Resistencia eléctrica entre extremos del rollo es de 100  10%.
- Aislamiento eléctrico mayor a 10kV.
En el caso de que alguno de los cables formantes no cumpla con una sola de las especificaciones anteriores, el cable trenzado debe ser marcado como de segunda calidad. Si ambos cables formantes dejan de cumplir con alguna de las dos especificaciones, el cable debe ser marcado como malo. El ingreso de datos finaliza cuando se ingresa un valor de resistencia nulo. Mostrar:
a) Cantidad de cables analizados.
b) Porcentaje de cables de primera y segunda calidad.
c) Promedio de la resistencia de los cables de la producción total.

## Análisis del problema (Top-Down)

1. Lectura de datos  
   1.1 Inicializar los contadores necesarios para los cables analizados, de primera calidad, de segunda calidad y la suma total de resistencias.  
   1.2 Repetir hasta que se ingrese un valor de resistencia nulo:  
       1.2.1 Leer la resistencia del primer cable.  
       1.2.2 Leer el aislamiento del primer cable.  
       1.2.3 Leer la resistencia del segundo cable.  
       1.2.4 Leer el aislamiento del segundo cable.

2. Procesamiento de datos  
   2.1 Verificar si ambos cables cumplen con las condiciones para ser de primera calidad:  
       - Resistencia entre 90 y 110.  
       - Aislamiento mayor a 10kV.  
   2.2 Clasificar el cable trenzado según la calidad:  
       2.2.1 Si ambos cables cumplen con las especificaciones, incrementar el contador de cables de primera calidad.  
       2.2.2 Si uno de los cables no cumple con alguna especificación, incrementar el contador de cables de segunda calidad.  
       2.2.3 Si ambos cables no cumplen con las especificaciones, marcar el cable como malo (sin incrementar contadores de primera o segunda calidad).  
   2.3 Sumar la resistencia total de los cables analizados para calcular el promedio más tarde.

3. Cálculos finales  
   3.1 Calcular el porcentaje de cables de primera calidad.  
       - Porcentaje de primera calidad = (Cables de primera calidad / Cantidad de cables analizados) * 100  
   3.2 Calcular el porcentaje de cables de segunda calidad.  
       - Porcentaje de segunda calidad = (Cables de segunda calidad / Cantidad de cables analizados) * 100  
   3.3 Calcular el promedio de la resistencia de los cables.  
       - Promedio = Resistencia total / Cantidad de cables analizados.

4. Mostrar resultados  
   4.1 Imprimir la cantidad de cables analizados.  
   4.2 Imprimir el porcentaje de cables de primera y segunda calidad.  
   4.3 Imprimir el promedio de la resistencia de los cables de la producción total.
