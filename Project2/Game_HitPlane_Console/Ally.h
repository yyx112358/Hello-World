#pragma once
#include "Plane.h"
class Ally :
	public Plane
{
public:
	Ally(Point tlpt, Size size,Size boardSize):Plane(tlpt,size,boardSize){}
	virtual ~Ally(){}

	virtual void Update() override;
	virtual void ProcessInput(const std::string& input) override;
	virtual void Interact(Object&another) override;
	virtual std::list<std::shared_ptr<Object>> Destroy() override;

	virtual const Bitmap& GetBitmap() const override;	
private:
	Ally();
};

