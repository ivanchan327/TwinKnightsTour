// TwinKnightsTour.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Chan Chi Yung
// SID: 1155175838
// Email: 1155175838@link.cuhk.edu.hk

#include <iostream>
#include "TwinKnightsTour.h"
using namespace std;

int main()
{
    int row1, col1, row2, col2;
    char knight;
    int r, c;
    do {
        cout << "Knights' starting positions (row1 col1 row2 col2): ";
        cin >> row1 >> col1 >> row2 >> col2;
        if (!(row1 >= 0 && row1 < TwinKnightsTour::N && col1 >= 0 && col1 < TwinKnightsTour::N && row2 >= 0 && row2 < TwinKnightsTour::N && col2 >= 0 && col2 < TwinKnightsTour::N) || (row1 == row2 && col1 == col2))
            cout << "Invalid position(s)!" << endl;
    } while (!(row1 >= 0 && row1 < TwinKnightsTour::N && col1 >= 0 && col1 < TwinKnightsTour::N && row2 >= 0 && row2 < TwinKnightsTour::N && col2 >= 0 && col2 < TwinKnightsTour::N) || (row1 == row2 && col1 == col2));
    
    TwinKnightsTour TwinKnightsTour(row1, col1, row2, col2);
    TwinKnightsTour.print();
    while (TwinKnightsTour.hasMoreMoves()) {
      cout << "Move (knight row col): ";
      cin >> knight >> r >> c;
      if (TwinKnightsTour.isValid(knight, r, c) == true) {
        TwinKnightsTour.move(knight, r, c);
        TwinKnightsTour.print();
      }
      else cout << "Invalid move!" << endl;
    }
    cout << "No more moves!";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
