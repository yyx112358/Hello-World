#pragma once
#include <vector>
#include "Point.h"

class Bitmap
{
public:
	std::vector<std::vector<char>>_data;
	int row, col;
};