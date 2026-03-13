#include <stdio.h>
#include "matrix_lab.h"

void printMatrix(const int matrix[SIZE][SIZE]){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      printf("%6d", matrix[i][j]);
    }
    printf("\n");
  }  
}

void addMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE], int result[SIZE][SIZE]){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      result[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

void multiplyMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE], int result[SIZE][SIZE]){
  for(int i = 0; i < SIZE; i++){
    for(int k = 0; k < SIZE; k++){
      for(int j = 0; j < SIZE; j++){
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
}

void transposeMatrix(const int matrix[SIZE][SIZE], int result[SIZE][SIZE]){
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      result[j][i] = matrix[i][j];
    }
  }
}