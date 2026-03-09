#ifndef SALES_REPORT_H
#define SALES_REPORT_H

#include <stdio.h>

typedef enum Month {
  JAN, FEB, MAR, APR, MAY, JUN, JUL,
  AUG, SEP, OCT, NOV, DEC, MONTH_COUNT
} Month;

extern const char *monthNames[MONTH_COUNT];

typedef struct {
  const char *month;
  double sales;
}SaleRecord;

void monthlyReport(const double sales[]);
void summaryReport(const double sale[]);
void movingAverageReport(const double sales[]);
void highestToLowestReport(const double sales[]);

#endif




