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
	//TODO:�Ĳ������ݽṹ���ṩ��ײ���
	int row, col;
};

