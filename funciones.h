/*****************************************************************************************************************
*
*                           Pontificia Universidad Javeriana
*                   ----------------------------------------------------
* Autor: Juan Diego Rojas
* Materia: Sistemas operativos
* Docente: J. Corredor, PHD
* Objetivo: Punteros en C
*******************************************************************************************************************/

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printFunction();

float imcFuncion(float masa, float altura);

void impMatrix(int N, float mA[N][N]);

void matrixMult(int N, float mA[N][N], float mB[N][N], float mC[N][N]);

void llenarMatriz(int N, float mA[N][N], float mB[N][N]);

#endif
