#include <stdio.h>
#include "sales_report.h"

int main(){
  double sales[MONTH_COUNT] = {
    [JAN] = 23458.01,
    [FEB] = 40112.00,
    [MAR] = 56011.85,
    [APR] = 37820.88,
    [MAY] = 37904.67,
    [JUN] = 60200.22,
    [JUL] = 72400.31,
    [AUG] = 56210.89,
    [SEP] = 67230.84,
    [OCT] = 68233.12,
    [NOV] = 80950.34,
    [DEC] = 95225.22
  };

  monthlyReport(sales);
  summaryReport(sales);
  movingAverageReport(sales);
  highestToLowestReport(sales);

  return 0;
}