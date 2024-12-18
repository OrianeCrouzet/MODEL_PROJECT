# Implementation project: Model

**Langage:**  
Langage du projet en C.  

## Introduction
Ce projet implémente une gamme d'algorithmes pour matrices, comprenant des approches naïves ainsi que des algorithmes optimisés tels que la méthode de Strassen. Il inclut des fonctions pour la multiplication matricielle, la décomposition LU et l'inversion matricielle, basées sur ces différentes techniques. Les performances de ces algorithmes seront évaluées et comparées sur des matrices de tailles variées, avec des coefficients à virgule flottante dans l'intervalle [-1, 1].


Ce fichier README.md explique comment compiler et exécuter le code du projet, ainsi qu'une brève description de chaque fichier. Veuillez suivre les instructions ci-dessous pour configurer l'environnement et tester le programme.

### Prérequis  

Avant d'exécuter ce projet, assurez-vous que les outils suivants sont installés :

    Compilateur GCC (version recommandée : >= 9.0)
    Outils de compilation Make

### Compilation

Ouvrez un terminal et accédez au répertoire du projet.

Exécutez la commande suivante pour compiler le projet :  
    
    make   # ou make all

Cela générera un fichier exécutable nommé main.

Si vous devez nettoyer les fichiers compilés et réinitialiser le répertoire, exécutez la commande suivante :  
 
    make clean


### Exécution

Une fois la compilation terminée, vous pouvez exécuter le programme en utilisant la commande suivante :

```bash
./main
```

Le programme exécutera les différents algorithmes et enregistrera les temps d'exécution dans un fichier `.csv` pour chaque algorithme, vous permettant ainsi de comparer leurs performances et de mieux comprendre leurs complexités.


### Description des fichiers

- **`main.c`** : Le programme principal qui teste les différents algorithmes et enregistre les temps d'exécution dans les fichiers `.csv`.
- **`MatrixOperations.c`** : Contient les fonctions de manipulation des opérations fondamentales sur les matrices, incluant la multiplication naïve.
- **`StrassenProduct.c`** : Implémente l'algorithme de Strassen pour la multiplication de matrices.
- **`LU_decomposition.c`** : Implémente la décomposition LU d'une matrice.
- **`Chronometer.c`** : Contient les fonctions pour mesurer le temps.
- **`MeasureComplexity.c`** : Calcule la complexité temporelle des algorithmes en utilisant les fonctions de `Chronometer.c` et en enregistrant les résultats dans des fichiers.
- **`Strassen_inversion.c`** : Implémente l'inversion de matrices par décomposition LU et par l'algorithme de Strassen (version classique et Strassen).
- **`MatrixOperations.h`** : En-tête pour les fonctions de manipulation des matrices.
- **`StrassenProduct.h`** : En-tête pour l'algorithme de Strassen et la multiplication de matrices par Strassen.
- **`LU_Decomposition.h`** : En-tête pour la décomposition LU.
- **`Chronometer.h`** : En-tête pour les fonctions de mesure du temps d'exécution.
- **`MeasureComplexity.h`** : En-tête pour les fonctions de calcul de la complexité temporelle.
- **`Strassen_inversion.h`** : En-tête pour l'inversion de matrices.
- **`InvNaive.csv`** : Contient les résultats des temps d'exécution pour l'inversion de matrices effectuée avec la méthode naïve.
- **`InvStrassen.csv`** : Contient les résultats des temps d'exécution pour l'inversion de matrices effectuée avec la méthode Strassen.
- **`LUInversion.csv`** : Contient les résultats des temps d'exécution pour l'inversion de matrices effectuée avec la décomposition LU.
- **`MultNaive.csv`** : Contient les résultats des temps d'exécution pour la multiplication de matrices effectuée avec la méthode naïve.
- **`MultStrassen.csv`** : Contient les résultats des temps d'exécution pour la multiplication de matrices effectuée avec la méthode Strassen.
- **`LUDecomposition.csv`** : Contient les résultats des temps d'exécution pour l'algorithme de décomposition LU.
- **`Makefile`** : Fichier de configuration pour la compilation du projet.


### Rapport

Le rapport final du projet est disponible dans le fichier **`report.pdf`**, où sont présentées les méthodes, les résultats, et les conclusions tirées des tests de performance.

