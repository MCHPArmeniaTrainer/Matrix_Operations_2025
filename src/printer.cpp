/* Printer.cpp */

#include <iostream>
#include "printer.h"

using namespace std;

void Printer::PrintToConsole(const Matrix& mtxA) {
    for (int r = 0; r < mtxA.GetRowCount(); ++r) {
        for (int c = 0; c < mtxA.GetColCount(); ++c) {
            cout << mtxA.At(r, c) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

