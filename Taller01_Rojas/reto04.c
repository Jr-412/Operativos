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
  int n, i, *ptr, sum = 0;  // Declara las variables n, i, ptr y sum
  printf("Enter number of elements: ");  // Imprime el mensaje 
  scanf("%d", &n);  // Lee el valor de n
  ptr = (int*)malloc(n * sizeof(int));  // Reserva memoria para n enteros asignado por el usuario
  if(ptr == NULL){  // Si ptr es NULL, imprime el mensaje de error y termina el programa
    printf("Error! memory not allocated.");
    exit(0);
  }
  
  for(i = 0; i < n; ++i){
    printf("Enter elements: ",i);  // Imprime el mensaje
    scanf("%d", ptr + i);  // Lee los valores de los elementos del arreglo
    sum += *(ptr + i);  // Suma los valores de los elementos del arreglo
    printf("\n");
  }
  printf("Sum = %d", sum,"\n");  // Imprime la suma de los valores de los elementos del arreglo
  free(ptr);  // Libera la memoria apuntada por ptr
  return 0;

}