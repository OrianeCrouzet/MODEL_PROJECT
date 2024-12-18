/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635
CROUZET Oriane 21414555
CHEN Shiyao 28707756

*/


#ifndef STRASSEN_INVERSION_H
#define STRASSEN_INVERSION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatrixOperations.h"
#include "StrassenProduct.h"
#include "LU_Decomposition.h"

//strassen_inversion
int is_power_of_two(int n);
int next_power_of_two(int n);
int max(int a, int b);
Matrix* pad_matrix(Matrix* A);
Matrix* unpad_matrix(Matrix* A, int orignal_Size);

// Inversion with LU decomposition
void matrix_inversion(Matrix* A, Matrix* invA);

// Strassen inversion with naive product and Strassen product
Matrix* strassen_inversion_naive_product(Matrix* A);
Matrix* strassen_inversion_strassen_product(Matrix* A);


#endif // STRASSEN_INVERSION_H