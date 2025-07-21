#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
class Matrix
{
private:
	int m_row;
	int m_col;
	int** m_matrix;
	void initWithRandom();
	void initWithUserInput();
public:
	Matrix( int nRows, int nCols, bool bInitWithRandom = true )
	{
		m_row=nRows;
		m_col=nCols;
		if(m_row==0 || m_col==0)
		{
			m_matrix=nullptr;	
		}else{
			m_matrix= new int*[m_row];
			for(int a=0; a<m_row; a++) m_matrix[a]=new int[m_col];
			if(bInitWithRandom) initWithRandom();
			else initWithUserInput();
		}
	}
	
    // Copy Constructor should do a deep copy +
	Matrix( const Matrix& mtxOther )
	{
		m_row=mtxOther.m_row;
		m_col=mtxOther.m_col;
		m_matrix = new int*[m_row];
		for(int a=0; a<m_row ; a++) m_matrix[a]=new int[m_col];
		for(int i=0; i<m_row ; i++)
		{
			for(int j=0; j<m_col; j++)
			{
				m_matrix[i][j]=mtxOther.m_matrix[i][j];
			}
		}
	}
	int& At( int row, int col )
	{
		assert(row<m_row && col <m_col);
		return m_matrix[row][col];
	}
	int At( int row, int col ) const
	{	
		assert(row<m_row && col <m_col);
		return m_matrix[row][col];
	}

	int GetRowCount()const {return m_row;}
	int GetColCount()const{	return m_col;}

	~Matrix(){
		for(int a =0; a<m_row; a++) delete[]m_matrix[a];
		delete[] m_matrix;
	}

};

// Utility Class to perform math operations
class MathOperation
{
public:

    // Takes two matrices as an arguments, adds them and initializes
    // a new matrix with the result of addition
    static Matrix Add( const Matrix& mtxA, const Matrix& mtxB );
    static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB );
    static Matrix Transpose( const  Matrix& mtxA );
};

class Printer
{
	public:
		static void PrintToConsole( const Matrix& mtxA );
};
void Matrix::initWithRandom()
{	
	std::srand(std::time(0));
	for(int i=0; i<m_row; i++)
	{
		for(int j=0; j<m_col; j++)
		{
			m_matrix[i][j]=rand()%10;
		}
	}
}	
void Matrix::initWithUserInput()
{	
	for(int i=0; i<m_row; i++)
	{
		for(int j=0; j<m_col; j++)
		{
			std::cin>>m_matrix[i][j];
		}
	}
}

Matrix MathOperation::Add(const Matrix& mtxA, const Matrix& mtxB)
{
	if(mtxA.GetRowCount()==mtxB.GetRowCount() && mtxA.GetColCount()==mtxB.GetColCount())
		{
			Matrix newMatrix(mtxA.GetRowCount(), mtxA.GetColCount());
			for(int i=0; i< mtxA.GetRowCount(); i++)
			{
				for(int j=0; j<mtxA.GetColCount(); j++)
				{
					newMatrix.At(i,j)=mtxA.At(i,j)+mtxB.At(i,j);
				}
			}
			//Printer::PrintToConsole(newMatrix);
			return newMatrix;
		}
	else{
			std::cout<<"Error"<<std::endl;
			Matrix newMatrix(0,0,false);		
			return newMatrix;
	}
}
Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB)
{
	Matrix mtxC(mtxA.GetRowCount(), mtxB.GetColCount());
	if(mtxA.GetColCount()==mtxB.GetRowCount())
		{
			int sumC=0;
			for(int i =0; i<mtxA.GetRowCount(); i++)
				{	
					for (int j=0; j< mtxB.GetColCount(); j++)
						{
							sumC=0;
							for(int a =0; a<mtxA.GetColCount(); a++)
								sumC+=mtxA.At(i,a)*mtxB.At(a,j);					
							mtxC.At(i,j)=sumC;	
						}
				}
		}
	Printer::PrintToConsole(mtxC);
	return mtxC;
}

Matrix MathOperation::Transpose(const Matrix& mtxA)
{
	Matrix mtxD(mtxA.GetColCount(), mtxA.GetRowCount());
	for(int i =0; i<mtxA.GetRowCount(); i++)
		{
			for (int j=0; j<mtxA.GetColCount(); j++)
				{
					mtxD.At(j,i)=mtxA.At(i,j);
				}
		}
	Printer::PrintToConsole(mtxD);
	return mtxD;
}

void Printer::PrintToConsole(const Matrix& mtxA)
{
	for(int i = 0; i<mtxA.GetRowCount(); i++)
	{
		for (int j=0; j <mtxA.GetColCount(); j++)
		{
			std::cout<<mtxA.At(i,j)<<' ';
		}
		std::cout<<std::endl;
	}
		std::cout<<std::endl;
}


int main()
{
	Matrix mtxA( 11, 12 );
	Printer::PrintToConsole(mtxA);
	mtxA.At( 3, 5 ) = 13;
	mtxA.At( 10, 11 ) = 36;
	
	Matrix mtxB(12,11 );
	Printer::PrintToConsole(mtxB);
    // Should print an error and return an empty matrix,
    // as to add two matrices they should have the same row and column count
 //MathOperation::Add( mtxA, mtxB );

    // Should succesfully do the multiplication
    // as to multiply two matrices the firstRowCount should be equal to secondColCount
    // and the firstColCount should be equal to the secondColCount
    Matrix mtxMult( MathOperation::Mult( mtxA, mtxB ) );
//    MathOperation::Transpose( mtxA );
  //  Printer::PrintToConsole( mtxMult );

    // The matrix A should become from 11 x 12 to 12 x 11
//    MathOperation::Transpose( mtxA );

    // The addition is now possible as both matrixes have the same 12 x 11 size
  //  Printer::PrintToConsole( MathOperation::Add( mtxA, mtxB ) );

    return 0;
}
