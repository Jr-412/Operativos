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
  char *q = NULL;  // Inicializa el puntero q en NULL
  printf("Requiring space for \"goodbye\"\n");  // Imprime el mensaje 
  q = (char *)malloc(strlen("goodbye") + 1);  // Reserva memoria para la cadena "goodbye" + 1 para el caracter nulo

  if(!q){   // Si q es NULL, imprime el mensaje de error y termina el programa
    perror("failed to allocate memory because:");  // Imprime el mensaje de error
    exit(1);  // Termina el programa
  }

  printf("About to copy \"goodbye\" into q at address %s\n",q);  // Imprime el mensaje
  strcpy(q, "goodbye");  // Copia la cadena "goodbye" en la dirección de memoria apuntada por q
  printf("String copied into q\n");  // Imprime el mensaje "String copied into q"
  printf("%s\n", q);  // Imprime el valor de la cadena apuntada por q

  free(q);   // Libera la memoria apuntada por q
  return 0;  // Termina el programa
  
}