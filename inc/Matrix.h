#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> m_vMatrix;
    int m_nRows;
    int m_nCols;

    void initWithRandom();
    void initWithUserInput();

public:
    Matrix(int nRows, int nCols, bool bInitWithRandom = true);
    Matrix(const Matrix& mtxOther);

    int& At(int row, int col);
    int At(int row, int col) const;

    int GetRowCount() const;
    int GetColCount() const;
};

#endif // MATRIX_H

