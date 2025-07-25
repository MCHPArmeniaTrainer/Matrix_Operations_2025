#include <iostream>
#include "MathOperation.h"

Matrix MathOperation::Add(const Matrix& mtxA, const Matrix& mtxB)
{
	if(mtxA.GetRowCount()==mtxB.GetRowCount() && mtxA.GetColCount()==mtxB.GetColCount())
		{
			Matrix newMatrix(mtxA.GetRowCount(), mtxA.GetColCount());
			for(int i=0; i< mtxA.GetRowCount(); i++)
			{
				for(int j=0; j<mtxA.GetColCount(); j++)
				{
					newMatrix.At(i,j)=mtxA.At(i,j)+mtxB.At(i,j);
				}
			}
			return newMatrix;
		}
	else{
			std::cout<<"Error, cols and rows should be equal "<<std::endl;
			return Matrix(0,0,false);
	}
}
Matrix MathOperation::Mult(const Matrix& mtxA, const Matrix& mtxB)
{
	if(mtxA.GetColCount()==mtxB.GetRowCount())
		{
			Matrix mtxC(mtxA.GetRowCount(), mtxB.GetColCount());
			int sumC=0;
			for(int i =0; i<mtxA.GetRowCount(); i++)
			{	
				for (int j=0; j< mtxB.GetColCount(); j++)
					{
						sumC=0;
						for(int a =0; a<mtxA.GetColCount(); a++){	
							sumC+=mtxA.At(i,a)*mtxB.At(a,j);
						}					
						mtxC.At(i,j)=sumC;	
					}
			}
			return mtxC;
		}
	else{
		std::cout<<"the firstColCount should be equal to the secondRowCount"<<std::endl;
		return Matrix(0,0, false);
	}
}

Matrix MathOperation::Transpose(const Matrix& mtxA)
{
	Matrix mtxD(mtxA.GetColCount(), mtxA.GetRowCount());
	for(int i =0; i<mtxA.GetRowCount(); i++)
		{
			for (int j=0; j<mtxA.GetColCount(); j++)
				{
					mtxD.At(j,i)=mtxA.At(i,j);
				}
		}
	return mtxD;
}

