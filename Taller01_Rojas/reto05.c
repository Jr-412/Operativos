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
  int *ptr, i, n1, n2;   //Declaramos variables
  printf("Enter size: ");  //Pedimos el tamaño del arreglo
  scanf("%d", &n1);  //Se lee tamaño del arreglo
  ptr = (int*)malloc(n1 * sizeof(int));  //Reservamos memoria para el arreglo
  printf("Addresses of previously allocated memory: ");  //Imprimimos las direcciones de memoria del arreglo
  for(i = 0; i < n1; ++i){ //for que recorre el arreglo
    printf("%p\n", ptr + i);  //Imprimimos las direcciones de memoria del arreglo
  }
  printf("\nEnter new size: ");  //Pedimos el nuevo tamaño del arreglo
  scanf("%d", &n2);  //Se lee nuevo tamaño del arreglo
  ptr = realloc(ptr, n2 * sizeof(int));  //Reasignamos memoria para el arreglo
  printf("Addresses of newly allocated memory: ");  //Imprimimos las direcciones de memoria del arreglo
  for(i = 0; i < n2; ++i){  //for que recorre el arreglo
    printf("%p\n", ptr + i);  //Imprimimos las direcciones de memoria del arreglo
  }

  free(ptr);  //Liberamos memoria
  return 0;
}