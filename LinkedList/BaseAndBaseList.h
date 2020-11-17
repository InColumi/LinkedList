#include "Node.h"
#include "List.h"
#include "TypeName.h"
#ifndef	BASEANSBASELIST_H
#define BASEANSBASELIST_H
class Base: public Node
{
private:
	ItemType _itemType;
	size_t _id;
	std::string _lastName;
	std::string _firstName;
	std::string _middleName;
	std::string _mailAddress;
	std::string _phoneNumber;
	std::string _data;
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

	std::string GetData()
	{
		return _data;
	}

	std::string GetFirstName()
	{
		return _firstName;
	}

	size_t GetId()
	{
		return _id;
	}

	std::string GetLastName()
	{
		return _lastName;
	}

	std::string GetMiddleName()
	{
		return _middleName;
	}

	std::string GetPhoneNumber()
	{
		return _phoneNumber;
	}

	std::string GetMailAddress()
	{
		return _mailAddress;
	}

	std::string GetNote()
	{
		return _note;
	}

	void Print();
};

class BaseList: public List
{
private:

public:
	void Print()
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

		std::cout << "Введите данные:\n";
		std::cout << "\tТабельный номер: "; std::cin >> id;
		std::cout << "\tФамилия: "; std::cin >> firstName;
		std::cout << "\tИмя: "; std::cin >> lastName;
		std::cout << "\tОтчество: "; std::cin >> middleName;
		std::cout << "\tПочтовый адрес: "; std::cin >> mailAddress;
		std::cout << "\tНомер телефона(формат +1 222 333-44-55) :"; std::cin >> phoneNumber;
		std::cout << "\tДата (дд.мм.гггг): "; std::cin >> data;
		std::cout << "\tТекстовая заметка: "; std::cin >> note;

		Add(new Base(itemType, id, lastName, firstName, middleName, mailAddress, phoneNumber, data, note));
	}

	void Sort()
	{
		Node* stepper = _head;
		Node* z, * g, * u;
		size_t size = GetSize(); //количество элементов списка
		//пузырьковая сортировка для списка
		std::string(Node:: * GetLastName)() = static_cast<std::string(Node::*)()>(&Base::GetLastName);
		for(size_t j = 0; j < size - 1; j++)
		{
			for(size_t i = 0; i < size - j - 1; i++)
			{
				if(Compere((stepper->*GetLastName)(), (stepper->GetNext()->*GetLastName)())) //сравниваем фамилии соседних элементов
				{
					//меняем их местами, если они не по порядку
					if(size == 2) //если в списке всего два элемента
					{
						z = stepper->GetNext();
						g = z->GetNext();
						SetNext(*stepper, g);
						SetNext(*z, stepper);
						SetPrev(*z, stepper->GetPrev());
						SetPrev(*stepper, z);
						_head = z;
					}
					else if(stepper == GetHead()) //если переставляем головной элемент
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
					else if(stepper->GetNext() != _tail) //если второй переставляемый не является хвостом
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
					else //если p->next является хвостом списка
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
					stepper = stepper->GetNext(); //переход к следующей паре	
			}
			stepper = _head; //следующих проход начинаем с головного элемента
		}
	}

	void Search(std::string text)
	{
		Node* stepper = _head;
		while(stepper != NULL)
		{
			if(((Base*) this)->GetNote().find(text) != std::string::npos)
			{
				((Base*) this)->Print();
			}
			/*if((stepper->*GetNote)().find(text) != std::string::npos)
			{
				(stepper->*Print)();
			}*/
			stepper = stepper->GetNext();
		}
	}

private:
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