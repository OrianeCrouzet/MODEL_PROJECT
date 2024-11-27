#ifndef STRASSEN_INVERSION_H
#define STRASSEN_INVERSION_H
#include "MatrixOperations.h"

//strassen_inversion
int is_power_of_two(int n);
int next_power_of_two(int n);
int max(int a, int b);
Matrix* pad_matrix(Matrix* A);
Matrix* unpad_matrix(Matrix* A, int orignal_Size);
void matrix_inversion(Matrix* A, Matrix* invA);
Matrix* strassen_inverse(Matrix* A);


#endif // STRASSEN_INVERSION_H