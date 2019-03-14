#include "Game.h"
#include "Ally.h"
#include <conio.h>
#include <windows.h>

using namespace std;

Game::Game(int row, int col) 
	:_board(row, col)
{
	auto player = make_shared<Ally>(Point(2,2), Size(1, 1), Size(col, row));
	_objs.push_back(player);
	//_allys.push_back(std::weak_ptr<Object>(player));
}

void Game::Process() //接收输入、根据输入处理、碰撞和交互、增删物体、显示
{
	while (1)
	{
		auto keys = GetKeys();
		if (keys.find(27) != string::npos)
			break;
		//TODO:需不需要一个CreateObjsBeforeMove();？？？
		//TODO:ManipulateObjsBeforeMove();脚本直接操纵，可以之后新建一个Script类
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

		list<shared_ptr<Object>>newObjs;
		//TODO:CreateObjsAfterMove();工厂类添加物体，工厂类一开始可以用时间随机生成，之后可以结合脚本做动态队列
		for (auto it = _objs.begin(); it != _objs.end();)//摧毁物体
		{
			if ((*it)->isNeedDestroy() == true)
			{
				auto tmp = (*it)->Destroy();
				newObjs.insert(newObjs.end(), tmp.begin(), tmp.end());
				it = _objs.erase(it);
			}
			else
				++it;
		}
		_objs.insert(_objs.end(), newObjs.begin(), newObjs.end());

		_board.Reset();
		for (auto obj : _objs)//TODO:可以改为固定间隔刷新
			_board.AddObj(obj);
		_board.Paint();
		Sleep(20);
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
