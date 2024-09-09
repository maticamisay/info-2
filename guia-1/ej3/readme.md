# Problema 2: Evaluación de muestras de pintura según la densidad y el color

## Enunciado
Un conjunto de pintores requiere que sus pinturas tengan una densidad entre 100 y 120 unidades inclusive para ser aceptadas, si la densidad no está comprendida en el rango especificado se considera como rechazada. Se deben ingresar los valores de densidad correspondientes a N muestras de pintura y la primer letra del color que corresponde. Se solicita calcular e imprimir:
a) La cantidad de muestras de pintura rechazadas.
b) El promedio de densidad de las muestras aptas para la aplicación.
c) La cantidad de muestras de color blanco que sean aptas.

## Análisis del problema (Top-Down)
1. Lectura de datos  
   1.1 Leer el valor de N (número de muestras a ingresar).  
   1.2 Repetir N veces para cada muestra:  
       1.2.1 Leer el valor de la densidad de la muestra.  
       1.2.2 Leer la letra del color correspondiente a la muestra.

2. Procesamiento de datos  
    2.1 Verificar si la muestra es rechazada (densidad fuera del rango [100, 120]).  
        2.1.1 Si es rechazada, aumentar el contador de muestras rechazadas.  
    2.2 Si la muestra es apta (densidad dentro del rango [100, 120]):  
        2.2.1 Sumar la densidad al acumulador de muestras aptas (para calcular el promedio más  tarde).  
        2.2.2 Aumentar el contador de muestras aptas.  
        2.2.3 Verificar si el color es blanco ('B'):  
            2.2.3.1 Si es blanco, aumentar el contador de muestras aptas de color blanco.

3. Cálculos finales  
   3.1 Calcular el promedio de densidad de las muestras aptas (si hay alguna muestra apta):  
       - Promedio = Suma de densidades aptas / Cantidad de muestras aptas.

4. Mostrar resultados  
   4.1 Imprimir la cantidad de muestras rechazadas.  
   4.2 Imprimir el promedio de densidad de las muestras aptas (si existe alguna).  
   4.3 Imprimir la cantidad de muestras aptas de color blanco.

## Tabla de traza

| Muestra | Densidad | Color | Rechazada (S/N) | Suma de aptas | Total aptas | Blancas aptas |
|---------|----------|-------|-----------------|---------------|-------------|---------------|
| 1       | 95       | R     | S               | 0             | 0           | 0             |
| 2       | 110      | B     | N               | 110           | 1           | 1             |
| 3       | 125      | G     | S               | 0             | 0           | 0             |
| 4       | 115      | B     | N               | 115           | 1           | 1             |
| 5       | 105      | Y     | N               | 105           | 1           | 0             |
| 6       | 100      | B     | N               | 100           | 1           | 1             |
| 7       | 90       | R     | S               | 0             | 0           | 0             |
| 8       | 120      | B     | N               | 120           | 1           | 1             |

### Resultados esperados:

- **Cantidad de muestras rechazadas**: 3
- **Promedio de densidad de muestras aptas**: 110
- **Cantidad de muestras aptas de color blanco**: 4
