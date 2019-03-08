#pragma once
#include<vector>

using namespace std;

class Board
{
public:
	Board(int row,int col);
	~Board();

	void Reset();
	const std::vector<std::vector<char>>&GetMat() { return mat; }
	const int row, col;
private:
	std::vector<std::vector<char>>mat;	
};


