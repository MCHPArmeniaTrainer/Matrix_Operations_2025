// Matrix of integers
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

class Matrix
{
public:
    Matrix(int nRows, int nCols, bool bInitWithRandom = true);
    Matrix() : Matrix(0, 0, true) {};
    Matrix(const Matrix& mtxOther);
    ~Matrix();

    Matrix& operator= (const Matrix& other);

    int& At(int row, int col);
    int At(int row, int col) const; // const variant: read-only

    // Get count of Rows and Columns:
    int GetRowCount() const;
    int GetColCount() const;

private:
    // The variables holding the matrix info:
    int m_row;
    int m_col;
    int** matrix;

    void initWithRandom();
    void initWithUserInput();
};

// Utility Class to perform math operations
class MathOperation
{
public:
    // Takes two matrices as an arguments, adds them and initializes
    // a new matrix with the result of addition
    static Matrix Add(const Matrix& mtxA, const Matrix& mtxB);
    static Matrix Mult(const Matrix& mtxA, const Matrix& mtxB);
    static void Transpose(Matrix& mtxA);
};

class Printer
{
public:
    static void PrintToConsole(const Matrix& mtxA);
};



int main()
{
    Matrix mtxA(11, 12);

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



/* Matrix */
Matrix::Matrix(int nRows, int nCols, bool bInitWithRandom) {
    m_row = nRows;
    m_col = nCols;
    matrix = nullptr;
    if (m_row != 0 && m_col != 0) {
        assert(m_row > 0);     // Ensure nRows is positive
        assert(m_col > 0);     // Ensure nCols is positive

        matrix = new int* [m_row];
        for (int i = 0; i < m_row; ++i)
            matrix[i] = new int[m_col];
        if (bInitWithRandom)
            initWithRandom();
        else
            initWithUserInput();
    }
}
Matrix::Matrix(const Matrix& mtxOther) {
    // Copy Constructor should do a deep copy:
    m_row = mtxOther.GetRowCount();
    m_col = mtxOther.GetColCount();
    matrix = new int* [m_row];
    for (int i = 0; i < m_row; ++i)
        matrix[i] = new int[m_col];
    for (int r = 0; r < m_row; ++r)
        for (int c = 0; c < m_col; ++c)
            matrix[r][c] = mtxOther.At(r, c);
}
Matrix::~Matrix() {
    if (matrix != nullptr) {
        for (int i = 0; i < m_row; ++i)
            delete[] matrix[i];
        delete[] matrix;
        matrix = nullptr;
    }
}
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other)  // self-assignment guard
        return *this;

    // First delete current matrix memory
    if (matrix != nullptr) {
        for (int i = 0; i < m_row; ++i)
            delete[] matrix[i];
        delete[] matrix;
    }

    // Copy dimensions
    m_row = other.m_row;
    m_col = other.m_col;

    // Allocate new memory
    if (m_row > 0 && m_col > 0) {
        matrix = new int* [m_row];
        for (int i = 0; i < m_row; ++i)
            matrix[i] = new int[m_col];

        // Copy data
        for (int r = 0; r < m_row; ++r)
            for (int c = 0; c < m_col; ++c)
                matrix[r][c] = other.matrix[r][c];
    }
    else {
        matrix = nullptr;
    }

    return *this;
}

int& Matrix::At(int row, int col) { 
    assert(matrix != nullptr);  // matrix must be allocated
    assert(row >= 0 && row < m_row);
    assert(col >= 0 && col < m_col);
    return matrix[row][col]; 
}
int Matrix::At(int row, int col) const { 
    assert(matrix != nullptr);
    assert(row >= 0 && row < m_row);
    assert(col >= 0 && col < m_col);
    return matrix[row][col]; 
}
int Matrix::GetRowCount() const { return m_row; }
int Matrix::GetColCount() const { return m_col; }
void Matrix::initWithRandom() {
    srand(time(0));
    // Fill the matrix with random numbers, e.g., from 1 to 10
    for (int r = 0; r < m_row; ++r)
        for (int c = 0; c < m_col; ++c)
            matrix[r][c] = (rand() % 10) + 1;
}
void Matrix::initWithUserInput() {
    cout << "Matrix dimensions is " 
        << m_row << "x" << m_col 
        << "\nEnter numbers of matrix: ";
    for (int r = 0; r < m_row; ++r)
        for (int c = 0; c < m_col; ++c)
            cin >> matrix[r][c];
}



/* MathOperation */
Matrix MathOperation::Add(const Matrix& mtxA, const Matrix& mtxB) {
    if (mtxA.GetRowCount() == mtxB.GetRowCount()
        && mtxA.GetColCount() == mtxB.GetColCount())
    {
        Matrix mtxAdd(mtxA.GetRowCount(), mtxA.GetColCount());
        for (int r = 0; r < mtxAdd.GetRowCount(); ++r)
            for (int c = 0; c < mtxAdd.GetColCount(); ++c)
                mtxAdd.At(r, c) = mtxA.At(r, c) + mtxB.At(r, c);
        return mtxAdd;
    }
    else {
        cout << "Error: add two matrices they should have the same row and column count" << endl;
        return Matrix(0, 0);
    }
}
Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB) {
    if (mtxA.GetColCount() == mtxB.GetRowCount()) {
        Matrix mtxMult(mtxA.GetRowCount(), mtxB.GetColCount());
        int sum = 0;
        for (int r = 0; r < mtxMult.GetRowCount(); ++r)
            for (int c = 0; c < mtxMult.GetColCount(); ++c) {
                sum = 0;
                for (int k = 0; k < mtxA.GetColCount(); ++k) {
                    sum += mtxA.At(r, k) * mtxB.At(k, c);
                }
                mtxMult.At(r, c) = sum;
            }
        return mtxMult;
    }
    else {
        cout << "Error: multiply two matrices the firstColCount should be equal to the secondRowCount" << endl;
        return Matrix(0, 0);
    }
}
void MathOperation::Transpose(Matrix& mtxA) {
    Matrix mtxTranspose(mtxA.GetColCount(), mtxA.GetRowCount());
    for (int r = 0; r < mtxA.GetRowCount(); ++r)
        for (int c = 0; c < mtxA.GetColCount(); ++c)
            mtxTranspose.At(c, r) = mtxA.At(r, c);
    mtxA = mtxTranspose;
}


/* Printer */
void Printer::PrintToConsole(const Matrix& mtxA) {
    for (int r = 0; r < mtxA.GetRowCount(); ++r) {
        for (int c = 0; c < mtxA.GetColCount(); ++c) {
            cout << mtxA.At(r, c) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

