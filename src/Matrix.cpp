#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <cassert>


Matrix::Matrix( int nRows, int nCols, bool bInitWithRandom )
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
Matrix::Matrix( const Matrix& mtxOther )
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
int Matrix::GetRowCount()const{return m_irow;}
int Matrix::GetColCount()const{return m_icol;}
Matrix::~Matrix()
{
         for(int a =0; a<m_irow; a++) delete[]m_matrix[a];
         delete[] m_matrix;
}
void Matrix::initWithRandom()
{	
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
