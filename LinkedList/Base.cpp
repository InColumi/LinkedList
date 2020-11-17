#include "Base.h"

Base::Base() {}

Base::Base(size_t id, std::string lastName, std::string firstName, std::string middleName, std::string mailAddress, std::string phoneNumber, std::string data, std::string note)
{
	_id = id;
	_lastName = lastName;
	_firstName = firstName;
	_middleName = middleName;
	_mailAddress = mailAddress;
	_phoneNumber = phoneNumber;
	_data = data;
	_note = note;
}

std::string Base::GetData()
{
	return _data;
}

std::string Base::GetFirstName()
{
	return _firstName;
}

size_t Base::GetId()
{
	return _id;
}

std::string Base::GetLastName()
{
	return _lastName;
}

std::string Base::GetMiddleName()
{
	return _middleName;
}

std::string Base::GetPhoneNumber()
{
	return _phoneNumber;
}

std::string Base::GetMailAddress()
{
	return _mailAddress;
}

std::string Base::GetNote()
{
	return _note;
}

void Base::Print()
{
	std::cout << "��������� �����: " << _id << '\n';
	std::cout << "���: " << _lastName << ' ' << _firstName << ' ' << _middleName << '\n';
	std::cout << "�������� �����: " << _mailAddress << '\n';
	std::cout << "����� ��������(������ +1 222 333-44-55): " << _phoneNumber << '\n';
	std::cout << "���� (��.��.����): " << _data << '\n';
	std::cout << "��������� �������: " << _note << "\n\n";
}