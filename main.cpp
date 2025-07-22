#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
class Matrix{
	private:
		int m_irow;
		int m_icol;
		int** m_matrix;
		void initWithRandom();
		void initWithUserInput();
	public:
		Matrix( int nRows, int nCols, bool bInitWithRandom = true )
		{
			m_irow=nRows;
			m_icol=nCols;
			if(m_irow==0 || m_icol==0)
			{
				m_matrix=nullptr;	
			}else{
				m_matrix= new int*[m_irow];
				for(int a=0; a<m_irow; a++) m_matrix[a]=new int[m_icol];
				if(bInitWithRandom) initWithRandom();
				else initWithUserInput();
			}
		}
		Matrix( const Matrix& mtxOther )
		{
			m_irow=mtxOther.m_irow;
			m_icol=mtxOther.m_icol;
			m_matrix = new int*[m_irow];
			for(int a=0; a<m_irow ; a++) m_matrix[a]=new int[m_icol];
			for(int i=0; i<m_irow ; i++)
			{
				for(int j=0; j<m_icol; j++)
				{
					m_matrix[i][j]=mtxOther.m_matrix[i][j];
				}
			}
		}
		int& At( int row, int col );
		int At( int row, int col ) const;

		int GetRowCount()const{return m_irow;}
		int GetColCount()const{return m_icol;}

		~Matrix(){
			for(int a =0; a<m_irow; a++) delete[]m_matrix[a];
			delete[] m_matrix;
		}
};
class MathOperation{
	public:
		static Matrix Add( const Matrix& mtxA, const Matrix& mtxB );
		static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB );
		static Matrix Transpose( const  Matrix& mtxA );
};
class Printer{
	public:
		static void PrintToConsole( const Matrix& mtxA );
};
void Matrix::initWithRandom()
{	
//	std::srand(std::time(0));
	for(int i=0; i<m_irow; i++)
	{
		for(int j=0; j<m_icol; j++)
		{
			m_matrix[i][j]=rand()%10;
		}
	}
}	
void Matrix::initWithUserInput()
{	
	for(int i=0; i<m_irow; i++)
	{
		for(int j=0; j<m_icol; j++)
		{
			std::cin>>m_matrix[i][j];
		}
	}
}

int& Matrix::At( int row, int col )
{
	assert(row<m_irow && col <m_icol);
	return m_matrix[row][col];
}
int Matrix::At( int row, int col ) const
{	
	assert(row<m_irow && col <m_icol);
	return m_matrix[row][col];
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
			return newMatrix;
		}
	else{
			std::cout<<"Error, cols and rows should be equal "<<std::endl;
			return Matrix(0,0,false);
	}
}
Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB)
{
	if(mtxA.GetColCount()==mtxB.GetRowCount())
		{
			Matrix mtxC(mtxA.GetRowCount(), mtxB.GetColCount());
			int sumC=0;
			for(int i =0; i<mtxA.GetRowCount(); i++)
			{	
				for (int j=0; j< mtxB.GetColCount(); j++)
					{
						sumC=0;
						for(int a =0; a<mtxA.GetColCount(); a++){	
							sumC+=mtxA.At(i,a)*mtxB.At(a,j);
						}					
						mtxC.At(i,j)=sumC;	
					}
			}
			return mtxC;
		}
	else{
		std::cout<<"the firstColCount should be equal to the secondRowCount"<<std::endl;
		return Matrix(0,0, false);
	}
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
	
//	Matrix mtxMult( MathOperation::Mult( mtxA, mtxB ) );
	//Printer::PrintToConsole( mtxMult );

	//MathOperation::Transpose( mtxA );

  //  Printer::PrintToConsole( MathOperation::Add( mtxA, mtxB ) );
    return 0;
}
