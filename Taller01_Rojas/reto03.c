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
  int *ptr;  // Declara un puntero a entero
  ptr = (int *)malloc(15 * sizeof(*ptr));  // Reserva memoria para 15 enteros

  if(ptr != NULL){   // Verifica si la memoria fue reservada correctamente
    *(ptr + 5) = 480;   // Asigna el valor 480 a la posición 5 del arreglo
    printf("ptr[5] = %d\n", *(ptr + 5));   // Imprime el valor de la posición 5 del arreglo
  }

  free(ptr);  // Libera la memoria apuntada por ptr
  return(0);  
}