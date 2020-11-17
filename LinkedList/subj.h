#include "Node.h"
#include "List.h"
#include "TypeName.h"
#include "BaseAndBaseList.h"
#include <string>

using namespace std;


class Doctor: public Base
{
	
public:
	Doctor(size_t id,
		   std::string lastName,
		   std::string firstName,
		   std::string middleName,
		   std::string mailAddress,
		   std::string phoneNumber,
		   std::string data,
		   std::string note
	): Base(EDoctor, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}
	void Print()
	{
		cout << "� - ������!\n";
	}
};


class Teacher: public Base
{

public:
	Teacher(size_t id,
		   std::string lastName,
		   std::string firstName,
		   std::string middleName,
		   std::string mailAddress,
		   std::string phoneNumber,
		   std::string data,
		   std::string note
	): Base(ETeacher, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}
	void Print()
	{
		cout << "� - �������!\n";
	}
};


class Fireman: public Base
{
public:
	Fireman(size_t id,
		   std::string lastName,
		   std::string firstName,
		   std::string middleName,
		   std::string mailAddress,
		   std::string phoneNumber,
		   std::string data,
		   std::string note
	): Base(EFireman, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}
	void Print()
	{
		cout << "� - ��������!\n";
	}
};

void Base::Print()
{
	//void(Doctor:: * PrintDoctor)() = static_cast<void(Doctor::*)()>(&Base::Print);
	//void(Teacher:: * PrintTeacher)() = static_cast<void(Teacher::*)()>(&Base::Print);
	//void(Fireman:: * PrintFireman)() = static_cast<void(Fireman::*)()>(&Base::Print);
	switch(_itemType)
	{
		case EDoctor:
			((Doctor*) this)->Print();
			break;
		case ETeacher:
			((Teacher*) this)->Print();
			break;
		case EFireman:
			((Fireman*) this)->Print();
			break;

		default:
			cout << "�� ������ ���!\n";
			break;
	}

	cout << "��������� �����: " << _id << '\n';
	cout << "���: " << _lastName << ' ' << _firstName << ' ' << _middleName << '\n';
	cout << "�������� �����: " << _mailAddress << '\n';
	cout << "����� ��������(������ +1 222 333-44-55): " << _phoneNumber << '\n';
	cout << "���� (��.��.����): " << _data << '\n';
	cout << "��������� �������: " << _note << "\n\n";
}