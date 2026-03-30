#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix() {
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      data[i][j] = 0;
    }
  }
}

void Matrix::readFromStdin() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cin >> data[i][j];
    }
  }
}

bool Matrix::readFromFile(ifstream& file) {
  for (int i = 0; i < SIZE; i++) {
    for  (int j = 0; j < SIZE; j++) {
      if (!(file >> data[i][j])) {
        return false;
      }
    }
  }
  return true;
}

void Matrix::display() const{
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cout << setw(4) << data[i][j];
    }
    cout << endl;
  }
}

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix sum;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      sum.data[i][j] = data[i][j] + other.data[i][j];
    }
  }

  return sum;
}

Matrix Matrix::operator*(const Matrix& other) const {
  Matrix product;

  for (int i = 0; i < SIZE; i++) {
    for (int k = 0; k < SIZE; k++) {
      for (int j = 0; j < SIZE; j++) {
        product.data[i][j] += data[i][k] * other.data[k][j];
      }
    }
  }

  return product;
}

int Matrix::sumOfDiagonals() const {
  int sum = 0;

  for (int i = 0; i < SIZE; i++) {
    sum += data[i][i] + data[i][SIZE - 1 - i];
  }
  
  return sum;
}

void Matrix::swapRows(int row1, int row2) {
  if (row1 < 0 || row1 >= SIZE || row2 < 0 || row2 >= SIZE){
    cout << "Invalid row indices." << endl;
    return;
  }

  for(int i = 0; i < SIZE; i++){
    int temp = data[row1][i];
    data[row1][i] = data[row2][i];
    data[row2][i] = temp;
  }
}