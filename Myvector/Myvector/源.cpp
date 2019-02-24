#include <iostream>
#include <iomanip>
#include <vector>
#include <exception>
#include <memory>
#include <string>
#include <assert.h>
using namespace std;

template<typename Tp>
class MyVector
{
public:
	MyVector()	//构造空数组
		:_p(nullptr),_size(0),_capacity(0)	
	{}
	MyVector(const size_t num)	//构造以默认值初始化的num个元素
		:_p(new Tp[num]()),_size(num),_capacity(num)
	{}
	MyVector(const size_t num, const Tp& value)	//构造以value初始化的num个元素
		:_p(new Tp[num]),_size(num),_capacity(num)
	{
		/* 这是一种写法，理论上效率高些，实际上优化后区别不大。还有一种是用memset()函数，这种对需要深复制或有虚函数表的类会无效
		Tp *p = _p;
		const Tp*end = _p + num;
		while(p<end)
			*p++ = value;*/
		for (auto i = 0u; i < num; i++)
			_p[i] = value;
	}
	MyVector(const MyVector<Tp>&src)//复制构造函数，将src的内容复制过来
		:_p(new Tp[src.size()]), _size(src.size()), _capacity(src.size())
	{
		for (auto i = 0u; i < _size; i++)
			_p[i] = src._p[i];
	}
	MyVector(std::initializer_list<Tp>initList)
		:_p(new Tp[initList.size()]), _size(initList.size()), _capacity(initList.size())
	{
		size_t i = 0;
		for (auto value : initList)
			_p[i++] = value;
	}
	~MyVector()
	{
		_size = 0;//这个优先设定为0，这是为了减少多线程任务中被打断的可能
		_capacity = 0;
		delete[]_p;
	}

	inline size_t size() const { return _size; }
	inline size_t capacity() const { return _capacity; }
	inline bool empty() const { return _size == 0; }

	//返回元素引用，注意考虑越界和空数组的情况
	int& at(const size_t loc)
	{
		assert(loc < _size);//assert(expression)是一个宏定义，在DEBUG模式下，expression成立则无动作，否则抛出异常。RELEASE模式下无效
		return _p[loc];
	}
	int& front()
	{
		assert(empty() == false);
		return _p[0];
	}
	int& back()
	{
		assert(empty() == false);
		return _p[_size - 1];
	}

	void push_back(const int pushnum);
	void pop_back();

	void insert(const size_t dstLoc, const MyVector<Tp>&src, const size_t srcBegin = 0, const size_t srcEnd = src.size())
	{
		//const static size_t expandTbl[] = { 1,2,3,4,6,9,13,19,28,42,63,94,141,211,316,474,711,1066, };
		assert(dstLoc <= _size && srcBegin < src._size && srcEnd <= src._size && srcBegin <= srcEnd);
		const size_t num = srcEnd - srcBegin;
		_expand(dstLoc, num);
		for (size_t i = 0; i < num; i++)
			_p[dstLoc + i] = src._p[srcBegin + i];
	}
	void insert(const size_t loc, const Tp& value);
	void erase(const size_t loc);//删除下标loc的元素
	void clear();//清空
	void swap(MyVector& src);//交换内容，应做到O(1)复杂度
	void reserve(const size_t num);//保留num这么多空间

	MyVector& operator=(const MyVector<Tp>&src);//赋值运算符重载
	int& operator[](const size_t loc);//[]运算符重载
	bool operator==(const MyVector<Tp>& src);//返回两个MyVector是否相等

	friend string to_string(const MyVector<Tp>& src);
	friend ostream&operator<<(ostream&os, const MyVector<Tp>& src)
	{
		os << '[';
		for (auto i = 0u; i < src._size; i++)
			os << src._p[i] << ',';
		os << ']' << endl;
		return os;
	}
protected:
private:
	void _expand(size_t loc, size_t num)
	{
		assert(loc <= _size);
		Tp*tmp = _p;
		if (loc + num > _capacity * 3 / 2)
		{
			tmp = new Tp[_size + num];
			_capacity = _size + num;
			_size += num;
		}
		else if (loc + num > _capacity)
		{
			tmp = new Tp[_capacity * 3 / 2];
			_capacity = _capacity * 3 / 2;
			_size += num;
		}
		else
			tmp = _p;
		
		for (size_t i = 0; i < loc; i++)
			tmp[i] = _p[i];
		for (size_t i = loc; i < loc + num; i++)
			tmp[i + num] = _p[i];
		
		delete[]p;
		p = tmp;
	}
	void _shrink(size_t loc, size_t num);
	Tp *_p = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
};

int main()
{
	vector<int>vi(11),vi1(55,34);
	vi.insert(vi.end(), vi1.begin(), vi1.end());
	try
	{
		MyVector<int>v1, v2(5), v3(4, 7), v4{ 0,1,2,3,4 }, v5 = v4;
		cout << v1 << v2 << v3 << v4 << v5;
		v2.insert(2, v1);
		v2.insert(v2.size(), v3, 1, 3);
// 		v1.front();
// 		v1.back();
		v2.at(4);
// 		v2.at(5);
// 		v2.at(-6);
//		v2 = v3;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
// 	MyVector v1;
// 	cout << v1;
// 	MyVector v2(5);//int a[5]
// 	cout << v2;
// 	MyVector v3(5, 6);//int a[5]={6,6,6,6,6}
// 	cout << v3;
// 	v3.puch_back(77);
// 	cout << v3;
// 	v3.pop_back();
// 	cout << v3;
// 	v3.pop_back();
// 	cout << v3;
// 	v3.puch_back(88);
// 	cout << v3;
// 	v3.puch_back(99);
// 	cout << v3;
// 	v3.insert(2, 100);
// 	cout << v3;
// 	v3.pop_back();
// 	cout << v3;
// 	v3.insert(2, 101);
// 	v3.insert(100, 222);
// 	cout << v3;//friend ostream&operator<<(ostream&os, const MyVector&src)   ||friend ostream&operator<<(cout, v3)
	system("pause");
	return 0;
}