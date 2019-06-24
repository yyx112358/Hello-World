#include "Ally.h"
#include <algorithm>

using namespace std;


void Ally::_Update()
{
	//throw std::logic_error("The method or operation is not implemented.");
}

void Ally::_ProcessInput(const std::string& input)
{
	for (auto c : input)
	{
		switch (c)
		{
		case 'w':_area.moveTop(_area.top() - 1); break;
		case 's':_area.moveTop(_area.top() + 1); break;
		case 'a':_area.moveLeft(_area.left() - 1); break;
		case 'd':_area.moveLeft(_area.left() + 1); break;
		default:
			break;
		}
	}
	if (_area.left() < 0)_area.moveLeft(0);
	if (_area.top() < 0)_area.moveTop(0);
	if (_area.right() >= _sceneSize.width())_area.moveRight(_sceneSize.width() - 1);
	if (_area.bottom() >= _sceneSize.height())_area.moveBottom(_sceneSize.height() - 1);
// 	_tlpt.x = max(0, _tlpt.x);
// 	_tlpt.x=min(0,)
}

void Ally::_Interact(std::shared_ptr<Object> another,bool isCollided)
{
	//throw std::logic_error("The method or operation is not implemented.");
	if (another->GetType() & Type::ENEMY_T && isCollided == true)
	{
		_HP--;
		_score++;
	}
}


void Ally::_Multiply(std::list<std::shared_ptr<Object>>&newObjs)
{

}

void Ally::_Destroy()
{
	//throw std::logic_error("The method or operation is not implemented.");
}
bool Ally::IsInteractable(std::shared_ptr<Object>target) const
{
	return target->GetType()&Type::ENEMY_T;
}




