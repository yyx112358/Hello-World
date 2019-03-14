#pragma once
#include "Object.h"
class Plane :
	public Object
{
public:
	Plane(Point tlpt, Size size,Size boardSize):Object(tlpt, size,boardSize){}
	virtual ~Plane(){}

private:
	Plane();
};

