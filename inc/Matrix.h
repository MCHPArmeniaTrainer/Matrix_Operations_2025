#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
    // Constructors
    Matrix(int nRows, int nCols, bool bInitWithRandom = true);
    Matrix(const Matrix& mtxOther);

    // Element access
    int& At(int row, int col);
    int At(int row, int col) const;

    // Getters
    int GetRowCount() const;
    int GetColCount() const;
    int getValue(int i, int j) const;

private:
    int rows, cols;
    std::vector<std::vector<int>> vMatrix;

    void initWithRandom();
    void initWithUserInput();
    void initWithZeros();
};

#endif
