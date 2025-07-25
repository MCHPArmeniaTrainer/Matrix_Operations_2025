#include <iostream>
#include <ctime>
#include "Matrix.h"
#include "MathOperation.h"
#include "Printer.h"
int main()
{
	std::srand(std::time(0));
	int row_a, col_a;
	std::cout<<"Enter row and col for mtxA"<<std::endl;
	std::cin>>row_a>> col_a;
	Matrix mtxA( row_a, col_a );
	//mtxA.At( 3, 5 ) = 13;
	//mtxA.At( 10, 11 ) = 36;

	int row_b, col_b;
	std::cout<<"Enter row and col for mtxB"<<std::endl;
	std::cin>>row_b>> col_b;
	Matrix mtxB( row_b, col_b);

	Printer::PrintToConsole(mtxA);
	Printer::PrintToConsole(mtxB);

//	MathOperation::Add( mtxA, mtxB );
	
	Matrix mtxMult( MathOperation::Mult( mtxA, mtxB ) );
	Printer::PrintToConsole( mtxMult );

	Printer::PrintToConsole(MathOperation::Transpose( mtxA ));

  	Printer::PrintToConsole( MathOperation::Add( mtxA, mtxB ) );
    return 0;
}
