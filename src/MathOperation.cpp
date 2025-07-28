#include "MathOperation.h"
#include <iostream>

Matrix MathOperation::Add(const Matrix& mtxA, const Matrix& mtxB) {
    Matrix mtxC(mtxA);

    if (mtxA.GetRowCount() == mtxB.GetRowCount() && mtxA.GetColCount() == mtxB.GetColCount()) {
        for (int i = 0; i < mtxA.GetRowCount(); ++i)
            for (int j = 0; j < mtxA.GetColCount(); ++j)
                mtxC.At(i, j) = mtxA.At(i, j) + mtxB.At(i, j);
    } else {
        std::cout << "rows and cols don't match\n";
    }

    return mtxC;
}

Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB) {
    if (mtxA.GetColCount() != mtxB.GetRowCount()) {
        std::cout << "Condition for mult two matrix is false\n";
        return Matrix(0, 0);
    }

    Matrix mtxC(mtxA.GetRowCount(), mtxB.GetColCount());

    for (int i = 0; i < mtxA.GetRowCount(); ++i)
        for (int j = 0; j < mtxB.GetColCount(); ++j) {
            int sum = 0;
            for (int k = 0; k < mtxA.GetColCount(); ++k)
                sum += mtxA.At(i, k) * mtxB.At(k, j);
            mtxC.At(i, j) = sum;
        }

    return mtxC;
}

void MathOperation::Transpose(Matrix& mtxA) {
    Matrix mtxC(mtxA.GetColCount(), mtxA.GetRowCount());
    for (int i = 0; i < mtxA.GetRowCount(); ++i)
        for (int j = 0; j < mtxA.GetColCount(); ++j)
            mtxC.At(j, i) = mtxA.At(i, j);
    mtxA = mtxC;
}

