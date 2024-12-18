/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635
CROUZET Oriane 21414555
CHEN Shiyao 28707756

*/

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
void free_matrix(Matrix* mat);

// Opérations élémentaires sur les lignes et colonnes
int swapRows(Matrix matrix, int row1, int row2);
int swapColumns(Matrix matrix, int col1, int col2);
Matrix** createPermutationMatrix(int size, int row1, int row2);
void moveElement(Matrix matrix, int x1, int y1, int x2, int y2);
Matrix* addMatrices(Matrix* A, Matrix* B);
Matrix* subtractMatrices(Matrix* A, Matrix* B);

// Multiplication de matrices
Matrix* naive_matrix_multiplication(Matrix* A, Matrix* B);

// Maximum d'une matrice
Pair searchForMax(Matrix* matrix, int size);

// Fonction pour découper une matrice en sous-matrices
void splitMatrix(Matrix* A, Matrix* A11, Matrix* A12, Matrix* A21, Matrix* A22);

#endif // MATRIX_OPERATIONS_H