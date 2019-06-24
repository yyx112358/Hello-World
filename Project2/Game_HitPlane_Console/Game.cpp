#include "Game.h"
#include "Ally.h"
#include "Enemy.h"
#include <conio.h>
#include <windows.h>
#include <random>
using namespace std;

Game::Game(int row, int col) 
	:_scene(row, col)
{
	auto player = make_shared<Ally>(QRect(0,0,1,1), QSize(col, row));
	_objs.push_back(player);
	QObject::connect(player.get(), &Object::sig_Updated,this, &Game::SetPlayerStatus);
	//_allys.push_back(std::weak_ptr<Object>(player));
}

void Game::Process() //接收输入、根据输入处理、碰撞和交互、增删物体、显示
{
	clock_t lastCreateEnemyTime = clock();
	while (1)
	{
		auto keys = GetKeys();
		if (keys.find(27) != string::npos)//退出
			break;
		if (keys.find('p') != string::npos || keys.find('P') != string::npos)//暂停
		{
			string tmpkeys;
			do 
			{
				tmpkeys = GetKeys();
			} while (tmpkeys.find('p') == string::npos
				&& tmpkeys.find('P') == string::npos);
		}
		//TODO:CreateObjsBeforeMove();工厂类添加物体，工厂类一开始可以用时间随机生成，之后可以结合脚本做动态队列
		if(clock()-lastCreateEnemyTime>2000)
		{
			_objs.push_back(std::make_shared<Enemy>(
				QRect(_scene.size().width() - 2, rand() % (_scene.size().height()), 1, 1),
				_scene.size()));
			lastCreateEnemyTime = clock();
		}
		//TODO:ManipulateObjsBeforeMove();脚本直接操纵，可以之后新建一个Script类
		for (auto &obj : _objs) 
		{
			obj->ProcessInput(keys);//处理输入
			obj->Update();//更新状态
		}

		//TODO:加入k-d tree碰撞检测，减少比较次数
		for (auto it1 = _objs.begin(); it1 != _objs.end(); ++it1)//交互
		{
			auto it2 = it1;
			++it2;
			for (; it2 != _objs.end(); ++it2)
			{
				bool collided = IsCollided(**it1, **it2);
				if((*it1)->IsInteractable(*it2)==true)
					(*it1)->Interact(*it2,collided);
				if((*it2)->IsInteractable(*it1) == true)
					(*it2)->Interact(*it1,collided);
			}
		}

		list<shared_ptr<Object>>newObjs;		
		for (auto it = _objs.begin(); it != _objs.end();)//添加和摧毁物体
		{
			(*it)->Multiply(newObjs);
			if ((*it)->IsNeedDestroy() == true)
			{
				(*it)->Destroy();
				it = _objs.erase(it);
			}
			else
				++it;
		}
		_objs.insert(_objs.end(), newObjs.begin(), newObjs.end());

		_scene.Reset();
		DisplayUI();
		for (auto obj : _objs)//TODO:可以改为固定间隔刷新
			_scene.AddObj(obj);
		_scene.Paint();
		if (_crashFlag == true)
			break;
		Sleep(40);
	}
	_scene.Reset();
	cout << "Game Over" << endl
		<< "得分:" << _score << endl;
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

void Game::DisplayUI()
{
	cout << "=========控制台游戏==========" << endl
		<< "分数：" << _score << endl
		<< "HP：" << _HP << '/' << _maxHP << endl;
}

void Game::SetPlayerStatus(const Object* const obj)
{
	const Ally*const player = dynamic_cast<const Ally* const>(obj);
	_HP = player->GetHP();
	_maxHP = player->GetMaxHP();
	_score = player->GetScore();
	if (_HP <= 0)
		_crashFlag = true;
}
