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
		cout << "Табельный номер: " << _id << '\n';
		cout << "ФИО: " << _firstName << ' ' << _lastName << ' ' << _middleName << '\n';
		cout << "Почтовый адрес: " << _mailAddress << '\n';
		cout << "Номер телефона(формат +1 222 333-44-55): " << _phoneNumber << '\n';
		cout << "Дата (дд.мм.гггг): " << _data << '\n';
		cout << "Текстовая заметка: " << _note << "\n\n";
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

		cout << "Введите данные:\n";
		cout << "\tТабельный номер: "; std::cin >> id;
		cout << "\tФамилия: "; std::cin >> firstName;
		cout << "\tИмя: "; std::cin >> lastName;
		cout << "\tОтчество: "; std::cin >> middleName;
		cout << "\tПочтовый адрес: "; std::cin >> mailAddress;
		cout << "\tНомер телефона(формат +1 222 333-44-55) :"; std::cin >> phoneNumber;
		cout << "\tДата (дд.мм.гггг): "; std::cin >> data;
		cout << "\tТекстовая заметка: "; std::cin >> note;

		Add(new Base(id, lastName, firstName, middleName, mailAddress, phoneNumber, data));
	}

private:


	//void Sort()
	//{
	//	Node* stepper = GetHead();
	//	Base* z, * g, * u;
	//	size_t size = GetSize(); //количество элементов списка
	//	//пузырьковая сортировка для списка
	//	for(size_t j = 0; j < size - 1; j++)
	//	{
	//		for(size_t i = 0; i < size - j - 1; i++)
	//		{
	//			if(strcmp(((Base)stepper->*GetLastName)(), ((Base*) stepper->next)->surname) > 0) //сравниваем фамилии соседних элементов
	//			{
	//				//меняем их местами, если они не по порядку
	//				if(size == 2) //если в списке всего два элемента
	//				{
	//					z = stepper->next;
	//					g = z->next;
	//					stepper->next = g;
	//					z->next = stepper;
	//					z->prev = stepper->prev;
	//					stepper->prev = z;
	//					_head = z;
	//				}
	//				else if(stepper == _head) //если переставляем головной элемент
	//				{
	//					z = stepper->next;
	//					g = z->next;
	//					g->prev = stepper;
	//					stepper->next = g;
	//					z->next = stepper;
	//					z->prev = stepper->prev;
	//					stepper->prev = z;
	//					_head = z;
	//				}
	//				else if(stepper->next != _tail) //если второй переставляемый не является хвостом
	//				{
	//					u = stepper->prev;
	//					z = stepper->next;
	//					g = z->next;
	//					g->prev = stepper;
	//					stepper->next = g;
	//					z->next = stepper;
	//					z->prev = stepper->prev;
	//					stepper->prev = z;
	//					u->next = z;
	//				}
	//				else //если p->next является хвостом списка
	//				{
	//					u = stepper->prev;
	//					z = stepper->next;
	//					g = z->next;
	//					stepper->next = g;
	//					z->next = stepper;
	//					z->prev = stepper->prev;
	//					stepper->prev = z;
	//					u->next = z;
	//					_tail = stepper;
	//				}
	//			}
	//			else
	//				stepper = stepper->next; //переход к следующей паре	
	//		}
	//		stepper = _head; //следующих проход начинаем с головного элемента
	//	}
	//}
	//	//void Search(const List* lst, char* key_word);
	//	//void PrintListData(const List* lst);
};

class Doctor: public Base, public SubjList
{
public:
	Doctor();
	~Doctor();

private:

};
