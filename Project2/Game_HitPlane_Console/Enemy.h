#pragma once
#include "Plane.h"
class Enemy :
	public Plane
{
public:
	Enemy();
	~Enemy();

	virtual void Update() override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


	virtual void ProcessInput(const std::string& input) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


	virtual void Interact(Object&another) override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


	virtual std::list<std::shared_ptr<Object>> Destroy() override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


	virtual const Bitmap& GetBitmap() const override
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

};

