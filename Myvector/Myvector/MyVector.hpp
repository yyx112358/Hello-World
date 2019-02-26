#pragma once
#include <assert.h>
#include <iostream>

template<typename Tp>
class MyVector
{
public:
	MyVector()	//构造空数组
		:_p(nullptr), _size(0), _capacity(0)
	{}
	MyVector(const size_t num)	//构造以默认值初始化的num个元素
		:_p(new Tp[num]()), _size(num), _capacity(num)
	{}
	MyVector(const size_t num, const Tp& value)	//构造以value初始化的num个元素
		:_p(new Tp[num]), _size(num), _capacity(num)
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
		clear();
	}

	inline size_t size() const { return _size; }
	inline size_t capacity() const { return _capacity; }
	inline bool empty() const { return _size == 0; }

	//返回元素引用，注意考虑越界和空数组的情况
	inline int& at(size_t loc)
	{
		assert(loc < _size);//assert(expression)是一个宏定义，在DEBUG模式下，expression成立则无动作，否则抛出异常。RELEASE模式下无效
		return _p[loc];
	}
	inline int& front()
	{
		assert(empty() == false);
		return _p[0];
	}
	inline int& back()
	{
		assert(empty() == false);
		return _p[_size - 1];
	}

	void push_back(const Tp& pushval)
	{
		insert(_size, pushval);
	}
	void pop_back()
	{
		erase(_size - 1, 1);
	}
	//在下标dstLoc处插入src的下标[srcBegin,srcEnd)元素
	void insert(size_t dstLoc, const MyVector<Tp>&src, size_t srcBegin, size_t srcEnd)
	{
		//const static size_t expandTbl[] = { 1,2,3,4,6,9,13,19,28,42,63,94,141,211,316,474,711,1066, };
		assert(dstLoc <= _size && srcBegin <= srcEnd && srcEnd <= src._size);
		const size_t num = srcEnd - srcBegin;
		if (num == 0)
			return;
		_expand(dstLoc, num);
		for (size_t i = 0; i < num; i++)
			_p[dstLoc + i] = src._p[srcBegin + i];
	}
	//在下标loc处插入一个value元素
	void insert(const size_t loc, const Tp& value)
	{
		assert(loc <= _size);
		_expand(loc, 1);
		_p[loc] = value;
	}
	void erase(const size_t loc, size_t num = 1)//删除下标[loc,loc+num)的元素
	{
		assert(loc <= _size);
		if (loc + num > _size)
			num = _size - loc;
		for (auto i = loc; i + num < _size; i++)
			_p[i] = _p[i + num];
		_size -= num;
	}
	void clear()//清空
	{
		_size = 0;	//最先把_size=0，减少被打断可能
		delete[]_p;
		_p = nullptr;
		_capacity = 0;
	}
	void swap(MyVector& src)//交换内容，应做到O(1)复杂度
	{
		std::swap(_size, src._size);
		std::swap(_capacity, src._capacity);
		std::swap(_p, src._p);
	}
	//void reserve(size_t num);//保留num这么多空间

	MyVector& operator=(const MyVector<Tp>&src)//赋值运算符重载
	{
		/*	避免自我赋值错误的第一种方法
		Tp*tmp = new Tp[src._size];//加入一个tmp，保证异常安全以及自我赋值安全（例如v1=v1）
		_size = src._size;
		_capacity = _size;
		for (auto i = 0u; i < _size; i++)
		tmp[i] = src._p[i];
		delete[]_p;
		_p = tmp;*/
		//	避免自我赋值错误的第二种方法
		MyVector tmp(src);
		swap(tmp);
		return *this;
	}
	inline int& operator[](const size_t loc)//[]运算符重载
	{
		return _p[loc];
	}
	bool operator==(const MyVector<Tp>& src)//返回两个MyVector是否相等
	{
		if (src._size != _size)
			return false;
		for (auto i = 0u; i < _size; i++)
		{
			if (_p[i] != src._p[i])
				return false;
		}
		return true;
	}

	//friend string to_string(const MyVector<Tp>& src);
	friend std::ostream&operator<<(std::ostream&os, const MyVector<Tp>& src)
	{
		os << '[';
		for (auto i = 0u; i < src._size; i++)
			os << src._p[i] << ',';
		os << ']' << endl;
		return os;
	}
protected:
private:
	void _expand(size_t loc, size_t num)//在下标loc处扩大num个元素
	{
		assert(loc <= _size);
		Tp*tmp = _p;
		if (_size + num > _capacity)	//_size + num > _capacity，需要重新分配内存
		{
			_capacity = (_size + num > _capacity * 3 / 2) ? (_size + num) : (_capacity * 3 / 2);
			tmp = new Tp[_capacity];

			for (size_t i = 0; i < loc; i++)
				tmp[i] = _p[i];
			for (size_t i = loc; i < _size; i++)
				tmp[i + num] = _p[i];
			_size += num;
			delete[]_p;
			_p = tmp;
		}
		else
		{
			tmp = _p;
			for (size_t i = loc; i < _size; i++)
				tmp[i + num] = _p[i];
			_size += num;
		}
	}
	Tp *_p = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
};