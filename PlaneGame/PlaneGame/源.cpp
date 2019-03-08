#include <iostream>
#include "PlaneGame.h"
#include <windows.h>
#include <ctime>
#include <vector>

class Point
{
public:
	Point() :x(0), y(y) {}
	Point(int x, int y):x(x),y(y){}
	int x, y;
};


using namespace std;
int main()
 {
// 	PlaneGame pg1;
// 	PlaneMove p1;
// 	EnemiesMove E1;
// 	while (1)
// 	{
// 		clock_t start,finish;
// 		start= clock();
// 		Sleep(20);
// 		p1.Move();
// 		finish = clock();
// 		if ((finish - start) / CLOCKS_PER_SEC>1)
// 		{
// 			E1.screen();
// 		}
// 		pg1.display();
// 		if (p1.endflag() != 0)
// 		{ 
// 			break;
// 		}
// 		system("cls");
// 	}
	 
	const int width = 8;
	char board[width][width];
	int px = 0, py = 0, n = width;
	int j = 0;
	char ch = 0;
	vector<int> enemyx , enemyy;
	vector<char>EnemyWarehouse{ 'q','e','r' };
	vector<char>EnempyType;

	for (auto i = 0; i < width; i++)
		for (auto j = 0; j < width; j++)  
			board[i][j] = ' ';

	auto enemyTime = clock(); 
	auto appearTime = clock();
	while (1)
	{
		int keyhits;
		bool _endflag = false;
		if (_kbhit())
		{
			keyhits = _getch();
			switch (keyhits)
			{
			case 'a': px > 0 ? px -= 1 : px; break;
			case 'd': px < n - 1 ? px += 1 : px; break;
			case 'w':  py > 0 ? py -= 1 : py; break;
			case 's': py < n - 1 ? py += 1 : py; break;
			case 27: _endflag = true;
			default:
				break;
			}
		}

		if(_endflag==true)
			break;
		if (clock() - appearTime > 2500)
		{
			EnempyType.push_back(EnemyWarehouse[rand() % 3]);
			enemyx.push_back(width);
			enemyy.push_back(rand() % (width - 1));
			appearTime = clock();
		}
		
		if (clock() - enemyTime>1000 &&enemyx.size()>0) 
		{
			for (int i = 0; i < enemyx.size();i++)
  			{
				switch (EnempyType.back()) 
				{
				case'e':enemyx[i]--; break;
				case'q':enemyx[i]--; enemyy[i]--; break;
				case'r':enemyx[i]--; enemyy[i]++; break;
				default:
					break;
				}
			}
			enemyTime = clock();
		}
		for (auto i = 0; i < width; i++)
			for (auto j = 0; j < width; j++)
				board[i][j] = ' ';
		board[py][px] = 'w';
		for (auto i = 0; i < enemyx.size()&& enemyx.size()>0&&EnempyType.size()>0;i++)
		{
			board[enemyy[i]][enemyx[i]] = EnempyType.back();
			EnempyType.pop_back();
		}	
		system("cls");
		for (auto i = 0; i < width; i++)
		{
			for (auto j = 0; j < width; j++)
				cout << board[i][j];
			cout << endl;
		}
		for (auto i = 0; i < enemyx.size()&&enemyx.size()>0; i++)
		{
			if (px == enemyx[i]&&py == enemyy[i])
			{
				cout << "Game Over" << endl;
				break;
			}
		}

	}
	system("pause");
	return 0;
}
