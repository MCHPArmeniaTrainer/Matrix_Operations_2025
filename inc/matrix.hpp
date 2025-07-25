#pragma once
#include <vector>

class Matrix {
public:
    Matrix(int nRows, int nCols, bool bInitWithRandom = true);
    Matrix(const Matrix& other);

    int& At(int row, int col);
    int At(int row, int col) const;

    int GetRowCount() const;
    int GetColCount() const;

private:
    int nRows;
    int nCols;
    std::vector<std::vector<int>> elements;

    void initWithRandom();
    void initWithUserInput();
    void initWithZeros();
};