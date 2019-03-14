#pragma once
#include "Plane.h"
class Ally :
	public Plane
{
public:
	Ally(QRect area, QSize boardSize) :Plane(area, boardSize) {	_bitmap = Bitmap(QSize(1, 1), 'w');	}
	virtual ~Ally(){}
	
	virtual bool isInteractable(std::shared_ptr<Object>target) const override;

protected:
	virtual const std::string& TypeName() override;
	virtual void _Update() override;
	virtual void _ProcessInput(const std::string& input) override;
	virtual void _Interact(Object&another) override;
	virtual std::list<std::shared_ptr<Object>>&& _Destroy() override;
private:
	Ally();
};

