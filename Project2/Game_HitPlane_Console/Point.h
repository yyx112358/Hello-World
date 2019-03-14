#pragma once
#include <math.h>
#include <iostream>

// template<typename Tp>
// class Vec2
// {
// public:
// 	Vec2():x(0),y(0){}
// 	Vec2(Tp x, Tp y):x(x),y(y){}
// 	
// 	Vec2 operator+(Vec2 src) { return Vec2(x + src.x, y + src.y); }
// 	Vec2& operator+=(Vec2 src) { x += src.x; y += src.y; return*this; }
// 	Vec2 operator-(Vec2 src) { return Vec2(x - src.x, y - src.y); }
// 	Vec2& operator-=(Vec2 src) { x -= src.x; y -= src.y; return*this; }
// 	Vec2 operator*(Tp scale) { return Vec2(x *scale, y *scale); }
// 	Vec2& operator*=(Tp scale) { x *= scale; y *= scale; return*this; }
// 	Vec2 operator/(Tp scale) { return Vec2(x / scale, y / scale); }
// 	Vec2& operator/=(Tp scale) { x /= scale; y /= scale; return*this; }
// 
// 	bool operator==(Vec2 src) { return (x == src.x) && (y == src.y); }
// 	bool operator!=(Vec2 src) { return (x != src.x) || (y != src.y); }
// 	//friend operator Vec2<float>() { return Vec2<float>(x, y); }
// 
// 	friend double Distance(Vec2 a, Vec2 b) { return sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y)); }
// 	double Distance(Vec2 p) { return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y)); }
// 
// 	friend std::ostream&operator<<(std::ostream&os, Vec2 p) { return os << '(' << p.x << ',' << p.y << ')'; }
// 
// 	Tp x, y;
// };
// 
// 
// 
// typedef Vec2<int> Point;//(x坐标，y坐标)
// typedef Vec2<float> Pointf;//(x坐标，y坐标)
// typedef Vec2<int> Size;//（宽度，高度）
// typedef Vec2<float> Speed;//（x速度分量，y速度分量）

