#pragma once
#include "Object.h"
class Plane :
	public Object
{
public:
	Plane(QRect area,QSize boardSize):Object(area,boardSize){}
	virtual ~Plane(){}

private:
	Plane();
};

