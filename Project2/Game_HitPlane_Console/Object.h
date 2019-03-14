#pragma once
#include "Point.h"
#include <string>
#include "Bitmap.h"
#include <list>
#include <memory>
#include <time.h>

class Object
{
public:
	Object(Point tlpt, Size size,Size boardSize) 
		:_tlpt(tlpt), _size(size),_boardSize(boardSize),
		id(_RegisterID()) ,createTime(clock())
	{  }
	virtual ~Object(){}

	virtual void Update() = 0;//TODO:����QT֮��Ҫ���⼸���麯��ǰ�����qSignal
	virtual void ProcessInput(const std::string& input) = 0;
	virtual void Interact(Object&another) = 0;
	virtual std::list<std::shared_ptr<Object>>Destroy() = 0;

	void SetBitmap(const Bitmap&src);
	virtual const Bitmap&GetBitmap()const = 0;

	void Move(Point delta);
	void MoveTo(Point dstPt);
	
	void Resize(Size size);

	bool isNeedDestroy()const { return _isNeedDestroy; }
	virtual bool isInteractable(std::shared_ptr<Object>target)const = 0;//��Ŀ������Ƿ�ɽ���

	Point GetCenter()const { return Point(_tlpt.x + _size.x / 2, _tlpt.y + _size.y / 2); }
	Point GetTopleft()const { return _tlpt; }
	Point GetBottomright()const { return Point(_tlpt.x + _size.x, _tlpt.y + _size.y); }
	size_t GetID()const { return id; }
	clock_t GetCreateTime()const { return createTime; }

	enum class InteractType:uint16_t	//�������ͣ�ALLY��ENEMYͬ���Ͳ�������NEUTRAL����������VIOLENT������
	{
		NEUTRAL = 0x0000,
		ALLY = 0x0100,
		ENEMY = 0x0200,
		VIOLENT_T = ALLY | ENEMY,
	};
	enum Type
	{

	};

	virtual const std::string& TypeName() = 0;//���������������ͷ���
	const size_t id;//��ţ�ÿһ���������
	const clock_t createTime;//����ʱ��	
protected:

	Point _tlpt = Point(0, 0);//�������Ͻ�(top left point)
	int _z;//[reserve]Z������
	Size _size = Size(0, 0);//����ߴ�
	Size _boardSize;//��Ļ�ߴ�

	clock_t _lastUpdateTime;//��һ�θ������ʱ��
	bool _isNeedDestroy = false;
private:
	Object();
	static size_t _RegisterID() { static int amount = 0; return amount++; }
};

