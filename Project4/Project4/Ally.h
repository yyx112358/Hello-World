#pragma once
#include "Board.h"
#include <conio.h>

class Ally
{
public:
	Ally(Board*board);
	~Ally();
	Board *pboard = nullptr;
	inline int Ally::Ax() const { return _Ax; }////////const
	inline int Ally::Ay() const { return _Ay; }////////const
	void keyevents();
	char AllyShape = 'p';
private:
	int _Ax = 0;
	int _Ay = 0;
	int _endflag = 0;
};