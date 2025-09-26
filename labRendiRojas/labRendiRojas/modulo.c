#include "modulo.h"

double *mA, *mB, *mC;
struct timeval ini, fin;

// Función para tomar tiempo inicial
void InicioMuestra() {
    gettimeofday(&ini, (void *)0);
}

// Función para tomar tiempo final y presentar el resultado actual
void FinMuestra() {
    gettimeofday(&fin, (void *)0);
    fin.tv_usec -= ini.tv_usec;
    fin.tv_sec -= ini.tv_sec;
    double tiempo = (double)(fin.tv_sec * 1000000 + fin.tv_usec);
    printf("%9.0f \n", tiempo);
}

// Función para inicializar las matrices
void iniMatriz(int n, double *m1, double *m2) {
    for (int i = 0; i < n * n; i++) {
        m1[i] = i * 2.3 + 1.3;
        m2[i] = i * 2.3;
    }
}

// Función para imprimir las matrices
void imprMatrices(int n, double *matriz) {
    if (n < 9) {
        printf("\n#######################################################\n");
        for (int i = 0; i < n * n; i++) {
            if (i % n == 0) printf("\n");
            printf(" %f ", matriz[i]);
        }
    } else {
        printf("\n#######################################################\n");
    }
}

// Algoritmo clásico de multiplicación de matrices
void multiMatrizClasica(double *m1, double *m2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sumaTemp = 0.0;
            double *pA = m1 + i * n;
            double *pB = m2 + j;
            for (int k = 0; k < n; k++, pA++, pB += n) {
                sumaTemp += *pA * *pB;
            }
            mC[j + i * n] = sumaTemp;
        }
    }
}