#include "modulo.h"

int main(int argc, char *argv[]) {
  if (argc <= 2) {
    printf("Numero argumentos incorrectos\n");
    printf("\n\t $ejecutable.exe DIM \n");
    return -1;
  }

  int N = (int)atof(argv[1]);
  if (N <= 0) {
    printf("\n Valores deben ser mayor que cero\n");
    return -1;
  }

  // Reservamos memoria
  mA = (double *)malloc(N * N * sizeof(double));
  mB = (double *)malloc(N * N * sizeof(double));
  mC = (double *)calloc(N * N, sizeof(double));

  // Inicializamos las 2 matrices
  iniMatriz(N, mA, mB);

  // Imprimimos matrices
  imprMatrices(N, mA);
  imprMatrices(N, mB);

  // Multiplicamos
  multiMatrizClasica(mA, mB, N);
  imprMatrices(N, mC);

  printf("\n\tFin del programa.............!\n");

  // Liberamos memoria
  free(mA);
  free(mB);
  free(mC);

  return 0;
}