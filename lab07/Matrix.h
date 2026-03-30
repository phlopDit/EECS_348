#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

const int SIZE = 4;

class Matrix {
  private: 
    int data[SIZE][SIZE];

  public:
    Matrix();

    void readFromStdin();
    bool readFromFile(std::ifstream& file);
    void display() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    int sumOfDiagonals() const;
    void swapRows(int row1, int row2);
};

#endif