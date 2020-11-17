#include "Node.h"
#include "List.h"
#include <string>

using namespace std;

enum ItemType { itDog = 1, itCat, itCrocodile };

class Base: public Node
{
private:
	size_t _id;
	string _lastName;
	string _firstName;
	string _middleName;
	string _mailAddress;
	string _phoneNumber;
	string _data;
	string _note;

public:
	Base(string lastName, string firstName, string middleName, string mailAddress, string phoneNumber, string data)
	{
		_lastName = lastName;
		_firstName = firstName;
		_middleName = middleName;
		_mailAddress = mailAddress;
		_phoneNumber = phoneNumber;
		_data = data;

	}

	void Print()
	{
		cout << "��������� �����: " << _id << '\n';
		cout << "���: " << _firstName << ' ' << _lastName << ' ' << _middleName << '\n';
		cout << "�������� �����: " << _mailAddress << '\n';
		cout << "����� ��������(������ +1 222 333-44-55) :" << _phoneNumber << '\n';
		cout << "����: (��.��.����)" << _data << '\n';
		cout << "��������� �����:" << _id << '\n';

	}
	void Input(Base* p);
	void Print(Base* p);

	void Sort(List* lst);
	void Search(const List* lst, char* key_word);
	void PrintListData(const List* lst);
};

class Doctor: public Base, public SubjList
{
public:
	Doctor();
	~Doctor();

private:

};

class SubjList: public List
{

public:
	SubjList();
	~SubjList();

private:

};