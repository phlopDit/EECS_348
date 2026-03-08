#include <stdio.h>
#include "sales_report.h"

const char *monthNames[MONTH_COUNT] = {
  "January","February","March","April","May","June",
  "July","August","September","October","Novemeber","December"
};

/**
 * Displays the montly sales report.
 * 
 * @param - Double arrar for montly sales.
 */
void monthlyReport(const double sales[]){
  printf("Monthly Sales Report:\n\n");
  printf("%-10s %s\n", "Month:", "Sales:");

  for(int i = 0; i < MONTH_COUNT; i++){
    printf("%-10s $%.2f\n", monthNames[i], sales[i]);
  }
  printf("\n");
}

/**
 * Takes in a sales array and finds the min month, max month, and average sales for a year and 
 * displays the results.
 * 
 * @param sales - Double array for monthly sales. 
 */
void summaryReport(const double sales[]){
  double min = sales[JAN];
  double max = sales[JAN];
  double sum = 0;
  int minMonth = JAN;
  int maxMonth = JAN;

  for(int i = JAN; i < MONTH_COUNT; i++){
    if(sales[i] < min){
      min = sales[i];
      minMonth = i;
    }else if (sales[i] > max){
      max = sales[i];
      maxMonth = i;
    }
    sum = sales[i];
  }

  double average = sum / MONTH_COUNT;

  printf("\nSales Summary Report:\n\n");
  printf("Minimum Sales: %.2f (%s)\n", min, monthNames[minMonth]);
  printf("Maximum Sales: %.2f (%s)\n", max, monthNames[maxMonth]);
  printf("Average sales: %.2f \n", average);
}

/**
 * Takes in sales array and computes a moving 6 month average and displays the results.
 * 
 * @param sales - Double array for monthly sales.
 */
void movingAverageReport(const double sales[]){
  printf("\nSix-Month moving average report:\n\n");
  for(int i = JAN; i <= JUL; i++){
    double sum = 0;
    for(int j = i; j < i + 6; j++){
      sum += sales[j];
    }
    double average = sum / 6;
    printf("%s-%s %.2f\n", monthNames[i], monthNames[i + 5], average);
  }
}

/**
 * Takes in sales array, creates a new sorted array from highest to lowest sales for each month,
 * and displays the results.
 * 
 * @param sales - Double array for monthly sales.
 */
void highestToLowestReport(const double sales[]){
  SaleRecord records[MONTH_COUNT];

  for(int i = JAN; i < MONTH_COUNT; i++){
    records[i].month = monthNames[i];
    records[i].sales = sales[i];
  }

  for(int i = JAN; i < MONTH_COUNT; i++){
    int max = i;
    for(int j = i +1; j < MONTH_COUNT; j++){
      if (records[j].sales > records[max].sales){
        max = j;
      }
    }
    if(max != i){
      SaleRecord temp = records[i];
      records[i]=records[max];
      records[max]=temp;
    }
  }

  printf("\nSales Report (Hightest to Lowest):\n\n");

  printf("%-12s %s\n", "Month:", "Sales:");
  for(int i = 0; i < MONTH_COUNT; i++){
    printf("%-12s $%.2f\n", records[i].month, records[i].sales);
  }
}
