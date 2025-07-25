#include "../inc/matrix.hpp"
#include "../inc/mathOperators.hpp"
#include "../inc/printer.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(0));
    Matrix mtxA(11, 12);
    mtxA.At(3, 5) = 13;
    mtxA.At(10, 11) = 36;

    Matrix mtxB(12, 11);
    MathOperation::Add(mtxA, mtxB);
    Matrix mtxMult(MathOperation::Mult(mtxA, mtxB));
    Printer::PrintToConsole(mtxMult);

    Matrix transposed = MathOperation::Transpose(mtxA);
    Printer::PrintToConsole(MathOperation::Add(transposed, mtxB));

    return 0;
}