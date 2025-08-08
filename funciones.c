#include "funciones.h" // Archivo de cabecera que contiene las declaraciones de las funciones
#include <stdio.h>  // Librería estándar para entrada y salida
#include <stdlib.h> // Librería estándar para utilidades generales (rand, conversión de tipos, etc.)
#include <time.h> // Librería para inicializar la semilla de números aleatorios con la hora actual

// ------------------------------------------------------------
// Función: printFunction
// Descripción: Imprime en pantalla el encabezado de la calculadora de masa
// corporal. Parámetros: Ninguno Retorna: int (0 para indicar éxito)
// ------------------------------------------------------------
int printFunction() {
  printf("********\n");
  printf("* Calculadora de Masa Corporal *\n");
  printf("********\n");
  return 0;
}

// ------------------------------------------------------------
// Función: imcFuncion
// Descripción: Calcula el Índice de Masa Corporal (IMC).
// Fórmula: IMC = masa / (altura^2)
// Parámetros:
//   - masa: masa corporal en kilogramos
//   - altura: altura en metros
// Retorna: valor del IMC como float
// ------------------------------------------------------------
float imcFuncion(float masa, float altura) { return masa / (altura * altura); }

// ------------------------------------------------------------
// Función: impMatrix
// Descripción: Imprime en pantalla una matriz cuadrada de tamaño N x N.
// Parámetros:
//   - N: tamaño de la matriz (número de filas y columnas)
//   - mA: matriz a imprimir
// Retorna: Nada (void)
// ------------------------------------------------------------
void impMatrix(int N, float mA[N][N]) {
  for (int i = 0; i < N; i++) {   // Recorre filas
    for (int j = 0; j < N; j++) { // Recorre columnas
      printf("%6.2f ",
             mA[i][j]); // Imprime el elemento con formato de 2 decimales
    }
    printf("\n"); // Salto de línea al terminar una fila
  }
  printf("\n"); // Línea en blanco final
}

// ------------------------------------------------------------
// Función: matrixMult
// Descripción: Realiza la multiplicación de dos matrices cuadradas (mA x mB).
// Parámetros:
//   - N: tamaño de las matrices
//   - mA: primera matriz (N x N)
//   - mB: segunda matriz (N x N)
//   - mC: matriz resultado (N x N)
// Retorna: Nada (void) - el resultado se almacena en mC
// ------------------------------------------------------------
void matrixMult(int N, float mA[N][N], float mB[N][N], float mC[N][N]) {
  for (int i = 0; i < N; i++) {     // Recorre filas de mA
    for (int j = 0; j < N; j++) {   // Recorre columnas de mB
      mC[i][j] = 0;                 // Inicializa el acumulador
      for (int k = 0; k < N; k++) { // Multiplica y suma
        mC[i][j] += mA[i][k] * mB[k][j];
      }
    }
  }
}

// ------------------------------------------------------------
// Función: llenarMatriz
// Descripción: Llena dos matrices cuadradas con valores aleatorios.
// Parámetros:
//   - N: tamaño de las matrices
//   - mA: primera matriz (N x N) que se llenará con valores aleatorios
//   - mB: segunda matriz (N x N) que se llenará con valores aleatorios
// Retorna: Nada (void)
// ------------------------------------------------------------
void llenarMatriz(int N, float mA[N][N], float mB[N][N]) {
  for (int i = 0; i < N; i++) {   // Recorre filas
    for (int j = 0; j < N; j++) { // Recorre columnas
      // Asigna valores aleatorios multiplicados por 0.121 para escalar el rango
      mA[i][j] = (rand() % 100) * 0.121;
      mB[i][j] = (rand() % 100) * 0.121;
    }
  }
}
