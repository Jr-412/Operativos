/******************************
 * Fecha:Agosto 21 2025
 * Autor: Juan Diego Rojas Osorio
 * Materia: Sistemas Operativos
 * Tema: Memoria Dinámica
 * Profesor: John Corredor
*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

int main(){
  char *p;
  char *q = NULL;
  printf("Address of p: %s\n", p);  // Imprime la direccion de memoria de p

  p = (char *)malloc(100 * sizeof(char));
  q = (char *)malloc(100 * sizeof(char));

  strcpy(p, "Hello, Im the best in operating systems");  // Copiamos la cadena en la dirección de memoria apuntada por p
  printf("Value of p: %s\n", p);  // Imprime el valor de la cadena apuntada por p
  printf("About to copy \"goodbye\" into p\n");  // Imprimimos siguiente mensaje 
  strcpy(q, "goodbye");  // Copia la cadena "goodbye" en la dirección de memoria apuntada por p
  printf("String copied into p\n");  // Imprime el mensaje 
  printf("%s\n", q);  // Imprime el valor de la cadena apuntada por q"

  free(p);  // Libera la memoria apuntada por p
  free(q);  // Libera la memoria apuntada por q
  return 0;
}