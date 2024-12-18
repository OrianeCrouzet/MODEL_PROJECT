/*
PROJET : MODEL 2024-2025

Etudiants :
CIDERE Taryck 21400635
CROUZET Oriane 21414555
CHEN Shiyao 28707756

*/

#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <time.h>
#include <stdio.h>

typedef struct Chronometer {
    clock_t start;
    clock_t end;
    char* label;
} Chronometer;

void setLabel(Chronometer* chrono, char* label);

char* getLabel(Chronometer* chrono);

void startChronometer(Chronometer* chrono);
void EndChronometer(Chronometer* chrono);

clock_t getElapsedTime(Chronometer* chrono);

void writeElapsedTimeToCSV(Chronometer** chronos, int count, const char* filename, const char* label);

#endif // CHRONOMETER_H