﻿#include <iostream>
using namespace std;

class MyVector
{
public:
	MyVector()
	{
		p = new int[0];
		size = 0;
		capacity = 0;
		cout << __FUNCTION__ << endl;
	}
	MyVector(int num)
	{
		p = new int[num];
		size = num;
		capacity = num;
		cout << __FUNCTION__ << endl;
	}
	MyVector(int num, int value)//创建num个value
	{
		p = new int[num];
		size = num;
		capacity = num;
		for (int i = 0; i < num; i++)
		{
			p[i] = value;
		}
		cout << __FUNCTION__ << endl;
	}
	~MyVector()
	{
		delete[] p;
		size = 0;
		capacity = 0;
		cout << __FUNCTION__ << endl;
	}
	void puch_back(int pushnum)
	{
		int *tmp;
		if (size >= capacity)
		{
			tmp = new int[size + 1];
			for (int i = 0; i < size; i++)
			{
				tmp[i] = p[i];
			}
			tmp[size] = pushnum;
			p = tmp;
			size++;
			capacity++;
		}
		else
		{
			p[size] = pushnum;
			size++;
		}

	}
	void pop_back()
	{
		size = size - 1;
	}
	friend ostream&operator<<(ostream&os, const MyVector&src)
	{
		os << '[';
		for (auto i = 0u; i < src.size; i++)
			os << src.p[i] << ',';
		os << ']' << endl;
		return os;
	}
protected:
private:
	int *p = nullptr;
	int size = 0;
	int capacity = 0;
};

int main()
{
	MyVector v1;
	cout << v1;
	MyVector v2(5);//int a[5]
	cout << v2;
	MyVector v3(5, 6);//int a[5]={6,6,6,6,6}
	cout << v3;
	v3.puch_back(77);
	cout << v3;
	v3.pop_back();
	cout << v3;
	v3.pop_back();
	cout << v3;
	v3.puch_back(88);
	cout << v3;
	v3.puch_back(99);
	cout << v3;
	cout << v3;//friend ostream&operator<<(ostream&os, const MyVector&src)   ||friend ostream&operator<<(cout, v3)
	system("pause");
	return 0;
}