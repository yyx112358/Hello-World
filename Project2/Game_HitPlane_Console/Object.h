#pragma once
#include "Point.h"
#include "Board.h"
#include <string>
#include "Bitmap.h"

class Object
{
public:
	Object(){}
	Object(Point tlpt,Size size):_tlpt(tlpt),_size(size){}
	virtual ~Object(){}

	virtual void Update() = 0;
	virtual void ProcessInput(std::string input) = 0;
	virtual void Interact(Object&another) = 0;

	virtual const Bitmap&GetBitmap()const = 0;

	Point CenterPoint()const { return Point(_tlpt.x + _size.x / 2, _tlpt.y + _size.y / 2); }
	Point TopLeftPoint()const { return _tlpt; }
	Point BottomRightPoint()const { return Point(_tlpt.x + _size.x, _tlpt.y + _size.y); }

	const std::string typeName;//类型名，用于类型反射
protected:
	Point _tlpt;//物体左上角(top left point)
	Point _z;//Z轴坐标
	Size _size;//物体尺寸
	size_t _id;//编号，每一个物体独有

	
	
};

