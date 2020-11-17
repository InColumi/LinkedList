#include "Base.h"
#include "BaseList.h"
#include <string>



using namespace std;

class Doctor: public Base
{
public:
	void Print()
	{
		cout << "Я - доктор!\n";
	}
};


class Teacher: public Base
{
public:
	void Print()
	{
		cout << "Я - учитель!\n";
	}
};


class Fireman: public Base
{
public:
	void Print()
	{
		cout << "Я - пожарный!\n";
	}
};