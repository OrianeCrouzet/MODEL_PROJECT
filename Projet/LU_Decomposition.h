/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635
CROUZET Oriane 21414555
CHEN Shiyao 28707756

*/

#ifndef LU_DECOMPOSITION_H
#define LU_DECOMPOSITION_H

#include "MatrixOperations.h"

typedef struct {
    Matrix L;
    Matrix U;
} LU_decomposition;

// Factorisation LU
void substractRow(Matrix* matrix, int row1, int row2, double multiple);
double findEliminationMutliple(Matrix* matrix, int row1, int row2, int col);
void elimination(Matrix* L, Matrix* U, int row1, int row2, int col);
void LU_facorization(Matrix* L, Matrix* U);

#endif //LU_DECOMPOSITION_H