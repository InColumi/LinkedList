#include "Base.h"
#include "BaseList.h"
#include <string>



using namespace std;

class Doctor: public Base
{
public:
	void Print()
	{
		cout << "� - ������!\n";
	}
};


class Teacher: public Base
{
public:
	void Print()
	{
		cout << "� - �������!\n";
	}
};


class Fireman: public Base
{
public:
	void Print()
	{
		cout << "� - ��������!\n";
	}
};