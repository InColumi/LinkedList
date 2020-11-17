#include "Node.h"
#include "List.h"
#include "TypeName.h"
#include "BaseAndBaseList.h"
#include <string>

using namespace std;

/// <summary>
/// ����� ������, ��������� Base
/// </summary>
class Doctor: public Base
{
	
public:
	/// <summary>
	/// ����������� � �����������
	/// </summary>
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
	/// <summary>
	/// ���������� ������� ������ Doctor
	/// </summary>
	void Print()
	{
		cout << "� - ������!\n";
	}
};

/// <summary>
/// ����� �������, ��������� Base
/// </summary>
class Teacher: public Base
{

public:
	/// <summary>
	/// ����������� � �����������
	/// </summary>
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
	/// <summary>
	/// ���������� ������� ������ Teacher
	/// </summary>
	void Print()
	{
		cout << "� - �������!\n";
	}
};

/// <summary>
/// ����� ��������, ��������� Base
/// </summary>
class Fireman: public Base
{
public:
	/// <summary>
	/// ����������� � �����������
	/// </summary>
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
	/// <summary>
	/// ���������� ������� ������ Fireman
	/// </summary>
	void Print()
	{
		cout << "� - ��������!\n";
	}
};

/// <summary>
/// ��������������� ����� ����� ���������� �����
/// </summary>
void Base::Print()
{
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