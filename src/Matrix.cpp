#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Matrix::Matrix(int nRows, int nCols, bool bInitWithRandom)
    : m_nRows(nRows), m_nCols(nCols) {
    if (bInitWithRandom)
        initWithRandom();
    else
        initWithUserInput();
}

Matrix::Matrix(const Matrix& mtxOther)
    : m_nRows(mtxOther.m_nRows), m_nCols(mtxOther.m_nCols), m_vMatrix(mtxOther.m_vMatrix) {}

int& Matrix::At(int row, int col) {
    if (row < 0 || row >= m_nRows || col < 0 || col >= m_nCols) {
        std::cout << "Wrong index!\n";
        return m_vMatrix[0][0];
    }
    return m_vMatrix[row][col];
}

int Matrix::At(int row, int col) const {
    if (row < 0 || row >= m_nRows || col < 0 || col >= m_nCols) {
        std::cout << "Wrong index!\n";
        return m_vMatrix[0][0];
    }
    return m_vMatrix[row][col];
}

int Matrix::GetRowCount() const {
    return m_nRows;
}

int Matrix::GetColCount() const {
    return m_nCols;
}

void Matrix::initWithRandom() {
    m_vMatrix.resize(m_nRows, std::vector<int>(m_nCols));
    std::srand(std::time(0));
    for (int i = 0; i < m_nRows; ++i)
        for (int j = 0; j < m_nCols; ++j)
            m_vMatrix[i][j] = rand() % 100;
}

void Matrix::initWithUserInput() {
    m_vMatrix.resize(m_nRows, std::vector<int>(m_nCols));
    int element;
    for (int i = 0; i < m_nRows; ++i)
        for (int j = 0; j < m_nCols; ++j)
            std::cin >> m_vMatrix[i][j];
}

