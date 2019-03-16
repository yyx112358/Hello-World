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
	if (_area.right() >= _boardSize.width())_area.moveRight(_boardSize.width() - 1);
	if (_area.bottom() >= _boardSize.height())_area.moveBottom(_boardSize.height() - 1);
// 	_tlpt.x = max(0, _tlpt.x);
// 	_tlpt.x=min(0,)
}

void Ally::_Interact(Object&another)
{
	//throw std::logic_error("The method or operation is not implemented.");
}


std::list<std::shared_ptr<Object>>&& Ally::_Destroy()
{
	//throw std::logic_error("The method or operation is not implemented.");
	return std::list<std::shared_ptr<Object>>();
}
bool Ally::isInteractable(std::shared_ptr<Object>target) const
{
	return false;
}




