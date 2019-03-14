#include "Ally.h"
#include <algorithm>

using namespace std;


void Ally::Update()
{
	//throw std::logic_error("The method or operation is not implemented.");
}

void Ally::ProcessInput(const std::string& input)
{
	for (auto c : input)
	{
		switch (c)
		{
		case 'w':_tlpt += Point(0, -1); break;
		case 's':_tlpt += Point(0, 1); break;
		case 'a':_tlpt += Point(-1, 0); break;
		case 'd':_tlpt += Point(1, 0); break;
		default:
			break;
		}
	}
	if (_tlpt.x < 0)_tlpt.x = 0;
	if (_tlpt.y < 0)_tlpt.y = 0;
	if (_tlpt.x + _size.x >= _boardSize.x)_tlpt.x = _boardSize.x - _size.x;
	if (_tlpt.y + _size.y >= _boardSize.y)_tlpt.y = _boardSize.y - _size.y;
// 	_tlpt.x = max(0, _tlpt.x);
// 	_tlpt.x=min(0,)
}

void Ally::Interact(Object&another)
{
	//throw std::logic_error("The method or operation is not implemented.");
}

const Bitmap& Ally::GetBitmap() const
{
	//throw std::logic_error("The method or operation is not implemented.");
	static Bitmap b(Size(1, 1), 'w');
	return b;
}

bool Ally::isInteractable(std::shared_ptr<Object>target) const
{
	return false;
}

const std::string& Ally::TypeName()
{
	static const std::string name = "Ally";
	return name;
}

std::list<std::shared_ptr<Object>> Ally::Destroy()
{
	//throw std::logic_error("The method or operation is not implemented.");
	return std::list<std::shared_ptr<Object>>();
}
