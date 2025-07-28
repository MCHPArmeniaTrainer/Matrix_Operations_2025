#ifndef MATH_OPERATION_H
#define MATH_OPERATION_H

#include "Matrix.h"

class MathOperation {
public:
    static Matrix Add(const Matrix& mtxA, const Matrix& mtxB);
    static Matrix Mult(const Matrix& mtxA, const Matrix& mtxB);
    static void Transpose(Matrix& mtxA);
};

#endif // MATH_OPERATION_H

