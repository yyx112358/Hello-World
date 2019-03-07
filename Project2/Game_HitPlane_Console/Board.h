#pragma once
#include<vector>

using namespace std;

class Board
{
public:
	Board(int row,int col);
	~Board();
	void Reset(int row, int col);
private:
	vector<vector<char>>bitmap;//
	//TODO:四叉树数据结构，提供碰撞检测
	int row, col;
};

