#pragma once
#include "Object.h"
class Plane :
	public Object
{
public:
	Plane(QRect area,QSize boardSize):Object(area,boardSize){}
	virtual ~Plane(){}

	float GetHP()const { return _HP; }
	float GetMaxHP()const { return _maxHP; }

protected:
	float _HP, _maxHP;

private:
	Plane();
};

