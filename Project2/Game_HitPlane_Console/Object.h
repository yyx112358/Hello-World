#pragma once
#include "Point.h"
#include "Board.h"
#include <string>

class Object
{
public:
	Object(){}
	virtual ~Object(){}

	virtual void Update() = 0;
	virtual void ProcessInput() = 0;
protected:
	Point _center;//物体几何中心
	Size _size;//物体尺寸
	size_t _id;//编号，每一个物体独有

	const std::string _typeName;//类型名，用于类型反射
	
};

