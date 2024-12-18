/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "MatrixOperations.h"
#include "LU_Decomposition.h"
#include "Strassen_inversion.h"
#include "MeasureComplexity.h"

/*
int main(){
    printf("***************** naive_matrix_multiplicationTest ****************\n");
    srand(time(NULL));  // Initialise la graine de nombre aléatoire

    // Définir la taille des matrices A et B
    int m = 3;  // nb de lignes de A
    int n = 3;  // nb de colonnes de B et nb de lignes de B
    int c = 3;  // nb de colonnes de B

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

    printf("\n**************** LU decomposition of a Matrix ****************\n");
    printf("\nLU decomposition of a Matrix: \n\n");
    
    Matrix* D = create_matrix(n,n);
    generate_random_matrix(D);

    // Créer une matrice de 3 lignes et 3 colonnes
    Matrix* lowerTriangular = createIdentity(m);
    
    printf("Matrices originales:\n");
    printf("\nMatrice L\n");
    print_matrix(lowerTriangular);
    printf("\nMatrice U\n");
    print_matrix(D);

    //LU Factorization :
    LU_facorization(lowerTriangular, D);

    printf("\nMatrices obtenues:\n");
    //Matrice L :
    printf("\nMatrice : L\n");
    print_matrix(lowerTriangular);
    //Matrice U :
    printf("\nMatrice : U\n");
    print_matrix(D);

    printf("***************** inversion une matrix par LU decomposition ****************\n");
    Matrix* M = create_matrix(n,n);
    generate_random_matrix(M);

    Matrix* invM = create_matrix(n, n);

    printf("l'original de Matrice A:\n");
    print_matrix(M);
    printf("\nl'inversion de Matrice A:\n");
    matrix_inversion(M,invM);
    print_matrix(invM);

    printf("\n***************** inversion une matrix par Strassen's inversion algorithm ****************\n");
    printf("l'inversion de Matrice M utilisé Algo Strassen\n");
    Matrix* res = strassen_inverse(M);
    print_matrix(res);
   

    // libère de la mémoire
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    free_matrix(D);
    free_matrix(M);
    free_matrix(invM);
    free_matrix(res);
    free_matrix(lowerTriangular);

    
    return 0;
}
*/

int main() {
    srand(time(NULL));  // Initialise la graine de nombre aléatoire

    measure_NaiveMatrixMultiplication(1000, "MultNaive.csv");
}