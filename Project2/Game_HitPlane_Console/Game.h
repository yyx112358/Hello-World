#pragma once
#include "Board.h"
#include <memory>
#include <list>
#include "Object.h"

class Game
{
public:
	Game(int row,int col);
	~Game(){}
	
	void Process();//接收输入、根据输入处理、碰撞和交互、增删物体、显示
	std::string GetKeys();
	void Display();
	void Pause(bool isPause);

protected:

	bool _crashFlag;
	//TODO:以后改成智能指针shared_ptr
	Board _board;
	std::list<std::shared_ptr<Object>>_objs;
	std::list<std::weak_ptr<Object>>_players;
	std::list<std::weak_ptr<Object>>_allys;
	std::list<std::weak_ptr<Object>>_enemys;
	std::list<std::weak_ptr<Object>>_allyBullets;
	std::list<std::weak_ptr<Object>>_enemyBullets;
	std::list<std::weak_ptr<Object>>_treasures;
	std::list<std::weak_ptr<Object>>_effects;
};

