#include "Printer.h"
#include <iostream>
void Printer::PrintToConsole(const Matrix& mtxA)
{
	for(int i = 0; i<mtxA.GetRowCount(); i++)
	{
		for (int j=0; j <mtxA.GetColCount(); j++)
		{
			std::cout<<mtxA.At(i,j)<<' ';
		}
		std::cout<<std::endl;
	}
		std::cout<<std::endl;
}
