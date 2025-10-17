/**********************************************
* Pontificia Universidad Javeriana
* Autor: Juan Diego Rojas Osorio
* Fecha: Octubre 16 2025
* Materia: Sistemas Operativos
* Tema: Implementacion de Productor Consumidor a partir de pipe named
*  
* **********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_FILE "/tmp/fifo_twoway"

//// Función que invierte una cadena (string)
void reverse_string(char *);

int main() {
   int fd;    // Descriptor de archivo para la FIFO
   char readbuf[80];   //Buffer para leer datos desde la FIFO
   char end[10];    //Palabra clave para finalizar ("end")
   int to_end;   //Variable para comparar si llega la palabra "end"
   int read_bytes;   //Número de bytes leídos

   /* Crear la FIFO si no existe */
   if (mkfifo(FIFO_FILE, 0640) == -1) {
       // No aborta si ya existe
       perror("Aviso o error al crear FIFO (puede existir)");
   }

   strcpy(end, "end");   //Se define la palabra clave de terminación de la comunicación

   fd = open(FIFO_FILE, O_RDWR);
   if (fd == -1) {
       perror("Error al abrir FIFO");
       exit(EXIT_FAILURE);
   }

   //El servidor espera continuamente mensajes desde la FIFO.
   while (1) {
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      if (read_bytes <= 0) {
         perror("Error al leer del FIFO o conexión cerrada");
         break;
      }

      readbuf[read_bytes] = '\0';   // Se lee la cadena
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));

      to_end = strcmp(readbuf, end);

      if (to_end == 0) {   //Si el cliente envía "end", se termina la conexión
         close(fd);
         break;
      }

      // Invierte la cadena y la envía de vuelta al cliente
      reverse_string(readbuf);
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
      write(fd, readbuf, strlen(readbuf));  //Envía la cadena invertida de nuevo por la FIFO.

      /* Espera breve para permitir que el otro proceso lea antes de continuar */
      sleep(2);
   }

   return 0;
}

//Funcion para invertir una cadena
void reverse_string(char *str) {
   int last, limit, first;
   char temp;
   last = strlen(str) - 1;
   limit = last / 2;
   first = 0;

   while (first < last) {
      temp = str[first];
      str[first] = str[last];
      str[last] = temp;
      first++;
      last--;
   }
   return;
}