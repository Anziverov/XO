#pragma once

#include "resource.h"

class Turn {
private:
	LPCWSTR STATE = L"N"; // N - none, x - x player, O - o player
						  //wchar_t* bf;
public:
	LPCWSTR makemove()
	{

		if (STATE == L"N") {
			STATE = L"X";
			return STATE;
		}
		if (STATE == L"X") {
			STATE = L"O";
			return STATE;
		}
		if (STATE == L"O") {
			STATE = L"X";
			return STATE;
		}
	}
	LPCWSTR getSTATE() {
		return STATE;
	}
	void resetGame()
	{
		STATE = L"N";
	}

};
class Field {
private:
	//LPWSTR FIELD[3][3];
	char FIELD[3][3];
	int freeFields = 9;
	LPCWSTR x_won = L"X's won!";
	LPCWSTR o_won = L"O's won!";
	LPCWSTR n_won = L"DRAW"; // in progress
public:
	void move(LPCWSTR sign, int x, int y) {
		if (sign == L"X")
			FIELD[x][y] = 'X';
		if (sign == L"O")
			FIELD[x][y] = 'O';
		--freeFields;
	}
	LPCWSTR winState() {
		if ((FIELD[0][0] == 'X' || FIELD[0][0] == 'O') && (FIELD[0][0] == FIELD[1][0] && FIELD[1][0] == FIELD[2][0])) {
			if (FIELD[0][0] == 'X')
				return x_won;
			if (FIELD[0][0] == 'O')
				return o_won;
		}
		if ((FIELD[0][1] == 'X' || FIELD[0][1] == 'O') && (FIELD[0][1] == FIELD[1][1] && FIELD[1][1] == FIELD[2][1])) {
			if (FIELD[0][1] == 'X')
				return x_won;
			if (FIELD[0][1] == 'O')
				return o_won;
		}
		if ((FIELD[0][2] == 'X' || FIELD[0][2] == 'O') && (FIELD[0][2] == FIELD[1][2] && FIELD[1][2] == FIELD[2][2])) {
			if (FIELD[0][2] == 'X')
				return x_won;
			if (FIELD[0][2] == 'O')
				return o_won;
		}
		if ((FIELD[0][0] == 'X' || FIELD[0][0] == 'O') && (FIELD[0][0] == FIELD[0][1] && FIELD[0][1] == FIELD[0][2])) {
			if (FIELD[0][0] == 'X')
				return x_won;
			if (FIELD[0][0] == 'O')
				return o_won;
		}
		if ((FIELD[1][0] == 'X' || FIELD[1][0] == 'O') && (FIELD[1][0] == FIELD[1][1] && FIELD[1][1] == FIELD[1][2])) {
			if (FIELD[1][0] == 'X')
				return x_won;
			if (FIELD[1][0] == 'O')
				return o_won;
		}
		if ((FIELD[2][0] == 'X' || FIELD[2][0] == 'O') && (FIELD[2][0] == FIELD[2][1] && FIELD[2][1] == FIELD[2][2])) {
			if (FIELD[2][0] == 'X')
				return x_won;
			if (FIELD[2][0] == 'O')
				return o_won;
		}
		if ((FIELD[0][0] == 'X' || FIELD[0][0] == 'O') && (FIELD[0][0] == FIELD[1][1] && FIELD[1][1] == FIELD[2][2])) {
			if (FIELD[0][0] == 'X')
				return x_won;
			if (FIELD[0][0] == 'O')
				return o_won;
		}
		if ((FIELD[0][2] == 'X' || FIELD[0][2] == 'O') && (FIELD[0][2] == FIELD[1][1] && FIELD[1][1] == FIELD[2][0])) {
			if (FIELD[0][2] == 'X')
				return x_won;
			if (FIELD[0][2] == 'O')
				return o_won;
		}
		if (freeFields == 0) return n_won;
		return NULL;
	}
	void reset() {
		freeFields = 9;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				FIELD[i][j] = '\0';
	}
};
