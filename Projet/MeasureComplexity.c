/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635
CROUZET Oriane 21414555
CHEN Shiyao 28707756

*/
#include <stdio.h>

#include "MeasureComplexity.h"
#include "Chronometer.h"

#include "MatrixOperations.h"
#include "LU_Decomposition.h"
#include "StrassenProduct.h"
#include "LU_Decomposition.h"
#include "Strassen_inversion.h"



void measure_NaiveMatrixMultiplication(int n, char* fileName) {
    Chronometer* chronos[n];
    
    // Allocation mémoire des chronos
    for (int i = 0; i < n; ++i) {
    chronos[i] = malloc(sizeof(Chronometer));
        if (!chronos[i]) {
            perror("Failed to allocate memory for Chronometer");
            exit(1);
        }
    }

    // Mesure des temps
    // On va réaliser la multiplication de matrice carré de taille croissante
    for (int i=0; i<n; ++i) {
        Chronometer* chrono = chronos[i];

        Matrix* A = create_matrix(i+1, i+1);
        Matrix* B = create_matrix(i+1, i+1);
        generate_random_matrix(A);
        generate_random_matrix(B);

        startChronometer(chrono);
        naive_matrix_multiplication(A, B);
        EndChronometer(chrono);
        // printf("i = %d\n", i);
        // Libération de la mémoire
        free_matrix(A);
        free_matrix(B);
    }
    // FIN mesures de temps

    // Ecriture des temps :
    writeElapsedTimeToCSV(chronos, n, fileName, "Temps");

    // Libération mémoire des chronos
    for (int i = 0; i < n; ++i) {
        free(chronos[i]);
    }
}


void measure_NaiveLUDecomposition(int n, char* fileName) {
    Chronometer* chronos[n];
    
    // Allocation mémoire des chronos
    for (int i = 0; i < n; ++i) {
    chronos[i] = malloc(sizeof(Chronometer));
        if (!chronos[i]) {
            perror("Failed to allocate memory for Chronometer");
            exit(1);
        }
    }

    // Mesure des temps
    // On va réaliser la multiplication de matrice carré de taille croissante
    for (int i=0; i<n; ++i) {
        Chronometer* chrono = chronos[i];

        Matrix* A = create_matrix(i+1, i+1);
        Matrix* B = createIdentity(i+1);
        generate_random_matrix(A);

        startChronometer(chrono);
        LU_facorization(A, B);
        EndChronometer(chrono);
        // printf("i = %d\n", i);

        // Libération de la mémoire
        free_matrix(A);
        free_matrix(B);
    }
    // FIN mesures de temps

    // Ecriture des temps :
    writeElapsedTimeToCSV(chronos, n, fileName, "Temps");

    // Libération mémoire des chronos
    for (int i = 0; i < n; ++i) {
        free(chronos[i]);
    }
}

void measure_StrassenMatrixMultiplication(int n, char* fileName) {
    Chronometer* chronos[n];
    
    // Allocation mémoire des chronos
    for (int i = 0; i < n; ++i) {
    chronos[i] = malloc(sizeof(Chronometer));
        if (!chronos[i]) {
            perror("Failed to allocate memory for Chronometer");
            exit(1);
        }
    }

    // Mesure des temps
    // On va réaliser la multiplication de matrice carré de taille croissante
    for (int i=0; i<n; ++i) {
        Chronometer* chrono = chronos[i];

        Matrix* A = create_matrix(i+1, i+1);
        Matrix* B = create_matrix(i+1, i+1);
        generate_random_matrix(A);
        generate_random_matrix(B);

        startChronometer(chrono);
        strassen_product(A, B);
        EndChronometer(chrono);
        // printf("i =%d \n",i);
        // Libération de la mémoire
        free_matrix(A);
        free_matrix(B);
    }
    // FIN mesures de temps

    // Ecriture des temps :
    writeElapsedTimeToCSV(chronos, n, fileName, "Temps");

    // Libération mémoire des chronos
    for (int i = 0; i < n; ++i) {
        free(chronos[i]);
    }
}


void measure_LUMatrixInversion(int n, char* fileName) {
    Chronometer* chronos[n];
    
    // Allocation mémoire des chronos
    for (int i = 0; i < n; ++i) {
    chronos[i] = malloc(sizeof(Chronometer));
        if (!chronos[i]) {
            perror("Failed to allocate memory for Chronometer");
            exit(1);
        }
    }

    // Mesure des temps
    // On va réaliser la multiplication de matrice carré de taille croissante
    for (int i=0; i<n; ++i) {
        Chronometer* chrono = chronos[i];

        Matrix* A = create_matrix(i+1, i+1);
        Matrix* B = create_matrix(i+1, i+1);
        generate_random_matrix(A);

        startChronometer(chrono);
        matrix_inversion(A, B);
        EndChronometer(chrono);
        // printf("i = %d\n",i);
        // Libération de la mémoire
        free_matrix(A);
        free_matrix(B);
    }
    // FIN mesures de temps

    // Ecriture des temps :
    writeElapsedTimeToCSV(chronos, n, fileName, "Temps");

    // Libération mémoire des chronos
    for (int i = 0; i < n; ++i) {
        free(chronos[i]);
    }
}

void measure_NaiveMatrixInversion(int n, char* fileName) {
    Chronometer* chronos[n];
    
    // Allocation mémoire des chronos
    for (int i = 0; i < n; ++i) {
    chronos[i] = malloc(sizeof(Chronometer));
        if (!chronos[i]) {
            perror("Failed to allocate memory for Chronometer");
            exit(1);
        }
    }

    // Mesure des temps
    // On va réaliser la multiplication de matrice carré de taille croissante
    for (int i=0; i<n; ++i) {
        Chronometer* chrono = chronos[i];

        Matrix* A = create_matrix(i+1, i+1);
        generate_random_matrix(A);

        startChronometer(chrono);
        strassen_inversion_naive_product(A);
        EndChronometer(chrono);
        // printf("i = %d\n", i);

        // Libération de la mémoire
        free_matrix(A);
    }
    // FIN mesures de temps

    // Ecriture des temps :
    writeElapsedTimeToCSV(chronos, n, fileName, "Temps");

    // Libération mémoire des chronos
    for (int i = 0; i < n; ++i) {
        free(chronos[i]);
    }
}

void measure_StrassenMatrixInversion(int n, char* fileName) {
    Chronometer* chronos[n];
    
    // Allocation mémoire des chronos
    for (int i = 0; i < n; ++i) {
    chronos[i] = malloc(sizeof(Chronometer));
        if (!chronos[i]) {
            perror("Failed to allocate memory for Chronometer");
            exit(1);
        }
    }

    // Mesure des temps
    // On va réaliser la multiplication de matrice carré de taille croissante
    for (int i=0; i<n; ++i) {
        Chronometer* chrono = chronos[i];

        Matrix* A = create_matrix(i+1, i+1);
        generate_random_matrix(A);
        startChronometer(chrono);
        strassen_inversion_strassen_product(A);
        EndChronometer(chrono);
        // printf("i =%d \n",i);
        // Libération de la mémoire
        free_matrix(A);
    }
    // FIN mesures de temps

    // Ecriture des temps :
    writeElapsedTimeToCSV(chronos, n, fileName, "Temps");

    // Libération mémoire des chronos
    for (int i = 0; i < n; ++i) {
        free(chronos[i]);
    }
}
