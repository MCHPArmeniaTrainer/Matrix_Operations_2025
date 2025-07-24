#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.hpp"

Matrix::Matrix( int nRows, int nCols, bool bInitWithRandom )
	    : rows(nRows), cols(nCols), data(nRows, std::vector<int>(nCols)) {
		if (nRows==0 || nCols==0) return;
		if (bInitWithRandom==true) initWithRandom();
		else if(bInitWithRandom==false) initWithUserInput();
	    }

Matrix::Matrix( const Matrix& mtxOther )
	:rows(mtxOther.rows), cols(mtxOther.cols), data(mtxOther.data) {}
	
Matrix::Matrix(int nRows, int nCols)
	:rows(nRows), cols(nCols), data(nRows, std::vector<int>(nCols)) {}

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
