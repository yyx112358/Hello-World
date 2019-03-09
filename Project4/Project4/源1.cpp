#include<iostream>
#include <vld.h>
#include "Ally.h"
#include "Board.h"
#include "Enemy.h"
#include "OneEnemy.h"
#include "Tim.h"
using namespace std;

int main()
{
	Board *pboard = nullptr;
	Ally *pally = nullptr;
	pboard = new Board(30, 30);
	int _endflag = 0;
	Ally ally(pboard);
	Enemy enemies;
	Tim tim;
	while (1)
	{
		ally.keyevents();
		if (tim.EnemyTime() == true)//¼ÓµĞÈË
		{
			int x = pboard->col() - 1;
			int y = (rand() % (pboard->row()));
			char c = enemies.RandomShape();
			enemies.EnemyState.push_back(OneEnemy(x, y, c));
			enemies.Enemynum += 1;
		}
		if (tim.MoveTime() == true)
		{
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
		for (auto i = 0; i < enemies.Enemynum; i++)
		{
			pboard->mat[enemies.EnemyState[i].y][enemies.EnemyState[i].x] = enemies.EnemyState[i].shape;
		}
		system("cls");
		pboard->display();
		pboard->mat[ally.Ay()][ally.Ax()] = ' ';
		for (auto i = 0; i < enemies.Enemynum; i++)
		{
			pboard->mat[enemies.EnemyState[i].y][enemies.EnemyState[i].x] = ' ';
		}
	}
	delete pboard;
	system("pause");
	return 0;
}
