#pragma once
#include<vector>
#include "Point.h"

using namespace std;

class Board
{
public:
	Board(int row,int col);
	~Board();
	void Reset(int row, int col, char value);
	void Draw(vector<vector<char>>, Point center);
private:
	vector<vector<char>>_bitmap;//
	//TODO:四叉树数据结构，提供碰撞检测
	int _row, _col;
};

