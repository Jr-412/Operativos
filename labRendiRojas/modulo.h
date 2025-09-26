#ifndef MODULO_H
#define MODULO_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Variables globales
extern double *mA, *mB, *mC;
extern struct timeval ini, fin;

// Funciones
void InicioMuestra();
void FinMuestra();
void iniMatriz(int n, double *m1, double *m2);
void imprMatrices(int n, double *matriz);
void multiMatrizClasica(double *m1, double *m2, int n);

#endif