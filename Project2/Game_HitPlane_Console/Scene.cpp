#include "Scene.h"
using namespace std;

void Scene::Reset() //=0
{
	system("cls");
	_bitmap.Reset(' ');
}

void Scene::AddObj(std::shared_ptr<Object>pobj)
{
	const Bitmap&objBitmap = pobj->GetBitmap();
	//TODO:���֧���ص��ĺ���	
	//TODO:��Ӵ�ͼ�����ʾ
	auto p = pobj->GetArea().topLeft();
	_bitmap(QPoint(p.x(),p.y())) = objBitmap.Read(QPoint(0,0));

	//Point crossTlpt(,)
}

void Scene::Paint() //=0
{
	for (auto x = 0; x < size().width() + 2; x++)
		cout << '*';
	cout << endl;
	for (auto y = 0; y < size().height(); y++)
	{
		std::cout <<'#';
		for (auto x = 0; x < size().width(); x++)
		{
			std::cout << (char)_bitmap(y, x);
		}
		std::cout << '#' << endl;
	}
	for (auto x = 0; x < size().width() + 2; x++)
		cout << '#';
	cout << endl;
}
