#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Matrix
{
public:
    // If the bInitWithRandom is false ask user for inputs,
    // Otherwise initialize the matrix with random numbers
    Matrix( int nRows, int nCols, bool bInitWithRandom = true ){
	    rows=nRows;
	    cols=nCols;
	    vMatrix = std::vector<std::vector<int>>(rows, std::vector<int>(cols));
    	if(bInitWithRandom){
		initWithRandom();
	}else{
		initWithUserInput();
	}
    
    }

    // Copy Constructor should do a deep copy
    Matrix( const Matrix& mtxOther ){
	    	rows=mtxOther.rows;
		cols=mtxOther.cols;
		vMatrix=mtxOther.vMatrix;
		std::cout<<"Copy constructory kachvec ";
    }

    int& At( int row, int col ){
    	return vMatrix[row][col];
    }
    int At( int row, int col ) const{
    	return vMatrix[row][col];
    }

    // Get count of rows,columns and matrix
    int GetRowCount() const{
    	return rows;
    }
    int GetColCount() const{
    	return cols;
    }

    int getValue(int i, int j) const {
        return vMatrix[i][j];
    }
private:
    int rows,cols;
    std::vector<std::vector<int>> vMatrix;

    void initWithRandom(){
    	std::srand(time(0));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			vMatrix[i][j]=std::rand() % 100;
		}
	}
    }
    void initWithUserInput(){
    	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			std::cin>>vMatrix[i][j];
			std::cout<<" ";
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
    static Matrix Add( const Matrix& mtxA, const Matrix& mtxB ){
    	if(mtxA.GetRowCount()!=mtxB.GetRowCount() || mtxA.GetColCount()!=mtxB.GetColCount()){
		std::cout<<"anhamapatasxanutyun "<<std::endl;
		return Matrix(0,0,false);
	}
	Matrix result(mtxA.GetRowCount(),mtxA.GetColCount(),false);

	for(int i=0;i<mtxA.GetRowCount();i++){
		for(int j=0;j<mtxA.GetColCount();j++){
			result.At(i, j) = mtxA.At(i, j) + mtxB.At(i, j);
		}
	}return result;

    }
    static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB ){
    	if(mtxA.GetColCount()!=mtxB.GetRowCount()){
		std::cout<<"petq e arajin matrixi syuneri ev erkrord matrixi toxeri qanaky havasar linen "<<std::endl;
	}
	Matrix result(mtxA.GetRowCount(),mtxB.GetColCount(),false);
	
	for(int i=0;i<mtxA.GetRowCount();i++){
		for(int j=0;j<mtxB.GetColCount();j++){
			result.At(i,j)=0;
			for(int k=0;k<mtxA.GetColCount();k++){
				result.At(i,j)+=mtxA.At(i,k)*mtxB.At(k,j);
			}
		}
	}return result;
	
    }
    static void Transpose( Matrix& mtxA );
};

class Printer
{
public:
    static void PrintToConsole( const Matrix& mtxA ){
    	for(int i=0;i<mtxA.GetRowCount();i++){
		for(int j=0;j<mtxA.GetColCount();j++){
			std::cout<<mtxA.At(i,j)<<" "<<std::endl;
		}
	}std::cout<<std::endl;
    
    }
};


int main()
{
    Matrix mtxA( 11, 12 );

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
