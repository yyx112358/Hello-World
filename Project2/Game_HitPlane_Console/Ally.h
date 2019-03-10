#pragma once
#include "Plane.h"
class Ally :
	public Plane
{
public:
	Ally(){}
	~Ally(){}

	virtual void Update() override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


	virtual void ProcessInput(std::string input) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


	virtual void Interact(Object&another) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


	virtual const Bitmap& GetBitmap() const override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};

