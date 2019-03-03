#pragma once
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

typedef char PlanMoveType;


class PlaneMove
{
public:
	PlaneMove();//构造函数，定义二维数组，飞机初始位置并显示
	void Move();//飞机wasd移动
	~PlaneMove();//析构函数
	size_t endflag() const;//结束游戏标志ESc
protected:
private:
	int px = 0;
	int py = 0;
	size_t n = 10;
	size_t _endflag = 0;
	char(*t)[10] = new char[n][10];
	void screen(int x, int y);//产生界面包括飞机位置
	void display();//将界面在控制台显示
	int keyevents();//键盘输入
};