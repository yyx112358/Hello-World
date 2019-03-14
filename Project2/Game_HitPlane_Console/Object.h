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
		:_tlpt(tlpt), _size(size),_boardSize(boardSize),_id(_RegisterID()) ,_createTime(clock())
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
	Point GetCenter()const { return Point(_tlpt.x + _size.x / 2, _tlpt.y + _size.y / 2); }
	Point GetTopleft()const { return _tlpt; }
	Point GetBottomright()const { return Point(_tlpt.x + _size.x, _tlpt.y + _size.y); }
	size_t GetID()const { return _id; }
	clock_t GetCreateTime()const { return _createTime; }

	const std::string typeName;//类型名，用于类型反射
protected:
	const size_t _id;//编号，每一个物体独有
	const clock_t _createTime;//创建时间	

	Point _tlpt = Point(0, 0);//物体左上角(top left point)
	int _z;//[reserve]Z轴坐标
	Size _size = Size(0, 0);//物体尺寸
	Size _boardSize;//屏幕尺寸

	bool _isNeedDestroy = false;
private:
	Object();
	size_t _RegisterID() { static int amount = 0; return amount++; }
};

