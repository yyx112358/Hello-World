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

	const std::string typeName;//���������������ͷ���
protected:
	Point _center;//���弸������
	Size _size;//����ߴ�
	size_t _id;//��ţ�ÿһ���������

	
	
};

