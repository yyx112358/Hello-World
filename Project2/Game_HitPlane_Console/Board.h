#pragma once
#include<vector>

using namespace std;

class Board
{
public:
	Board(int row,int col);
	~Board();
	void Reset();
private:
	vector <vector<char>>v1;
	int row, col;
};


