/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635

*/

#include "MeasureComplexity.h"
#include "Chronometer.h"

#include "MatrixOperations.h"
#include "LU_Decomposition.h"

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

        // Libération de la mémoire
        free_matrix(A);
        free_matrix(B);
    }
    // FIN mesures de temps

    // Ecriture des temps :
    writeElapsedTimeToCSV(chronos, n, fileName, "Multiplication Naive");

    // Libération mémoire des chronos
    for (int i = 0; i < n; ++i) {
        free(chronos[i]);
    }
}

