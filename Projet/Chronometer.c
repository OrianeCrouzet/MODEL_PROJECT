/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635

*/

#include "Chronometer.h"

// Commence le chronometre
void startChronometer(Chronometer* chrono) {
    if (chrono) {
        chrono->start = clock();
    }
}

// Arrête le chronometre
void EndChronometer(Chronometer* chrono) {
    if (chrono && chrono->start) {
        chrono->end = clock();
    }
}

void setLabel(Chronometer* chrono, char* label) {
    if (chrono) {
        chrono->label = label;
    }
}

char* getLabel(Chronometer* chrono) {
    if (chrono) {
        return chrono->label;
    }
    return NULL;
}

// Donne le temps écoulé entre le début et la fin du chronomètre
clock_t getElapsedTime(Chronometer* chrono) {
    if (chrono && chrono->end) {
        return (double)(chrono->end - chrono->start)/ CLOCKS_PER_SEC * 1 /* TEMPS EN SECONDES */;
    }
    // Si le chronometre n'est pas dans un état correcte.
    return -1;
}

void writeElapsedTimeToCSV(Chronometer** chronos, int count, const char* filename, const char* label) {
    if (!chronos || count <= 0 || !filename || !label) {
        fprintf(stderr, "Invalid arguments passed to writeElapsedTimeToCSV.\n");
        return;
    }

    // Ouvrir le fichier en mode append
    FILE* file = fopen(filename, "a");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Écrire le label
    fprintf(file, "Tailles,%s\n", label);

    // Parcourir la liste des chronomètres
    for (int i = 0; i < count; ++i) {
        Chronometer* chrono = chronos[i];

        // Vérifier que le chronomètre est bien initialisé
        if (!chrono || chrono->start == 0 || chrono->end == 0) {
            fprintf(stderr, "Chronometer at index %d is not properly initialized.\n", i);
            continue; // Passer au prochain chronomètre
        }

        // Calculer le temps écoulé
        double elapsedTime = (double)(chrono->end - chrono->start) / CLOCKS_PER_SEC * 1000.0;

        // Ajouter le temps dans le fichier
        fprintf(file, "%d,%.2f\n", i+1,elapsedTime);
    }

    // Ligne vide pour séparer les groupes (facultatif)
    fprintf(file, "\n");

    fclose(file);
}