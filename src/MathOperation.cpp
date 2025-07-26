#include <iostream>
#include "MathOperation.hpp"

// Adding two matrices and assigning the result to a new matrix. Returns the sum matrix.
Matrix MathOperation::Add( const Matrix& mtxA, const Matrix& mtxB ) {
    const int row = mtxA.GetRowCount();
    const int col = mtxA.GetColCount();
    if(row != mtxB.GetRowCount() || col != mtxB.GetColCount()) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    } else {
        Matrix mtxC(row, col);
        for(int r = 0; r < row;  r++) {
            for(int c = 0; c < col; c++) {
                mtxC.At(r, c) = mtxA.At(r, c) +  mtxB.At(r, c);
            }
        }
        return mtxC;
    }
}

// Multiplying two matrices and assigning the result to a new matrix. Return the product matrix.
Matrix MathOperation::Mult( const Matrix& mtxA, const Matrix& mtxB ) {
    const int row = mtxA.GetRowCount();
    const int col = mtxA.GetColCount();
    if(col != mtxB.GetRowCount()) {
        throw std::invalid_argument("The first matrix col count must match the second matrix row count.");
    } else {
        Matrix mtxC(row, mtxB.GetColCount());
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < mtxB.GetColCount(); c++) {
                int sum = 0;
                for(int e = 0; e < col; e++) {
                    sum += mtxA.At(r, e) * mtxB.At(e, c);
                }
                mtxC.At(r, c) = sum;
            }
        }
        return mtxC; 
    }
}

// Transposing the given matrix and assigning the result to a new matrix. Returns the transposed matrix.
Matrix MathOperation::Transpose( Matrix& mtxA ) {
    const int row = mtxA.GetRowCount();
    const int col = mtxA.GetColCount();
    Matrix mtxC(col, row);
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            mtxC.At(c, r) = mtxA.At(r, c);
        }
    }
    return mtxC;
}


