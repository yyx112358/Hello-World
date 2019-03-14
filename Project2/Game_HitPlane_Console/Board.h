#pragma once
#include <memory>
#include "Point.h"
#include "Bitmap.h"
#include "Object.h"

//TODO:֮���Ϊ������
class Board	//��ͼ��
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
	//TODO:�Ĳ������ݽṹQuadtree���ṩ��ײ���	
};

