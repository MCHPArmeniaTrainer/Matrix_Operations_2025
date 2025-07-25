#include "Matrix.h"
class MathOperation{
	public:
		static Matrix Add( const Matrix& mtxA, const Matrix& mtxB );
		static Matrix Mult( const Matrix& mtxA, const Matrix& mtxB );
		static Matrix Transpose( const  Matrix& mtxA );
};
