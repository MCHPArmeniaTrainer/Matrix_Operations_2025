#include "../inc/matrix.hpp"
#include <iostream>
#include <cstdlib>

Matrix::Matrix(int nRows, int nCols, bool bInitWithRandom=true)
    : nRows(nRows), nCols(nCols)
{
    elements.resize(nRows, std::vector<int>(nCols));
    if (bInitWithRandom==true)
        initWithRandom();
    else
        initWithUserInput();
}

Matrix::Matrix(const Matrix& mtxOther)
    : nRows(mtxOther.nRows), nCols(mtxOther.nCols), elements(mtxOther.elements)
{}

int& Matrix::At(int row, int col) {
    return elements[row][col];
}

int Matrix::At(int row, int col) const {
    return elements[row][col];
}

int Matrix::GetRowCount() const { return nRows; }
int Matrix::GetColCount() const { return nCols; }

void Matrix::initWithRandom() {
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            elements[i][j] = rand() % 10 + 1;
}

void Matrix::initWithUserInput() {
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j) {
            std::cout << "Enter element [" << i << "][" << j << "]: ";
            std::cin >> elements[i][j];
        }
}

void Matrix::initWithZeros() {
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            elements[i][j] = 0;
}
