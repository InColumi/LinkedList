#include "Node.h"
#include "List.h"
#include "BaseAndBaseList.h"
#include <string>

using namespace std;

/// <summary>
/// ����� ������, ��������� Base
/// </summary>
class Doctor: public Base
{

public:
	Doctor() {}
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
	): Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}

	size_t GetType() override
	{
		return 1;
	}

	void Input() override
	{
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "������� ������ ��� �������:\n";
		std::cout << "\t��������� �����: "; std::cin >> id;
		std::cout << "\t�������: "; std::cin >> firstName;
		std::cout << "\t���: "; std::cin >> lastName;
		std::cout << "\t��������: "; std::cin >> middleName;
		std::cout << "\t�������� �����: "; std::cin >> mailAddress;
		std::cout << "\t����� ��������(������ +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\t���� (��.��.����): "; std::cin >> data;
		std::cout << "\t��������� �������: "; std::cin >> note;

		*this = Doctor(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note);
	}

	/// <summary>
	/// ���������� ������� ������ Doctor
	/// </summary>
	void Print()
	{
		cout << "� - ������!\n";
		cout << "��������� �����: " << GetId() << '\n';
		cout << "���: " << GetLastName() << ' ' << GetLastName() << ' ' << GetMiddleName() << '\n';
		cout << "�������� �����: " << GetMailAddress() << '\n';
		cout << "����� ��������(������ +1 222 333-44-55): " << GetPhoneNumber() << '\n';
		cout << "���� (��.��.����): " << GetData() << '\n';
		cout << "��������� �������: " << GetNote() << "\n\n";
	}
};

/// <summary>
/// ����� �������, ��������� Base
/// </summary>
class Teacher: public Base
{
public:
	Teacher() {}
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
	): Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}

	size_t GetType() override
	{
		return 1;
	}

	void Input() override
	{
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "������� ������ ��� �������:\n";
		std::cout << "\t��������� �����: "; std::cin >> id;
		std::cout << "\t�������: "; std::cin >> firstName;
		std::cout << "\t���: "; std::cin >> lastName;
		std::cout << "\t��������: "; std::cin >> middleName;
		std::cout << "\t�������� �����: "; std::cin >> mailAddress;
		std::cout << "\t����� ��������(������ +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\t���� (��.��.����): "; std::cin >> data;
		std::cout << "\t��������� �������: "; std::cin >> note;

		*this = Teacher(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note);
	}

	/// <summary>
	/// ���������� ������� ������ Teacher
	/// </summary>
	void Print()
	{
		cout << "� - �������!\n";
		cout << "��������� �����: " << GetId() << '\n';
		cout << "���: " << GetLastName() << ' ' << GetLastName() << ' ' << GetMiddleName() << '\n';
		cout << "�������� �����: " << GetMailAddress() << '\n';
		cout << "����� ��������(������ +1 222 333-44-55): " << GetPhoneNumber() << '\n';
		cout << "���� (��.��.����): " << GetData() << '\n';
		cout << "��������� �������: " << GetNote() << "\n\n";
	}
};

/// <summary>
/// ����� ��������, ��������� Base
/// </summary>
class Fireman: public Base
{
public:
	Fireman() {}
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
	): Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note)
	{}

	size_t GetType() override
	{
		return 3;
	}

	void Input() override
	{
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "������� ������ ��� �������:\n";
		std::cout << "\t��������� �����: "; std::cin >> id;
		std::cout << "\t�������: "; std::cin >> firstName;
		std::cout << "\t���: "; std::cin >> lastName;
		std::cout << "\t��������: "; std::cin >> middleName;
		std::cout << "\t�������� �����: "; std::cin >> mailAddress;
		std::cout << "\t����� ��������(������ +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\t���� (��.��.����): "; std::cin >> data;
		std::cout << "\t��������� �������: "; std::cin >> note;

		*this = Fireman(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note);
	}

	/// <summary>
	/// ���������� ������� ������ Fireman
	/// </summary>
	void Print() override
	{
		cout << "� - ��������!\n";
		cout << "��������� �����: " << GetId() << '\n';
		cout << "���: " << GetLastName() << ' ' << GetLastName() << ' ' << GetMiddleName() << '\n';
		cout << "�������� �����: " << GetMailAddress() << '\n';
		cout << "����� ��������(������ +1 222 333-44-55): " << GetPhoneNumber() << '\n';
		cout << "���� (��.��.����): " << GetData() << '\n';
		cout << "��������� �������: " << GetNote() << "\n\n";
	}
};

/// <summary>
/// ��������������� ����� ����� ���������� �����
/// </summary>
void Base::Print()
{
	cout << "��������� �����: " << _id << '\n';
	cout << "���: " << _lastName << ' ' << _firstName << ' ' << _middleName << '\n';
	cout << "�������� �����: " << _mailAddress << '\n';
	cout << "����� ��������(������ +1 222 333-44-55): " << _phoneNumber << '\n';
	cout << "���� (��.��.����): " << _data << '\n';
	cout << "��������� �������: " << _note << "\n\n";
}