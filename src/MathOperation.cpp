#include <iostream>
#include "MathOperation.hpp"

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
