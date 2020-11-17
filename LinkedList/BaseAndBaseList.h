#include "Node.h"
#include "List.h"
#include "TypeName.h"
#ifndef	BASEANSBASELIST_H
#define BASEANSBASELIST_H
/// <summary>
/// ��������� Node
/// </summary>
class Base: public Node
{
private:
	/// <summary>
	/// ��� ������ ��������
	/// </summary>
	ItemType _itemType;
	/// <summary>
	/// ��������� �����
	/// </summary>
	size_t _id;
	/// <summary>
	/// �������
	/// </summary>
	std::string _lastName;
	/// <summary>
	/// ���
	/// </summary>
	std::string _firstName;
	/// <summary>
	/// ��������
	/// </summary>
	std::string _middleName;
	/// <summary>
	/// �������� �����
	/// </summary>
	std::string _mailAddress;
	/// <summary>
	/// �������
	/// </summary>
	std::string _phoneNumber;
	/// <summary>
	/// ����
	/// </summary>
	std::string _data;
	/// <summary>
	/// �������
	/// </summary>
	std::string _note;

public:
	Base() {}

	Base(ItemType itemType, size_t id, std::string lastName, std::string firstName, std::string middleName, std::string mailAddress, std::string phoneNumber, std::string data, std::string note)
	{
		_itemType = itemType;
		_id = id;
		_lastName = lastName;
		_firstName = firstName;
		_middleName = middleName;
		_mailAddress = mailAddress;
		_phoneNumber = phoneNumber;
		_data = data;
		_note = note;
	}

	/// <summary>
	/// ���������� ���� 
	/// </summary>
	/// <returns></returns>
	std::string GetData()
	{
		return _data;
	}

	/// <summary>
	/// ���������� ���
	/// </summary>
	/// <returns></returns>
	std::string GetFirstName()
	{
		return _firstName;
	}

	/// <summary>
	/// ���������� ��������� �����
	/// </summary>
	/// <returns></returns>
	size_t GetId()
	{
		return _id;
	}

	/// <summary>
	/// ���������� �������
	/// </summary>
	/// <returns></returns>
	std::string GetLastName()
	{
		return _lastName;
	}

	/// <summary>
	/// ���������� �������
	/// </summary>
	/// <returns></returns>
	std::string GetMiddleName()
	{
		return _middleName;
	}

	/// <summary>
	/// ���������� �������
	/// </summary>
	/// <returns></returns>
	std::string GetPhoneNumber()
	{
		return _phoneNumber;
	}

	/// <summary>
	/// ���������� �����
	/// </summary>
	/// <returns></returns>
	std::string GetMailAddress()
	{
		return _mailAddress;
	}

	/// <summary>
	/// ���������� �������
	/// </summary>
	/// <returns></returns>
	std::string GetNote()
	{
		return _note;
	}

	/// <summary>
	/// ������� �� ������� � ����������� �� ����
	/// </summary>
	void Print();
};

/// <summary>
/// ��������� List
/// </summary>
class BaseList: public List
{
private:

public:
	/// <summary>
	/// ������� �� ������� ���� ������
	/// </summary>
	void Print()
	{
		Node* head = GetHead();
		while(head != NULL)
		{
			((Base*)this)->Print();
			head = head->GetNext();
		}
		delete head;
	}

	/// <summary>
	/// ���� � ����������
	/// </summary>
	/// <param name="itemType">��� ������ ����</param>
	void Input(ItemType itemType)
	{
		Base base;
		size_t id;
		std::string lastName;
		std::string firstName;
		std::string middleName;
		std::string mailAddress;
		std::string phoneNumber;
		std::string data;
		std::string note;

		std::cout << "������� ������:\n";
		std::cout << "\t��������� �����: "; std::cin >> id;
		std::cout << "\t�������: "; std::cin >> firstName;
		std::cout << "\t���: "; std::cin >> lastName;
		std::cout << "\t��������: "; std::cin >> middleName;
		std::cout << "\t�������� �����: "; std::cin >> mailAddress;
		std::cout << "\t����� ��������(������ +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\t���� (��.��.����): "; std::cin >> data;
		std::cout << "\t��������� �������: "; std::cin >> note;

		Add(new Base(itemType, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note));
	}

	/// <summary>
	/// ���������� ������ �� �������� ������� �->�
	/// </summary>
	void Sort()
	{
		Node* stepper = _head;
		Node* z, * g, * u;
		size_t size = GetSize(); //���������� ��������� ������
		//����������� ���������� ��� ������
		std::string(Node:: * GetLastName)() = static_cast<std::string(Node::*)()>(&Base::GetLastName);
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
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						_head = z;
					}
					else if(stepper == GetHead()) //���� ������������ �������� �������
					{
						z = stepper->GetNext();
						g = z->GetNext();
						SetPrev(*g, stepper);
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						_head = z;
					}
					else if(stepper->GetNext() != _tail) //���� ������ �������������� �� �������� �������
					{
						u = stepper->GetPrev();
						z = stepper->GetNext();
						g = z->GetNext();
						SetPrev(*g, stepper);
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						SetNext(*u, z);
					}
					else //���� p->next �������� ������� ������
					{
						u = stepper->GetPrev();
						z = stepper->GetNext();

						g = z->GetNext();
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						SetNext(*u, z);
						_tail = stepper;
					}
				}
				else
					stepper = stepper->GetNext(); //������� � ��������� ����	
			}
			stepper = _head; //��������� ������ �������� � ��������� ��������
		}
	}

	/// <summary>
	/// ����� �� ��������� ����� � ��������(���� ������� ����������, �� ������� �� �����)
	/// </summary>
	/// <param name="text">�������� �����</param>
	void Search(std::string text)
	{
		Node* stepper = _head;
		while(stepper != NULL)
		{
			if(((Base*) this)->GetNote().find(text) != std::string::npos)
			{
				((Base*) this)->Print();
			}
			stepper = stepper->GetNext();
		}
	}

private:
	/// <summary>
	/// ��������� ���� �����
	/// </summary>
	/// <param name="s1">������ ������</param>
	/// <param name="s2">������ ������</param>
	/// <returns>true ���� ������ ������ ������(�.�. ����� ���� � ��������)</returns>
	bool Compere(std::string s1, std::string s2)
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
};

#endif