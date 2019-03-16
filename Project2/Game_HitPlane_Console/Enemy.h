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
	}
	~Enemy(){}

	virtual bool isInteractable(std::shared_ptr<Object>target) const override
	{
		return false;
	}

protected:
	virtual void _Update() override
	{
		_area.moveLeft(_area.left()-1);
		if (_area.right() < 0)
			_isNeedDestroy = true;
	}


	virtual void _ProcessInput(const std::string& input) override
	{
		return;
	}


	virtual void _Interact(Object&another) override
	{
		return;
	}


	virtual std::list<std::shared_ptr<Object>>&& _Destroy() override
	{
		return std::list<std::shared_ptr<Object>>();
	}

};

