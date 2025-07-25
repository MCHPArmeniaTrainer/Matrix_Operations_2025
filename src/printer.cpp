#include "../inc/printer.hpp"
#include <iostream>

void Printer::PrintToConsole(const Matrix& mtx) {
    for (int i = 0; i < mtx.GetRowCount(); ++i) {
        for (int j = 0; j < mtx.GetColCount(); ++j) {
            std::cout << mtx.At(i, j) << "\t";
        }
        std::cout << "\n";
    }
}