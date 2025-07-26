#pragma once

class Matrix {
public:
    // Public function declarations.
    Matrix(int nRows, int nCols, bool bInitWithRandom = true);
    Matrix(const Matrix& mtxOther);
    ~Matrix();

    int& At(int row, int col);
    int At(int row, int col) const;

    int GetRowCount() const;
    int GetColCount() const;

private:
    // Private function declarations.
    int row_, col_;
    int** matrix;

    void initWithRandom();
    void initWithUserInput();
};


