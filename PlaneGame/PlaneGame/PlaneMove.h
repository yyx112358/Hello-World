#pragma once
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

typedef char PlanMoveType;


class PlaneMove
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
	size_t n = 10;
	size_t _endflag = 0;
	char(*t)[10] = new char[n][10];
	void screen(int x, int y);//������������ɻ�λ��
	void display();//�������ڿ���̨��ʾ
	int keyevents();//��������
};