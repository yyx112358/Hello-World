#include <iostream>
#include <vld.h>
using namespace std;


class MyVector
{
public:
	MyVector()
	{
		p = new int[0];
		_size = 0;
		_capacity = 0;
		cout << __FUNCTION__ << endl;
	}
	MyVector(const int num)
	{
		p = new int[num];
		_size = num;
		_capacity = num;
		cout << __FUNCTION__ << endl;
	}
	MyVector(const size_t num,const int value)//����num��value
	{ 
		p = new int[num];
		_size = num;
		_capacity = num;
		for (size_t i = 0; i < num; i++)
		{
			p[i] = value;
		}
		cout << __FUNCTION__ << endl;
	}
	MyVector(const MyVector&src)//���ƹ��캯������src�����ݸ��ƹ���
	{
// 		_size = src.size();
// 		_capacity = _size;
// 		p = new int[_size];
// 		for (int i = 0; i < _size;i++)
// 		{
// 			p[i] = src.p[i];
// 		}
		_copy(src);
		cout << __FUNCTION__ << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
	}
	~MyVector()
	{
		delete[] p;
		p = nullptr;//����Ҫָ��nullptr
		_size = 0;
		_capacity = 0;
		cout << __FUNCTION__ << endl;
	}

	size_t size() const
	{
		return _size;
	}
	size_t capacity() const
	{
		return _capacity;
	}
	bool empty() const
	{
		return _size == 0;
	}

	//����Ԫ�����ã�ע�⿼��Խ��Ϳ���������
	int& at(const size_t loc)
	{
		if (size()<=loc)
		{
			throw "������ʾ";
		}
		return p[loc];
	}
	int& front()
	{
		if (size() == 0)
		{
			throw "������ʾ";
		}
		return p[0];
	}
	int& back()
	{
		if (size() == 0)
		{
			throw "������ʾ";
		}
		return p[size()-1];
	}
	void push_back(const int pushnum)
	{
		int *tmp;
		if (_size >= _capacity)
		{
			tmp = new int[_size + 1];
			for (size_t i = 0; i < _size; i++)
			{
				tmp[i] = p[i];
			}
			tmp[_size] = pushnum;
			delete[]p;
			p = tmp;
			_size++;
			_capacity++;
		}
		else
		{
			p[_size] = pushnum;
			_size++;
		}

	}
	void pop_back()
	{
		//TODO:MyVector�ǿյ�ʱ��pop_back()��ô�죿
		if (empty() == true)
			throw "������";
		_size = _size - 1;
	}

	void insert(const size_t loc,const int value)
	{
		if (loc >= _size)
		{
			throw "������";
		}
		if (_size>=_capacity)
		{
			int *tmp;
			tmp = new int[_size+1];
			for (size_t i = 0; i <loc; i++)
			{
				tmp[i] = p[i];
			}
			tmp[loc] = value;//����ܰ���û���ظ�����
			for (size_t i = loc; i <_size;i++)
			{
				tmp[i + 1] = p[i];
			}
			delete[] p;
			p = tmp;
			_size++;
			_capacity++;
		}
		else
		{
			for (size_t i = _size; i >loc; i--)
			{
				p[i] = p[i - 1];
			}
			p[loc] = value;
			_size++;
		}
	}
	void erase(const size_t loc)//ɾ���±�loc��Ԫ��
	{
		if (size() <= loc)
		{
			throw "������ʾ";
		}
		//������Բ����·����ڴ�
		int *tmp=new int[capacity()-1];
		for (int i = 0; i < size();i++)//��ð������жϷ�������
		{
			if (i<loc-1)
			{
				tmp[i] = p[i];
			}
			else if (i >= loc)
			{
				tmp[i] = p[i + 1];
			}
			else
			{
				continue;
			}
		}
		p = tmp;
		delete[] p;
		_size--;
		_capacity--;
	}
	void clear()//���
	{
		delete[]p;
		 p = nullptr;
		 _size = 0;
		 _capacity = 0;
	}
	void swap(MyVector& src)//�������ݣ�Ӧ����O(1)���Ӷ�
	{
		int *tmp;
		tmp = p;
		p = src.p;
		src.p = tmp;
		std::swap(_size,src._size);
		std::swap(_capacity, src._capacity);
	}

 	MyVector& operator=(const MyVector&src)//��ֵ���������
 	{
	_copy(src);
	return *this;
 	}
	int& operator[](const size_t loc)//[]���������
	{
		return at(loc);
	}
	bool operator==(const MyVector&src)//��������MyVector�Ƿ����
	{
		if (size()==src.size())
		{
			for (int i = 0; i < size();i++)
			{
				if (p[i]!=src.p[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	friend string to_string(const MyVector&src);
	friend ostream&operator<<(ostream&os, const MyVector&src)
	{
		os << '[';
		for (auto i = 0u; i < src._size; i++)
			os << src.p[i] << ',';
		os << ']' << endl;
		return os;
	}
protected:
private:
	void _copy(const MyVector&src)
	{
		//����������Ҹ�ֵ����
		if (p!=nullptr)
		{
			delete[]p;
		}
		_size = src.size();
		_capacity = _size;
		p = new int[_size];
		for (int i = 0; i < _size; i++)
		{
			p[i] = src.p[i];
		}
	}

	int *p = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;

	
};

class MyStack:private MyVector//pop push empty size top
{
public:
	MyStack() :MyVector() { cout << "��ʼ�����캯��"; }
	MyStack(int num) :MyVector(num) { cout << "��ʼ�����캯��num"; }
	MyStack(int num,int value) :MyVector(num, value) { cout << "���캯��num,loc"; }
	friend ostream&operator<<(ostream&os, const MyStack&src)
	{
		os << '[';
		for (auto i = 0u; i < src._size; i++)
			os << src.p[i] << ',';
		os << ']' << endl;
		return os;
	}
protected:
private:
	int *p = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
};

int main()
{
/* 	vector<int>vi{ 0,1,2,3,4,5 };*/
	//vi.clear();
/*	vi.~vector();*/
// 	vi.insert(vi.begin() + 2, 99);
// 		vi.erase(vi.begin() + 3);
// 	MyVector v1;
// 	cout << v1;
// 	MyVector v2(5);//int a[5]
// 	cout << v2;
// 	MyVector v3(5, 6);//int a[5]={6,6,6,6,6}
// 	cout << v3;
// 	v3.push_back(77);
// 	cout << v3;
// 	v3.pop_back();
// 	cout << v3;
// 	v3.pop_back();
// 	cout << v3;
// 	v3.push_back(88);
// 	cout << v3;
// 	v3.push_back(99);
// 	cout << v3;
// 	v3.insert(2, 100);
// 	cout << v3;
// 	v3.pop_back();
// 	cout << v3;
// 	v3.insert(2, 101);
// 	//v3.insert(100, 222);
// 	cout << v3;//friend ostream&operator<<(ostream&os, const MyVector&src)   ||friend ostream&operator<<(cout, v3)
// 	MyVector v5 = v3;
// 	cout << "---------swapp����-------------" << endl;
// 	MyVector Vs(4, 5);
// 	MyVector Va(6, 6);
// 	Vs.swap(Va);
// 	cout << Vs;
// 	cout << Va;
// 	try
// 	{
// vi.at(100);
// 	}
// 	catch (const std::out_of_range&e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	
// 
// 	bool flag;
// 	flag= vi == vt;
// 	cout << flag << endl;
	MyStack();
	MyStack v1(3);
	cout << v1;
	MyStack v2(3, 4);
	cout << v2;

	system("pause");
	return 0;
}