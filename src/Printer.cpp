#include <iostream>
#include "Printer.hpp"

void Printer::PrintToConsole(const Matrix& mtxA)
{
		for(int i=0; i<mtxA.rows; i++)
		{
				for(int j=0; j<mtxA.cols; j++)
				{
						std::cout<<mtxA.data[i][j]<<" ";
				}
				std::cout<<std::endl;
		}
		std::cout<<std::endl;
}
