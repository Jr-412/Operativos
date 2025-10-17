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

int main() {
   int fd;
   int end_process;
   int stringlen;
   int read_bytes;
   char readbuf[80];
   char end_str[5];

   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");

   //Se abre la FIFO existente (creada por el servidor) en modo lectura/escritura.
   //Si no se puede abrir, el programa termina con un mensaje de error.
   fd = open(FIFO_FILE, O_RDWR);
   if (fd == -1) {
      perror("Error al abrir FIFO");
      exit(EXIT_FAILURE);
   }

   strcpy(end_str, "end"); //// Define la palabra clave que terminará la comunicación

   //el cliente envía mensajes al servidor de forma continua
   while (1) {
      printf("Enter string: ");
      if (fgets(readbuf, sizeof(readbuf), stdin) == NULL) {
         printf("Error leyendo entrada\n");
         break;
      }

      stringlen = strlen(readbuf);

      //// Elimina el salto de línea final en la cadena ingresada
      if (stringlen > 0 && readbuf[stringlen - 1] == '\n') {
         readbuf[stringlen - 1] = '\0';
      }

      end_process = strcmp(readbuf, end_str);

      if (end_process != 0) {
         //Si el usuario no escribe "end", el mensaje se envía al servidor a través del FIFO, y luego se espera la respuesta del servidor.
         if (write(fd, readbuf, strlen(readbuf)) == -1) {
            perror("Error al escribir en FIFO");
            break;
         }

         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n",
                readbuf, (int)strlen(readbuf));

         /* Leer respuesta del servidor */
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         if (read_bytes <= 0) {
            perror("Error o cierre al leer FIFO");
            break;
         }

         readbuf[read_bytes] = '\0';
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n",
                readbuf, (int)strlen(readbuf));

      } else {
         // Si el usuario escribe "end", se envía este mensaje al servidor para indicar el fin de la comunicación
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         close(fd);
         break;
      }
   }

   return 0;
}