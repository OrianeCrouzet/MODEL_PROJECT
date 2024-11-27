#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MatrixOperations.h"
#include "Strassen_inversion.h"
#include "LU_Decomposition.h"


// Vérifie si n est une puissance de 2
int is_power_of_two(int n) {
    return n >= 0  && (n & (n - 1)) == 0;
}

// Trouver le 2^k le plus proche supérieur ou égal à n
int next_power_of_two(int n) { // O(log(n))
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
Matrix* pad_matrix(Matrix* A){ // O(n²) n = newSize
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
Matrix* unpad_matrix(Matrix* A, int orignal_Size){ // O(n²) n = orignal_Size
    Matrix* unpadded = create_matrix(orignal_Size, orignal_Size);
    for(int i = 0; i < orignal_Size; i++){
        for(int j = 0; j<orignal_Size; j++){
            unpadded->m[i][j] = A->m[i][j];
        }
    }
    return unpadded;
}

// Matrix Inversion Using LU Decomposition
void matrix_inversion(Matrix* A, Matrix* invA){ // O(n^3) n = A->rows
    int n = A->rows;
    Matrix* L = createIdentity(n);
    Matrix* U = create_matrix(n,n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            U->m[i][j]=A->m[i][j];
        }
    }

    LU_facorization(L,U);

    for(int j = 0; j < n; j++){
        double *e = calloc(n, sizeof(double));
        double *y = calloc(n, sizeof(double));
        e[j] = 1.0;

        // Forward substitution for L * y = e
        for (int i = 0; i < n; i++) {
            y[i] = e[i];
            for (int k = 0; k < i; k++) {
                y[i] -= L->m[i][k] * y[k];
            }
        }

        // Backward substitution for U * x = y
        for (int i = n - 1; i >= 0; i--) {
            invA->m[i][j] = y[i];
            for (int k = i + 1; k < n; k++) {
                invA->m[i][j] -= U->m[i][k] * invA->m[k][j];
            }
            invA->m[i][j] /= U->m[i][i];
        }
        free(e);
        free(y);
    }
    free_matrix(L);
    free_matrix(U);
}


Matrix* strassen_inverse(Matrix* A) { // O(n^w), with 2 < w < 3.
    int originalSize = A ->rows;

    // Remplit la matrice à la taille 2^k la plus proche
    Matrix* pad = pad_matrix(A);

    int n = pad->rows;

    // Creer un matrice inverse de A
    Matrix* res = create_matrix(n,n);
    if (n == 1){
        if(pad->m[0][0]==0.0){
            free_matrix(res);
            return pad;
        }
        res->m[0][0]=1/pad->m[0][0];
        free_matrix(pad);
        return res;
    }
    
    int newSize = n / 2;

    // Split the matrix A into 4 submatrices a, b, c, d
    Matrix* a = create_matrix(newSize,newSize);
    Matrix* b = create_matrix(newSize,newSize);
    Matrix* c = create_matrix(newSize,newSize);
    Matrix* d = create_matrix(newSize,newSize);

    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            a->m[i][j] = pad->m[i][j];
            b->m[i][j] = pad->m[i][j+newSize];
            c->m[i][j] = pad->m[i+newSize][j];
            d->m[i][j] = pad->m[i+newSize][j+newSize];
        }
    }

    // Step 1: Compute e = a^-1 recursively
    Matrix* e = strassen_inverse(a);
    // printf("e:\n");
    // print_matrix(e);

    // Step 2: Compute Z = d - ceb
    Matrix* tmp1 = naive_matrix_multiplication(c,e);
    Matrix* tmp2 = naive_matrix_multiplication(tmp1,b);
    Matrix* Z = subtractMatrices(d,tmp2);

    // printf("Z:\n");
    // print_matrix(Z);


    // Step 3:Compute t = Z^-1 recursively.
    Matrix* t = strassen_inverse(Z);
    // printf("t:\n");
    // print_matrix(t);

    // Step 4:Compute y = -ebt, z = -tce, x = e + ebtce.

    // y = -ebt
    Matrix* tmp3 = naive_matrix_multiplication(e,b);
    Matrix* y = naive_matrix_multiplication(tmp3,t);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            y->m[i][j] = -y->m[i][j]; // y = -y
        }
    }
    // printf("y:\n");
    // print_matrix(y);

    // z = -tce
    Matrix* tmp4 = naive_matrix_multiplication(t,c);
    Matrix* z = naive_matrix_multiplication(tmp4,e);
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            z->m[i][j] = -z->m[i][j]; // y = -y
        }
    }
    // printf("z:\n");
    // print_matrix(z);


    // x = e + ebtce
    Matrix* tmp5 = naive_matrix_multiplication(e,b);
    Matrix* tmp6 = naive_matrix_multiplication(tmp5,t);
    Matrix* tmp7 = naive_matrix_multiplication(tmp6,c);
    Matrix* tmp8 = naive_matrix_multiplication(tmp7,e);
    Matrix* x = addMatrices(e,tmp8);
    // printf("x:\n");
    // print_matrix(x);

    // Fusionner x, y, z, t en A_inv
    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            res->m[i][j] = x->m[i][j];
            res->m[i][j+newSize] = y->m[i][j];
            res->m[i+newSize][j] = z->m[i][j];
            res->m[i+newSize][j+newSize] = t->m[i][j];
        }
    }
    // printf("\ninv de mat:\n");
    // print_matrix(res);

    Matrix* res_unpad = unpad_matrix(res,originalSize);
    // Libérer la mémoire
    free_matrix(pad);
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
    free_matrix(d);
    free_matrix(e);
    free_matrix(Z);
    free_matrix(t);
    free_matrix(tmp1);
    free_matrix(tmp2);
    free_matrix(tmp3);
    free_matrix(tmp4);
    free_matrix(tmp5);
    free_matrix(tmp6);
    free_matrix(tmp7);
    free_matrix(tmp8);
    free_matrix(x);
    free_matrix(y);
    free_matrix(z);
    free_matrix(res);

    return res_unpad;
}

int main3(){
    int rows = 4, cols = 4;

    // Créer une matrice de 3 lignes et 4 colonnes
    Matrix* M = create_matrix(rows, cols);
    Matrix* invM = create_matrix(rows, cols);

    double** matrix = M->m;

    matrix[0][0] = 4; matrix[0][1] = 4; matrix[0][2] = 8; matrix[0][3] = 1;
    matrix[1][0] = 2; matrix[1][1] = 8; matrix[1][2] = 7; matrix[1][3] = 1;
    matrix[2][0] = 1; matrix[2][1] = 3; matrix[2][2] = 6; matrix[2][3] = 1;
    matrix[3][0] = -4; matrix[3][1] = 6; matrix[3][2] = 5; matrix[3][3] = 1;
    printf("l'original de Matrice A\n");
    print_matrix(M);
    printf("\nl'inversion de Matrice A\n");
    matrix_inversion(M,invM);
    print_matrix(invM);

    printf("\nl'inversion de Matrice A utilisé Algo Strassen\n");
    Matrix* res = strassen_inverse(M);
    print_matrix(res); 
    return 0;
}
