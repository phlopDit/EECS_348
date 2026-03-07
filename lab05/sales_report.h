#ifndef SALES_REPORT_H
#define SALES_REPORT_H

#include <stdio.h>

typedef enum Month {
  JAN, FEB, MAR, APR, MAY, JUN, JUL,
  AUG, SEP, OCT, NOV, DEC, MONTH_COUNT
} Month;

extern const char *monthNames[MONTH_COUNT];

int readSales(File *file, double size[]);
void monthlyReport(double sales[]);
void summarReport(double sale[]);
void movingAverageReport(double sales[]);
void highestToLowestReport(double sales[]);

#endif



// double sales[MONTH_COUNT];



