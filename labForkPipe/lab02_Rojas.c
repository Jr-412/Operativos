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


int main(int argc, char *argv[]) {

    int processID = fork();
    // Si el valor devuelto por fork() es mayor que 0, significa que este es el proceso padre
    if (processID > 0) {
        printf("\n 'proceso padre' .... \n");
    }
        // Si el valor devuelto es 0, significa que este es el proceso hijo recién creado
    else if (processID == 0) {
        printf("\n 'proceso hijo' recién creado \n");
    }
        // Si el valor devuelto es negativo, la creación del proceso falló
    else {
        printf("\n llamada al sistema fork() falló\n");
    }
// imprime los valorea de los procesos 
    printf("\n\n Imprimiendo ... \n");
    for (int i = 0; i < 5; i++) {
        printf(" %d ", i);
    }
    // final del proceso
    printf("\n Fin \n");

    return 0;
}