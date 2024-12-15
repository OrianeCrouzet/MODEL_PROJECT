#ifndef STRASSEN_PRODUCT_H
#define STRASSEN_PRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatrixOperations.h"

int nextPowerOfTwo(int n);
Matrix* resize_to_power_of_two(Matrix* mat, int newSize);
Matrix* strassen_product(Matrix* A, Matrix* B);

#endif