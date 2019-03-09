#include "Board.h"
#include<iostream>

using namespace std;

Board::Board()
{}
Board::Board(const int& row, const int& col)
	:mat(vector<vector<char>>(row, vector<char>(col, ' '))), _row(row), _col(col)
{}
Board::~Board()
{}
void Board::display()
{
	for (auto i = 0; i < row(); i++)
	{
		for (auto j = 0; j < col(); j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}
}
inline int Board::row()const { return _row; }
inline int Board::col()const { return _col; }
