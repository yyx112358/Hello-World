#pragma once
#include <memory>
#include "Point.h"
#include "Bitmap.h"
#include "Object.h"

//TODO:之后改为抽象类
class Board	//绘图类
{
public:
	Board(int row, int col) :_bitmap(QSize(col, row), ' ')
	{}

	void Resize();
	/*virtual*/ void Reset();//=0
	/*virtual*/ void Paint();//=0
	void AddObj(std::shared_ptr<Object>pobj);
	QSize size()const { return _bitmap.size; }
private:
	Bitmap _bitmap;//
	//TODO:四叉树数据结构Quadtree，提供碰撞检测	
};

