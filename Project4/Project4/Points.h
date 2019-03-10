#pragma once

class Points
{
public:
	Points() 
	{}
	Points(int x, int y);
	Points(int x, int y, char shape);
	int x, y;
	char shape;

};