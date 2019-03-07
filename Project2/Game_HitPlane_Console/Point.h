#pragma once
#include <math.h>
#include <iostream>
class Vec2
{
public:
	Vec2():x(0),y(0){}
	Vec2(float x, float y):x(x),y(y){}
	
	Vec2 operator+(Vec2 src) { return Vec2(x + src.x, y + src.y); }
	Vec2& operator+=(Vec2 src) { x += src.x; y += src.y; return*this; }
	Vec2 operator-(Vec2 src) { return Vec2(x - src.x, y - src.y); }
	Vec2& operator-=(Vec2 src) { x -= src.x; y -= src.y; return*this; }
	Vec2 operator*(float scale) { return Vec2(x *scale, y *scale); }
	Vec2& operator*=(float scale) { x *= scale; y *= scale; return*this; }
	Vec2 operator/(float scale) { return Vec2(x / scale, y / scale); }
	Vec2& operator/=(float scale) { x /= scale; y /= scale; return*this; }

	friend float Distance(Vec2 a, Vec2 b) { return sqrtf((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y)); }
	float Distance(Vec2 p) { return sqrtf((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y)); }

	friend std::ostream&operator<<(std::ostream&os, Vec2 p) { return os << '(' << p.x << ',' << p.y << ')'; }

	float x, y;
};

typedef Vec2 Point;
typedef Vec2 Size;
typedef Vec2 Speed;

