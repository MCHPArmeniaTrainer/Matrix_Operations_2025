/* math_operation.cpp */

#include <iostream>
#include "math_operation.h"

using namespace std;

/* Addition */
Matrix MathOperation::Add(const Matrix& mtxA, const Matrix& mtxB) {
    if (mtxA.GetRowCount() == mtxB.GetRowCount()
        && mtxA.GetColCount() == mtxB.GetColCount())
    {
        Matrix mtxAdd(mtxA.GetRowCount(), mtxA.GetColCount());
        for (int r = 0; r < mtxAdd.GetRowCount(); ++r)
            for (int c = 0; c < mtxAdd.GetColCount(); ++c)
                mtxAdd.At(r, c) = mtxA.At(r, c) + mtxB.At(r, c);
        return mtxAdd;
    }
    else {
        cout << "Error: add two matrices they should have the same row and column count" << endl;
        return Matrix(0, 0);
    }
}

/* Multiplication */
Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB) {
    if (mtxA.GetColCount() == mtxB.GetRowCount()) {
        Matrix mtxMult(mtxA.GetRowCount(), mtxB.GetColCount());
        int sum = 0;
        for (int r = 0; r < mtxMult.GetRowCount(); ++r)
            for (int c = 0; c < mtxMult.GetColCount(); ++c) {
                sum = 0;
                for (int k = 0; k < mtxA.GetColCount(); ++k) {
                    sum += mtxA.At(r, k) * mtxB.At(k, c);
                }
                mtxMult.At(r, c) = sum;
            }
        return mtxMult;
    }
    else {
        cout << "Error: multiply two matrices the firstColCount should be equal to the secondRowCount" << endl;
        return Matrix(0, 0);
    }
}

/* Transpose */
void MathOperation::Transpose(Matrix& mtxA) {
    Matrix mtxTranspose(mtxA.GetColCount(), mtxA.GetRowCount());
    for (int r = 0; r < mtxA.GetRowCount(); ++r)
        for (int c = 0; c < mtxA.GetColCount(); ++c)
            mtxTranspose.At(c, r) = mtxA.At(r, c);
    mtxA = mtxTranspose;
}

