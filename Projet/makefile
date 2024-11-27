all: main

main: main.o MatrixOperations.o LU_Decomposition.o Strassen_inversion.o
	gcc -Wall -o main main.o MatrixOperations.o LU_Decomposition.o Strassen_inversion.o
main.o: main.c MatrixOperations.o LU_Decomposition.o Strassen_inversion.o
	gcc -Wall  -c main.c

Strassen_inversion.o: Strassen_inversion.c Strassen_inversion.h LU_Decomposition.o MatrixOperations.o
	gcc -Wall  -c Strassen_inversion.c

LU_Decomposition.o: LU_Decomposition.c LU_Decomposition.h MatrixOperations.o
	gcc -Wall -c LU_Decomposition.c

MatrixOperations.o: MatrixOperations.c MatrixOperations.h
	gcc -Wall -c MatrixOperations.c

clean:
	rm -f  main  *.o

