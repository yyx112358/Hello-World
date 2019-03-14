#include "Board.h"
using namespace std;


void Board::AddObj(std::shared_ptr<Object>pobj)
{
	const Bitmap&objBitmap = pobj->GetBitmap();
	Point boardTlpt(0, 0), boardBrpt(_bitmap.size.x, _bitmap.size.y);
	//TODO:添加支持重叠的函数	
	_bitmap(pobj->GetTopleft()) = objBitmap.Read(Point(0,0));

	//Point crossTlpt(,)
}

void Board::Reset() //=0
{
	system("cls");
	_bitmap.Reset(' ');
}

void Board::Paint() //=0
{
	for (auto x = 0; x < size().x + 2; x++)
		cout << '*';
	cout << endl;
	for (auto y = 0; y < size().y; y++)
	{
		std::cout <<'#';
		for (auto x = 0; x < size().x; x++)
		{
			std::cout << _bitmap(y, x);
		}
		std::cout << '#' << endl;
	}
	for (auto x = 0; x < size().x + 2; x++)
		cout << '#';
	cout << endl;
}
