#pragma once
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

typedef char PlanMoveType;

class PlaneGame
{
public:
	PlaneGame();//�����ά����
	~PlaneGame();
	void display();//�������ڿ���̨��ʾ
protected:
	int Ex;
	int Ey;
	size_t n = 10;
	size_t _endflag = 0;
	char(*t)[10] = new char[n][10];

private:

};


class PlaneMove:virtual public PlaneGame
{
public:
	PlaneMove();//���캯���������ά���飬�ɻ���ʼλ�ò���ʾ
	void Move();//�ɻ�wasd�ƶ�
	~PlaneMove();//��������
	size_t endflag() const;//������Ϸ��־ESc
protected:
private:
	int px = 0;
	int py = 0;
	void screen(int x, int y);//��������(�ɻ�)λ��
	int keyevents();//��������
};
class EnemiesMove:virtual public PlaneGame
{
public:
	EnemiesMove();
	~EnemiesMove();
	void screen();
private:
	int Ex;
	int Ey; 

};
