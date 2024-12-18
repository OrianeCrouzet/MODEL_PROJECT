/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "StrassenProduct.h"
#include "MatrixOperations.h"

// Fonction pour obtenir la puissance de 2 la plus proche supérieure
int nextPowerOfTwo(int n) {
    int power = 1;
    while (power < n) {
        power *= 2;
    }
    return power;
}

// Fonction pour redimensionner une matrice à une taille puissance de 2
Matrix* resize_to_power_of_two(Matrix* mat, int newSize) {
    Matrix* resized = create_matrix(newSize, newSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            resized->m[i][j] = (i < mat->rows && j < mat->cols) ? mat->m[i][j] : 0.0;
        }
    }
    return resized;
}

// Fonction Strassen pour la multiplication de deux matrices
Matrix* strassen_product(Matrix* A, Matrix* B) {
    // Ajustement pour la taille puissance de 2
    int originalRows = A->rows;
    int originalCols = B->cols;
    int maxSize = nextPowerOfTwo(A->rows > A->cols ? A->rows : A->cols);
    maxSize = nextPowerOfTwo(B->rows > maxSize ? B->rows : maxSize);

    Matrix* resizedA = resize_to_power_of_two(A, maxSize);
    Matrix* resizedB = resize_to_power_of_two(B, maxSize);

    // Cas de base : multiplication de deux scalaires
    if (maxSize == 1) {
        Matrix* C = create_matrix(1, 1);
        C->m[0][0] = resizedA->m[0][0] * resizedB->m[0][0];
        free_matrix(resizedA);
        free_matrix(resizedB);
        return C;
    }

    int newSize = maxSize / 2;

    // Allocation des sous-matrices
    Matrix* A11 = create_matrix(newSize, newSize);
    Matrix* A12 = create_matrix(newSize, newSize);
    Matrix* A21 = create_matrix(newSize, newSize);
    Matrix* A22 = create_matrix(newSize, newSize);
    Matrix* B11 = create_matrix(newSize, newSize);
    Matrix* B12 = create_matrix(newSize, newSize);
    Matrix* B21 = create_matrix(newSize, newSize);
    Matrix* B22 = create_matrix(newSize, newSize);

    // Découpage des matrices A et B
    splitMatrix(resizedA, A11, A12, A21, A22);
    splitMatrix(resizedB, B11, B12, B21, B22);

    // Calcul des 7 produits de Strassen
    Matrix* M1 = strassen_product(addMatrices(A11, A22), addMatrices(B11, B22));
    Matrix* M2 = strassen_product(addMatrices(A21, A22), B11);
    Matrix* M3 = strassen_product(A11, subtractMatrices(B12, B22));
    Matrix* M4 = strassen_product(A22, subtractMatrices(B21, B11));
    Matrix* M5 = strassen_product(addMatrices(A11, A12), B22);
    Matrix* M6 = strassen_product(subtractMatrices(A21, A11), addMatrices(B11, B12));
    Matrix* M7 = strassen_product(subtractMatrices(A12, A22), addMatrices(B21, B22));

    // Combinaison des résultats
    Matrix* C11 = addMatrices(subtractMatrices(addMatrices(M1, M4), M5), M7);
    Matrix* C12 = addMatrices(M3, M5);
    Matrix* C21 = addMatrices(M2, M4);
    Matrix* C22 = addMatrices(subtractMatrices(addMatrices(M1, M3), M2), M6);

    // Assemblage de la matrice résultat C
    Matrix* fullC = create_matrix(maxSize, maxSize);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            fullC->m[i][j] = C11->m[i][j];
            fullC->m[i][j + newSize] = C12->m[i][j];
            fullC->m[i + newSize][j] = C21->m[i][j];
            fullC->m[i + newSize][j + newSize] = C22->m[i][j];
        }
    }

    // Tronquer le résultat à la taille originale
    Matrix* result = create_matrix(originalRows, originalCols);
    for (int i = 0; i < originalRows; i++) {
        for (int j = 0; j < originalCols; j++) {
            result->m[i][j] = fullC->m[i][j];
        }
    }

    // Libération de mémoire
    free_matrix(resizedA); free_matrix(resizedB);
    free_matrix(A11); free_matrix(A12); free_matrix(A21); free_matrix(A22);
    free_matrix(B11); free_matrix(B12); free_matrix(B21); free_matrix(B22);
    free_matrix(M1); free_matrix(M2); free_matrix(M3); free_matrix(M4);
    free_matrix(M5); free_matrix(M6); free_matrix(M7);
    free_matrix(C11); free_matrix(C12); free_matrix(C21); free_matrix(C22);
    free_matrix(fullC);

    return result;
}

int main4() {
    Matrix* A = create_matrix(4, 4);
    Matrix* B = create_matrix(4, 4);

    // Initialisation des matrices A et B
    generate_random_matrix_bounded(A, 1, 10);
    generate_random_matrix_bounded(B, 1, 10);

    printf("Matrice A :\n");
    print_matrix(A);
    printf("Matrice B :\n");
    print_matrix(B);

    // Multiplication Strassen
    Matrix* C = strassen_product(A, B);

    printf("Resultat A x B (Strassen) :\n");
    print_matrix(C);

    // Libération de mémoire
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    return 0;
}

