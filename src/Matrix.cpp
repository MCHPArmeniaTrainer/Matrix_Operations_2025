#include "Matrix.h"

Matrix::Matrix( int nRows, int nCols,bool bInitWithRandom)
{
    rows=nRows;
    cols=nCols;
    vMatrix = std::vector<std::vector<int>>(rows, std::vector<int>(cols));

    	if(bInitWithRandom){
		initWithRandom();
	}else{
		initWithUserInput();
	}
    }

    // Copy Constructor should do a deep copy
Matrix::Matrix( const Matrix& mtxOther ){
	    	rows=mtxOther.rows;
		cols=mtxOther.cols;
		vMatrix=mtxOther.vMatrix;
    }

    int& Matrix::At( int row, int col ){
    	return vMatrix[row][col];
    }
    int Matrix::At( int row, int col ) const{
    	return vMatrix[row][col];
    }

    // Get count of rows,columns and matrix
    int Matrix::GetRowCount() const{
    	return rows;
    }
    int Matrix::GetColCount() const{
    	return cols;
    }

    int Matrix::getValue(int i, int j) const {
        return vMatrix[i][j];
    }

    void Matrix::initWithRandom(){
    	std::srand(time(0));
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			vMatrix[i][j]=std::rand() % 100;
		}
	}
    }
    void Matrix::initWithUserInput(){
    	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			std::cin>>vMatrix[i][j];
			std::cout<<" ";
		}
	}
    }
	void Matrix::initWithZeros() {
    		for (int i = 0; i < rows; ++i){
        		for (int j = 0; j < cols; ++j){
            			vMatrix[i][j] = 0;
			}
		}
	}
    // The variables holding the matrix info
    // It's up to You to decide what it should be


