/* main.cpp 
* 
*  Examples: Matrix of integers
*/

#include "matrix.h"
#include "math_operation.h"
#include "printer.h"

using namespace std;

int main()
{
    Matrix mtxA(11, 12);

    mtxA.At( 3, 5 ) = 13;
    mtxA.At( 10, 11 ) = 36;

    Matrix mtxB( 12, 11 );

    // Should print an error and return an empty matrix,
    // as to add two matrices they should have the same row and column count
    MathOperation::Add( mtxA, mtxB );

    // Should succesfully do the multiplication
    // as to multiply two matrices the firstColCount should be equal to the secondRowCount
    Matrix mtxMult( MathOperation::Mult( mtxA, mtxB ) );
    Printer::PrintToConsole( mtxMult );

    // The matrix A should become from 11 x 12 to 12 x 11
    MathOperation::Transpose( mtxA );

    // The addition is now possible as both matrixes have the same 12 x 11 size
    Printer::PrintToConsole( MathOperation::Add( mtxA, mtxB ) );
    
    return 0;
}

