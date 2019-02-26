#include <iomanip>
#include <vector>
#include <exception>
#include <memory>
#include <string>
#include <vld.h>

#include "MyVector.hpp"

using namespace std;

int main()
{
	vector<int>vi{ 0,1,2,3,4 };
	vi.erase(vi.begin() + 2, vi.begin() + 2 + 2);
	try
	{
		MyVector<int>v1, v2(5), v3(4, 7), v4{ 0,1,2,3,4 }, v5 = v4;
		cout << v1 << v2 << v3 << v4 << v5;
		v2.insert(2, v1, 0, v1.size()); cout << v2;
		v3.insert(v3.size()-2, v4, 0, v4.size()); cout << v3;
		v3 = v3; cout << v3;
		v3.erase(2, 3); cout << v3;
		v3.insert(v3.size() - 2, v4, 0, 2); cout << v3;
		v3.erase(3, v3.size() - 1); cout << v3;
		v3.push_back(100); cout << v3;
		v3.pop_back(); cout << v3;
		v5.insert(3, 99); cout << v5;
		cout << v1 << v2 << v3 << v4 << v5;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}