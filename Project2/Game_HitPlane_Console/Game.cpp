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

void Game::Process() //�������롢�������봦����ײ�ͽ�������ɾ���塢��ʾ
{
	clock_t lastCreateEnemyTime = clock();
	while (1)
	{
		auto keys = GetKeys();
		if (keys.find(27) != string::npos)//�˳�
			break;
		if (keys.find('p') != string::npos || keys.find('P') != string::npos)//��ͣ
		{
			string tmpkeys;
			do 
			{
				tmpkeys = GetKeys();
			} while (tmpkeys.find('p') == string::npos
				&& tmpkeys.find('P') == string::npos);
		}
		//TODO:CreateObjsBeforeMove();������������壬������һ��ʼ������ʱ��������ɣ�֮����Խ�Ͻű�����̬����
		if(clock()-lastCreateEnemyTime>2000)
		{
			_objs.push_back(std::make_shared<Enemy>(
				QRect(_scene.size().width() - 2, rand() % (_scene.size().height()), 1, 1),
				_scene.size()));
			lastCreateEnemyTime = clock();
		}
		//TODO:ManipulateObjsBeforeMove();�ű�ֱ�Ӳ��ݣ�����֮���½�һ��Script��
		for (auto &obj : _objs) 
		{
			obj->ProcessInput(keys);//��������
			obj->Update();//����״̬
		}

		//TODO:����k-d tree��ײ��⣬���ٱȽϴ���
		for (auto it1 = _objs.begin(); it1 != _objs.end(); ++it1)//����
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
		for (auto it = _objs.begin(); it != _objs.end();)//��Ӻʹݻ�����
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
		for (auto obj : _objs)//TODO:���Ը�Ϊ�̶����ˢ��
			_scene.AddObj(obj);
		_scene.Paint();
		if (_crashFlag == true)
			break;
		Sleep(40);
	}
	_scene.Reset();
	cout << "Game Over" << endl
		<< "�÷�:" << _score << endl;
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
	cout << "=========����̨��Ϸ==========" << endl
		<< "������" << _score << endl
		<< "HP��" << _HP << '/' << _maxHP << endl;
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
