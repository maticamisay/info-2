#include <stdio.h>
#include <stdlib.h> // Librería necesaria para atoi

// atoi convierte una cadena de caracteres a un entero. La cadena debe contener
// solo caracteres numéricos y puede tener un signo al principio. atoi lee la
// cadena hasta que encuentra un caracter que no sea un dígito y devuelve el
// número entero correspondiente a los dígitos leídos. Si la cadena no comienza
// con un número, atoi devuelve 0. Por ejemplo: atoi("123") -> 123 atoi("abc")
// ->
// 0

// coloca un ejemplo de codigo en main

int main() {
  char movil[10];
  printf("Ingrese el código del móvil (ej. rms01): ");
  scanf("%s", movil);
  int movilIdx = atoi(movil + 3) - 1;
  printf("El índice del móvil es: %d\n", movilIdx);
  return 0;
}