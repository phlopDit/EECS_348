#ifndef MATRIX_LAB_H
#define MATRIX_LAB_H

#define SIZE 5

void addMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(const int m1[SIZE][SIZE], const int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(const int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(const int matrix[SIZE][SIZE]);

#endif