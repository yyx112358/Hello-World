#pragma once
#include <vector>

using namespace std;

class Board
{
public:
	vector<vector<char>>mat;
	Board();
	Board(const int& row, const int& col);
	~Board();
	void display();
	inline int row()const;
	inline int col()const;
private:
	int _row = 0;
	int _col = 0;
};