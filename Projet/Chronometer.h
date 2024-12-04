#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <time.h>
#include <stdio.h>

typedef struct Chronometer {
    clock_t start;
    clock_t end;
} Chronometer;

void startChronometer(Chronometer* chrono);
void EndChronometer(Chronometer* chrono);

void getElapsedTime(Chronometer* chrono);

void writeElapsedTimeToCSV(Chronometer* chrono, const char* filename, const char* label);

#endif // CHRONOMETER_H