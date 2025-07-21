// Matrix of integers
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
class Matrix
{
public:
	std::vector<std::vector<int>> m_vMatrix;
	int m_nRows;
	int m_nCols;
	
    // If the bInitWithRandom is false ask user for inputs,
    // Otherwise initialize the matrix with random numbers
    Matrix( int nRows, int nCols, bool bInitWithRandom = true ) : m_nRows(nRows),m_nCols(nCols){
	
		if(bInitWithRandom){
			initWithRandom();
		}
		else{
			initWithUserInput();
		}
	}
 	
    // Copy Constructor should do a deep copy
    Matrix( const Matrix& mtxOther ) : m_nRows(mtxOther.m_nRows),m_nCols(mtxOther.m_nCols),m_vMatrix(mtxOther.m_vMatrix) {}

    int& At( int row, int col );
    // Think why we are not declaring as const the above funcition?
    int At( int row, int col ) const;

    // Get count of rows and columns
    int GetRowCount() const;
    int GetColCount() const;

private:
    
	
	void initWithRandom(){
		std::srand(time(0));
		for(int i = 0;i<m_nRows;++i){
			for(int j = 0;j < m_nCols;++i){
				m_vMatrix[i][j] = rand()%100;	
			}
		}	
	}
    void initWithUserInput(){
		int element = 0;	
		for(int i = 0;i<m_nRows;++i){
			for(int j = 0;j < m_nCols;++i){
			std::cin>>element;
				m_vMatrix[i][j] = element;	
			}
		}	
	}
    void initWithZeros();

    // The variables holding the matrix info
    // It's up to You to decide what it should be
};

// Utility Class to perform math operations
class MathOperation
{
public:
    // Takes two matrices as an arguments, adds them and initializes
    // a new matrix with the result of addition
    static Matrix Add( const Matrix& mtxA, const Matrix& mtxB );
    static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB );
    static void Transpose( Matrix& mtxA );
};

class Printer
{
public:
    static void PrintToConsole( const Matrix& mtxA );
};


int main()
{

	//Matrix mtxA( 11, 12 );

    //mtxA.at( 3, 5 ) = 13;
    //mtxA.at( 10, 11 ) = 36;

    //Matrix mtxB( 12, 11 );

    // Should print an error and return an empty matrix,
    // as to add two matrices they should have the same row and column count
    //MathOperation::Add( mtxA, mtxB );

    // Should succesfully do the multiplication
    // as to multiply two matrices the firstColCount should be equal to the secondRowCount
    //Matrix mtxMult( MathOperation::Mult( mtxA, mtxB ) );

    //Printer::PrintToConsole( mtxMult );

    // The matrix A should become from 11 x 12 to 12 x 11
    //MathOperation::Transpose( mtxA );

    // The addition is now possible as both matrixes have the same 12 x 11 size
    //Printer::PrintToConsole( MathOperation::Add( mtxA, mtxB ) );

    return 0;
}
