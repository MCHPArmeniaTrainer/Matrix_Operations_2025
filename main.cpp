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

    int& At( int row, int col )
	{  if(row > m_nRows || col > m_nCols ){
			std::cout<<"Wrong index!";	
			return m_vMatrix[0][0];
		}
		else{
					
			return m_vMatrix[row][col];
		}
	}



    // Think why we are not declaring as const the above funcition?
    int At( int row, int col ) const
	{ 
	  if(row > m_nRows || col > m_nCols ){
			
			std::cout<<"Wrong index!";	
			return m_vMatrix[0][0];
		}
		else{
			return m_vMatrix[row][col];
		}
	}

    // Get count of rows and columns
    int GetRowCount() const
	{
		return m_nRows;
	}

    int GetColCount() const
	{
		return m_nCols;
	}

private:
    
	
	void initWithRandom(){
		    m_vMatrix.resize(m_nRows, std::vector<int>(m_nCols));
		std::srand(time(0));
		for(int i = 0;i<m_nRows;++i){
			for(int j = 0;j < m_nCols;++j){
				m_vMatrix[i][j] = rand()%100;	
			}
		}	
	
}
    void initWithUserInput(){
	    m_vMatrix.resize(m_nRows, std::vector<int>(m_nCols));
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
    static Matrix Add( const Matrix& mtxA, const Matrix& mtxB )
	{
		Matrix mtxC(mtxA);

		if(mtxA.m_nRows == mtxB.m_nRows && mtxA.m_nCols == mtxB.m_nCols)
		{
	    	
			for(int i = 0;i < mtxA.GetColCount();i++){
				for(int j = 0;j < mtxA.GetColCount();++j){
				    for(int k = 0;k < mtxA.GetRowCount();++k){
						mtxC.At(i,j) += mtxA.At(i,k) * mtxB.At(k,j);	
					}
				}
			}
			return mtxC;
		}
		else{
			std::cout<<"rows and cols don't match \n";
			return mtxC;
		}
		
	}
    static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB )
	{
		Matrix mtxC(mtxA);
		if(mtxA.m_nCols == mtxB.m_nRows)
		{   
			
		for(int i = 0;i < mtxA.m_nRows;++i){
			for(int j = 0;i < mtxA.m_nCols;++j){
					mtxC.At(i,j) += mtxA.At(i,j) * mtxB.At(j,i);
			}
		}
			return mtxC;
		}
		else
		{   std::cout<<"Condition for mult two matrix is false";
			return mtxC;
		} 
	}
    static void Transpose( Matrix& mtxA ){
		
		Matrix mtxC(mtxA);
		for(int i = 0;i < mtxA.m_nRows;++i){
			for(int j = 0;j < mtxA.m_nCols;++j){
					mtxC.At(i,j) = mtxA.At(j,i);
			}
		
		}
		mtxA = mtxC;
	}
};

class Printer
{
public:
    static void PrintToConsole( const Matrix& mtxA ){
		for(int i = 0;i < mtxA.GetRowCount();i++){
			for(int j = 0;j < mtxA.GetColCount();++j){
				std::cout<<mtxA.m_vMatrix[i][j]<<"  ";
			}
			std::cout<<std::endl;
	}
	}
};


int main()
{
	Matrix matrix(3,3);
	Printer::PrintToConsole(matrix);
	MathOperation::Transpose(matrix);
	Printer::PrintToConsole(matrix);
	/*Matrix matrixB(3,4);
	Printer::PrintToConsole(matrixB);
	Printer::PrintToConsole(MathOperation::Add(matrix,matrixB));
	*/	
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
