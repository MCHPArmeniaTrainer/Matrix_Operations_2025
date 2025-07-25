#pragma once 
class Matrix{
	private:
		int m_irow;
		int m_icol;
		int** m_matrix;
		void initWithRandom();
		void initWithUserInput();
	public:
		Matrix( int nRows, int nCols, bool bInitWithRandom = true );
		Matrix( const Matrix& mtxOther ); 

		int& At( int row, int col );
		int At( int row, int col ) const;
		int GetRowCount()const;
		int GetColCount()const;

		~Matrix();
};
