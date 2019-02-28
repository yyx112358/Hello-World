#pragma once
#include <QImage>
#include <QString>


class Interface_UI
{
public:
	virtual void Reset() = 0;

	virtual void Display(const QImage& img) = 0;
	virtual void ShowText(const QString&text) = 0;
	virtual int GetKey() = 0;
	virtual int32_t Wait(int32_t ms) = 0;

};