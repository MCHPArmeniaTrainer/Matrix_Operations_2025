#ifndef MATRIX_H
#define MATRIX_H

/* Header file: Matrix.h */

class Matrix
{
public:
    Matrix(int nRows, int nCols, bool bInitWithRandom = true);
    Matrix() : Matrix(0, 0, true) {};
    Matrix(const Matrix& mtxOther);
    ~Matrix();

    Matrix& operator= (const Matrix& other);

    int& At(int row, int col);
    int At(int row, int col) const; // const variant: read-only

    // Get count of Rows and Columns:
    int GetRowCount() const;
    int GetColCount() const;

private:
    // The variables holding the matrix info:
    int m_row;
    int m_col;
    int** matrix;

    void initWithRandom();
    void initWithUserInput();
};

#endif // MATRIX_H

