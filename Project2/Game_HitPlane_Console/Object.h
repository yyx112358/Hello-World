#pragma once
#include "Point.h"
#include "Board.h"

class Object
{
public:
	Object(Board*pboard, float x = 0, float y = 0);
	virtual~Object();

	Point SetLocation(Point newLoc) { _loc = newLoc; return _loc; }
	Point GetLocation()const { return _loc; }

	virtual void progress() = 0;
	virtual void shape() = 0; 
	virtual void tag() = 0;
	

protected:
	Board* const _pboard;
	Point _loc;
	//Speed speed;
	//const char*ob;
};

