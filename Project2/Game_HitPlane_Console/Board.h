#pragma once
#include <memory>
#include "Point.h"
#include "Bitmap.h"
#include "Object.h"

using namespace std;

class Board
{
public:
	Board(int row, int col) :_bitmap(Size(col, row), ' ')
	{}

	void Board::Reset(int row, int col, uint8_t value)
	{
		_bitmap.Reset(value);
	}
	void Draw(std::shared_ptr<Object>pobj);
	Size size()const { return _bitmap.size; }
private:
	Bitmap _bitmap;//
	//TODO:四叉树数据结构Quadtree，提供碰撞检测	
};

