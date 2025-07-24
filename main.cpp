#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Matrix of integers
class Matrix
{
public:
    // If the bInitWithRandom is false ask user for inputs,
    // Otherwise initialize the matrix with random numbers
    Matrix( int nRows, int nCols, bool bInitWithRandom )
	    : rows(nRows), cols(nCols), data(nRows, std::vector<int>(nCols)) {
		if (nRows==0 || nCols==0) return;
		if (bInitWithRandom==true) initWithRandom();
		else if(bInitWithRandom==false) initWithUserInput();
	    }

    // Copy Constructor should do a deep copy
    Matrix( const Matrix& mtxOther )
	    :rows(mtxOther.rows), cols(mtxOther.cols), data(mtxOther.data) {}

    int& At( int row, int col );
    // Think why we are not declaring as const the above funcition?
    int At( int row, int col ) const;

    // Get count of rows and columns
    int GetRowCount() const;
    int GetColCount() const;

private:
    void initWithRandom();
    void initWithUserInput();
    void initWithZeros();
	Matrix(int nRows, int nCols)
	:rows(nRows), cols(nCols), data(nRows, std::vector<int>(nCols)) {}	
    // The variables holding the matrix info
    // It's up to You to decide what it should be
	int rows, cols;
	std::vector<std::vector<int>> data;
	bool isInitialized=false;
	
	friend class MathOperation;
	friend class Printer;
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

int& Matrix::At( int row, int col )
{
	return data[row][col];
}

int Matrix::At(int row, int col) const 
{
	return data[row][col];
}

int Matrix::GetRowCount() const
{
	return rows;
}

int Matrix::GetColCount() const
{
	return cols;
}

void Matrix::initWithRandom()
{
	if(isInitialized) return;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			data[i][j] = rand() % 100;
		}
	}
	isInitialized=true;
}

void Matrix::initWithUserInput()
{
	if(isInitialized) return;
	std::cout<<"Enter "<<rows*cols<<" elements\n";
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			std::cin>>data[i][j];
		}
	}
	isInitialized=true;
}

void Matrix::initWithZeros()
{
	if(isInitialized) return;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			data[i][j]=0;
		}
	}
	isInitialized=true;
}

Matrix MathOperation::Add( const Matrix& mtxA, const Matrix& mtxB )
{
		if(mtxA.rows != mtxB.rows || mtxA.cols != mtxB.cols) 
		{
			std::cout<<"Matrix sizes do not match for addition\n";
			return Matrix(0, 0);
		}
		Matrix result(mtxA.rows, mtxA.cols);
		result.initWithZeros();
		for(int i=0; i<mtxA.rows; i++)
		{
				for(int j=0; j<mtxA.cols; j++)
				{
						result.data[i][j]=mtxA.data[i][j]+mtxB.data[i][j];
				}
		}
		return result;
}

Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB)
{
		if(mtxA.cols != mtxB.rows)
		{
			std::cout<<"Matrix sizes are incompatible for multiplication.\n";
			return Matrix(0, 0);
		}
		Matrix result(mtxA.rows, mtxB.cols);
		result.initWithZeros();
		for(int i=0; i<result.rows; i++)
		{
				for(int j=0; j<result.cols; j++)
				{
						for(int k=0; k<mtxA.cols; k++)
						{
								result.data[i][j] += mtxA.data[i][k] * mtxB.data[k][j];
						}
				}
		}
		return result;
}

void MathOperation::Transpose(Matrix& mtxA)
{
		std::vector<std::vector<int>> transposed(mtxA.cols, std::vector<int>(mtxA.rows));
		for(int i=0; i<mtxA.rows; i++)
		{
				for(int j=0; j<mtxA.cols; j++)
				{
						transposed[j][i]=mtxA.data[i][j];
				}
		}
		mtxA.data = transposed;
		int temp=mtxA.rows;
		mtxA.rows=mtxA.cols;
		mtxA.cols=temp;
}

void Printer::PrintToConsole(const Matrix& mtxA)
{
		for(int i=0; i<mtxA.rows; i++)
		{
				for(int j=0; j<mtxA.cols; j++)
				{
						std::cout<<mtxA.data[i][j]<<" ";
				}
				std::cout<<std::endl;
		}
		std::cout<<std::endl;
}
