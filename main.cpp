#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
class Matrix
{
private:
	std::vector<std::vector<int>> m_vMatrix;
	int m_nRows;
	int m_nCols;
public:	
    Matrix( int nRows, int nCols, bool bInitWithRandom = true ) : m_nRows(nRows),m_nCols(nCols){
	
		if(bInitWithRandom){
			initWithRandom();
		}
		else{
			initWithUserInput();
		}
	}
 	
    Matrix( const Matrix& mtxOther ) : m_nRows(mtxOther.m_nRows),m_nCols(mtxOther.m_nCols),m_vMatrix(mtxOther.m_vMatrix) {}

    int& At( int row, int col )
	{  if(row < 0 || row >= m_nRows || col >= m_nCols || col < 0 ){
			std::cout<<"Wrong index!";	
			return m_vMatrix[0][0];
		}
		else{
					
			return m_vMatrix[row][col];
		}
	}



    int At( int row, int col ) const
	{ 
	  if(row < 0 || row >= m_nRows || col >= m_nCols || col < 0){
			
			std::cout<<"Wrong index!";	
			return m_vMatrix[0][0];
		}
		else{
			return m_vMatrix[row][col];
		}
	}

    int GetRowCount() const
	{
		return m_nRows;
	}

    int GetColCount() const
	{
		return m_nCols;
	}

private:
    
	
	void initWithRandom(){
		    m_vMatrix.resize(m_nRows, std::vector<int>(m_nCols));
		std::srand(time(0));
		for(int i = 0;i<m_nRows;++i){
			for(int j = 0;j < m_nCols;++j){
				m_vMatrix[i][j] = rand()%100;	
			}
		}	
	
}
    void initWithUserInput(){
	    m_vMatrix.resize(m_nRows, std::vector<int>(m_nCols));
		int element = 0;	
		for(int i = 0;i<m_nRows;++i){
			for(int j = 0;j < m_nCols;++j){
			std::cin>>element;
					
				m_vMatrix[i][j] = element;	
			}
		}	
	}

};

class MathOperation
{
public:
    static Matrix Add( const Matrix& mtxA, const Matrix& mtxB )
	{
		Matrix mtxC(mtxA);

		if(mtxA.GetRowCount() == mtxB.GetRowCount() && mtxA.GetColCount() == mtxB.GetColCount())
		{
	    	
			for(int i = 0;i < mtxA.GetRowCount();i++){
				for(int j = 0;j < mtxA.GetColCount();++j){
						mtxC.At(i,j) = mtxA.At(i,j) +  mtxB.At(i,j);	
				}
			}
			return mtxC;
		}
		else{
			std::cout<<"rows and cols don't match \n";
			return mtxC;
		}
		
	}


	static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB )
{
    if(mtxA.GetColCount() != mtxB.GetRowCount())
    {
        std::cout<<"Condition for mult two matrix is false";
        return Matrix(0,0);  
    }

    Matrix mtxC(mtxA.GetRowCount(), mtxB.GetColCount());

    for (int i = 0; i < mtxA.GetRowCount(); ++i) {
        for (int j = 0; j < mtxB.GetColCount(); ++j) {
            int sum = 0;
            for (int k = 0; k < mtxA.GetColCount(); ++k) {
                sum += mtxA.At(i, k) * mtxB.At(k, j);
            }
            mtxC.At(i, j) = sum;
        }
    }

    return mtxC;
}


    static void Transpose( Matrix& mtxA ){
		
		Matrix mtxC(mtxA.GetColCount(),mtxA.GetRowCount());
		for(int i = 0;i < mtxA.GetRowCount();++i){
			for(int j = 0;j < mtxA.GetColCount();++j){
					mtxC.At(j,i) = mtxA.At(i,j);
			}
		
		}
		mtxA = mtxC;
	}
};

class Printer
{
public:
    static void PrintToConsole( const Matrix& mtxA ){
		for(int i = 0;i < mtxA.GetRowCount();i++){
			for(int j = 0;j < mtxA.GetColCount();++j){
				std::cout<<mtxA.At(i,j)<<"  ";
			}
			std::cout<<std::endl;
	}
	}
};


int main()
{
    return 0;
}
