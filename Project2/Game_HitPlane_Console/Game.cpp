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

void Game::Process() //�������롢�������봦����ײ�ͽ�������ɾ���塢��ʾ
{
	while (1)
	{
		auto keys = GetKeys();
		if (keys.find(27) == string::npos)
			break;

		for (auto &obj : _objs) 
		{
			obj->ProcessInput(keys);//��������
			obj->Update();//����״̬
		}

		for (auto it1 = _objs.begin(); it1 != _objs.end(); ++it1)//����
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

		for (auto &obj : _objs)//TODO:���Ը�Ϊ�̶����ˢ��
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
