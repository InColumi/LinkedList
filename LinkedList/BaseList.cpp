#include "BaseList.h"

BaseList::BaseList() {}
BaseList::~BaseList() {}

void BaseList::Show()
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

void BaseList::Input()
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

	Add(new Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note));
}

void BaseList::Sort()
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

void BaseList::Search(std::string text)
{
	void (Node:: * Print)() = static_cast<void(Node::*)()>(&Base::Print);
	std::string(Node:: * GetNote)() = static_cast<std::string(Node::*)()>(&Base::GetNote);
	Node* stepper = _head;
	while(stepper != NULL)
	{
		if((stepper->*GetNote)().find(text) != std::string::npos)
		{
			(stepper->*Print)();
		}
		stepper = stepper->GetNext();
	}
}

bool BaseList::Compere(std::string s1, std::string s2)
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