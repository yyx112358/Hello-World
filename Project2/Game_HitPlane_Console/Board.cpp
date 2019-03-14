#include "Board.h"
using namespace std;

void Board::Reset() //=0
{
	system("cls");
	_bitmap.Reset(' ');
}

void Board::AddObj(std::shared_ptr<Object>pobj)
{
	const Bitmap&objBitmap = pobj->GetBitmap();
	//TODO:添加支持重叠的函数	
	_bitmap(pobj->GetArea().topLeft()) = objBitmap.Read(QPoint(0,0));

	//Point crossTlpt(,)
}

void Board::Paint() //=0
{
	for (auto x = 0; x < size().width() + 2; x++)
		cout << '*';
	cout << endl;
	for (auto y = 0; y < size().height(); y++)
	{
		std::cout <<'#';
		for (auto x = 0; x < size().width(); x++)
		{
			std::cout << _bitmap(y, x);
		}
		std::cout << '#' << endl;
	}
	for (auto x = 0; x < size().width() + 2; x++)
		cout << '#';
	cout << endl;
}
