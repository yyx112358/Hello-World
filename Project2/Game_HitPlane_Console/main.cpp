#include <QtCore/QCoreApplication>
#include <iostream>
#include "Game.h"

using namespace std;

/*
class base
{
public:
base()
{
cout << __FUNCSIG__ << endl;
}
virtual ~base()
{
cout << __FUNCSIG__ << endl;
}

virtual void func()
{
cout << __FUNCSIG__ << endl;
}
};
class derive:public base
{
public:
derive()
{
cout << __FUNCSIG__ << endl;
}
virtual ~derive()
{
cout << __FUNCSIG__ << endl;
}
virtual void func()final
{
cout << __FUNCSIG__ << endl;
}
};

void foo(shared_ptr<base>&& pd)
{
pd->func();
}*/

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
