#include "Game.h"
#include "Ally.h"
#include <conio.h>

using namespace std;

Game::Game(int row, int col) 
	:_board(row, col)
{
	
	_objs.push_back(make_shared<Ally>());
//	_allys.push_back(std::weak_ptr<Object>(player));
}

void Game::Process() //接收输入、根据输入处理、碰撞和交互、增删物体、显示
{
	while (1)
	{
		auto keys = GetKeys();
		if (keys.find(27) == string::npos)
			break;

		for (auto &obj : _objs)
			_board.Draw(obj)//obj->Update();
	}
}

std::string Game::GetKeys()
{
	if (_kbhit())
	{
		string str;
		str.push_back(_getch());
		return str;
	}
	else
		return "";
}
