#include <iostream>
#include "Matrix.hpp"
#include "MathOperation.hpp"
#include "Printer.hpp"

int main()
{
	// Creating Matrix A 3x3. Printing the matrix to console.
    Matrix mtxA(3, 3);
    Printer::PrintToConsole(mtxA);
    std::cout << std::endl;

	// Creating Matrix B 3x3. Printing the matrix to console.
    Matrix mtxB(3, 3);
    Printer::PrintToConsole(mtxB);
    std::cout << std::endl;

	// Creating Matrix C and assignes the result sum matrix.
	// Printing the matrix to console.
    Matrix mtxC =  MathOperation::Add( mtxA, mtxB );
    Printer::PrintToConsole(mtxC);
    std::cout << std::endl;

	// Creating Matrix Mult  and assignes the result product matrix.
	// Printing the matrix to console.
    Matrix mtxMult(MathOperation::Mult( mtxA, mtxB ));
    Printer::PrintToConsole(mtxMult);
    std::cout << std::endl;

	// Creating Matrix Transpose and assignes the result of transposed  matrix.
	// Printing the matrix to console.
    Matrix mtxTrp(MathOperation::Transpose( mtxA ));
    Printer::PrintToConsole(mtxTrp);
    std::cout << std::endl;

    return 0;
}
