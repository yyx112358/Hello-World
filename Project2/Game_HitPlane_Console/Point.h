#pragma once
#include <iostream>

class Point
{
public:
	Point()//默认初始化，初始化为(0,0)
	{
		x = 0;
		y = 0;
	}

	Point(float in_x, float in_y)//初始化为(x,y)
	{
		x = in_x;
		y = in_y;
	}

	Point  operator+(Point src)
	{
		Point p;
		p.x = this->x + src.x;
		p.y = y + src.y;
		return p;
	}
	Point& operator+=(Point src)//int a=5; a+=2;
	{
		x = x + src.x;
		y = y + src.y;
		return *this;
	}
	Point  operator-(Point src)
	{
		Point p;
		p.x = this->x - src.x;
		p.y = y - src.y;
		return p;
	}
	Point& operator-=(Point src)
	{
		x = x - src.x;
		y = y - src.y;
		return *this;
	}
	
	friend std::ostream& operator<<(std::ostream&os, const Point p)
	{
		os << '(' << p.x<<',' << p.y << ')';
		return os;
	}

	float x, y;
};
