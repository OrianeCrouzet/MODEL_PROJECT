#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatrixOperations.h"
#include "MatrixOperations.c"

// Vérifie si n est une puissance de 2
int is_power_of_two(int n) {
    return n >=0 && (n & (n - 1)) == 0;
}

// Trouver le 2^k le plus proche supérieur ou égal à n
int next_power_of_two(int n) {
    int is_puissance2 = is_power_of_two(n);
    if (is_puissance2 == 1){
        return n;

    }
    int power = 1;
    while (power < n) {
        power *= 2;
    }
    return power;  
}

// Calculer la fonction max
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Remplit la matrice à la taille 2^k la plus proche
Matrix* pad_matrix(Matrix* A){
    int newRow = next_power_of_two(A->rows);
    int newCol = next_power_of_two(A->cols);
    int newSize = max(newRow, newCol);
    Matrix* padded = create_matrix(newSize, newSize);
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j<A->cols; j++){
            padded->m[i][j] = A->m[i][j];
        }
    }
    return padded;
}


// Supprime la matrice remplie
Matrix* unpad_matrix(Matrix* A, int orignal_Size){
    Matrix* unpadded = create_matrix(orignal_Size, orignal_Size);
    for(int i = 0; i < A->rows; i++){
        for(int j = 0; j<A->cols; j++){
            unpadded->m[i][j] = A->m[i][j];
        }
    }
    return unpadded;
}

// Strassen’s inversion algorithm
void strassen_inverse(Matrix* A) {
    int n = A->cols;
    if (n == 1){
        return ;
    }
}
