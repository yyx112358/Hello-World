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
	OneEnemy(int x,int y,char shape)
		:x(x),y(y),shape(shape)
	{} 
	int x, y;
	char shape;

};

class Enemy
{
public:
//  	vector<int>Enemyx, Enemyy;
//  	vector<char>EnemyShape;
	vector<OneEnemy>EnemyState;
	int Enemynum = 0;
	Enemy()
	{}
	~Enemy()
	{}
	char RandomShape()
	{
		vector<char> RandomLibrary{ 'q','r','e' };
		char rs=(RandomLibrary[rand() % 3]);
		return rs;
	}
	void Enemytag(int i)
	{
		switch (EnemyState[i].shape)
		{
		case 'q':(EnemyState[i].x)--; (EnemyState[i].y)--; break;
		case 'e':(EnemyState[i].x)--; break;
		case 'r':(EnemyState[i].x)--; (EnemyState[i].y)++; break;
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
			int x=pboard->col() - 1;
			int y=(rand() % (pboard->row()));
			char c=enemies.RandomShape();
			enemies.EnemyState.push_back(OneEnemy(x, y, c));
			enemies.Enemynum += 1;
		}
		if (tim.MoveTime() ==true)
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
		for (auto i = 0; i < enemies.Enemynum;i++)
		{
			if ((ally.Ax()==enemies.EnemyState[i].x) && ally.Ay()==enemies.EnemyState[i].y)
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