#include<iostream>
#include<conio.h>
#include <vector>
#include<ctime>
#include <vld.h>
using namespace std;

class Board
{
public:
	vector<vector<char>>mat;
	Board()
	{}
	Board(const int& row,const int& col)
		:mat(vector<vector<char>>(row, vector<char>(col, ' '))),_row(row),_col(col)
	{}
	~Board()
	{}
	void display()
	{
		for (auto i = 0; i < row(); i++)
		{
			for (auto j = 0; j < col(); j++)
			{
				cout << mat[i][j];
			}
			cout << endl;
		}
	}
	inline int row()const { return _row; }
	inline int col()const { return _col; }
private:
	int _row = 0;
	int _col = 0;


};
class Ally
{
public:
	int _Ax = 0;
	int _Ay = 0;
	int _endflag = 0;
	char AllyShape = 'p';
	Ally(Board*board)
		:pboard(board)
	{
		_Ax = pboard->row() / 2;
		_Ay = pboard->col() / 2;
	}
	~Ally()
	{}
	Board *pboard = nullptr;
	inline int Ax() const { return _Ax; }
	inline int Ay() const { return _Ay; }
	void keyevents()
	{
		int keyhits;
		if (_kbhit())
		{
			keyhits = _getch();
			switch (keyhits)
			{
			case 'w': _Ay > 0 ? _Ay -= 1 : _Ay; break;
			case 's': _Ay < pboard->row() - 1 ? _Ay += 1 : _Ay; break;
			case 'a':  _Ax > 0 ? _Ax -= 1 : _Ax; break;
			case 'd': _Ax < pboard->col() - 1 ? _Ax += 1 : _Ax; break;
			case 27: _endflag = 1; break;
			default:
				break;
			}
		}
	}
private:
};

class OneEnemy
{
public:
	int x, y;
	char shape;
};

class Enemy
{
public:
 	vector<int>Enemyx, Enemyy;
 	vector<char>EnemyShape;
	int Enemynum = 0;
	Enemy()
	{}
	~Enemy()
	{}
	void RandomShape()
	{
		vector<char> RandomLibrary{ 'q','r','e' };
		EnemyShape.push_back(RandomLibrary[rand() % 3]);
	}
	void Enemytag(int i)
	{
		switch (EnemyShape[i])
		{
		case 'q':Enemyx[i]--; Enemyy[i]--; break;
		case 'e':Enemyx[i]--; break;
		case 'r':Enemyx[i]--; Enemyy[i]++; break;
		default:
			break;
		}
	}
protected:
private:
};

class Tim
{
public:
	Tim()
		:StartTime1(0)
	{}
	~Tim()
	{}
	bool EnemyTime()
	{
		if (clock()-StartTime1>2500)
		{
			StartTime1 = clock();
			return  true;
		}
		else 
			return false; 
	}
	bool MoveTime()
	{
		if (clock()-StartTime2>1000)
		{		
			StartTime2 = clock();
			return true;

		}
		else 
			return false;
	}
protected:
private:
	int StartTime1 = 0;
	int StartTime2 = 0;
	bool EnemyTim = false;
	bool MoveTim = false;
};


int main()
{
	Board *pboard = nullptr;
	Ally *pally = nullptr;
	pboard = new Board(10,10);
	int _endflag = 0;
	Ally ally(pboard);
	Enemy enemies;
	Tim tim;
	while (1)
	{
		ally.keyevents();
		if (tim.EnemyTime()==true)//¼ÓµÐÈË
		{
			enemies.Enemyx.push_back(pboard->col() - 1);
			enemies.Enemyy.push_back((rand() % (pboard->row())));
			enemies.RandomShape();
			enemies.Enemynum += 1;
		}
		if (tim.MoveTime() ==true)
		{
			for (int i = 0; i < enemies.Enemynum; )
			{
				enemies.Enemytag(i);
				if (enemies.Enemyx[i] < 0 || enemies.Enemyx[i] >= pboard->col()
					|| enemies.Enemyy[i] < 0 || enemies.Enemyy[i] >= pboard->row())
				{
					enemies.Enemyx.erase(enemies.Enemyx.begin() + i);
					enemies.Enemyy.erase(enemies.Enemyy.begin() + i);
					enemies.EnemyShape.erase(enemies.EnemyShape.begin() + i);
					enemies.Enemynum--;
				}
				else
					i++;
			}
		}
		for (auto i = 0; i < enemies.Enemynum;i++)
		{
			if ((ally.Ax()==enemies.Enemyx[i]) && ally.Ay()==enemies.Enemyy[i])
			{
				cout << "Game over";
				_endflag = 1;

			}
		}
		if (_endflag==1)
		{
			break;
		}
		pboard->mat[ally.Ay()][ally.Ax()] = ally.AllyShape;
		for (auto i = 0; i < enemies.Enemynum;i++)
		{
			pboard->mat[enemies.Enemyy[i]][enemies.Enemyx[i]] = enemies.EnemyShape[i];
		}
		system("cls");
		pboard->display();
		pboard->mat[ally.Ay()][ally.Ax()] = ' ';
		for (auto i = 0; i < enemies.Enemynum; i++)
		{
			pboard->mat[enemies.Enemyy[i]][enemies.Enemyx[i]] = ' ';
		}
	}
	delete pboard;
	system("pause");
	return 0;
}