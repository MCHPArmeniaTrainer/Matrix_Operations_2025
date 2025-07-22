#include <iostream>
#include <cstdlib>
#include <ctime>
// Hello test aaa
// The Class of int Matrix.
class Matrix
{
public:
    // Public function declarations.
    Matrix(int nRows, int nCols, bool bInitWithRandom = true);
    Matrix(const Matrix& mtxOther);
    ~Matrix();

    int& At(int row, int col);
    int At(int row, int col) const;

    int GetRowCount() const;
    int GetColCount() const;

private:
    // Private function declarations.
    int row_, col_;
    int** matrix;

    void initWithRandom();
    void initWithUserInput();
};

// Constructor of the class. Takes rows, cols and inoitialization method.
Matrix::Matrix( int nRows, int nCols, bool bInitWithRandom)  {
    row_ = nRows;
    col_ = nCols;

    // Creating a dynamic matrix with given rows and cols.
    matrix = new int*[row_];
    for(int r = 0; r < row_; r++) {
        matrix[r] = new int[col_];
    }

    // Checking bInitWithRandom value and calling appropriate methods.
    if(bInitWithRandom) initWithRandom();
    else initWithUserInput();
}

// Copy constructor of the class. Deep copy.
Matrix::Matrix(const Matrix& mtxOther) {
    row_ = mtxOther.row_;
    col_ = mtxOther.col_;

    for(int r = 0; r < mtxOther.row_; r++) {
        for(int c = 0; c < mtxOther.col_; c++) {
            matrix[r][c] = mtxOther.matrix[r][c];
        }
    }
}

// Destructor of the class. Deletes allocated memory.
Matrix::~Matrix() {
    for(int r = 0; r < row_; r++) {
        delete[] matrix[r];
    }
    delete[] matrix;
}

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
