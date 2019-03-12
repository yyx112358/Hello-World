#include "Game.h"
#include "Ally.h"
#include <conio.h>

using namespace std;

Game::Game(int row, int col) 
	:_board(row, col)
{
	auto player = make_shared<Ally>();
	_objs.push_back(player);
	//_allys.push_back(std::weak_ptr<Object>(player));
}

void Game::Process() //接收输入、根据输入处理、碰撞和交互、增删物体、显示
{
	while (1)
	{
		auto keys = GetKeys();
		if (keys.find(27) == string::npos)
			break;

		for (auto &obj : _objs) 
		{
			obj->ProcessInput(keys);//处理输入
			obj->Update();//更新状态
		}

		for (auto it1 = _objs.begin(); it1 != _objs.end(); ++it1)//交互
		{
			auto it2 = it1;
			++it2;
			for (; it2 != _objs.end(); ++it2)
			{
				(*it1)->Interact(**it2);
				(*it2)->Interact(**it1);
			}
		}

		for (auto it = _objs.begin(); it != _objs.end();)
		{

		}

		for (auto &obj : _objs)//TODO:可以改为固定间隔刷新
			_board.Draw(obj);//obj->Update();
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
