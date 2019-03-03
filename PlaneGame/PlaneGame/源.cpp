#include <iostream>
#include "PlaneMove.h"

using namespace std;
int main()
{
	PlaneMove p1;
	while (1)
	{
		p1.Move();
		if (p1.endflag() != 0)
		{
			break;
		}
		system("cls");
	}
	system("pause");
	return 0;
}
