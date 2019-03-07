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
	Point _center;//���弸������
	Size _size;//����ߴ�
	size_t _id;//��ţ�ÿһ���������

	const std::string _typeName;//���������������ͷ���
	
};

