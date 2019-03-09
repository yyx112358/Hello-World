#include "Ally.h"


Ally::Ally(Board*board)
	:pboard(board)
{
	_Ax = pboard->row() / 2;
	_Ay = pboard->col() / 2;
}
Ally::~Ally()
{}

void Ally::keyevents()
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
