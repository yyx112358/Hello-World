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

int main()
{
// 	auto p = make_shared<derive>();
// 	foo(p);

	Game game(4,5);
	game.Process();
	system("pause");
	return 0;
}