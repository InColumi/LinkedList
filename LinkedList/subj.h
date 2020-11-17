#include "Node.h"
#include "List.h"
#include <string>

using namespace std;

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
	Base() {}

	Base(size_t id, string lastName, string firstName, string middleName, string mailAddress, string phoneNumber, string data)
	{
		_id = id;
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

	string GetMailAddress()
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

	void Print()
	{
		cout << "��������� �����: " << _id << '\n';
		cout << "���: " << _lastName << ' ' << _firstName << ' ' << _middleName << '\n';
		cout << "�������� �����: " << _mailAddress << '\n';
		cout << "����� ��������(������ +1 222 333-44-55): " << _phoneNumber << '\n';
		cout << "���� (��.��.����): " << _data << '\n';
		cout << "��������� �������: " << _note << "\n\n";
	}
};

class SubjList: public List
{
private:

public:
	SubjList() {}
	~SubjList() {}

	void Show()
	{
		Node* head = GetHead();
		void (Node:: * Print)() = static_cast<void(Node::*)()>(&Base::Print);
		while(head != NULL)
		{
			(head->*Print)();
			head = head->GetNext();
		}
		delete head;
	}

	void Input()
	{
		Base base;
		size_t id;
		string lastName;
		string firstName;
		string middleName;
		string mailAddress;
		string phoneNumber;
		string data;
		string note;

		cout << "������� ������:\n";
		cout << "\t��������� �����: "; std::cin >> id;
		cout << "\t�������: "; std::cin >> firstName;
		cout << "\t���: "; std::cin >> lastName;
		cout << "\t��������: "; std::cin >> middleName;
		cout << "\t�������� �����: "; std::cin >> mailAddress;
		cout << "\t����� ��������(������ +1 222 333-44-55) :"; std::cin >> phoneNumber;
		cout << "\t���� (��.��.����): "; std::cin >> data;
		cout << "\t��������� �������: "; std::cin >> note;

		Add(new Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data));
	}

	void Sort()
	{
		Node* stepper = _head;
		Node* z, * g, * u;
		size_t size = GetSize(); //���������� ��������� ������
		//����������� ���������� ��� ������
		string(Node:: * GetLastName)() = static_cast<string(Node::*)()>(&Base::GetLastName);
		for(size_t j = 0; j < size - 1; j++)
		{
			for(size_t i = 0; i < size - j - 1; i++)
			{
				if(Compere((stepper->*GetLastName)(), (stepper->GetNext()->*GetLastName)())) //���������� ������� �������� ���������
				{
					//������ �� �������, ���� ��� �� �� �������
					if(size == 2) //���� � ������ ����� ��� ��������
					{
						z = stepper->GetNext();
						g = z->GetNext();
						SetNext(*stepper, g);
						//stepper->GetNext() = g;
						SetNext(*z, stepper);
						//z->GetNext() = stepper;
						SetPrev(*z, stepper->GetPrev());
						//z->GetPrev() = stepper->prev;
						SetPrev(*stepper, z);
						//stepper->prev = z;
						_head = z;
					}
					else if(stepper == GetHead()) //���� ������������ �������� �������
					{
						z = stepper->GetNext();
						g = z->GetNext();
						SetPrev(*g, stepper);
						//g->prev = stepper;
						SetNext(*stepper, g);
						//stepper->next = g;
						SetNext(*z, stepper);
						//z->next = stepper;
						SetPrev(*z, stepper->GetPrev());
						//z->prev = stepper->GetPrev();
						SetPrev(*stepper, z);
						//stepper->prev = z;
						_head = z;
					}
					else if(stepper->GetNext() != _tail) //���� ������ �������������� �� �������� �������
					{
						u = stepper->GetPrev();
						z = stepper->GetNext();
						g = z->GetNext();
						SetPrev(*g, stepper);
						//g->prev = stepper;
						SetNext(*stepper, g);
						//stepper->next = g;
						SetNext(*z, stepper);
						//z->next = stepper;
						SetPrev(*z, stepper->GetPrev());
						//z->prev = stepper->prev;
						SetPrev(*stepper, z);
						//stepper->prev = z;
						SetNext(*u, z);
						//u->next = z;
					}
					else //���� p->next �������� ������� ������
					{
						u = stepper->GetPrev();
						z = stepper->GetNext();

						g = z->GetNext();
						SetNext(*stepper, g);
						//stepper->next = g;
						SetNext(*z, stepper);
						//z->next = stepper;
						SetPrev(*z, stepper->GetPrev());
						//z->prev = stepper->prev;
						SetPrev(*stepper, z);
						//stepper->prev = z;
						SetNext(*u, z);
						//u->next = z;
						_tail = stepper;
					}
				}
				else
					stepper = stepper->GetNext(); //������� � ��������� ����	
			}
			stepper = _head; //��������� ������ �������� � ��������� ��������
		}
	}

private:

	bool Compere(string s1, string s2)
	{
		size_t count = 0;
		size_t size1 = s1.size();
		size_t size2 = s2.size();
		for(size_t i = 0; i < size1 && i < size2; i++)
		{
			if(s1[i] == s2[i])
			{
				count++;
				continue;
			}
			return s1[i] > s2[i];
		}
		return (count == size1) ? true : false;
	}



	//void Search(const List* lst, char* key_word);
	//void PrintListData(const List* lst);
};

class Doctor: public Base, public SubjList
{
public:
	Doctor();
	~Doctor();

private:

};
