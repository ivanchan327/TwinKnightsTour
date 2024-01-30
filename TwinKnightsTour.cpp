// Name: Chan Chi Yung
// SID: 1155175838
// Email: 1155175838@link.cuhk.edu.hk

#include <iostream>
#include <string>
#include "TwinKnightsTour.h"

using namespace std;

TwinKnightsTour::TwinKnightsTour(int r1, int c1, int r2, int c2) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = ".";
		}
	}
	posR1 = r1; posC1 = c1; posR2 = r2; posC2 = c2; steps1 = 0; steps2 = 0; consec1 = 0; consec2 = 0;
	board[r1][c1] = "@"; board[r2][c2] = "#";
}

void TwinKnightsTour::print() const {
	cout << "  ";
	for (int i = 0; i < N; i++) {
		if (i < 10)
			cout << "  " << i;
		else cout << " " << i;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		if (i < 10)
			cout << " " << i;
		else cout << i;
		for (int j = 0; j < N; j++) {
			string width(board[i][j]);
			if (width.length() == 1)
				cout << "  " << board[i][j];
			else if (width.length() == 2)
				cout << " " << board[i][j];
		}
		cout << endl;
	}
}
bool TwinKnightsTour::isValid(char knight, int r, int c) const {
	if (!(r >= 0 && r < N && c >= 0 && c < N))
		return false;
	else if (!(knight == '@' || knight == '#'))
		return false;
	else if (board[r][c] != ".")
		return false;
  else if (knight == '@') {
    if (consec1 == 2)
      return false;
  }
  else if (knight == '#') {
    if (consec2 == 2)
      return false;
  }
	if (knight == '@') {
		if (r == posR1 - 1 && c == posC1 - 2)
			return true;
		else if (r == posR1 - 2 && c == posC1 - 1)
			return true;
		else if (r == posR1 - 2 && c == posC1 + 1)
			return true;
		else if (r == posR1 - 1 && c == posC1 + 2)
			return true;
		else if (r == posR1 + 1 && c == posC1 + 2)
			return true;
		else if (r == posR1 + 2 && c == posC1 + 1)
			return true;
		else if (r == posR1 + 2 && c == posC1 - 1)
			return true;
		else if (r == posR1 + 1 && c == posC1 - 2)
			return true;
	}
	else if (knight == '#') {
		if (r == posR2 - 1 && c == posC2 - 2)
			return true;
		else if (r == posR2 - 2 && c == posC2 - 1)
			return true;
		else if (r == posR2 - 2 && c == posC2 + 1)
			return true;
		else if (r == posR2 - 1 && c == posC2 + 2)
			return true;
		else if (r == posR2 + 1 && c == posC2 + 2)
			return true;
		else if (r == posR2 + 2 && c == posC2 + 1)
			return true;
		else if (r == posR2 + 2 && c == posC2 - 1)
			return true;
		else if (r == posR2 + 1 && c == posC2 - 2)
			return true;
	}
  return false;
}

bool TwinKnightsTour::hasMoreMoves() const {
	if (isValid('@', posR1 - 1, posC1 - 2) == true && posR1 - 1 >= 0 && posC1 - 2 >= 0)
    return true;
	else if (isValid('@', posR1 - 2, posC1 - 1) == true && posR1 - 2 >= 0 && posC1 - 1 >= 0)
		return true;
	else if (isValid('@', posR1 - 2, posC1 + 1) == true && posR1 - 2 >= 0 && posC1 + 1 < N)
		return true;
	else if (isValid('@', posR1 - 1, posC1 + 2) == true && posR1 - 1 >= 0 && posC1 + 2 < N)
		return true;
	else if (isValid('@', posR1 + 1, posC1 + 2) == true && posR1 + 1 < N && posC1 + 2 < N)
		return true;
	else if (isValid('@', posR1 + 2, posC1 + 1) == true && posR1 + 2 < N && posC1 + 1 < N)
		return true;
	else if (isValid('@', posR1 + 2, posC1 - 1) == true && posR1 + 2 < N && posC1 - 1 >= 0)
		return true;
	else if (isValid('@', posR1 + 1, posC1 - 2) == true && posR1 + 1 < N && posC1 - 2 >= 0)
		return true;
	else if (isValid('#', posR2 - 1, posC2 - 2) == true && posR2 - 1 >= 0 && posC2 - 2 >= 0)
		return true;
	else if (isValid('#', posR2 - 2, posC2 - 1) == true && posR2 - 2 >= 0 && posC2 - 1 >= 0)
		return true;
	else if (isValid('#', posR2 - 2, posC2 + 1) == true && posR2 - 2 >= 0 && posC2 + 1 < N)
		return true;
	else if (isValid('#', posR2 - 1, posC2 + 2) == true && posR2 - 1 >= 0 && posC2 + 2 < N)
		return true;
	else if (isValid('#', posR2 + 1, posC2 + 2) == true && posR2 + 1 < N && posC2 + 2 < N)
		return true;
	else if (isValid('#', posR2 + 2, posC2 + 1) == true && posR2 + 2 < N && posC2 + 1 < N)
		return true;
	else if (isValid('#', posR2 + 2, posC2 - 1) == true && posR2 + 2 < N && posC2 - 1 >= 0)
		return true;
	else if (isValid('#', posR2 + 1, posC2 - 2) == true && posR2 + 1 < N && posC2 - 2 >= 0)
		return true;
	else return false;
}

bool TwinKnightsTour::move(char knight, int r, int c) {
	if (isValid(knight, r, c)) {
		if (knight == '@') {
			steps1++; consec1++; consec2 = 0;
			board[r][c] = "@";
			if (steps1 % 26 == 0) {
				if (steps1 == 26)
					board[posR1][posC1] = "Z";
				else {
					string s1 = "AZ";
					s1[0] = 'A' + (steps1 - 1) / 26 - 1;
					board[posR1][posC1] = s1;
				}
			}
			else if (steps1 < 26) {
				board[posR1][posC1] = 'A' + steps1 % 26 - 1;
			}
			else {
				string s1 = "AA";
				s1[0] = 'A' + (steps1 - 1) / 26 - 1;
				s1[1] = 'A' + steps1 % 26 - 1;
				board[posR1][posC1] = s1;
			}
			posR1 = r; posC1 = c;
			return true;
		}
		else if (knight == '#') {
			steps2++; consec2++; consec1 = 0;
			board[r][c] = "#";
			if (steps2 % 26 == 0) {
				if (steps2 == 26)
					board[posR2][posC2] = "z";
				else {
					string s2 = "az";
					s2[0] = 'a' + (steps2 - 1) / 26 - 1;
					board[posR2][posC2] = s2;
				}
			}
			else if (steps2 < 26) {
				board[posR2][posC2] = 'a' + steps2 % 26 - 1;
			}
			else {
				string s2 = "aa";
				s2[0] = 'a' + (steps2 - 1) / 26 - 1;
				s2[1] = 'a' + steps2 % 26 - 1;
				board[posR2][posC2] = s2;
			}
			posR2 = r; posC2 = c;
			return true;
		}
	}
	else return false;
}