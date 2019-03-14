#pragma once
#include <vector>
//#include <QImage>
#include <QSize>
#include <QPoint>

constexpr uint32_t CalcARGB(uint8_t alpha, uint8_t red, uint8_t green, uint8_t blue)
{
	return (((uint32_t)alpha) << 24) | (((uint32_t)red) << 16) | (((uint32_t)green) << 8) | blue;
}

class Bitmap
{
public:
	Bitmap() {}
	Bitmap(QSize size,uint32_t value)
		:size(size),
		_data(std::vector<std::vector<uint8_t>>(size.height(), std::vector<uint8_t>(size.width(),value)))
	{}

	void Reset(uint32_t value)
	{
		for (auto row = 0; row < size.height(); row++)
			for (auto col = 0; col < size.width(); col++)
				_data[row][col] = value;
	}

	void Draw(const Bitmap&src, QPoint tlpt)//��src�����Լ��ϣ�
	{
		throw __FUNCSIG__"Not Implement!";

	}

	uint8_t&operator()(size_t row, size_t col) { return _data[row][col]; }
	uint8_t&operator()(QPoint pt) { return _data[pt.y()][pt.x()]; }

	uint8_t Read(QPoint pt)const { return _data[pt.y()][pt.x()]; }
	//TODO:�����ݸ�Ϊshared_ptr����������״̬��������ϵ�����Աȶ�ϵ�����Ŵ�ϵ�����������Ż�
	std::vector<std::vector<uint8_t>>_data;
	QSize size;

	bool isVisiable = true;//�Ƿ�ɼ�
	uint8_t alpha = 0xFF;//͸����
	float brightnessScaler = 1;//���ȷŴ�ϵ��
	float widthScaler = 1;//��ȷŴ�ϵ��
	float heightScaler = 1;//�߶ȷŴ�ϵ��
	float rotateAngle = 0;//��ת�Ƕȣ�˳ʱ�룬�Ƕ��ƣ�
private:
};