#include "../inc/mathOperators.hpp"
#include <iostream>

Matrix MathOperation::Add(const Matrix& mtxA, const Matrix& mtxB) {
    int mRows = mtxA.GetRowCount();
    int mCols = mtxA.GetColCount();
    if (mRows != mtxB.GetRowCount() || mCols != mtxB.GetColCount()) {
        std::cout << "Matrices must have same dimensions\n";
        return Matrix(mRows, mCols, false);
    }

    Matrix result(mRows, mCols, false);
    for (int i = 0; i < mRows; ++i)
        for (int j = 0; j < mCols; ++j)
            result.At(i, j) = mtxA.At(i, j) + mtxB.At(i, j);
    return result;
}

Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB) {
    int mRows = mtxA.GetRowCount();
    int mCols = mtxA.GetColCount();
    if (mRows != mtxB.GetRowCount() || mCols != mtxB.GetColCount()) {
        std::cout << "Matrices must have same dimensions\n";
        return Matrix(mRows, mCols, false);
    }

    Matrix result(mRows, mCols, false);
    for (int i = 0; i < mRows; ++i)
        for (int j = 0; j < mCols; ++j)
            result.At(i, j) = mtxA.At(i, j) * mtxB.At(i, j);
    return result;
}

Matrix MathOperation::Transpose(Matrix& mtxA) {
    int mRows = mtxA.GetRowCount();
    int mCols = mtxA.GetColCount();

    Matrix result(mCols, mRows, false);
    for (int i = 0; i < mRows; ++i)
        for (int j = 0; j < mCols; ++j)
            result.At(j, i) = mtxA.At(i, j);
    return result;
}