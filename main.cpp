#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Matrix of integers
class Matrix
{
public:
    // If the bInitWithRandom is false ask user for inputs,
    // Otherwise initialize the matrix with random numbers
Matrix(int nRows, int nCols, bool bInitWithRandom = true)
    : nRows(nRows), nCols(nCols)
{
    elements.resize(nRows, std::vector<int>(nCols));

    if (bInitWithRandom= true) {
        initWithRandom();
    } else {
        initWithUserInput();
    }
};

    // Copy Constructor should do a deep copy
    Matrix( const Matrix& mtxOther )
    : nRows(mtxOther.nRows), nCols(mtxOther.nCols), elements(mtxOther.elements){};

    int& At( int row, int col ){
        return elements[row][col];
    };
    // Think why we are not declaring as const the above funcition?
    int At( int row, int col ) const{
        return elements[row][col];
    };

    // Get count of rows and columns
    int GetRowCount() const{
        return nRows;
    };
    int GetColCount() const{
        return nCols;
    };

private:
    int nRows;
    int nCols;
    std::vector<std::vector<int>> elements;


    void initWithRandom(){
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            elements[i][j] = rand() % 10 + 1;
    }

        void initWithUserInput(){
            for (int i = 0; i < nRows; ++i){
                for (int j = 0; j < nCols; ++j){
                    std::cout << "Enter element [" << i << "][" << j << "]: ";
                    std::cin >> elements[i][j];
                }
            };
            
    };

    void initWithZeros(){
            for (int i = 0; i < nRows; ++i){
                for (int j = 0; j < nCols; ++j){
                    elements[i][j] = 0;
                }
            };
    };
};

    // The variables holding the matrix info
    // It's up to You to decide what it should be

// Utility Class to perform math operations
class MathOperation
{
public:
    // Takes two matrices as an arguments, adds them and initializes
    // a new matrix with the result of addition
    static Matrix Add( const Matrix& mtxA, const Matrix& mtxB ){
        int mRows = mtxA.GetRowCount();
        int mCols = mtxA.GetColCount();

        if (mRows != mtxB.GetRowCount() || mCols != mtxB.GetColCount()){
            std::cout << "The matrices must have the same cols or rows"<< std::endl;
            Matrix zeroMatrix(mRows, mCols);
            return zeroMatrix;
            exit(1);
        }

        Matrix result(mRows, mCols);
        for(int i = 0; i < mRows; i++){
            for (int j = 0; j < mCols; j++){
                result.At(i, j) = mtxA.At(i, j) + mtxB.At(i, j);
            }
        }
        return result;
    };

    static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB ){
        int mRows = mtxA.GetRowCount();
        int mCols = mtxA.GetColCount();

        if (mRows != mtxB.GetRowCount() || mCols != mtxB.GetColCount()){
            std::cout << "The matrices must have the same cols or rows"<< std::endl;
            Matrix zeroMatrix(mRows, mCols);
            return zeroMatrix;
            exit(1);
        }

        Matrix result(mRows, mCols);
        for(int i = 0; i < mRows; i++){
            for (int j = 0; j < mCols; j++){
                result.At(i, j) = mtxA.At(i, j) * mtxB.At(i, j);
            }
        }
        return result;
    };

    static Matrix Transpose( Matrix& mtxA ){
        int mRows = mtxA.GetRowCount();
        int mCols = mtxA.GetColCount();

        Matrix result(mCols, mRows);
        for(int i = 0; i < mRows; i++){
            for (int j = 0; j < mCols; j++){
                result.At(i, j) = mtxA.At(j, i);
            }
        }
        return result;
        }
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
