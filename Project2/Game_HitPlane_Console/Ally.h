#pragma once
#include "Plane.h"
class Ally :
	public Plane
{
public:
	Ally(QRect area, QSize boardSize) 
		:Plane(area, boardSize)
	{
		_bitmap = Bitmap(QSize(1, 1), 'w');	
		_typeName = "ALLY_T";
		_type = Type::ALLY_T;

		_HP = 5;
		_maxHP = 5;
		_score = 0;
	}
	virtual ~Ally(){}
	
	virtual bool IsInteractable(std::shared_ptr<Object>target) const override;
	float GetScore()const { return _score; }
protected:
	
	virtual void _Update() override;
	virtual void _ProcessInput(const std::string& input) override;
	virtual void _Interact(std::shared_ptr<Object> another, bool isCollided) override;
	virtual void _Multiply(std::list<std::shared_ptr<Object>>&newObjs);
	virtual void _Destroy() override;

	float _score;
private:
	Ally();
	
};

