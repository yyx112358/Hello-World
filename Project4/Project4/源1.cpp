#include<iostream>
#include <vld.h>
#include "Ally.h"
#include "Board.h"
#include "Enemy.h"
#include "Points.h"
#include "Tim.h"
#include "Bullets.h"
using namespace std;

int main()
{
	Board *pboard = nullptr;
	Ally *pally = nullptr;
	pboard = new Board(10, 10);
	int _endflag = 0;
	Ally ally(pboard);
	Bullets bullets(pboard->row()/2+1, pboard->col()/2);////////
	Enemy enemies;
	Tim tim;
	Points p;//////
	while (1)
	{
		ally.keyevents();		
		if (tim.EnemyTime() == true)//¼ÓµÐÈË
		{
			int x = pboard->col() - 1;
			int y = (rand() % (pboard->row()));
			char c = enemies.RandomShape();
			enemies.EnemyState.push_back(Points(x, y, c));
			enemies.Enemynum += 1;
		}
		if (tim.MoveTime() == true)
		{
			bullets.BulletsPush_back((ally.Ax()+1), ally.Ay());
			for (int i = 0; i < enemies.Enemynum; )
			{
				enemies.Enemytag(i);
				if (enemies.EnemyState[i].x < 0 || enemies.EnemyState[i].x >= pboard->col()
					|| enemies.EnemyState[i].y < 0 || enemies.EnemyState[i].y >= pboard->row())
				{
					// 					enemies.Enemyx.erase(enemies.Enemyx.begin() + i);
					// 					enemies.Enemyy.erase(enemies.Enemyy.begin() + i);
					// 					enemies.EnemyShape.erase(enemies.EnemyShape.begin() + i);
					enemies.EnemyState.erase(enemies.EnemyState.begin() + i);
					enemies.Enemynum--;
				}
				else
					i++;
			}
			for (int i = 0; i < bullets.BulletsSize();)
			{
				bullets.BulletsTag(i);
				if (bullets.BulletsValue(i).x >= pboard->col())
				{
					bullets.Bulletsearse(i);
				}
				else
					i++;
			}
		}
		for (auto i = 0; i < bullets.BulletsSize();)
		{
			auto j = 0; 
			bool b = false;
			for (; j < enemies.Enemynum;)
			{
				if ((bullets.BulletsValue(i).x == enemies.EnemyState[j].x) && bullets.BulletsValue(i).y == enemies.EnemyState[j].y)
				{
					bullets.Bulletsearse(i);
					enemies.EnemyState.erase(enemies.EnemyState.begin() + j);
					enemies.Enemynum--;
					b = true;
					break;
				}
				else
					j++;
			}
			if (b==false)
			{
				i++;
			}
		}
		for (auto i = 0; i < enemies.Enemynum; i++)
		{
			if ((ally.Ax() == enemies.EnemyState[i].x) && ally.Ay() == enemies.EnemyState[i].y)
			{
				cout << "Game over";
				_endflag = 1;

			}
		}
		if (_endflag == 1)
		{
			break;
		}
		pboard->mat[ally.Ay()][ally.Ax()] = ally.AllyShape;
		for (auto i = 0; i < bullets.BulletsSize();i++)
		{
			pboard->mat[bullets.BulletsValue(i).y][bullets.BulletsValue(i).x] = '-';
		}
		for (auto i = 0; i < enemies.Enemynum; i++)
		{
			pboard->mat[enemies.EnemyState[i].y][enemies.EnemyState[i].x] = enemies.EnemyState[i].shape;
		}
		system("cls");
		pboard->display();
		static int tim = 0;
		cout << tim++ << endl;
		pboard->mat[ally.Ay()][ally.Ax()] = ' ';
		for (auto i = 0; i < bullets.BulletsSize(); i++)
		{
			pboard->mat[bullets.BulletsValue(i).y][bullets.BulletsValue(i).x] = ' ';
		}
		for (auto i = 0; i < enemies.Enemynum; i++)
		{
			pboard->mat[enemies.EnemyState[i].y][enemies.EnemyState[i].x] = ' ';
		}
	}
	delete pboard;
	system("pause");
	return 0;
}
