#pragma once
#include <conio.h>
#include "Board.h"
#include "Ally.h"
//#include <vector>

class Game
{
public:
	Game(int row,int col);
	~Game();

	string GetKeys();
	void Process();
	void Display();

	bool CrashFlag=0;
private:
	Board board;
	//Ally player;
};

