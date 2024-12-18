all: main

main: main.o MatrixOperations.o LU_Decomposition.o Strassen_inversion.o Chronometer.o MeasureComplexity.o StrassenProduct.o
	gcc -Wall -o main main.o MatrixOperations.o LU_Decomposition.o Strassen_inversion.o Chronometer.o MeasureComplexity.o StrassenProduct.o

main.o: main.c MatrixOperations.h LU_Decomposition.h Strassen_inversion.h Chronometer.h MeasureComplexity.h StrassenProduct.h
	gcc -Wall -c main.c

Strassen_inversion.o: Strassen_inversion.c Strassen_inversion.h LU_Decomposition.o MatrixOperations.o
	gcc -Wall  -c Strassen_inversion.c

LU_Decomposition.o: LU_Decomposition.c LU_Decomposition.h MatrixOperations.o
	gcc -Wall -c LU_Decomposition.c

MatrixOperations.o: MatrixOperations.c MatrixOperations.h
	gcc -Wall -c MatrixOperations.c

StrassenProduct.o: StrassenProduct.c StrassenProduct.h
	gcc -Wall -c StrassenProduct.c

Chronometer.o: Chronometer.c Chronometer.h
	gcc -Wall -c Chronometer.c

MeasureComplexity.o: MeasureComplexity.c MeasureComplexity.h
	gcc -Wall -c MeasureComplexity.c

clean:
	rm -f  main  *.o

