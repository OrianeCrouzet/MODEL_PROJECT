#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

//Valeur absolue d'un nombre
#define ABS(x) ((x) > 0 ? (x) : -(x))

typedef struct {
    int row;
    int col;
} Pair;

typedef struct {
    double** m;
    int rows;
    int cols;
} Matrix;

// Fonction de commodité :
// Renvoie 1 si la matrice est carrée.
int isSquare(Matrix* m);

// Création et affichage de matrices
Matrix* create_matrix(int rows, int cols);
Matrix* createIdentity(int size);
void print_matrix(const Matrix* matrix);
Matrix* generate_random_matrix(Matrix* mat);
void generate_random_matrix_bounded(Matrix* matrix, int min_value, int max_value);

// Opérations élémentaires sur les lignes et colonnes
int swapRows(Matrix matrix, int row1, int row2);
int swapColumns(Matrix matrix, int col1, int col2);
Matrix** createPermutationMatrix(int size, int row1, int row2);
void moveElement(Matrix matrix, int x1, int y1, int x2, int y2);

// Multiplication de matrices
Matrix* naive_matrix_multiplication(Matrix* A, Matrix* B);

// Maximum d'une matrice
Pair searchForMax(Matrix* matrix, int size);

//strassen_inversion
int is_power_of_two(int n);
int next_power_of_two(int n);
int max(int a, int b);
Matrix* pad_matrix(Matrix* A);
Matrix* unpad_matrix(Matrix* A, int orignal_Size);

#endif // MATRIX_OPERATIONS_H