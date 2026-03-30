#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main () {
  string filePath = "matrix-data.txt";
  ifstream file(filePath);
  
  if (!file.is_open()) {
    cerr << "Failed to open file: " << filePath << endl;

    return 1;
  }

  Matrix mat1;
  Matrix mat2;

  if (!mat1.readFromFile(file) || !mat2.readFromFile(file)) {
    cerr << "Error: could not read matrices from file." << endl;
    file.close();

    return 1;
  }

  cout << "Matrix 1:" << endl;
  mat1.display();
  cout << endl;

  cout << "Matrix 2:" << endl;
  mat2.display();
  cout << endl;

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();
  cout << endl;

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();
  cout << endl;

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
  cout << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows 0 and 2:" << endl;
  mat1.display();

  return 0;
}