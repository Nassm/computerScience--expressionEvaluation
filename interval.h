#ifndef INTERVAL_H
#define INTERVAL_H
#include <stdio.h>
#include <stdlib.h>

/* Interval structure */
typedef struct Interval
{
    double min;
    double max;

} interval ;

//const int maxArraySize = 4;

/* getMin */
double getMin(double b[4]);

/* getMax */
double getMax(double b[4]);

/* getSum */
interval getSum(interval alpha, interval beta);

/* getDiff */
interval getDiff(interval alpha, interval beta);

/* getMull*/
interval getMul(interval x, interval y);

/* test for tree eval*/
interval evaTreeWith(interval x, interval y);

/* test for print interval*/
void printinterval(interval X);

#endif // INTERVAL_H