#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{

// 	QCoreApplication a(argc, argv);
// 
// 	return a.exec();
	Game game(8, 9);
	game.Process();
	system("pause");
	return 0;
}
