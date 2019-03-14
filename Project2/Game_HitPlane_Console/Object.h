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

	virtual void Update() = 0;//TODO:换用QT之后，要在这几个虚函数前后调用qSignal
	virtual void ProcessInput(const std::string& input) = 0;
	virtual void Interact(Object&another) = 0;
	virtual std::list<std::shared_ptr<Object>>Destroy() = 0;

	void SetBitmap(const Bitmap&src);
	virtual const Bitmap&GetBitmap()const = 0;

	void Move(Point delta);
	void MoveTo(Point dstPt);
	
	void Resize(Size size);

	bool isNeedDestroy()const { return _isNeedDestroy; }
	virtual bool isInteractable(std::shared_ptr<Object>target)const = 0;//与目标对象是否可交互

	Point GetCenter()const { return Point(_tlpt.x + _size.x / 2, _tlpt.y + _size.y / 2); }
	Point GetTopleft()const { return _tlpt; }
	Point GetBottomright()const { return Point(_tlpt.x + _size.x, _tlpt.y + _size.y); }
	size_t GetID()const { return id; }
	clock_t GetCreateTime()const { return createTime; }

	enum class InteractType:uint16_t	//交互类型，ALLY和ENEMY同类型不攻击，NEUTRAL都不攻击，VIOLENT都攻击
	{
		NEUTRAL = 0x0000,
		ALLY = 0x0100,
		ENEMY = 0x0200,
		VIOLENT_T = ALLY | ENEMY,
	};
	enum Type
	{

	};

	virtual const std::string& TypeName() = 0;//类型名，用于类型反射
	const size_t id;//编号，每一个物体独有
	const clock_t createTime;//创建时间	
protected:

	Point _tlpt = Point(0, 0);//物体左上角(top left point)
	int _z;//[reserve]Z轴坐标
	Size _size = Size(0, 0);//物体尺寸
	Size _boardSize;//屏幕尺寸

	clock_t _lastUpdateTime;//上一次更新完成时间
	bool _isNeedDestroy = false;
private:
	Object();
	static size_t _RegisterID() { static int amount = 0; return amount++; }
};

