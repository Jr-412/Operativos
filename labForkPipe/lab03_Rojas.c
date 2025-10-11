/**********************************************
* Pontificia Universidad Javeriana
* Autor: Juan Diego Rojas Osorio
* Fecha: Octubre 9 2025
* Materia: Sistemas Operativos
* Tema: Creacion procesos fork
*  -Identificar el proceso padre y el proceso hijo
* **********************************************/
#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <string.h>     

int main() {
    int pipefd[2];      // Arreglo de 2 enteros: pipefd[0] para lectura y pipefd[1] para escritura
    pid_t hijo_PID;     // Variable para almacenar el identificador (PID) del proceso hijo

    //Creacion de la tuberia
    if (pipe(pipefd) == -1) {
        perror("Error al crear la tubería");  
        exit(EXIT_FAILURE);                   //Termina el programa en caso de error
    }

    // creacion proceso hijo

    hijo_PID = fork();

    if (hijo_PID == -1) {
        perror("Error en fork");  
        exit(EXIT_FAILURE);
    }

    //se duplica el proceso
    if (hijo_PID == 0) {
        //proceso hijo
        printf("\n[HIJO] Mi PID es %d, el PID de mi padre es %d\n", getpid(), getppid());

        /* Cerrar salida para lectura del pipe */
        // El hijo solo va a leer, por eso se cierra el extremo de escritura.
        close(pipefd[1]);

        /* Leer mensaje desde el pipe */
        char mensaje[100];  
        ssize_t lecturaB = read(pipefd[0], mensaje, sizeof(mensaje));
        // read() lee datos desde el extremo de lectura del pipefd[0] y los almacena en 'mensaje'.

        if (lecturaB == -1) {
            perror("Error al leer del pipe");  
            exit(EXIT_FAILURE);
        }

        // Muestra el mensaje recibido por el hijo y la cantidad de bytes leídos
        printf("[HIJO] Leí %zd bytes: \"%s\"\n", lecturaB, mensaje);

        close(pipefd[0]); // cerrar extremo de lectura
    } 
    else {
        //proceso padre
        printf("\n[PADRE] Mi PID es %d, el PID de mi hijo es %d\n", getpid(), hijo_PID);

        // Cerrar entrada para lectura (solo escritura)
       
        close(pipefd[0]);

        // Mensaje que el padre enviará al hijo
        char mensaje[] = "Hijo, voy a darte plata y gaseosas";

        // write() escribe el mensaje en el pipe.
        
        ssize_t escrituraB = write(pipefd[1], mensaje, strlen(mensaje) + 1);

        if (escrituraB == -1) {
            perror("Error al escribir en el pipe");  // Si ocurre un error al escribir
            exit(EXIT_FAILURE);
        }

        // Muestra la cantidad de bytes escritos en el pipe
        printf("[PADRE] Escribí %zd bytes en el pipe.\n", escrituraB);

        close(pipefd[1]); // Cerrar extremo de escritura
    }

    return 0;
     }