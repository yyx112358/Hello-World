#include "PlaneMove.h"
#include<iostream>

using namespace std;



PlaneMove::PlaneMove() 
{
	screen(5, 5);
	display();
}

void PlaneMove::Move()
{
	keyevents();
	screen(px, py);
	display();
}
PlaneMove::~PlaneMove()
{
	delete[](*t);
	px = 0;
	py = 0;
}

size_t PlaneMove:: endflag() const
{
	return _endflag;
}

void PlaneMove::screen(int x, int y)
{
	px = x;
	py = y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			t[i][j] = ' ';
		}
	}
	t[x][y] = 'P';
}

void PlaneMove::display()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << "  " << t[i][j];
		cout << endl;
	}
}

int PlaneMove::keyevents()
{
	int keyhits;
	if (_kbhit())
	{
		keyhits = _getch();
		switch (keyhits)
		{
		case 119:return px > 0 ? px -= 1 : px;
		case 115:return px < n - 1 ? px += 1 : px;
		case 97: return py > 0 ? py -= 1 : py;
		case 100:return py < n - 1 ? py += 1 : py;
		case 27:return _endflag = 1;
		default:
			break;
		}
	}
}