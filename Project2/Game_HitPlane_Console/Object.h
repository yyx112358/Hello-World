#pragma once
#include "Point.h"
#include "Board.h"
#include <string>
#include "Bitmap.h"

class Object
{
public:
	Object(){}
	virtual ~Object(){}

	virtual void Update() = 0;
	virtual void ProcessInput() = 0;
	virtual const Bitmap&GetBitmap()const = 0;

	const std::string typeName;//类型名，用于类型反射
protected:
	Point _center;//物体几何中心
	Size _size;//物体尺寸
	size_t _id;//编号，每一个物体独有

	
	
};

