#pragma once
#include <vector>
#include "Point.h"

class Bitmap
{
public:
	//Bitmap() {}
	Bitmap(Size size,uint8_t value)
		:size(size),
		_data(std::vector<std::vector<uint8_t>>(size.y, std::vector<uint8_t>(size.x,value)))
	{}

	void Reset(uint8_t value)
	{
		for (auto row = 0; row < size.y; row++)
			for (auto col = 0; col < size.x; col++)
				_data[row][col] = value;
	}

	void Draw(Bitmap&src, Point tlpt)
	{
		size_t thisBeginX = (tlpt.x >= 0) ? (tlpt.x) : (0);
		size_t srcBeginX = (tlpt.x >= 0) ? (0) : (tlpt.x);
		size_t thisBeginY = (tlpt.y >= 0) ? (tlpt.y) : (0);
		size_t srcBeginY = (tlpt.y >= 0) ? (0) : (tlpt.y);

	}

	uint8_t&operator()(size_t row, size_t col) { return _data[row][col]; }
	uint8_t&operator()(Point pt) { return _data[pt.y][pt.x]; }
	//TODO:将数据改为shared_ptr，并加入多个状态，如亮度系数、对比度系数、放大系数等来进行优化
	std::vector<std::vector<uint8_t>>_data;
	Size size;
private:
	Bitmap();
};