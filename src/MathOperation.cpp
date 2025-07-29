#include <iostream>
#include "MathOperation.h"


    Matrix MathOperation::Add( const Matrix& mtxA, const Matrix& mtxB ){
    	if(mtxA.GetRowCount()!=mtxB.GetRowCount() || mtxA.GetColCount()!=mtxB.GetColCount()){
		std::cout<<"anhamapatasxanutyun "<<std::endl;
		return Matrix(0,0,false);
	}
	Matrix result(mtxA.GetRowCount(),mtxA.GetColCount(),false);

	for(int i=0;i<mtxA.GetRowCount();i++){
		for(int j=0;j<mtxA.GetColCount();j++){
			result.At(i, j) = mtxA.At(i, j) + mtxB.At(i, j);
		}
	}return result;

    }
    Matrix MathOperation::Mult( const Matrix& mtxA, const Matrix& mtxB ){
    	if(mtxA.GetColCount()!=mtxB.GetRowCount()){
		std::cout<<"petq e arajin matrixi syuneri ev erkrord matrixi toxeri qanaky havasar linen "<<std::endl;
	}
	Matrix result(mtxA.GetRowCount(),mtxB.GetColCount(),false);
	
	for(int i=0;i<mtxA.GetRowCount();i++){
		for(int j=0;j<mtxB.GetColCount();j++){
			result.At(i,j)=0;
			for(int k=0;k<mtxA.GetColCount();k++){
				result.At(i,j)+=mtxA.At(i,k)*mtxB.At(k,j);
			}
		}
	}return result;
	
    }
    void MathOperation::Transpose( Matrix& mtxA ){
    	int originalRows=mtxA.GetRowCount();
	int originalCols=mtxA.GetColCount();

	Matrix transposed(originalCols,originalRows,true);
	
	for(int i=0;i<originalCols;i++){
		for(int j=0;j<originalRows;j++){
			transposed.At(i,j)=mtxA.At(j,i);
		}
	}
	mtxA=transposed;
    }
