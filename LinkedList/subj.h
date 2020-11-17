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

	size_t GetId()
	{
		return _id;
	}

	string GetLastName()
	{
		return _lastName;
	}

	string GetFirstName()
	{
		return _firstName;
	}

	string GetMiddleName()
	{
		return _middleName;
	}

	string GeMailAddress()
	{
		return _mailAddress;
	}

	string GetPhoneNumber()
	{
		return _phoneNumber;
	}

	string GetData()
	{
		return _data;
	}

	string GetNote()
	{
		return _note;
	}
};

class SubjList: public List
{

public:
	SubjList();
	~SubjList();

private:
	void Print(size_t index)
	{

		cout << "��������� �����: " << _id << '\n';
		cout << "���: " << _firstName << ' ' << _lastName << ' ' << _middleName << '\n';
		cout << "�������� �����: " << _mailAddress << '\n';
		cout << "����� ��������(������ +1 222 333-44-55) :" << _phoneNumber << '\n';
		cout << "����: (��.��.����)" << _data << '\n';
		cout << "��������� �������: " << _note << '\n';
	}

	void Input()
	{
		cout << "������� ������:\n";
		cout << "\t��������� �����: "; std::cin >> _id;
		cout << "\t�������: "; std::cin >> _firstName;
		cout << "\t���: "; std::cin >> _lastName;
		cout << "\t��������: "; std::cin >> _middleName;
		cout << "\t�������� �����: "; std::cin >> _mailAddress;
		cout << "\t����� ��������(������ +1 222 333-44-55) :"; std::cin >> _phoneNumber;
		cout << "\t���� (��.��.����): "; std::cin >> _data;
		cout << "\t��������� �������: "; std::cin >> _note;
	}

	void Sort()
	{
		Base* p = _head;
		Base* z, * g, * u;
		int k, j, i;
		int n = this; //���������� ��������� ������
		//����������� ���������� ��� ������
		for(j = 0; j < n - 1; j++)
		{
			for(i = 0; i < n - j - 1; i++)
			{
				if(strcmp(p->surname, ((Base*) p->next)->surname) > 0) //���������� ������� �������� ���������
				{
					//������ �� �������, ���� ��� �� �� �������
					if(n == 2) //���� � ������ ����� ��� ��������
					{
						z = p->next;
						g = z->next;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						_head = z;
					}
					else if(p == _head) //���� ������������ �������� �������
					{
						z = p->next;
						g = z->next;
						g->prev = p;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						_head = z;
					}
					else if(p->next != _tail) //���� ������ �������������� �� �������� �������
					{
						u = p->prev;
						z = p->next;
						g = z->next;
						g->prev = p;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						u->next = z;
					}
					else //���� p->next �������� ������� ������
					{
						u = p->prev;
						z = p->next;
						g = z->next;
						p->next = g;
						z->next = p;
						z->prev = p->prev;
						p->prev = z;
						u->next = z;
						_tail = p;
					}
				}
				else
					p = p->next; //������� � ��������� ����	
			}
			p = _head; //��������� ������ �������� � ��������� ��������
		}
		void Search(const List * lst, char* key_word);
		void PrintListData(const List * lst);
	};

};

class Doctor: public Base, public SubjList
{
public:
	Doctor();
	~Doctor();

private:

};
