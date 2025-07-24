#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.hpp"
#include "Printer.hpp"
#include "MathOperation.hpp"

int main()
{
    srand(time(0));
    Matrix mtxA( 11, 12, true );
	
    mtxA.At( 3, 5 ) = 13;
    mtxA.At( 10, 11 ) = 36;

    Printer::PrintToConsole( mtxA );
    Matrix mtxB( 12, 11, true );
    Printer::PrintToConsole( mtxB );

    // Should print an error and return an empty matrix,
    // as to add two matrices they should have the same row and column count
    std::cout<<"Matrix after addition\n";
    Matrix mtxAdd(MathOperation::Add(mtxA, mtxB));
	Printer::PrintToConsole(mtxAdd);

    // Should succesfully do the multiplication
    // as to multiply two matrices the firstColCount should be equal to the secondRowCount
    std::cout<<"Matrix after Multiplication\n";	
    Matrix mtxMult( MathOperation::Mult( mtxA, mtxB ) );
    Printer::PrintToConsole( mtxMult );

    // The matrix A should become from 11 x 12 to 12 x 11
    std::cout<<"Matrix after Transpose\n";
    MathOperation::Transpose( mtxA );
	Printer::PrintToConsole( mtxA );
    
	// The addition is now possible as both matrixes have the same 12 x 11 size
	std::cout<<"Matrix after addition\n";
	mtxAdd = MathOperation::Add(mtxA, mtxB);
	Printer::PrintToConsole(mtxAdd);
    return 0;
}
