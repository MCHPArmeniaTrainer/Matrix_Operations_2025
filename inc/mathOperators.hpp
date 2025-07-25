#pragma once
#include "matrix.hpp"

class MathOperation {
public:
    static Matrix Add(const Matrix& mtxA, const Matrix& mtxB);
    static Matrix Mult(const Matrix& mtxA, const Matrix& mtxB);
    static Matrix Transpose(Matrix& mtxA);
};