#include <iostream>
#include <math.h>
#include <conio.h>
#include <vld.h>

using namespace std;

template<typename Tp> 

class PlaneMove
{
public:
	PlaneMove()
	{
		screen(5,5);
		display();
	}

	void Move()
	{
		keyevents();
		screen(px, py);
		display();
	}
	~PlaneMove()
	{
		delete[] p;
		delete[] (*t);
		px = 0;
		py = 0;
	}
	inline size_t endflag() const
	{
		return _endflag;
	}

protected:
private:
	Tp *p = nullptr;
	int px = 0;
	int py = 0;
	size_t n = 10;
	size_t _endflag = 0;
	char (*t)[10]= new char[n][10];
	void screen(int x,int y)
	{
		px = x;
		py = y;
		for (int i = 0; i < n;i++)
		{
			for (int j = 0; j < n;j++)
			{
				t[i][j] =' ';
			}
		}
		t[x][y] ='P';
	}
	void display()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout<<"  "<<t[i][j];
			cout<<endl;
		}
	}
	int keyevents()
	{
		int keyhits;
		if (_kbhit())
		{
			keyhits = _getch();
			switch (keyhits)
			{
			case 119:return px > 0 ? px -= 1 : px;		 
			case 115:return px<n-1?px+=1:px;
			case 97: return py>0?py-=1:py;
			case 100:return py<n-1?py+=1:py;
			case 27:return _endflag = 1;
			default:
				break;
			}
		}
	}
};

int main()
{
	PlaneMove<string> p1;
	while (1)
	{
		p1.Move();	
		if (p1.endflag()!=0)
		{
			break;
		}
		system("cls");
	}
	system("pause");
	return 0;
}
