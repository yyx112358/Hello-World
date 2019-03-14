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

void Game::Process() //�������롢�������봦����ײ�ͽ�������ɾ���塢��ʾ
{
	while (1)
	{
		auto keys = GetKeys();
		if (keys.find(27) != string::npos)
			break;
		//TODO:�費��Ҫһ��CreateObjsBeforeMove();������
		//TODO:ManipulateObjsBeforeMove();�ű�ֱ�Ӳ��ݣ�����֮���½�һ��Script��
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

		list<shared_ptr<Object>>newObjs;
		//TODO:CreateObjsAfterMove();������������壬������һ��ʼ������ʱ��������ɣ�֮����Խ�Ͻű�����̬����
		for (auto it = _objs.begin(); it != _objs.end();)//�ݻ�����
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
		for (auto obj : _objs)//TODO:���Ը�Ϊ�̶����ˢ��
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
