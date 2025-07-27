/* Matrix.cpp */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "matrix.h"

using namespace std;

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
        matrix = nullptr; //just good practice
    }

    // Copy dimensions
    m_row = other.m_row;
    m_col = other.m_col;

    // Allocate new memory
    if (m_row > 0 && m_col > 0) {
        matrix = new int*[m_row];
        for (int i = 0; i < m_row; ++i) {
            matrix[i] = new int[m_col];
        }

        // Copy data
        for (int r = 0; r < m_row; ++r)
            for (int c = 0; c < m_col; ++c)
                matrix[r][c] = other.matrix[r][c];
    } else {
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

