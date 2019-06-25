#pragma once
#include "Scene.h"
#include <memory>
#include <list>
#include "Object.h"

class Game:public QObject
{
	Q_OBJECT
public:
	Game(int row,int col);
	~Game(){}
	
	void Process();//�������롢�������봦����ײ�ͽ�������ɾ���塢��ʾ
	std::string GetKeys()const;
	void DisplayUI();
	void Pause(bool isPause);

	void SetPlayerStatus(const Object* const obj);
protected:
	float _score = 0;
	float _maxHP = 1, _HP = 1;
	bool _crashFlag = false;

	Scene _scene;
	std::list<std::shared_ptr<Object>>_objs;
/*
	std::list<std::weak_ptr<Object>>_players;
	std::list<std::weak_ptr<Object>>_allys;
	std::list<std::weak_ptr<Object>>_enemys;
	std::list<std::weak_ptr<Object>>_allyBullets;
	std::list<std::weak_ptr<Object>>_enemyBullets;
	std::list<std::weak_ptr<Object>>_treasures;
	std::list<std::weak_ptr<Object>>_effects;*/
};

