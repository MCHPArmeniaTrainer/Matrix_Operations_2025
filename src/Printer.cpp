#include <iostream>
#include "Printer.hpp"

// Printing the matrices to the console.
void Printer::PrintToConsole( const Matrix& mtxA ) {
    int row = mtxA.GetRowCount();
    int col = mtxA.GetColCount();
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            std::cout << mtxA.At(r, c) << ' ';
        } 
        std::cout << std::endl;
    }
}



