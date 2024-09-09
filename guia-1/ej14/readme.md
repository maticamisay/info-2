# Problema 4: Control de calidad de cables trenzados

## Enunciado

Una empresa de cables trenzados desea controlar la calidad de sus productos. Para ello se ha pedido un algoritmo que lea datos relevantes de la producción. El cable producido se obtiene trenzando dos cables, los que deben cumplir con las siguientes condiciones para formar un cable trenzado bueno:

- Resistencia eléctrica entre extremos del rollo es de 100Ohm +/- 10%.
- Aislamiento eléctrico mayor a 10kV.

En el caso de que alguno de los cables formantes no cumpla con una sola de las especificaciones anteriores, el cable trenzado debe ser marcado como de segunda calidad. Si ambos cables formantes dejan de cumplir con alguna de las dos especificaciones, el cable debe ser marcado como malo. El ingreso de datos finaliza cuando se ingresa un valor de resistencia nulo. Mostrar:

a) Cantidad de cables analizados.

b) Porcentaje de cables de primera y segunda calidad.

c) Promedio de la resistencia de los cables de la producción total.

## Análisis del problema (Top-Down)

1. Lectura de datos  
    1.1. Inicializar los contadores necesarios para los cables analizados, de primera calidad, de segunda    calidad y la suma total de resistencias.  
    1.2. Repetir hasta que se ingrese un valor de resistencia nulo:  
        1.2.1. Leer la resistencia del primer cable.  
        1.2.2 Leer el aislamiento del primer cable.  
        1.2.3 Leer la resistencia del segundo cable.  
        1.2.4 Leer el aislamiento del segundo cable.

2. Procesamiento de datos  
   2.1 Verificar si ambos cables cumplen con las condiciones para ser de primera calidad:

   - Resistencia entre 90Ohm y 110Ohm.
   - Aislamiento mayor a 10kV.

    2.2 Clasificar el cable trenzado según la calidad:  
        2.2.1 Si ambos cables cumplen con las especificaciones, incrementar el contador de cables de primera   calidad. 
        2.2.2 Si uno de los cables no cumple con alguna especificación, incrementar el contador de cables de    segunda calidad.  
        2.2.3 Si ambos cables no cumplen con las especificaciones, marcar el cable como malo (sin incrementar   contadores de primera o segunda calidad).  
        2.3 Sumar la resistencia total de los cables analizados para calcular el promedio más tarde.

3. Cálculos finales  

    3.1 Calcular el porcentaje de cables de primera calidad.
        
        Porcentaje de primera calidad = (Cables de primera calidad / Cantidad de cables analizados) \_ 100

    3.2 Calcular el porcentaje de cables de segunda calidad.
        
        Porcentaje de segunda calidad = (Cables de segunda calidad / Cantidad de cables analizados) \_ 100

    3.3 Calcular el promedio de la resistencia de los cables.
        
        Promedio = Resistencia total / Cantidad de cables analizados.

4. Mostrar resultados  

   4.1 Imprimir la cantidad de cables analizados.  

   4.2 Imprimir el porcentaje de cables de primera y segunda calidad. 

   4.3 Imprimir el promedio de la resistencia de los cables de la producción total.

## Tabla de traza

| Cable | Resistencia 1 (Ohm) | Aislamiento 1 (kV) | Resistencia 2 (Ohm) | Aislamiento 2 (kV) | Calidad Esperada  | Resistencia Total |
|-------|---------------------|--------------------|---------------------|--------------------|-------------------|-------------------|
| 1     | 95                  | 15                 | 105                 | 12                 | Primera calidad   | 100               |
| 2     | 85                  | 8                  | 110                 | 9                  | Mala              | 97.5              |
| 3     | 100                 | 11                 | 101                 | 13                 | Primera calidad   | 100.5             |
| 4     | 120                 | 14                 | 90                  | 11                 | Segunda calidad   | 105               |
| 5     | 92                  | 9                  | 111                 | 10                 | Segunda calidad   | 101.5             |
| 6     | 110                 | 11                 | 89                  | 8                  | Mala              | 99.5              |
| 7     | 97                  | 16                 | 104                 | 17                 | Primera calidad   | 100.5             |
| 8     | 101                 | 12                 | 107                 | 8                  | Segunda calidad   | 104               |
| 9     | 108                 | 14                 | 91                  | 15                 | Primera calidad   | 99.5              |
| 10    | 115                 | 18                 | 85                  | 7                  | Mala              | 100               |

### Resultados esperados:

1. **Cantidad de cables analizados**: 10 cables.
2. **Cables de primera calidad**: 4 cables (Cables 1, 3, 7, 9).
3. **Cables de segunda calidad**: 3 cables (Cables 4, 5, 8).
4. **Cables malos**: 3 cables (Cables 2, 6, 10).
5. **Porcentaje de cables de primera calidad**: (4/10) * 100 = 40%.
6. **Porcentaje de cables de segunda calidad**: (3/10) * 100 = 30%.
7. **Promedio de resistencia de la producción total**: (100 + 97.5 + 100.5 + 105 + 101.5 + 99.5 + 100.5 + 104 + 99.5 + 100) / 10 = **100.8 Ohm**.
