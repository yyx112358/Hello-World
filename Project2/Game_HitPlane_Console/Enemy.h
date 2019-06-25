#pragma once
#include "Plane.h"
class Enemy :
	public Plane
{
public:
	Enemy(QRect area, QSize boardSize) 
		:Plane(area, boardSize)
	{
		_bitmap = Bitmap(QSize(1, 1), 'e'); 
		_typeName = "ENEMY_T";
		_type = Type::ENEMY_T;
		_vx = -1;
	}
	virtual ~Enemy(){}

	virtual bool IsInteractable(std::shared_ptr<Object>target) const override
	{
		return target->GetType()&Type::ALLY_T;
	}

protected:
	clock_t _lastMoveTime = clock();

	virtual void _Update() override
	{
		Object::_Update();
		if (_area.right() <= 0)
			_isNeedDestroy = true;

// 		if (clock() - _lastMoveTime > 500)
// 		{
// 			_area.moveLeft(_area.left() - 1);
// 			if (_area.right() < 0)
// 				_isNeedDestroy = true;
// 			_lastMoveTime = clock();
// 		}
	}


	virtual void _ProcessInput(const std::string& input) override
	{
		return;
	}


	virtual void _Interact(std::shared_ptr<Object> another, bool isCollided) override
	{
		if (another->GetType()&Type::ALLY_T && isCollided ==true)
		{
			_isNeedDestroy = true;
		}
		return;
	}

	virtual void _Multiply(std::list<std::shared_ptr<Object>>&newObjs)
	{

	}
	virtual void _Destroy() override
	{
		
	}

};

