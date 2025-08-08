/*********************
 *                Pontificia Universidad Javeriana
 *               =================*==================
 *
 *Autor: Juan Diego Rojas
 *Materia: Sistemas Operativos
 *Docente: John Corredor, Phd
 *Objetivo: Punteros en C
 *
 *Descripcion: punteros
 ********************/

#include "funciones.h" // Archivo de cabecera que contiene las declaraciones de funciones utilizadas
#include <stdio.h>  // Librería estándar para funciones de entrada y salida
#include <stdlib.h> // Librería estándar para funciones generales (conversión de tipos, control del programa, etc.)
#include <time.h> // Librería para manejar tiempo y generar números aleatorios con srand()

int main(int argc, char *argv[]) {
  // Verifica si se han pasado al menos 3 argumentos: altura, masa y N
  if (argc < 4) {
    // Si no hay suficientes argumentos, muestra el formato correcto de uso y
    // termina
    printf("Uso: %s altura masa N\n", argv[0]);
    return 1; // Sale del programa con código de error
  }

  // Inicializa la semilla para la generación de números aleatorios usando la
  // hora actual
  srand(time(NULL));

  // Convierte los argumentos de la línea de comandos a los tipos de datos
  // necesarios
  float altura =
      atof(argv[1]); // Convierte el primer argumento (altura) a float
  float masacorporal =
      atof(argv[2]);     // Convierte el segundo argumento (masa) a float
  int N = atoi(argv[3]); // Convierte el tercer argumento (N) a entero

  // Declaración de matrices cuadradas de tamaño N x N
  float m1[N][N], m2[N][N], mC[N][N];

  // Llama a la función que imprime el título de la aplicación
  printFunction();

  // Calcula el índice de masa corporal (IMC) usando la función correspondiente
  float valorIMC = imcFuncion(masacorporal, altura);
  // Muestra el resultado del IMC calculado
  printf("El índice de masa corporal es %.2f\n\n", valorIMC);

  // Muestra un encabezado para la sección de matrices
  printf("********\n");
  printf("*      MATRICES      *\n");
  printf("********\n");

  // Llena las matrices m1 y m2 con valores aleatorios
  llenarMatriz(N, m1, m2);

  // Imprime el contenido de la matriz m1
  printf("Matriz 1:\n");
  impMatrix(N, m1);

  // Imprime el contenido de la matriz m2
  printf("Matriz 2:\n");
  impMatrix(N, m2);

  // Multiplica las matrices m1 y m2, almacenando el resultado en mC
  matrixMult(N, m1, m2, mC);

  // Imprime la matriz resultante de la multiplicación
  printf("Matriz C = M1 x M2:\n");
  impMatrix(N, mC);

  // Termina el programa correctamente
  return 0;
}