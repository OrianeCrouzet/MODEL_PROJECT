/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635
CHEN Shiyao 28707756

*/

#include <stdio.h>
#include <stdlib.h>

#include "LU_Decomposition.h"
#include "MatrixOperations.h"

/* 
Soustrait à une ligne d'une matrixe une autre ligne multipliée par un double quelconque.
*/
void substractRow(Matrix* matrix, int row1, int row2, double multiple) {
    for (int i=0; i<matrix->cols; ++i) {
        matrix->m[row2][i] = matrix->m[row2][i]-matrix->m[row1][i]*multiple;
    }
}
/*
Recherche le facteur multiplicatif (x) tel que la soustraction : row2-row1*x mette à 0 l'élément en row2,col.
*/
double findEliminationMutliple(Matrix* matrix, int row1, int row2, int col) {
    return matrix->m[row2][col]/matrix->m[row1][col] ;
}

/*
Réalise l'opération : row2-row1*x tel que l'élément en row2,col vaut 0.
*/
void elimination(Matrix* L, Matrix* U, int row1, int row2, int col) {
        double multiple = findEliminationMutliple(U, row1, row2, col);
        L->m[row2][col] = multiple; //Ajout du coefficient multiplicatif dans la matrice L (triangulaire inférieur)
        substractRow(U, row1, row2, multiple);
}

// Actually we only need U to compute the factorization...
// TODO : Correct this part --> Simplify
void LU_facorization(Matrix* L, Matrix* U) {
    int current_col = 0;

    // Are L and U square matrixes of size n ?
    if (isSquare(L) && isSquare(U) && L->cols == U->cols) {
        int size = L->rows;
        for (int i=0; i<size-1; ++i) {
            for (int j=i+1; j<size; ++j) {
                elimination(L, U, i, j, current_col);
            }
            ++current_col;
            if (current_col==size-1) {
                break; 
            }
        }
    }
    else { // Error
        fprintf(stderr, "Matrixes must be square and the same size.\n");
        exit(EXIT_FAILURE);
    }

}

int main1() {
    int rows = 4, cols = 4;

    // Créer une matrice de 3 lignes et 4 colonnes
    Matrix* M = create_matrix(rows, cols);
    Matrix* lowerTriangular = createIdentity(rows);

    double** matrix = M->m;

    matrix[0][0] = 4; matrix[0][1] = 4; matrix[0][2] = 8; matrix[0][3] = 1;
    matrix[1][0] = 2; matrix[1][1] = 8; matrix[1][2] = 7; matrix[1][3] = 1;
    matrix[2][0] = 1; matrix[2][1] = 3; matrix[2][2] = 6; matrix[2][3] = 1;
    matrix[3][0] = -4; matrix[3][1] = 6; matrix[3][2] = 5; matrix[3][3] = 1;

    printf("Matrices originales:\n");
    printf("Matrice U\n");
    print_matrix(M);
    printf("Matrice L\n");
    print_matrix(lowerTriangular);


    //printf("Multiplication de la matrice : \n");
    //printMatrix(multiplyMatrix(matrix, matrix, 3, 3, 3), 3, 3);

    //LU Factorization :
    LU_facorization(lowerTriangular, M);

    //Matrice L :
    printf("Matrice : L\n");
    print_matrix(lowerTriangular);
    //Matrice U :
    printf("Matrice : U\n");
    print_matrix(M);
    return 0;
}