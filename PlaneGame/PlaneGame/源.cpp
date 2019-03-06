#include <iostream>
#include "PlaneGame.h"
#include <windows.h>
#include <ctime>

using namespace std;
int main()
 {
	 PlaneGame pg1;
	 PlaneMove p1;
	EnemiesMove E1;
	while (1)
	{
		clock_t start,finish;
		start= clock();
		Sleep(2);
		p1.Move();
		finish = clock();
		if ((finish - start) / CLOCKS_PER_SEC>1)
		{
			E1.screen();
		}
		pg1.display();
		if (p1.endflag() != 0)
		{ 
			break;
		}
		system("cls");
	}
	system("pause");
	return 0;
}
