#pragma once
#include <assert.h>
#include <iostream>

template<typename Tp>
class MyVector
{
public:
	MyVector()	//���������
		:_p(nullptr), _size(0), _capacity(0)
	{}
	MyVector(const size_t num)	//������Ĭ��ֵ��ʼ����num��Ԫ��
		:_p(new Tp[num]()), _size(num), _capacity(num)
	{}
	MyVector(const size_t num, const Tp& value)	//������value��ʼ����num��Ԫ��
		:_p(new Tp[num]), _size(num), _capacity(num)
	{
		/* ����һ��д����������Ч�ʸ�Щ��ʵ�����Ż������𲻴󡣻���һ������memset()���������ֶ���Ҫ��ƻ����麯����������Ч
		Tp *p = _p;
		const Tp*end = _p + num;
		while(p<end)
		*p++ = value;*/
		for (auto i = 0u; i < num; i++)
			_p[i] = value;
	}
	MyVector(const MyVector<Tp>&src)//���ƹ��캯������src�����ݸ��ƹ���
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

	//����Ԫ�����ã�ע�⿼��Խ��Ϳ���������
	inline int& at(size_t loc)
	{
		assert(loc < _size);//assert(expression)��һ���궨�壬��DEBUGģʽ�£�expression�������޶����������׳��쳣��RELEASEģʽ����Ч
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
	//���±�dstLoc������src���±�[srcBegin,srcEnd)Ԫ��
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
	//���±�loc������һ��valueԪ��
	void insert(const size_t loc, const Tp& value)
	{
		assert(loc <= _size);
		_expand(loc, 1);
		_p[loc] = value;
	}
	void erase(const size_t loc, size_t num = 1)//ɾ���±�[loc,loc+num)��Ԫ��
	{
		assert(loc <= _size);
		if (loc + num > _size)
			num = _size - loc;
		for (auto i = loc; i + num < _size; i++)
			_p[i] = _p[i + num];
		_size -= num;
	}
	void clear()//���
	{
		_size = 0;	//���Ȱ�_size=0�����ٱ���Ͽ���
		delete[]_p;
		_p = nullptr;
		_capacity = 0;
	}
	void swap(MyVector& src)//�������ݣ�Ӧ����O(1)���Ӷ�
	{
		std::swap(_size, src._size);
		std::swap(_capacity, src._capacity);
		std::swap(_p, src._p);
	}
	//void reserve(size_t num);//����num��ô��ռ�

	MyVector& operator=(const MyVector<Tp>&src)//��ֵ���������
	{
		/*	�������Ҹ�ֵ����ĵ�һ�ַ���
		Tp*tmp = new Tp[src._size];//����һ��tmp����֤�쳣��ȫ�Լ����Ҹ�ֵ��ȫ������v1=v1��
		_size = src._size;
		_capacity = _size;
		for (auto i = 0u; i < _size; i++)
		tmp[i] = src._p[i];
		delete[]_p;
		_p = tmp;*/
		//	�������Ҹ�ֵ����ĵڶ��ַ���
		MyVector tmp(src);
		swap(tmp);
		return *this;
	}
	inline int& operator[](const size_t loc)//[]���������
	{
		return _p[loc];
	}
	bool operator==(const MyVector<Tp>& src)//��������MyVector�Ƿ����
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
	void _expand(size_t loc, size_t num)//���±�loc������num��Ԫ��
	{
		assert(loc <= _size);
		Tp*tmp = _p;
		if (_size + num > _capacity)	//_size + num > _capacity����Ҫ���·����ڴ�
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