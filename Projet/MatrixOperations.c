/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635

*/

#include "MatrixOperations.h"

// ################################################################################

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Implement a naive (classical) algorithm for multiplying two matrices over double-precision floating-point numbers.

// isSquare : Détermine si une matrice est carrée :
int isSquare(Matrix* m) {
    if (m-> cols == m->rows)
        return 1;
    else
        return 0;
}

// Fonction pour créer une matrice de dimensions rows x cols remplie de 0
Matrix* create_matrix(int row, int col) { //O(mn) où m = row et n = col
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    if (mat == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    mat->rows = row;
    mat->cols = col;

    mat->m = (double **)malloc(row * sizeof(double *));
    if (mat->m == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Allouer de la mémoire pour chaque ligne et initialiser les éléments à 0
    for (int i = 0; i < row; i++) {
        mat->m[i] = (double *)malloc(col * sizeof(double));
        if (mat->m[i] == NULL) {
            fprintf(stderr,"Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        // Remplir chaque élément de la ligne avec 0
        for (int j = 0; j < col; ++j) {
            mat->m[i][j] = 0.0;
        }
    }
    return mat;
}

// Fonction pour générer aléatoirement des éléments de matrice dans la plage [-1, 1]
Matrix* generate_random_matrix(Matrix* mat) { //O(mn) où m = mat->rows et n = mat->cols
    if (mat != NULL) {
        for (int i = 0; i < mat->rows; i++) {
            for (int j = 0; j < mat->cols; j++) {
                mat->m[i][j] = (rand() / (double)RAND_MAX) * 2.0 - 1.0;
                //mat->m[i][j] = (double)rand() / RAND_MAX * 2.0 - 1.0;;
            }
        }
        return mat;
    }
    else {
        fprintf(stderr, "Matrix must have its dimensions already defined.\n");
        exit(EXIT_FAILURE);
    }
}

// Fonctions de génération d'une matrice identité N :
Matrix* createIdentity(int size) { // O(n) où n = size  
    Matrix* m = create_matrix(size, size);
    for (int i=0; i<size; ++i) {
        m->m[i][i] = 1;
    }
    return m;
}



// Fonction pour générer une matrice aléatoire avec des valeurs entre min_value et max_value
void generate_random_matrix_bounded(Matrix* matrix, int min_value, int max_value) { //O(mn) où m = mat->rows et n = mat->cols
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            //matrix->m[i][j] = min_value + (double) rand() % (max_value - min_value + 1);
            matrix->m[i][j] = min_value + (double) rand() / RAND_MAX * (max_value - min_value);
        }
    }
}


// Fonction pour afficher une matrice
void print_matrix(const Matrix* mat) { //O(mn) où m = mat->rows et n = mat->cols
    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->cols; ++j) {
            printf("%lf ", mat->m[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour libérer la mémoire de la matrice
void free_matrix(Matrix* mat) { //O(n) où n = mat->rows
    for (int i = 0; i < mat->rows; i++) {
        free(mat->m[i]);
    }
    free(mat->m);
    free(mat);
}

// Addition de deux matrices
Matrix* addMatrices(Matrix* A, Matrix* B) { //O(nm) où n = A->rows and n = A->cols
    if (A->cols != B->cols || A->rows != B->rows) {
        fprintf(stderr, "Matrixes dimensions are not compatible with addition\n");
        exit(EXIT_FAILURE);
    }

    //Créer la matrice résultat C de taille A.row x A.col
    Matrix* result = create_matrix(A->rows, A->cols);

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->m[i][j] = A->m[i][j] + B->m[i][j];
        }
    }
    return result;
}

// Soustraction de deux matrices
Matrix* subtractMatrices(Matrix* A, Matrix* B) { //O(nm) où n = A->rows and n = A->cols
    if (A->cols != B->cols || A->rows != B->rows) {
        fprintf(stderr, "Matrixes dimensions are not compatible with subtraction\n");
        exit(EXIT_FAILURE);
    }

    //Créer la matrice résultat C de taille A.row x A.col
    Matrix* result = create_matrix(A->rows, A->cols);

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->m[i][j] = A->m[i][j] - B->m[i][j];
        }
    }

    return result;
}


//Fonction pour calculer la matrice C =A*B où A=n*m et B=m*q
Matrix* naive_matrix_multiplication(Matrix* A, Matrix* B) { // O(mnp) où m = A->rows , n = A->cols et p = B->cols 
    if (A->cols != B->rows) {
        fprintf(stderr, "Matrixes dimensions are not compatible with multiplication\n");
        exit(EXIT_FAILURE);
    }

    //Créer la matrice résultat C de taille A.row x B.col
    Matrix* C = create_matrix(A->rows, B->cols);

    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j < B->cols; j++){
            for(int k = 0; k < A->cols; k++){
                C->m[i][j] += A->m[i][k] * B->m[k][j]; 
            }
        }
    }
    return C;
}

// Fonction de recherche du maximum dans une matrice :
Pair searchForMax(Matrix* matrix, int size) { //O(n²) où n = size
    Pair pair;
    double max = matrix->m[0][0];
    pair.row = 0; pair.col = 0;
    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            if ( ABS(matrix->m[i][j]) > max) {
                max = matrix->m[i][j];
                pair.row = i;
                pair.col = j;
            }
        }
    }
    return pair;
}

// Fonction pour découper une matrice en sous-matrices
void splitMatrix(Matrix* A, Matrix* A11, Matrix* A12, Matrix* A21, Matrix* A22) {
    int newSize = A->rows / 2;
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11->m[i][j] = A->m[i][j];
            A12->m[i][j] = A->m[i][j + newSize];
            A21->m[i][j] = A->m[i + newSize][j];
            A22->m[i][j] = A->m[i + newSize][j + newSize];
        }
    }
}


// Fonctions de Permutations :



// ###### Tests :
//gcc -Wall -o mat MatrixOperations.c

int naive_matrix_multiplicationTest() {
    srand(time(NULL));  // Initialise la graine de nombre aléatoire

    // Définir la taille des matrices A et B
    int m = 3;  // nb de lignes de A
    int n = 4;  // nb de colonnes de B et nb de lignes de B
    int c = 2;  // nb de colonnes de B

    // Créer les matrices A et B
    Matrix* A = create_matrix(m, n);
    Matrix* B = create_matrix(n, c);

    // Générer une matrice aléatoire
    generate_random_matrix(A);
    generate_random_matrix(B);

    //Afficher les matrices A et B
    printf("Matrix A (size %d x %d):\n", A->rows, A->cols);
    print_matrix(A);
    printf("\nMatrix B (size %d x %d):\n", B->rows, B->cols);
    print_matrix(B);

    // calculer le produit matriciel C = A * B
    Matrix* C = naive_matrix_multiplication(A, B);

    // Afficher lA matrice résultat C
    printf("\nResult Matrix C (size %d x %d):\n", C->rows, C->cols);
    print_matrix(C);

    // libère de la mémoire
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);

    return 0;
}

int main0() {

    naive_matrix_multiplicationTest();
    return 0;
}