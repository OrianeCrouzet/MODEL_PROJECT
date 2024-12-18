/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635
CHEN Shiyao 28707756

*/

#ifndef MEASURE_COMPLEXITY_H
#define MEASURE_COMPLEXITY_H

// Pour chacune des fonctions qu'on a crée, nous allons créer une méthode qui prendra en entrée :
/*  - Un entier qui représentera le nombre de fois qu'on exécutera la fonction
    - Un nom de fichier qui correspondra au fichier ou seront écrit les données récoltés

    Les méthodes crées auront pour but de mesurer le temps d'exécution de chacune de nos fonctions.
    Les Matrices utilisées pour la mesures devront être crées aleatoirement comme demandé dans l'énoncé du projet.
    On convertira en CSV les résultats directement via une méthode de Chronometre (vous pouvez en créer d'autres si celle déjà implémenter ne vous convient pas.)
    On pourra par la suite tracer des graphes avec python ou ce que vous voulez. (Il exsite un dossier Mesures où pourront être stocker les résultats pour éviter de créer un bordel)
*/

// Mesure le temps d'exécution de la multiplication naive
void measure_NaiveMatrixMultiplication(int n, char* fileName);

// Mesure le temps d'exécution de la LU
void measure_NaiveLUDecomposition(int n, char* fileName);

// Mesure le temps d'exécution de la multiplication strassen
void measure_StrassenMatrixMultiplication(int n, char* fileName);

// Mesure le temps d'exécution de la inversion par LU 
void measure_LUMatrixInversion(int n, char* fileName);

// Mesure le temps d'exécution de l'inversion naive
void measure_NaiveMatrixInversion(int n, char* fileName);

// Mesure le temps d'exécution de l'inversion strassen
void measure_StrassenMatrixInversion(int n, char* fileName);


#endif // MEASURE_COMPLEXITY_H