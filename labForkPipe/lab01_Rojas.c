/**********************************************
* Pontificia Universidad Javeriana
* Autor: Juan Diego Rojas Osorio
* Fecha: Octubre 9 2025
* Materia: Sistemas Operativos
* Tema: Creacion procesos fork
*  -Identificar el proceso padre y el proceso hijo
* **********************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(){
  /*Se invoca la creacion del proceso en un INT para identificar el proceso*/
  int  procesoID = fork();

  //Se duplica el proceso
  if(procesoID == 0){
    printf("Soy luke skywalker!!!  ID = %d \n", getpid());
} else {
    printf("Soy tu padre!!! ID = %d \n", getpid());
}
}