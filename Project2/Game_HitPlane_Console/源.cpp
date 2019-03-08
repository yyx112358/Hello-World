#include <iostream>
#include "Game.h"

using namespace std;


int main()
{
// 	Point a, b(3, 4),c(5,6);
// 	cout << a << b << c << endl;
// 	cout << a + b << endl;
// 	(a + b).x = 777;
// 	cout << a << b << c << endl;
// 	cout << a << b << c << endl;
// 	cout << (a += b) << endl;
// 	cout << a << b << c << endl;
// 	cout << (a = b + c) << endl;
// 	cout << endl;

	Game game(3,4);

	game.Process();
	system("pause");
	return 0;
}