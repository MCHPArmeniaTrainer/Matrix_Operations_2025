#pragma once
#include <vector>

class Matrix
{
public:
    // If the bInitWithRandom is false ask user for inputs,
    // Otherwise initialize the matrix with random numbers
    Matrix( int nRows, int nCols, bool bInitWithRandom );
    // Copy Constructor should do a deep copy
    Matrix( const Matrix& mtxOther );

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
	Matrix(int nRows, int nCols);
    // The variables holding the matrix info
    // It's up to You to decide what it should be
	int rows, cols;
	std::vector<std::vector<int>> data;
	bool isInitialized=false;
	
	friend class MathOperation;
	friend class Printer;
};
