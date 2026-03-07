#include <stdio.h>
#include "sales_report.h"

const char *monthNames[MONTH_COUNT] = {
  "January","February","March","April","May","June","July","August","September","October","Novemeber","December"
};

int readSales(FILE *file, double sales[]){
  for(int i = JAN; i < MONTH_COUNT; i++){
    if(fscanf(file, "%lf", &sales[i]) != 1){
      return 0;
    }
  }
  return 1;
}
