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

void Game::Process() //�������롢�������봦����ײ�ͽ�������ɾ���塢��ʾ
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
