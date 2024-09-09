# Problema 3: Procesamiento de un conjunto de N números reales

## Enunciado
Realizar un algoritmo que permita leer un valor R y un conjunto de N de números reales (máximo 100), y que calcule y escriba:
a) La cantidad de valores mayores que el primero ingresado.
b) El promedio de los valores positivos menores que R.
c) El porcentaje de valores positivos pares.

## Análisis del problema (Top-Down)
1. Lectura de datos  
   1.1 Leer el valor de R.  
   1.2 Leer el valor de N (cantidad de números a ingresar, máximo 100).  
   1.3 Leer el conjunto de N números reales, guardando el primero ingresado en una variable separada para comparaciones futuras.

2. Procesamiento de datos  
   2.1 Inicializar contadores para:  
       - Cantidad de valores mayores que el primero.  
       - Cantidad de valores positivos menores que R.  
       - Suma de valores positivos menores que R (para el promedio).  
       - Cantidad de valores positivos pares.
   2.2 Para cada número (a partir del segundo ingresado):  
       2.2.1 Verificar si es mayor que el primero ingresado.  
           2.2.1.1 Si es mayor, incrementar el contador de mayores que el primero.
       2.2.2 Si el número es positivo, verificar:  
           2.2.2.1 Si es menor que R, sumar al acumulador de positivos menores que R e incrementar el contador.  
           2.2.2.2 Si es par, incrementar el contador de positivos pares.

3. Cálculos finales  
   3.1 Calcular el promedio de los valores positivos menores que R (si existen).  
       - Promedio = Suma de positivos menores que R / Cantidad de positivos menores que R.  
   3.2 Calcular el porcentaje de valores positivos pares:  
       - Porcentaje = (Cantidad de positivos pares / N) * 100.

4. Mostrar resultados  
   4.1 Imprimir la cantidad de valores mayores que el primero ingresado.  
   4.2 Imprimir el promedio de los valores positivos menores que R (si existen).  
   4.3 Imprimir el porcentaje de valores positivos pares.

## Tabla de traza

| Números (N=6) | R   | Primero ingresado | Mayores que el primero | Promedio positivos < R | % positivos pares |
|---------------|-----|-------------------|------------------------|------------------------|-------------------|
| 5, 3, 8, -1, 12, 4 | 6   | 5                 | 2                      | 3.5 (3, 4)            | 50 (8)          |

### Resultados esperados:

1. **Conjunto de valores: 5, 3, 8, -1, 12, 4; R = 6**
   - Mayores que el primero (5): **8, 12** (2 valores)
   - Promedio de positivos menores que R: **(3 + 4) / 2 = 3.5**
   - Porcentaje de positivos pares: **2 valores pares (8, 4) de 4 positivos (3, 8, 12, 4) ** -> **(1/3) * 100 = 33.33%**
