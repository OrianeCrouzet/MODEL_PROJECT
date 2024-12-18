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

### Structure des fichiers





