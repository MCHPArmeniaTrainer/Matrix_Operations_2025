#include "Matrix.h"
#include "MathOperation.h"
#include "Printer.h"

int main() {
    Matrix A(2, 3);
    Matrix B(2, 3);
    Matrix C = MathOperation::Add(A, B);

    Printer::PrintToConsole(C);

    Matrix D = MathOperation::Mult(Matrix(2, 2), Matrix(2, 2));
    Printer::PrintToConsole(D);

    MathOperation::Transpose(C);
    Printer::PrintToConsole(C);

    return 0;
}

