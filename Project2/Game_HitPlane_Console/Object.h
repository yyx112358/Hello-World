#pragma once
//#include "Point.h"
#include <QPoint>
#include <QSize>
#include <QRect>
#include <QObject>

#include <string>
#include "Bitmap.h"
#include <list>
#include <memory>
#include <time.h>

class Object:public QObject
{
	Q_OBJECT

public:
	Object(QRect area, QSize sceneSize)
		:QObject(nullptr),_area(area), _sceneSize(sceneSize),
		id(_RegisterID()), createTime(clock())
	{  }
	virtual ~Object() {}

	void Update()//TODO:����QT֮��Ҫ���⼸���麯��ǰ�����qSignal
	{
		this->_Update();
		_lastUpdateTime = clock();
		emit sig_Updated(this);
	}
	void ProcessInput(const std::string& input)
	{
		this->_ProcessInput(input);
	}
	void Interact(std::shared_ptr<Object> another, bool isCollided)
	{
		this->_Interact(another, isCollided);
	}
	void Multiply(std::list<std::shared_ptr<Object>>&newObjs)
	{
		this->_Multiply(newObjs);
	}
	void Destroy()
	{
		this->_Destroy();
	}

	void SetBitmap(const Bitmap&src) { _bitmap = src; }
	const Bitmap&GetBitmap()const { return _bitmap; }

	void Move(QPoint delta);
	void MoveTo(QPoint dstPt);

	void Resize(QSize size);

	bool IsNeedDestroy()const { return _isNeedDestroy; }
	virtual bool IsInteractable(std::shared_ptr<Object>target)const = 0;//��Ŀ������Ƿ�ɽ���
	friend bool IsCollided(const Object&obj1, const Object&obj2) { return obj1._area.contains(obj2._area, false); }

	const QRect& GetArea()const { return _area; }
	size_t GetID()const { return id; }
	clock_t GetCreateTime()const { return createTime; }

	enum class InteractType :uint16_t	//�������ͣ�ALLY��ENEMYͬ���Ͳ�������NEUTRAL����������VIOLENT������
	{
		NEUTRAL = 0x0000,
		ALLY = 0x0100,
		ENEMY = 0x0200,
		VIOLENT_T = ALLY | ENEMY,
	};
	enum Type
	{
		ALLY_T = (int)InteractType::ALLY,
		ALLY_BULLET_T = ALLY_T + 0x40,
		ALLY_EFFECT_T = ALLY_T + 0x80,
		ENEMY_T = (int)InteractType::ENEMY,
		ENEMY_BULLET_T = ALLY_T + 0x40,
		ENEMY_EFFECT_T = ALLY_T + 0x80,
	};

	Type GetType()const { return _type; }
	const std::string& TypeName() { return _typeName; };
	const size_t id;//��ţ�ÿһ���������
	const clock_t createTime;//����ʱ��	

signals:
	void sig_Updated(const Object* const obj);
protected:
	virtual void _Update() = 0;
	virtual void _ProcessInput(const std::string& input) = 0;
	virtual void _Interact(std::shared_ptr<Object> another, bool isCollided) = 0;
	virtual void _Multiply(std::list<std::shared_ptr<Object>>&newObjs) = 0;
	virtual void _Destroy() = 0;

	QRect _area;//ռ�����򣬰���λ�úʹ�С
	int _z;//[reserve]Z������
	QSize _sceneSize;//��Ļ�ߴ�
	std::string _typeName;//���������������ͷ���
// 	InteractType _interactType;//�������ͣ��ο�InteractType
 	Type _type;//����

	clock_t _lastUpdateTime;//��һ�θ������ʱ��
	bool _isNeedDestroy = false;

	Bitmap _bitmap;
private:
	Object();
	static size_t _RegisterID() { static int amount = 0; return amount++; }
};

