# Problema: Procesar pares de valores enteros (x, y) hasta que se cumpla una condición de parada

1. Lectura de datos  
   1.1 Leer dos valores enteros x e y.  
   1.2 Repetir el proceso hasta que la diferencia entre ambos sea impar y divisible por 7.  
       1.2.1 Calcular la diferencia entre x e y, verificar si la diferencia es impar y divisible por 7.  
       1.2.2 Si la condición se cumple, finalizar el ciclo.

2. Procesamiento de datos  
   2.1 Para cada par (x, y):  
       2.1.1 **Si y > x**: Mostrar los valores intermedios entre x e y (exclusivos).  
       2.1.2 **Si y > 0**: Calcular x elevado a y mediante productos sucesivos y mostrar el resultado en `main()`.  
       2.1.3 **Si x > 0**: Acumular los valores de x para calcular el promedio más tarde.  
       2.1.4 Verificar si alguno de los valores es 0 y contar el par si al menos uno es 0.  

3. Cálculos finales  
   3.1 Calcular el promedio de los valores de x mayores que 0.  
   3.2 Calcular el porcentaje de pares con al menos un valor igual a 0.

4. Mostrar resultados finales  
   4.1 Imprimir el promedio de los valores de x mayores que 0.  
   4.2 Imprimir el porcentaje de pares con al menos un valor igual a 0.
