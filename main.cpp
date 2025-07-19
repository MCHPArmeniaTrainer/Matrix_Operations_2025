#include <iostream>
#include <ctime>
#include <cstdlib>


// Matrix of integers
class Matrix
{
public:
	int row;
	int col;
	int** matrix;


    

// If the bInitWithRandom is false ask user for inputs,  +
    // Otherwise initialize the matrix with random numbers   +
	Matrix( int nRows, int nCols, bool bInitWithRandom = true )
	{
		row=nRows;
		col=nCols;
		matrix= new int*[row];
		for(int a=0; a<row; a++) matrix[a]=new int[col];
		if(bInitWithRandom) initWithRandom();
		else initWithUserInput();
	}
	

    // Copy Constructor should do a deep copy +
    Matrix( const Matrix& mtxOther )
	{
		row=mtxOther.row;
		col=mtxOther.col;
		matrix = new int*[row];
		for(int a=0; a<row ; a++) matrix[a]=new int[row];
		for(int i=0; i<row ; i++)
		{
			for(int j=0; j<col; j++)
			{
				matrix[i][j]=mtxOther.matrix[i][j];
			}
		}
	}

    int& At( int row, int col );

    // Get count of rows and columns
    int GetRowCount();
    int GetColCount();



	~Matrix(){
		for(int a =0; a<row; a++) delete[]matrix[a];
		delete[] matrix;
	}
private:
    void initWithRandom();
    void initWithUserInput();

    // The variables holding the matrix info
    // It's up to You to decide what it should be
};
void Matrix::initWithRandom()
{	
	std::srand(std::time(0));
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			matrix[i][j]=rand()%100;
			std::cout<<matrix[i][j]<<' ';
		}
		std::cout<<std::endl;
	}
}	
void Matrix::initWithUserInput()
{	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			std::cin>>matrix[i][j];
			std::cout<<matrix[i][j]<<' ';
		}
		std::cout<<std::endl;
	}
}	








// Utility Class to perform math operations
class MathOperation
{
public:
    // Takes two matrices as an arguments, adds them and initializes
    // a new matrix with the result of addition
    static Matrix Add( const Matrix& mtxA, const Matrix& mtxB );
    static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB );
    static Matrix Transpose( Matrix& mtxA );//տ ողերի պ ա ր ու նա կությունը    սյուներ
};

class Printer
{
public:
    static void PrintToConsole( const Matrix& mtxA );
};








int main()
{
    Matrix mtxA( 11, 12 );

    mtxA.at( 3, 5 ) = 13;
    mtxA.at( 10, 11 ) = 36;

    Matrix mtxB( 12, 11 );

    // Should print an error and return an empty matrix,
    // as to add two matrices they should have the same row and column count
    //MathOperation::Add( mtxA, mtxB );

    // Should succesfully do the multiplication
    // as to multiply two matrices the firstRowCount should be equal to secondColCount
    // and the firstColCount should be equal to the secondColCount
    //Matrix mtxMult( MathOperation::Mult( mtxA, mtxB ) );

    //Printer::PrintToConsole( mtxMult );

    // The matrix A should become from 11 x 12 to 12 x 11
    //MathOperation::Transpose( mtxA );

    // The addition is now possible as both matrixes have the same 12 x 11 size
    //Printer::PrintToConsole( MathOperation::Add( mtxA, mtxB ) );

    return 0;
}
